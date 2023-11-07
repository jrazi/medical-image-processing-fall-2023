#include <torch/torch.h>
#include <torchvision/torchvision.h>
#include <cereal/archives/binary.hpp>

// Define the AlexNet module
struct AlexNetImpl : torch::nn::Module {
    torch::nn::Conv2d conv1{nullptr}, conv2{nullptr}, conv3{nullptr}, conv4{nullptr}, conv5{nullptr};
    torch::nn::Linear fc1{nullptr}, fc2{nullptr}, fc3{nullptr};
    torch::nn::Dropout dropout{nullptr};

    AlexNetImpl(int num_classes) {
        // Initialize layers
        conv1 = register_module("conv1", torch::nn::Conv2d(torch::nn::Conv2dOptions(3, 96, 11).stride(4)));
        conv2 = register_module("conv2", torch::nn::Conv2d(torch::nn::Conv2dOptions(96, 256, 5).padding(2)));
        conv3 = register_module("conv3", torch::nn::Conv2d(torch::nn::Conv2dOptions(256, 384, 3).padding(1)));
        conv4 = register_module("conv4", torch::nn::Conv2d(torch::nn::Conv2dOptions(384, 384, 3).padding(1)));
        conv5 = register_module("conv5", torch::nn::Conv2d(torch::nn::Conv2dOptions(384, 256, 3).padding(1)));
        fc1 = register_module("fc1", torch::nn::Linear(256 * 6 * 6, 4096));
        fc2 = register_module("fc2", torch::nn::Linear(4096, 4096));
        fc3 = register_module("fc3", torch::nn::Linear(4096, num_classes));
        dropout = register_module("dropout", torch::nn::Dropout(0.5));

        // Initialize weights
        initialize_weights();
    }

    torch::Tensor forward(torch::Tensor x) {
        // Implement the forward pass
        x = torch::relu(conv1->forward(x));
        x = torch::max_pool2d(x, 3, 2);
        x = torch::relu(conv2->forward(x));
        x = torch::max_pool2d(x, 3, 2);
        x = torch::relu(conv3->forward(x));
        x = torch::relu(conv4->forward(x));
        x = torch::relu(conv5->forward(x));
        x = torch::max_pool2d(x, 3, 2);
        x = x.view({x.size(0), 256 * 6 * 6});
        x = dropout->forward(torch::relu(fc1->forward(x)));
        x = dropout->forward(torch::relu(fc2->forward(x)));
        x = fc3->forward(x);
        return x;
    }

    void initialize_weights() {
        // Implement weight initialization
        for (auto& module : modules(/*include_self=*/false)) {
            if (auto* conv = dynamic_cast<torch::nn::Conv2dImpl*>(module.get())) {
                torch::nn::init::normal_(conv->weight, 0.0, 0.01);
                torch::nn::init::constant_(conv->bias, 0);
            } else if (auto* linear = dynamic_cast<torch::nn::LinearImpl*>(module.get())) {
                torch::nn::init::normal_(linear->weight, 0.0, 0.01);
                torch::nn::init::constant_(linear->bias, 0);
            }
        }
    }
};

// TORCH_MODULE(AlexNet);



int main() {
    // Set device
    torch::Device device(torch::kCUDA);

    // Create model
    auto model = AlexNet(3);  // 3 classes for brain disease
    model->to(device);

    // Define loss function and optimizer
    auto loss_function = torch::nn::CrossEntropyLoss();
    auto optimizer = torch::optim::Adam(model->parameters(), torch::optim::AdamOptions(1e-4));

    // Load datasets
    auto train_dataset = torch::data::datasets::PickleDataset("train_dataset.pkl").map(torch::data::transforms::Stack<>());
    auto valid_dataset = torch::data::datasets::PickleDataset("valid_dataset.pkl").map(torch::data::transforms::Stack<>());
    auto test_dataset = torch::data::datasets::PickleDataset("test_dataset.pkl").map(torch::data::transforms::Stack<>());

    auto train_loader = torch::data::make_data_loader<torch::data::samplers::RandomSampler>(std::move(train_dataset), 64);
    auto valid_loader = torch::data::make_data_loader<torch::data::samplers::SequentialSampler>(std::move(valid_dataset), 64);
    auto test_loader = torch::data::make_data_loader<torch::data::samplers::SequentialSampler>(std::move(test_dataset), 64);

    // Training loop
    for (size_t epoch = 0; epoch != 10; ++epoch) {
        size_t batch_index = 0;
        // Iterate the data loader
        for (auto& batch : *train_loader) {
            // Transfer your images and labels to GPU
            auto data = batch.data.to(device), targets = batch.target.to(device);
            // Reset gradients
            optimizer.zero_grad();
            // Execute forward pass
            auto output = model->forward(data);
            // Compute loss value
            auto loss = loss_function(output, targets);
            // Backpropagate loss
            loss.backward();
            // Update weights
            optimizer.step();

            if (++batch_index % 10 == 0) {
                std::cout << "Epoch: " << epoch << " | Batch: " << batch_index << " | Loss: " << loss.item<float>() << std::endl;
            }
        }
    }

    // Save model
    torch::save(model, "model.pt");

    // Model evaluation
    model->eval();
    torch::NoGradGuard no_grad;
    double total_accuracy = 0;
    size_t total_samples = 0;
    for (const auto& batch : *test_loader) {
        auto data = batch.data.to(device), targets = batch.target.to(device);
        auto output = model->forward(data);
        auto pred = output.argmax(1);
        total_accuracy += pred.eq(targets).sum().item<double>();
        total_samples += targets.size(0);
    }
    double accuracy = total_accuracy / total_samples;
    std::cout << "Accuracy: " << accuracy << std::endl;

    // TODO: Add code for recall, precision, F1 score
    // TODO: Add code for visualizations

    return 0;
}
