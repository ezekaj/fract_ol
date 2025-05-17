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

typedef struct s_coord
{
	double	real_before;
	double	imag_before;
	double	real_after;
	double	imag_after;
	double	zoom_factor;
}	t_coord;

/* Fractal calculation functions */
int		mandelbrot(double real, double imag, int max_i);
int		julia(double real, double imag, double c_real, double c_imag, int max_i);

/* Rendering functions */
void	map(int x, int y, double *real, double *imag, t_fractol *fractol);
int		calculate_pixel(double real, double imag, t_fractol *fractol);
void	render_row(int y, t_fractol *fractol);
void	fractal_render(t_fractol *fractol);

/* Color functions */
int		color_classic(int i, int max_i);
int		color_blue(int i, int max_i);
int		color_fire(int i, int max_i);
int		color_psychedelic(int i, int max_i);
int		color_grayscale(int i, int max_i);
int		colors(int i, int max_i, int color_scheme);

/* Input handling functions */
void	handle_navigation_keys(t_fractol *fractol, keys_t key, double move_speed);
void	handle_zoom_keys(t_fractol *fractol, keys_t key);
void	handle_special_keys(t_fractol *fractol, keys_t key);
void	handle_keys(mlx_key_data_t keydata, void *param);

/* Scroll handling functions */
double	calculate_zoom_factor(t_fractol *fractol, double ydelta);
void	get_coordinates(t_fractol *fractol, int32_t mouse_x, int32_t mouse_y,
			t_coord *coord);
void	adjust_view(t_fractol *fractol, t_coord *coord, double ydelta);
void	handle_scroll(double xdelta, double ydelta, void *param);

/* Initialization and utility functions */
int		parse_sign(const char *str, int *i);
double	parse_integer_part(const char *str, int *i);
double	parse_decimal_part(const char *str, int *i);
double	ft_atof(const char *str);

void	set_default_values(t_fractol *fractol, int type);
void	set_offsets(t_fractol *fractol, int type);
void	set_julia_params(t_fractol *fractol, char **av);
void	init_fractol(t_fractol *fractol, int type, char **av);

# endif