/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scroll_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezekaj <ezekaj@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 15:30:38 by ezekaj            #+#    #+#             */
/*   Updated: 2025/05/17 15:31:40 by ezekaj           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fractol.h"

double	calculate_zoom_factor(t_fractol *fractol, double ydelta)
{
	double	zoom_factor;

	zoom_factor = 1.0;
	if (ydelta > 0)
	{
		if (fractol->zoom < 1e10)
			zoom_factor = 1.1;
	}
	else
	{
		if (fractol->zoom > 0.1)
			zoom_factor = 0.9;
	}
	return (zoom_factor);
}

void	get_coordinates(t_fractol *fractol, int32_t mouse_x, int32_t mouse_y,
		t_coord *coord)
{
	map(mouse_x, mouse_y, &coord->real_before, &coord->imag_before, fractol);
	fractol->zoom *= coord->zoom_factor;
	map(mouse_x, mouse_y, &coord->real_after, &coord->imag_after, fractol);
}

void	adjust_view(t_fractol *fractol, t_coord *coord, double ydelta)
{
	fractol->offset_x += (coord->real_before - coord->real_after);
	fractol->offset_y += (coord->imag_before - coord->imag_after);
	if (ydelta > 0 && fractol->zoom > 10)
		fractol->max_iter = DEFAULT_MAX_ITER
			+ (int)(50 * log10(fractol->zoom));
}

void	handle_scroll(double xdelta, double ydelta, void *param)
{
	t_fractol	*fractol;
	int32_t		mouse_x;
	int32_t		mouse_y;
	t_coord		coord;

	(void)xdelta;
	fractol = param;
	mlx_get_mouse_pos(fractol->mlx, &mouse_x, &mouse_y);
	coord.zoom_factor = calculate_zoom_factor(fractol, ydelta);
	get_coordinates(fractol, mouse_x, mouse_y, &coord);
	adjust_view(fractol, &coord, ydelta);
	fractal_render(fractol);
}
