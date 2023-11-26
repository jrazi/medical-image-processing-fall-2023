import cellprofiler_core.module as cpm
import cellprofiler_core.pipeline as cpp
import cellprofiler_core.setting as cps

# Create a new pipeline
pipeline = cpp.Pipeline()

# Part I: Preliminary Preparation
# Step 2: Load the incomplete pipeline
pipeline.load("[path_to_incomplete_pipeline.cppipe]")

# Step 3: Import images
images = pipeline.add_image_directory("[path_to_Image_folder]", name="Images")

# Step 5: NameAndType
name_and_type = pipeline.add_module(cpm.NameAndType)
name_and_type.images[0].image_name.value = "OrigColor"
name_and_type.images[0].file_types.value = "ColorImage"
name_and_type.assignments[0].image_name.value = "PlateTemplate"
name_and_type.assignments[0].file_types.value = "BinaryMask"
name_and_type.assignment_method.value = cps.ASSIGN_RULES
name_and_type.assignment_data.value = [{"object_name": "OrigColor", "rule": "starts with", "operand": "-1"},
                                       {"object_name": "PlateTemplate", "rule": "contains", "operand": "PlateTemplate"}]

# Part II: Preparing the Pipeline
# Step 7: ColorToGray
color_to_gray = pipeline.add_module(cpm.ColorToGray)
color_to_gray.channels[0].input_image_name.value = "OrigColor"
color_to_gray.channels[0].output_image_name.value = "OrigRed"
color_to_gray.channels[1].input_image_name.value = "OrigColor"
color_to_gray.channels[1].output_image_name.value = "OrigGreen"
color_to_gray.channels[2].input_image_name.value = "OrigColor"
color_to_gray.channels[2].output_image_name.value = "OrigBlue"

# Step 8: CorrectIlluminationCalculation
illumination_calculation_red = pipeline.add_module(cpm.CorrectIlluminationCalculation)
illumination_calculation_red.input_image_name.value = "OrigRed"
illumination_calculation_red.output_image_name.value = "IllumRed"
illumination_calculation_red.background.value = cps.BF_CORRECTION
illumination_calculation_red.block_size.value = 22

# Repeat the above steps for green and blue channels

# Step 10: ImageMath
image_math = pipeline.add_module(cpm.ImageMath)
image_math.image1_name.value = "OrigBlue"
image_math.image2_name.value = "OrigGreen"
image_math.math.value = "Add"
image_math.output_image_name.value = "CombinedImage"
image_math.scalar.value = 0.5

# Repeat the above steps for steps 11 to 13

# Save the pipeline
pipeline.save("[path_to_save_final_pipeline.cppipe]")
