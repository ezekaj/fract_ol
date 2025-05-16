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

size_t	ft_strlen(char *s);

# endif