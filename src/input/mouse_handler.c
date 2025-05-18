/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasoline-eater <gasoline-eater@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 15:30:38 by ezekaj            #+#    #+#             */
/*   Updated: 2025/05/17 22:10:19 by gasoline-ea      ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "../../inc/fractol.h"

void	update_julia_params(t_fractol *fractol)
{
	int32_t	mouse_x;
	int32_t	mouse_y;
	double	real;
	double	imag;

	if (fractol->type != JULIA || fractol->julia_locked)
		return ;
	mlx_get_mouse_pos(fractol->mlx, &mouse_x, &mouse_y);
	map(mouse_x, mouse_y, &real, &imag, fractol);
	fractol->c_real = real;
	fractol->c_imag = imag;

	if (fractol->use_threads)
		threaded_fractal_render(fractol);
	else
		fractal_render(fractol);
}

void	handle_mouse_click(mouse_key_t button, action_t action,
							modifier_key_t mods, void *param)
{
	t_fractol	*fractol;

	(void)mods;
	fractol = param;
	if (button == MLX_MOUSE_BUTTON_LEFT && action == MLX_PRESS)
	{
		if (fractol->type == JULIA)
			fractol->julia_locked = !fractol->julia_locked;
	}
}
