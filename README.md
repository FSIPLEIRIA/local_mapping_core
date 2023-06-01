# T24e Local Mapping Core Library

T24e local mapping core library.

It constructs a map of the cone's location relative to the car's axes from a pair of color and depth images.

It will use DAMO-YOLO convolutional neural network to detect the cones, and then uses the camera's intrinsic parameters
to reconstruct the image coordinates to relative world coordinates.

In the future, we are thinking of adding another neural network to perform depth estimation
from color, to make it work only on color images.

## Requirements

- Eigen 3
- OpenCV