/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezekaj <ezekaj@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 15:30:38 by ezekaj            #+#    #+#             */
/*   Updated: 2025/05/19 01:30:00 by ezekaj           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

int	handle_close(t_fractol *f)
{
	mlx_destroy_image(f->mlx, f->img);
	mlx_destroy_window(f->mlx, f->win);
	mlx_destroy_display(f->mlx);
	free(f->mlx);
	exit(0);
	return (0);
}

int	handle_key(int keycode, t_fractol *f)
{
	if (keycode == KEY_ESC)
		handle_close(f);
	else if (keycode == KEY_PLUS)
	{
		if (f->zoom < 1e10)
			f->zoom *= 1.1;
	}
	else if (keycode == KEY_MINUS)
	{
		if (f->zoom > 0.1)
			f->zoom /= 1.1;
	}
	fractal_render(f);
	return (0);
}

static void	zoom_center(t_fractol *f, double factor)
{
	if (factor > 1.0 && f->zoom >= 1e10)
		return ;
	if (factor < 1.0 && f->zoom <= 0.1)
		return ;
	f->zoom *= factor;
}

int	handle_mouse(int button, int x, int y, t_fractol *f)
{
	(void)x;
	(void)y;
	if (button == SCROLL_UP)
		zoom_center(f, 1.1);
	else if (button == SCROLL_DOWN)
		zoom_center(f, 1.0 / 1.1);
	else if (button == MOUSE_LEFT && f->type == JULIA)
		f->julia_locked = !f->julia_locked;
	fractal_render(f);
	return (0);
}
