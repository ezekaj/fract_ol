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
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <string.h>
# include <pthread.h>
# include "../MLX42/include/MLX42/MLX42.h"
# include "../MLX42/include/MLX42/MLX42_Int.h"
# include "../libft/libft.h"

# define WIDTH 800
# define HEIGHT 600
# define TITLE "Fractol"
# define NUM_THREADS 4

# define MANDELBROT 1
# define JULIA 2
# define TRICORN 3

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
	int			smooth_color;
	int			show_ui;
	int			julia_locked;
	int			use_threads;
	int			animate_colors;
	double		animation_time;
	double		animation_speed;
}	t_fractol;

typedef struct s_thread_data
{
	t_fractol	*fractol;
	int			start_y;
	int			end_y;
}	t_thread_data;

typedef struct s_coord
{
	double	real_before;
	double	imag_before;
	double	real_after;
	double	imag_after;
	double	zoom_factor;
}	t_coord;

typedef struct s_color
{
	int		r;
	int		g;
	int		b;
	int		brightness;
	double	t;
	double	phase;
	double	time_phase;
}	t_color;

typedef struct s_julia_params
{
	double	real;
	double	imag;
	double	c_real;
	double	c_imag;
	int		max_i;
}	t_julia_params;

typedef struct s_map_params
{
	int		x;
	int		y;
	double	*real;
	double	*imag;
}	t_map_params;

typedef struct s_smooth_calc
{
	double		z_real;
	double		z_imag;
	double		temp;
	double		real;
	double		imag;
	int			i;
	int			j;
	double		*smooth_i;
	t_fractol	*fractol;
}	t_smooth_calc;

typedef struct s_render_vars
{
	double			real;
	double			imag;
	double			smooth_i;
	int				x;
	int				i;
	int				color;
	t_map_params	map_params;
}	t_render_vars;

/* Fractal calculation functions */
int		mandelbrot(double real, double imag, int max_i);
int		julia(t_julia_params *params);
int		tricorn(double real, double imag, int max_i);

/* Rendering functions */
void	map(t_map_params *params, t_fractol *fractol);
int		calculate_pixel(double real, double imag, t_fractol *fractol);
void	calculate_mandelbrot_smooth(t_smooth_calc *calc);
void	calculate_julia_smooth(t_smooth_calc *calc);
void	calculate_tricorn_smooth(t_smooth_calc *calc);
void	calculate_smooth_values(t_smooth_calc *calc);
int		get_animated_smooth_color(t_fractol *fractol, double smooth_i, int i);
int		get_smooth_color(t_fractol *fractol, double smooth_i, int i);
void	process_smooth_color(t_render_vars *vars, t_fractol *fractol);
void	process_standard_color(t_render_vars *vars, t_fractol *fractol);
void	process_pixel_color(t_render_vars *vars, t_fractol *fractol, int y);
void	render_row(int y, t_fractol *fractol);
void	fractal_render(t_fractol *fractol);
void	create_render_threads(pthread_t *threads, t_thread_data *thread_data,
			t_fractol *fractol);
void	threaded_fractal_render(t_fractol *fractol);

/* UI functions */
void	get_color_scheme_name(int color_scheme, char *buffer);
void	get_fractal_name(int type, char *buffer);
void	render_ui_text(t_fractol *fractol);

/* Color functions */
int		color_classic(int i, int max_i);
int		color_blue(int i, int max_i);
int		color_fire(int i, int max_i);
int		color_psychedelic(int i, int max_i);
int		color_grayscale(int i, int max_i);
int		color_classic_animated(int i, int max_i, double time);
int		color_blue_animated(int i, int max_i, double time);
int		color_fire_animated(int i, int max_i, double time);
void	init_psychedelic_animated_color(t_color *color, int i, int max_i,
			double time);
void	apply_psychedelic_animated_effects(t_color *color);
int		color_psychedelic_animated(int i, int max_i, double time);
int		color_grayscale_animated(int i, int max_i, double time);
int		colors(int i, int max_i, int color_scheme);
int		colors_animated_classic_blue(int i, int max_i, int color_scheme,
			double time);
int		colors_animated_fire_psychedelic(int i, int max_i,
			int color_scheme, double time);
int		colors_animated(int i, int max_i, int color_scheme, double time);

/* Smooth coloring functions */
double	calc_smooth_value(double z_real, double z_imag, int iter, int max_i);
int		smooth_color_classic(double smooth_iter, int max_i);
int		smooth_color_blue(double smooth_iter, int max_i);
int		smooth_color_fire(double smooth_iter, int max_i);
void	init_psychedelic_color(t_color *color, double smooth_iter, int max_i);
void	apply_psychedelic_effects(t_color *color);
void	clamp_color_values(t_color *color);
int		smooth_color_psychedelic(double smooth_iter, int max_i);
int		smooth_color_grayscale(double smooth_iter, int max_i);
int		smooth_color_classic_animated(double smooth_iter,
			int max_i, double time);
int		smooth_color_blue_animated(double smooth_iter, int max_i, double time);
int		smooth_color_fire_animated(double smooth_iter, int max_i, double time);
void	init_psychedelic_animated(t_color *color, double smooth_iter,
			int max_i, double time);
void	apply_animated_effects(t_color *color);
int		psychedelic_animated(double smooth_iter, int max_i, double time);
int		smooth_color_grayscale_animated(double smooth_iter,
			int max_i, double time);

/* Input handling functions */
void	handle_nav_keys(t_fractol *fractol, keys_t key, double move_speed);
void	handle_zoom_keys(t_fractol *fractol, keys_t key);
void	handle_display_keys(t_fractol *fractol, keys_t key);
void	handle_special_keys(t_fractol *fractol, keys_t key);
void	handle_keys(mlx_key_data_t keydata, void *param);

/* Mouse handling functions */
void	update_julia_params(t_fractol *fractol);
void	handle_mouse_click(mouse_key_t button, action_t action,
			modifier_key_t mods, void *param);

/* Scroll handling functions */
double	calculate_zoom_factor(t_fractol *fractol, double ydelta);
void	get_coordinates(t_fractol *fractol, int32_t mouse_x, int32_t mouse_y,
			t_coord *coord);
void	adjust_view(t_fractol *fractol, t_coord *coord, double ydelta);
void	handle_scroll(double xdelta, double ydelta, void *param);

/* Animation functions */
void	animation_loop(void *param);
void	handle_animation_keys(t_fractol *fractol, keys_t key);

/* Initialization and utility functions */
int		parse_sign(const char *str, int *i);
double	parse_integer_part(const char *str, int *i);
double	parse_decimal_part(const char *str, int *i);
double	ft_atof(const char *str);

void	set_default_values(t_fractol *fractol, int type);
void	set_offsets(t_fractol *fractol, int type);
void	set_julia_params(t_fractol *fractol, char **av);
void	init_fractol(t_fractol *fractol, int type, char **av);

#endif
