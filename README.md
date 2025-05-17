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
- `tricorn`: The Tricorn/Mandelbar fractal

## Controls

- **Mouse wheel**: Zoom in/out at mouse cursor position
- **+/-**: Zoom in/out from center (works with both regular and numpad keys)
- **Arrow keys** or **WASD**: Move around
- **C**: Cycle through color schemes
- **I/D**: Increase/Decrease maximum iterations
- **R**: Reset view (resets position, zoom, and iterations)
- **S**: Toggle smooth coloring
- **U**: Toggle UI display
- **T**: Toggle multi-threaded rendering
- **M**: Toggle color animation (for psychedelic color scheme)
- **+/-**: Adjust animation speed when animation is enabled
- **L**: Lock/unlock Julia set parameters (when in Julia mode)
- **Left Mouse Button**: Lock current Julia parameters (when in Julia mode)
- **ESC**: Exit the program

## Color Schemes

The program includes several color schemes that can be cycled through using the C key:
- Classic: Purple and white gradient
- Blue: Blue-dominant gradient
- Fire: Red, orange, and yellow gradient resembling flames
- Psychedelic: Rainbow cycling colors
- Grayscale: Black and white gradient

## Bonus Features

- **Multiple Fractal Types**: Mandelbrot, Julia, and Tricorn
- **Interactive Julia Set**: Move your mouse over the Julia set to change parameters in real-time
- **Smooth Coloring**: Toggle with S key for more aesthetically pleasing renders
- **Animated Colors**: Toggle with M key for dynamic, flowing color transitions in the psychedelic scheme
- **On-screen Information**: Display coordinates, zoom level, and iteration count
- **Multi-threading**: Toggle with T key for faster rendering on multi-core systems
- **UI Controls**: Toggle the UI display with U key

## Project Structure

- `src/`: Source code files
- `inc/`: Header files
- `libft/`: Custom C library
- `MLX42/`: Graphics library
