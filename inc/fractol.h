#ifndef FRACTOL_H
# define FRACTOL_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <string.h>
# include "../MLX42/include/MLX42/MLX42.h"
# include "../MLX42/include/MLX42/MLX42_Int.h"
# include "../libft/libft.h"

# define WIDTH 800
# define HEIGHT 600
# define TITLE "Fractol"

# define MANDELBROT 1
# define JULIA 2

# define COLOR_SCHEME_CLASSIC 0
# define COLOR_SCHEME_BLUE 1
# define COLOR_SCHEME_FIRE 2
# define COLOR_SCHEME_PSYCHEDELIC 3
# define COLOR_SCHEME_GRAYSCALE 4
# define NUM_COLOR_SCHEMES 5

# define DEFAULT_MAX_ITER 100

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
	int			color_scheme;
	int			max_iter;
}	t_fractol;

void	map(int x, int y, double *real, double *imag, t_fractol *fractol);
void	fractal_render(t_fractol *fractol);
int		mandelbrot(double real, double imag, int max_i);
int		julia(double real, double imag, double c_real, double c_imag, int max_i);
int		colors(int i, int max_i, int color_scheme);
void	init_fractol(t_fractol *fractol, int type, char **av);
void	handle_keys(mlx_key_data_t keydata, void *param);
void	handle_scroll(double xdelta, double ydelta, void *param);

# endif