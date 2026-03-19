/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_util_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezekaj <ezekaj@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 15:30:38 by ezekaj            #+#    #+#             */
/*   Updated: 2025/05/19 01:30:00 by ezekaj           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol_bonus.h"

void	zoom_at_mouse(t_fractol *f, int x, int y, double factor)
{
	double	real_before;
	double	imag_before;

	real_before = (x - WIDTH / 2.0) * 4.0 / (WIDTH * f->zoom) + f->offset_x;
	imag_before = (y - HEIGHT / 2.0) * 4.0 / (HEIGHT * f->zoom) + f->offset_y;
	if (factor > 1.0 && f->zoom >= 1e10)
		return ;
	if (factor < 1.0 && f->zoom <= 0.1)
		return ;
	f->zoom *= factor;
	f->offset_x = real_before - (x - WIDTH / 2.0) * 4.0 / (WIDTH * f->zoom);
	f->offset_y = imag_before - (y - HEIGHT / 2.0) * 4.0 / (HEIGHT * f->zoom);
	if (factor > 1.0 && f->zoom > 10)
		f->max_iter = MAX_ITER + (int)(50 * log10(f->zoom));
}

void	re_render(t_fractol *f)
{
	fractal_render(f);
}

int	handle_zoom_keys(int keycode, t_fractol *f)
{
	if (keycode == KEY_PLUS)
	{
		if (f->zoom < 1e10)
			f->zoom *= 1.1;
	}
	else if (keycode == KEY_MINUS)
	{
		if (f->zoom > 0.1)
			f->zoom /= 1.1;
	}
	return (0);
}

int	animation_loop(t_fractol *f)
{
	if (f->animate_colors)
	{
		f->color_shift += f->anim_speed;
		fractal_render(f);
	}
	return (0);
}
