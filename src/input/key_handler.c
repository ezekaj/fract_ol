/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezekaj <ezekaj@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 15:30:38 by ezekaj            #+#    #+#             */
/*   Updated: 2025/05/22 18:17:40 by ezekaj           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fractol.h"

void	handle_nav_keys(t_fractol *fractol, keys_t key, double move_speed)
{
	if (key == MLX_KEY_ESCAPE)
		mlx_close_window(fractol->mlx);
	else if (key == MLX_KEY_UP)
		fractol->offset_y -= move_speed;
	else if (key == MLX_KEY_DOWN)
		fractol->offset_y += move_speed;
	else if (key == MLX_KEY_LEFT)
		fractol->offset_x -= move_speed;
	else if (key == MLX_KEY_RIGHT)
		fractol->offset_x += move_speed;
}

void	handle_zoom_keys(t_fractol *fractol, keys_t key)
{
	if (key == MLX_KEY_EQUAL || key == MLX_KEY_KP_ADD)
	{
		if (fractol->zoom < 1e10)
			fractol->zoom *= 1.1;
	}
	else if (key == MLX_KEY_MINUS || key == MLX_KEY_KP_SUBTRACT)
	{
		if (fractol->zoom > 0.1)
			fractol->zoom /= 1.1;
	}
}

void	handle_display_keys(t_fractol *fractol, keys_t key)
{
	if (key == MLX_KEY_S)
		fractol->smooth_color = !fractol->smooth_color;
	else if (key == MLX_KEY_U)
		fractol->show_ui = !fractol->show_ui;
	else if (key == MLX_KEY_T)
		fractol->use_threads = !fractol->use_threads;
	else if (key == MLX_KEY_L && fractol->type == JULIA)
		fractol->julia_locked = !fractol->julia_locked;
	else
		handle_animation_keys(fractol, key);
}

void	handle_special_keys(t_fractol *fractol, keys_t key)
{
	if (key == MLX_KEY_C)
		fractol->color_scheme = (fractol->color_scheme + 1) % NUM_COLOR_SCHEMES;
	else if (key == MLX_KEY_R)
	{
		fractol->zoom = 1.0;
		if (fractol->type == MANDELBROT)
			fractol->offset_x = -0.5;
		else
			fractol->offset_x = 0.0;
		fractol->offset_y = 0.0;
		fractol->max_iter = DEFAULT_MAX_ITER;
	}
	else
		handle_display_keys(fractol, key);
}

void	handle_keys(mlx_key_data_t keydata, void *param)
{
	t_fractol	*fractol;
	double		move_speed;

	if (keydata.action != MLX_PRESS)
		return ;
	fractol = param;
	move_speed = 0.1 / fractol->zoom;
	handle_nav_keys(fractol, keydata.key, move_speed);
	handle_zoom_keys(fractol, keydata.key);
	handle_special_keys(fractol, keydata.key);
	if (fractol->use_threads)
		threaded_fractal_render(fractol);
	else
		fractal_render(fractol);
}
