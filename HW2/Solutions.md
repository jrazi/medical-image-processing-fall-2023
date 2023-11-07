# HW 2 Solutions

## Problem 1

1. Answer:

Let's denote the 2x2 matrix as follows:

$$
\begin{bmatrix}
a & b \\
c & d \\
\end{bmatrix}
$$

We can calculate the projections at different angles using the given data. Here's how:

1. **0 degrees (horizontal projection)**:
    - r=0: The projection passes through cells 'a' and 'b', so a+b=10.
    - r=1: The projection passes through cells 'c' and 'd', so c+d=7.

2. **45 degrees (diagonal projection from top-left to bottom-right)**:
    - r=0: The projection passes through cell 'a', so a=7.
    - r=1: The projection passes through cells 'b' and 'c', so b+c=8.
    - r=2: The projection passes through cell 'd', so d=2.

3. **90 degrees (vertical projection)**:
    - r=0: The projection passes through cells 'a' and 'c', so a+c=12.
    - r=2: The projection passes through cells 'b' and 'd', so b+d=5.

4. **135 degrees (diagonal projection from bottom-left to top-right)**:
    - r=0: The projection passes through cell 'c', so c=5.
    - r=1: The projection passes through cells 'a' and 'd', so a+d=9.
    - r=2: The projection passes through cell 'b', so b=3.

From these equations, we can solve for the values of 'a', 'b', 'c', and 'd'. Here's how:

- From the 45-degree projection, we know that a=7.
- From the 135-degree projection, we know that c=5.
- From the 0-degree projection, we can calculate b=10-a=3 and d=7-c=2.
- From the 90-degree projection, we can verify that a+c=12 and b+d=5.

So, the original 2x2 matrix is:

$$
\begin{bmatrix}
7 & 3 \\
5 & 2 \\
\end{bmatrix}
$$

2. Answer:

In a CT scan, the pixel values in the reconstructed image represent the radiodensity of the tissue at each location. The radiodensity is typically measured in Hounsfield units (HU), where air is assigned a value of -1000 HU, water is 0 HU, and dense bone can be over 1000 HU.

In our 2x2 matrix:

$$
\begin{bmatrix}
7 & 3 \\
5 & 2 \\
\end{bmatrix}
$$

We don't have the exact scale to convert these values to Hounsfield units, but we can make some educated guesses based on the relative values.

- The higher values (7 and 5) would likely correspond to denser tissue, such as bone.
- The lower values (3 and 2) would likely correspond to less dense tissue or air.

So, if we had to guess, we might say:

- Indices (1,1) and (2,1) with values 7 and 5, respectively, could correspond to bone tissue.
- Indices (1,2) and (2,2) with values 3 and 2, respectively, could correspond to air.

3. Answer

1. **Speed**: Backprojection is a computationally intensive process. For each pixel in the image, we need to integrate over all possible angles. This means that the time complexity of the algorithm is high, making it slow for large images or when many projections are used.

2. **Sensitivity to Noise**: The backprojection process is highly sensitive to noise in the projection data. Small errors or noise in the measurements can lead to significant artifacts in the reconstructed image. This is particularly problematic in medical imaging, where the quality of the image can directly impact diagnosis and treatment.

3. **Memory Requirement**: Storing the projection data for all angles and distances requires a significant amount of memory. This can be a challenge when dealing with large images or 3D volumes.

In practice, more sophisticated methods are used for CT image reconstruction. One common approach is filtered backprojection, which applies a filter to the projection data to reduce noise before performing the backprojection. Another approach is iterative reconstruction, which starts with an initial guess for the image and iteratively refines it to better match the projection data. These methods can provide better image quality and are more robust to noise, but they are also more computationally intensive.

## Problem 2

1. Answer:

**Contrast in MRI Imaging:** In MRI imaging, contrast between different tissues is primarily created by differences in the relaxation times (T1, T2, and T2*) of the tissues. These relaxation times represent how quickly the net magnetization vector returns to equilibrium after being disturbed by a radiofrequency pulse. Different tissues have different relaxation times due to differences in their molecular composition and structure. For example, fat has a short T1 relaxation time and appears bright on T1-weighted images, while fluid has a long T1 relaxation time and appears dark. By selecting appropriate imaging parameters, an MRI scan can be made sensitive to specific tissue properties, enhancing the contrast between different types of tissues.

2. Answer:

According to the slides, we have $S(t) = e^{-t/T_{2_s}}cos(ω t)$

By setting rotational speed $ω -> 0$, we can remove the sinussoidal compoenent, so we have:

$S(t) = e^{-t/T_{2_s}}$

3. Answer:

Calculating the Frequency and Flip Angle for MRI: The frequency for MRI imaging can be calculated using the Larmor equation, which states that the frequency of precession (f) is equal to the gyromagnetic ratio (γ) times the magnetic field strength (B). Given that the gyromagnetic ratio for hydrogen is 42.5 MHz/T, and the magnetic field at z=2 is B = 2.6 + 0.3*2 = 3.2 T, the frequency would be f = γB = 42.5 MHz/T* 3.2 T = 136 MHz.

## Problem 3

For Matter L1, we have:

$$N_1 = N_0 e^{-\int_{0}^{l_1} 2x^2 dx} = N_0 e^{-\frac{2}{3}l_1^3}$$

For Matter L2, we have:

$$N_2 = N_1 e^{-\int_{0}^{l_2} (x + 3) dx} = N_1 e^{-\frac{1}{2}l_2^2 - 3l_2} = N_0 e^{-\frac{2}{3}l_1^3} e^{-\frac{1}{2}l_2^2 - 3l_2}$$

And for Matter L3, we have:

$$N_3 = N_2 e^{-\int_{0}^{l_3} \frac{1}{3} dx} = N_2 e^{-\frac{1}{3}l_3} = N_0 e^{-\frac{2}{3}l_1^3} e^{-\frac{1}{2}l_2^2 - 3l_2} e^{-\frac{1}{3}l_3}$$

So, the final expression for $N_3$ is:

$$N_3 = N_0 e^{-\frac{2}{3}l_1^3 - \frac{1}{2}l_2^2 - 3l_2 - \frac{1}{3}l_3}$$

This is the output radiation after passing through all three matters. The actual numerical value of $N_3$ will depend on the values of $N_0$, $l_1$, $l_2$, and $l_3$.

## Problem 4

1. The advantages of PET-CT digital systems, compared to the previous systems, are:
    - They use silicon-photomultipliers (SiPM) that exhibit an increased detector sensitivity, resulting in a higher spatial resolution and coincidence time resolution  .
    - They have improved signal recovery, which increases the detectability of small and low-count lesions  .
    - They benefit from the time-of-flight (TOF) option, which enhances the image quality and reduces the noise .
    - They allow for shorter acquisition times or lower administered activities without compromising the diagnostic quality  .
2. The idea and the methodology used in the paper are:
    - The paper aims to generate synthetic full-dose PET images from ultra-low-count ExtremePET images that are acquired on a digital PET/CT scanner in about 30 seconds, using a deep learning network.
    - The input of the network is a six-channel image that combines the ExtremePET and the CT images, both in 2.5-dimensional (2.5d) format. The 2.5d format consists of stacking three adjacent axial slices to create a three-channel image. The output of the network is a single-channel image that corresponds to the central slice of the synthetic full-dose PET image.
    - The network architecture is based on the pix2pixHD model , which consists of two generators and a multi-scale discriminator. The generators operate with different resolutions to aggregate both local and global features of the image. The discriminator employs three separate discriminators, each operating on a different image scale. The network also uses a group convolution in the first layer of the generators, which allows the network to process PET and CT images separately.
    - The metrics used for evaluation are the Structural Similarity Index Measure (SSIM), the Peak Signal to Noise Ratio (PSNR), and the SUV-based Mean Absolute Error (MAE). These metrics measure the similarity between the synthetic and the original full-dose PET images. The results show that the network can produce synthetic PET images of high visual quality and reasonable lesion detectability and quantification. However, the network performs better for larger lesions of higher tracer uptake than for smaller and low-uptake lesions.

## Problem 5

1. **A-Mode (Amplitude Mode) Ultrasound**¹²:
    - A-mode ultrasound is the simplest type of ultrasound imaging.
    - The image is shown on the screen in one-dimension¹.
    - A single transducer scans the body. Using an X and Y axis, the collected information is then plotted on the screen as a function of depth¹.
    - A-mode, or amplitude mode, is ideal for measuring distances¹.
    - A-mode ultrasound may also be used to discover cysts or tumors¹.

2. **B-Mode (Brightness Mode) Ultrasound**¹⁴:
    - B-mode ultrasound uses linear array transducers to simultaneously scan a plane through the body¹.
    - These echoes are converted by the machine into a 2D image¹.
    - This is the most commonly used ultrasound mode¹.
    - B-mode, or 2B mode, has a wide range of applications¹.
    - The visual created by B-mode ultrasound is easy to interpret quickly¹.
    - B-mode ultrasound allows for visualization and quantification of anatomical structures, as well as for diagnostic and therapeutic procedures⁴.

3. **M-Mode (Motion Mode) Ultrasound**¹⁷:
    - M-mode ultrasound works similarly to a stop-motion video¹.
    - This type takes a collection of A-mode or B-mode ultrasound images and uses them, in effect, to create a video¹.
    - M-mode ultrasound, or “movement mode”, allows doctors to see the amplitude of movements¹.
    - This is ideal for regulating the velocity of organ structures or observing differences over a period of time¹.
    - M-mode provides a one-dimensional view of all reflectors along one ultrasound line, displaying all structures along that line over time⁷.

Each of these modes has its own unique applications and is used depending on the specific requirements of the ultrasound examination. For example, A-mode might be used for simple distance measurements, B-mode for a more comprehensive view of the internal structures, and M-mode for observing the motion of these structures over time.

## Problem 6

1. Adversarial attacks are malicious inputs that can fool deep neural networks into making wrong predictions or classifications. Medical images are usually noisy due to various factors such as imaging modalities, patient motion, and environmental interference. These noises can act as adversarial perturbations that degrade the performance and robustness of deep neural networks in medical image analysis. For example, the paper mentions that multiplicative noise, such as speckle, Poisson, and Gaussian noise, is common in radiological medical images like X-rays, and can cause linear filters to fail in denoising ¹[1].

2. The challenges of creating a balanced, annotated dataset of medical images include the following:
    - The scarcity of annotated medical image data, which prevents the training and validation of robust deep learning architectures²[2]. The image labeling is a tedious task that requires supervision by medical professionals, making it expensive and time-consuming ³[3].
    - The imbalance of data for a particular class in the dataset, which can create a bias in the deep neural network and lead to overfitting or underfitting⁴[4]. Overfitting means that the model learns the training data too well and fails to generalize to new data. Underfitting means that the model fails to learn the training data sufficiently and has poor performance on both training and test data .
    - The privacy and ethical issues related to medical data, which restrict the sharing and distribution of medical image data in the open-source domain⁵[5]. Medical data is protected by various international regulations in different countries, such as the Health Insurance Portability and Accountability Act (HIPAA) in the United States, which prohibit the disclosure of sensitive patient health information without the knowledge or consent of the patient ⁶[6].

    The solutions for creating a balanced, annotated dataset of medical images include the following:
    - The generation of synthetic datasets using data augmentation techniques, which involve the manipulation of original images to produce new images with preserved features⁷[7]. Data augmentation can increase the effective volume and diversity of the image dataset and reduce the risk of overfitting. Data augmentation techniques can be divided into classical image manipulation methods, such as translation, rotation, cropping, flipping, scaling, and noise addition, and deep learning methods, such as autoencoders and generative adversarial networks (GANs), which can learn the features of the data and generate realistic synthetic images  ⁸[8].
    - The use of domain adaptation techniques, which enable the transfer of knowledge from a source domain to a target domain with different distributions. Domain adaptation can overcome the problem of data scarcity and imbalance by leveraging the existing labeled data from a related domain and adapting it to the unlabeled data from the target domain. Domain adaptation techniques can be categorized into feature-based methods, which aim to align the feature distributions of the source and target domains, and pixel-based methods, which aim to transform the appearance of the source images to match the target images  .
    - The use of privacy-preserving techniques, which ensure the security and anonymity of the medical data while allowing its sharing and analysis. Privacy-preserving techniques can be classified into pseudonymization methods, which replace the identifiable information of the patients with pseudonyms, and differential privacy methods, which add controlled noise to the data or the queries to prevent the inference of individual information  .

3. Quantitative metrics to evaluate models are not enough because they do not provide a clear and intuitive explanation of how the model works and why it makes certain predictions or classifications. Quantitative metrics, such as accuracy, precision, recall, and F1 score, can only measure the overall performance of the model on a given dataset, but they cannot reveal the internal logic, the learned features, or the potential errors or biases of the model⁹[9]. Therefore, we also need visual explainability, which is a technique that uses visual representations, such as heatmaps, saliency maps, or activation maps, to highlight the regions or pixels in the input image that contribute the most to the output of the model. Visual explainability can help the users to understand the reasoning process and the decision criteria of the model, as well as to verify the validity and reliability of the model's predictions or classifications. Visual explainability can also help the developers to debug and improve the model by identifying the sources of errors or failures  .

Some examples of algorithms for visual explainability are:

    - Class Activation Mapping (CAM), which uses the output of the last convolutional layer and the weights of the fully connected layer to generate a heatmap that shows the importance of each spatial location for a specific class .
    - Gradient-weighted Class Activation Mapping (Grad-CAM), which extends CAM by using the gradients of the output class with respect to the feature maps of the last convolutional layer to produce a heatmap that is more general and applicable to different architectures .
    - Local Interpretable Model-agnostic Explanations (LIME), which approximates the behavior of the model around a given input by using a simple interpretable model, such as a linear regression, and generates a saliency map that shows the weights of each pixel for the prediction .

4. Answer:

- Model agnostic methods are explainability techniques that can be applied to any type of model or architecture, regardless of their internal structure or logic. They provide a high level of flexibility and generality, but they may not capture the specific features or mechanisms of a particular model. Some examples of model agnostic methods are LIME, SHAP, and WIT, which use local approximations, game theory, or interactive visualization to explain the predictions of a model.
- Model specific methods are explainability techniques that are tailored to a specific type of model or architecture, taking advantage of their internal structure or logic. They provide a more detailed and accurate explanation of a particular model, but they may not be applicable or transferable to other models. Some examples of model specific methods are CAM, Grad-CAM, and LRP, which use the output of the convolutional layers, the gradients of the output class, or the relevance propagation to generate heatmaps that highlight the important regions or pixels in the input image.
- The pros and cons of model agnostic and model specific methods can be summarized as follows:

Sure, here is the information from the table converted into a simplified text:

- **Model Agnostic Methods**:
  - **Pros**: These methods are applicable to any model or architecture, making them flexible and general. They are also relatively easy to implement and compare across different models.
  - **Cons**: On the downside, they may not capture the specific features or mechanisms of a particular model. Their accuracy or reliability may not be very high, and they may require additional computation or data.

- **Model Specific Methods**:
  - **Pros**: These methods are tailored to a specific model or architecture, allowing them to provide detailed and accurate explanations. They can exploit the internal structure or logic of the model.
  - **Cons**: However, they are not applicable or transferable to other models. They may be complex or difficult to implement or interpret, and their effectiveness may depend on the model architecture or parameters.
