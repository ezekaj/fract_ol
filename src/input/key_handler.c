/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezekaj <ezekaj@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 15:30:38 by ezekaj            #+#    #+#             */
/*   Updated: 2025/05/17 15:31:40 by ezekaj           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fractol.h"

void	handle_navigation_keys(t_fractol *fractol, keys_t key, double move_speed)
{
	if (key == MLX_KEY_ESCAPE)
		mlx_close_window(fractol->mlx);
	else if (key == MLX_KEY_UP || key == MLX_KEY_W)
		fractol->offset_y -= move_speed;
	else if (key == MLX_KEY_DOWN || key == MLX_KEY_S)
		fractol->offset_y += move_speed;
	else if (key == MLX_KEY_LEFT || key == MLX_KEY_A)
		fractol->offset_x -= move_speed;
	else if (key == MLX_KEY_RIGHT || key == MLX_KEY_D)
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

void	handle_special_keys(t_fractol *fractol, keys_t key)
{
	if (key == MLX_KEY_C)
		fractol->color_scheme = (fractol->color_scheme + 1) % NUM_COLOR_SCHEMES;
	else if (key == MLX_KEY_R)
	{
		fractol->zoom = 1.0;
		fractol->offset_x = (fractol->type == MANDELBROT) ? -0.5 : 0.0;
		fractol->offset_y = 0.0;
		fractol->max_iter = DEFAULT_MAX_ITER;
	}
	else if (key == MLX_KEY_I)
		fractol->max_iter += 50;
	else if (key == MLX_KEY_D && fractol->max_iter > 50)
		fractol->max_iter -= 50;
}

void	handle_keys(mlx_key_data_t keydata, void *param)
{
	t_fractol	*fractol;
	double		move_speed;

	if (keydata.action != MLX_PRESS)
		return ;
	fractol = param;
	move_speed = 0.1 / fractol->zoom;
	handle_navigation_keys(fractol, keydata.key, move_speed);
	handle_zoom_keys(fractol, keydata.key);
	handle_special_keys(fractol, keydata.key);
	fractal_render(fractol);
}
