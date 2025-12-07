# FriendlyFace

### Overview

Humanoid robot faces are unnerving, why not make them friendly looking?

Introducing *FriendlyFace*, a face display program built in C++ using SDL3, controlled with ROS 2.

#### What is FriendlyFace?

FriendlyFace is a C++ SDL program designed to display different faces depending on the read `emotionValue` variable. A separate thread updates `emotionValue`, avoiding interference with the main thread.

### Installing Dependencies

```bash
# Update apt before continuing
sudo apt update

# FriendlyFace requires SDL3 and SDL3-Image, to install it run:
sudo apt-get install libsdl3-dev libsdl3-image-dev

# Building FriendlyFace requires CMake, to install it run:
sudo apt install build-essential cmake
```

### Building with CMake

```bash
# Install the RobotDevelopment repo (which includes FriendlyFace)
git clone https://github.com/voldgalf/FriendlyFace.git

# Navigate towards the installed repo's directory
cd FriendlyFace

# Create the build files
mkdir build

cd build

cmake ..

# Build FriendlyFace
cmake --build .
```

# License
[MIT License](/LICENSE.txt)