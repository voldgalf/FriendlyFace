# FriendlyFace

### Overview

A ROS 2 controlled digital face built with C++ and SDL3

### Installation

#### Installing dependences

##### Linux
```bash
# Update apt before continuing
sudo apt update

# FriendlyFace requires SDL3 and SDL3-Image, to install it run:
sudo apt-get install libsdl3-dev libsdl3-image-dev

# Building FriendlyFace requires CMake, to install it run:
sudo apt install build-essential cmake
```

#### Windows

Follow the SDL3 build process

#### Building with CMake

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
