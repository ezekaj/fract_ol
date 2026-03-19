/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezekaj <ezekaj@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 18:33:28 by ezekaj            #+#    #+#             */
/*   Updated: 2025/05/19 01:30:00 by ezekaj           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_BONUS_H
# define FRACTOL_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include "../minilibx-linux/mlx.h"
# include "../libft/libft.h"

# define WIDTH 800
# define HEIGHT 600
# define MAX_ITER 100

# define MANDELBROT 1
# define JULIA 2
# define TRICORN 3

# define SCHEME_CLASSIC 0
# define SCHEME_BLUE 1
# define SCHEME_FIRE 2
# define SCHEME_PSYCHEDELIC 3
# define SCHEME_GRAYSCALE 4
# define NUM_SCHEMES 5

# ifdef __APPLE__
#  define KEY_ESC 53
#  define KEY_UP 126
#  define KEY_DOWN 125
#  define KEY_LEFT 123
#  define KEY_RIGHT 124
#  define KEY_PLUS 24
#  define KEY_MINUS 27
#  define KEY_C 8
#  define KEY_R 15
#  define KEY_S 1
#  define KEY_L 37
#  define KEY_M 46
# else
#  define KEY_ESC 65307
#  define KEY_UP 65362
#  define KEY_DOWN 65364
#  define KEY_LEFT 65361
#  define KEY_RIGHT 65363
#  define KEY_PLUS 61
#  define KEY_MINUS 45
#  define KEY_C 99
#  define KEY_R 114
#  define KEY_S 115
#  define KEY_L 108
#  define KEY_M 109
# endif
# define MOUSE_LEFT 1
# define SCROLL_UP 4
# define SCROLL_DOWN 5

typedef struct s_color
{
	int		r;
	int		g;
	int		b;
	double	t;
	double	phase;
}	t_color;

typedef struct s_fractol
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
	int		type;
	double	c_real;
	double	c_imag;
	double	zoom;
	double	offset_x;
	double	offset_y;
	int		max_iter;
	int		color_scheme;
	int		julia_locked;
	int		smooth_color;
	int		animate_colors;
	double	color_shift;
	double	anim_speed;
	double	z_real;
	double	z_imag;
}	t_fractol;

/* parse_bonus.c */
int		parse_sign(const char *str, int *i);
double	parse_integer_part(const char *str, int *i);
double	parse_decimal_part(const char *str, int *i);
double	ft_atof(const char *str);
int		parse_args(int ac, char **av);

/* init_bonus.c */
void	set_default_values(t_fractol *f, int type);
void	set_offsets(t_fractol *f, int type);
void	set_julia_params(t_fractol *f, char **av);
void	init_fractol(t_fractol *f, int type, char **av);

/* fractal_bonus.c */
int		mandelbrot(double real, double imag, t_fractol *f);
int		julia(double real, double imag, t_fractol *f);
int		tricorn(double real, double imag, t_fractol *f);
int		calc_pixel(double real, double imag, t_fractol *f);

/* render_bonus.c */
void	my_pixel_put(t_fractol *f, int x, int y, int color);
double	calc_smooth_value(t_fractol *f, int iter);
void	fractal_render(t_fractol *f);

/* colors_bonus.c */
int		color_classic(double t, double tp);
int		color_blue(double t, double tp);
int		color_fire(double t, double tp);
int		color_psychedelic(double t, double tp);
int		color_grayscale(double t, double tp);

/* colors_util_bonus.c */
int		get_color(int scheme, double t, double tp);
void	clamp_color(t_color *c);
int		pack_color(t_color *c);
int		color_inside(void);

/* events_bonus.c */
int		handle_close(t_fractol *f);
int		handle_key(int keycode, t_fractol *f);
int		handle_mouse(int button, int x, int y, t_fractol *f);

/* events_util_bonus.c */
void	zoom_at_mouse(t_fractol *f, int x, int y, double factor);
void	re_render(t_fractol *f);
int		handle_zoom_keys(int keycode, t_fractol *f);
int		animation_loop(t_fractol *f);

/* main_bonus.c */
void	print_usage(void);

#endif
