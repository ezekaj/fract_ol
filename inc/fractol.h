#ifndef FRACTOL_H
# define FRACTOL_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include "../MLX42/include/MLX42/MLX42.h"
# include "../MLX42/include/MLX42/MLX42_Int.h"

# define WIDTH 800
# define HEIGHT 600
# define TITLE "Fractol"

typedef struct s_fractol
{
    mlx_t      *mlx;
    mlx_image_t *img;
} t_fractol;

void	map(int x, int y, double *real, double *imag, t_fractol *fractol)

int	mandelbrot(double real, double imag, int max_i)

# endif