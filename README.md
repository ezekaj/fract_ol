# Fract'ol

A fractal exploration program created as part of the 42 curriculum.

## Description

This program renders different types of fractals, allowing you to explore and interact with them.

## Dependencies

- [GLFW](https://www.glfw.org/)
- CMake (for building MLX42)

### Installing Dependencies

#### On Linux (Debian/Ubuntu)
```bash
sudo apt update
sudo apt install build-essential libx11-dev libglfw3-dev libglfw3 xorg-dev cmake
```

#### On macOS (using Homebrew)
```bash
brew install glfw cmake
```

## Installation

1. Clone the repository with submodules:
```bash
git clone https://github.com/gasolineeater/fract_ol.git
cd fract_ol
git submodule init
git submodule update
```

Alternatively, you can clone with submodules in one command:
```bash
git clone --recurse-submodules https://github.com/gasolineeater/fract_ol.git
cd fract_ol
```

2. Compile the project:
```bash
make
```

This will:
- Build the MLX42 library
- Compile the libft library
- Build the fractol executable

## Usage

Run the program with:
```bash
./fractol [fractal_type]
```

Where `fractal_type` is the type of fractal you want to display:

- `mandelbrot`: The Mandelbrot set
- `julia [c_real] [c_imag]`: The Julia set with optional parameters (default: -0.7 0.27015)

## Controls

- **Mouse wheel**: Zoom in/out at mouse cursor position
- **+/-**: Zoom in/out from center
- **Arrow keys**: Move around
- **Page Up/Down**: Cycle through color schemes
- **I/D**: Increase/Decrease maximum iterations
- **R**: Reset view
- **ESC**: Exit the program

## Color Schemes

The program includes several color schemes that can be cycled through using the Page Up and Page Down keys:
- Classic: Purple and white gradient
- Blue: Blue-dominant gradient
- Fire: Red, orange, and yellow gradient resembling flames
- Psychedelic: Rainbow cycling colors
- Grayscale: Black and white gradient

## Project Structure

- `src/`: Source code files
- `inc/`: Header files
- `libft/`: Custom C library
- `MLX42/`: Graphics library
