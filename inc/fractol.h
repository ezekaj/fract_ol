/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezekaj <ezekaj@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 18:33:28 by ezekaj            #+#    #+#             */
/*   Updated: 2025/05/19 01:30:00 by ezekaj           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

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

# define KEY_ESC 65307
# define KEY_PLUS 61
# define KEY_MINUS 45
# define SCROLL_UP 4
# define SCROLL_DOWN 5
# define MOUSE_LEFT 1

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
}	t_fractol;

/* parse.c */
int		parse_sign(const char *str, int *i);
double	parse_integer_part(const char *str, int *i);
double	parse_decimal_part(const char *str, int *i);
double	ft_atof(const char *str);
int		parse_args(int ac, char **av);

/* init.c */
void	set_default_values(t_fractol *f, int type);
void	set_julia_params(t_fractol *f, char **av);
void	init_fractol(t_fractol *f, int type, char **av);

/* fractal.c */
int		mandelbrot(double real, double imag, int max_i);
int		julia(double real, double imag, t_fractol *f);
int		calc_pixel(double real, double imag, t_fractol *f);

/* render.c */
void	my_pixel_put(t_fractol *f, int x, int y, int color);
void	fractal_render(t_fractol *f);

/* events.c */
int		handle_close(t_fractol *f);
int		handle_key(int keycode, t_fractol *f);
int		handle_mouse(int button, int x, int y, t_fractol *f);

/* main.c */
void	print_usage(void);

#endif
