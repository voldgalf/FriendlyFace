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
