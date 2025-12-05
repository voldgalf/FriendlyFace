# FriendlyFace

### Overview

A simple customizable robot face written in C with SDL.

#### Features

- Customizable faces
- Emotional controlled expressions
  
#### Emotional Face Controls protocol

The protocol allows for emotion controlled facial expressions, via socket connections with an *emotion server*

The Emotional Face Controls protocol is seperate from the main thread, running in a second thread.

This is completely optional and is **not** required for the program to run correctly.

### Installation

> [!CAUTION]
> FriendlyFace is currently only supported on Linux

#### Installing dependences

```bash
# Update apt before continuing
sudo apt update

# FriendlyFace requires SDl3, to install it run:
sudo apt-get install libsdl3-dev

# Building FriendlyFace requires CMake, to install it run:
sudo apt install build-essential cmake
```

#### Building with CMake

```bash
# Install the RobotDevelopment repo (which includes FriendlyFace)
git clone https://github.com/voldgalf/RobotDevelopment.git

# Navigate towards the installed repo's directory
cd RobotDevelopment/FriendlyFace

# Create the build files
mkdir build

cd build

cmake ..

# Build FriendlyFace
cmake --build .
```
