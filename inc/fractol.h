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

# define MANDELBROT 1
# define JULIA 2

typedef struct s_fractol
{
	mlx_t		*mlx;
	mlx_image_t	*img;
	int			type;
	double		c_real;
	double		c_imag;
	double		zoom;
	double		offset_x;
	double		offset_y;
}	t_fractol;

void	map(int x, int y, double *real, double *imag, t_fractol *fractol);
void	fractal_render(t_fractol *fractol);
int		mandelbrot(double real, double imag, int max_i);
int		julia(double real, double imag, double c_real, double c_imag, int max_i);
int		colors(int i, int max_i);
void	init_fractol(t_fractol *fractol, int type, char **av);
void	handle_keys(mlx_key_data_t keydata, void *param);
void	handle_scroll(double xdelta, double ydelta, void *param);

# endif