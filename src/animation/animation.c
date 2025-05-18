/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezekaj <ezekaj@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 15:30:38 by ezekaj            #+#    #+#             */
/*   Updated: 2025/05/18 21:50:42 by ezekaj           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fractol.h"

void	animation_loop(void *param)
{
	t_fractol	*fractol;

	fractol = param;
	if (fractol->animate_colors)
	{
		fractol->animation_time += fractol->animation_speed;
		if (fractol->use_threads)
			threaded_fractal_render(fractol);
		else
			fractal_render(fractol);
	}
}

void	handle_animation_keys(t_fractol *fractol, keys_t key)
{
	if (key == MLX_KEY_M)
		fractol->animate_colors = !fractol->animate_colors;
	else if (key == MLX_KEY_EQUAL || key == MLX_KEY_KP_ADD)
	{
		if (fractol->animation_speed < 0.5)
			fractol->animation_speed += 0.01;
	}
	else if (key == MLX_KEY_MINUS || key == MLX_KEY_KP_SUBTRACT)
	{
		if (fractol->animation_speed > 0.01)
			fractol->animation_speed -= 0.01;
	}
}
