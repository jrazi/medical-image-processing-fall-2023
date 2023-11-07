
# Intelligent Analysis Of Medical Images

## Theory Problems

### Problem One

1. Using data described below, for a CT-Scan image, reconstruct the original 2x2 matrix by back projection. Provide an step-by-step explanation.

The below data describes that for each pair of (angle (degrees), distance=r), What number is displayed by the receiver. (In context of CT Scan Images). Some values are intentionally missing (marked with `?`)

(Hint: Consider a 2x2 square object that you want to find it's 4 values. For each angle, you must calculate that for each r, which cells in the table are involved )

```
angle,r,x
0,0,10
0,1,7
0,2,?
45,0,7
45,1,8
45,2,2
90,0,12
90,2,5
90,3,?
135,0,5
135,1,9
135,2,3
```

Here is the formula for backprojection btw:

$b(x, y) = B\{p(r, \theta)\} = \int_0^π p(x.cos(\theta) + y.sin(\theta), \theta) d\theta$

1. Determine which indices in the reconstructed matrix of CT belonged to Bone tissue, and which indices were related to air. Provide rationale behind your answer.

2. Why do you think this method in not practical in reconstruction of CT images? (Discuss the problem from aspects of speed, sensitivity to light, memory requirement)

### Problem 2

1. In MRI imaging, how contrast is created between different tissues?

2. In MRI, the signal received from tissues is a damped sinusoidoal function. How the sinussoidal part can be removed so that the only part of the signal, are parts that are informative about the tissue.

3. The magnetic field, generated in an MRI device is equal to $B = 2.6 + 0.3z$. What frequency should we use if we want to image in the cross section $z = 2$? Secondary, if the maximum signal detectable by the device is $68 * 10^7 MHZ$, find the flip angle. (Consider the gyromagnetic factor of Hydrogen to be 42.5 T/M, and assume that there are $10^7$ Hydrogen atoms in the target tissue.)

### Problem 3

The below text describes 3 different matters with damping coefficients of $\mu_1, \mu_2, \mu_3$ and the lengths of $l_1, l_2, l_3$.

```

Matter L1:
Input: $N_0$
Damping Coefficients: $\mu_1$
Length: $l_1$
Output: $N_1$


Matter L2:
Input: $N_1$
Damping Coefficients: $\mu_2$
Length: $l_2$
Output: $N_2$

Matter L3:
Input: $N_2$
Damping Coefficients: $\mu_3$
Length: $l_3$
Output: $N_3$

```

If $N_0$ is the input radiation, what is the value of $N_3$? Here are the $\mu$ functions:

```
$\mu_1(x) = 2x^2$

$\mu_2(x) = x + 3$

$\mu_3(x) = \sub{1}{3}$ 
```

Hint: You can take advantage of the formula of attenuation ($\mu(x)$), which has the following equation:

$I_{out} = I_{in}e^{-\int_{x_{in}}^{x_out} \mu(x) dx}$

Where $x_{in} and x_{out}$ can be $(0, l_k)$

### Problem 4

In PET-CT Imaging, you typically do a simultaneuous CT Scan, in addition to the Pet Scan, so that the hot (active) areas highlighted by PET, are accompanied with other tissues, and also precise location of active areas. On the other hand, we know that given the significantly longer half-life of the elements used in a PET Scan, it can take a much longer time compared to CT Scan, which can make the imaging a bit more challenging. It is better for us, and the patient,  if we  minimize the imaging time. However, if the enough time is not dedicated to the imaging procedure, and enough number of particles are not detected, the reconstructed image will have a low quality.

The paper with the title "Artificial intelligence guided enhancement of digital PET: scans as fast as CT?", DOI "10.1007/s00259-022-05901-x", provides a deep learning solution to address this issue. Here is the abstract of the paper:

"""
Both digital positron emission tomography (PET) detector technologies and artificial intelligence based image post-reconstruction methods allow to reduce the PET acquisition time while maintaining diagnostic quality. The aim of this study was to acquire ultra-low-count fluorodeoxyglucose (FDG) ExtremePET images on a digital PET/computed tomography (CT) scanner at an acquisition time comparable to a CT scan and to generate synthetic full-dose PET images using an artificial neural network.
"""

Considering the problem, and by studying and analyzing the said paper, answer the following:

1. What is the advantages of PET-CT digital systems, compared to the previous systems?
2. Explain the idea, and the methodology used in the paper. Your explanation MUST include the following: (And other important key points)

- What is the input and the output of the network?
- Describe the architecture of the proposed network in this paper.
- What is the metric(s) used for evaluation, and what are the results?

### Problem 5

Considering that for analyzing, and working with Ultrasound images, you need to have knowledge of different modes of Ultrasound images, study the difference between 3 modes of A, B, and M in Ultrasound imaging. What are their main differences among them, and What are the applications of each one?

### Problem 6

I want to get more acknowledged to the challenges of using AI, and specifically Deep Learning, in analyzing medical images. The paper "Challenges of Deep Learning in Medical Image Analysis—Improving Explainability and Trust", with DOI "10.1109/TTS.2023.3234203", is a good paper on this subject. Here is the abstract of the paper:

"""
Deep learning has revolutionized the detection of diseases and is helping the healthcare sector break barriers in terms of accuracy and robustness to achieve efficient and robust computer-aided diagnostic systems. The application of deep learning techniques empowers automated AI-based utilities requiring minimal human supervision to perform any task related to medical diagnosis of fractures, tumors, and internal hemorrhage; preoperative planning; intra-operative guidance, etc. However, deep learning faces some major threats to the flourishing healthcare domain. This paper traverses the major challenges that the deep learning community of researchers and engineers faces, particularly in medical image diagnosis, like the unavailability of balanced annotated medical image data, adversarial attacks faced by deep neural networks and architectures due to noisy medical image data, a lack of trustability among users and patients, and ethical and privacy issues related to medical data. This study explores the possibilities of AI autonomy in healthcare by overcoming the concerns about trust that society has in autonomous intelligent systems.
"""

By reading the full text of paper, and have a deep understading of what it says, answer the following questions.

1. What are the effects of adverserial attack on deep neural networks, considering the fact that medical images are usually noisy.

2. Discuss the challenges, and the provided solutions in creating a balanced, annotated dataset of medical images.

3. Explain that why we quantitive metrics to evaluate models are not enough, and we also need "Visual Explaintability". Provide a few example of algorithms for visual explainability.
4. Discuss the "Explainability" of "Model Agnostic", and "Model Specific" methods, and compare them by describing the pros and cons of each one.
