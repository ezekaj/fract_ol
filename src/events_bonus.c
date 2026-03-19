/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezekaj <ezekaj@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 15:30:38 by ezekaj            #+#    #+#             */
/*   Updated: 2025/05/19 01:30:00 by ezekaj           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol_bonus.h"

int	handle_close(t_fractol *f)
{
	mlx_destroy_image(f->mlx, f->img);
	mlx_destroy_window(f->mlx, f->win);
	mlx_destroy_display(f->mlx);
	free(f->mlx);
	exit(0);
	return (0);
}

static void	handle_nav(t_fractol *f, int keycode)
{
	double	speed;

	speed = 0.1 / f->zoom;
	if (keycode == KEY_UP)
		f->offset_y -= speed;
	else if (keycode == KEY_DOWN)
		f->offset_y += speed;
	else if (keycode == KEY_LEFT)
		f->offset_x -= speed;
	else if (keycode == KEY_RIGHT)
		f->offset_x += speed;
}

static void	handle_special(t_fractol *f, int keycode)
{
	if (keycode == KEY_C)
		f->color_scheme = (f->color_scheme + 1) % NUM_SCHEMES;
	else if (keycode == KEY_S)
		f->smooth_color = !f->smooth_color;
	else if (keycode == KEY_L && f->type == JULIA)
		f->julia_locked = !f->julia_locked;
	else if (keycode == KEY_M)
		f->animate_colors = !f->animate_colors;
	else if (keycode == KEY_R)
	{
		f->zoom = 1.0;
		set_offsets(f, f->type);
		f->max_iter = MAX_ITER;
		f->color_shift = 0.0;
	}
}

int	handle_key(int keycode, t_fractol *f)
{
	if (keycode == KEY_ESC)
		handle_close(f);
	handle_nav(f, keycode);
	handle_zoom_keys(keycode, f);
	handle_special(f, keycode);
	re_render(f);
	return (0);
}

int	handle_mouse(int button, int x, int y, t_fractol *f)
{
	if (button == SCROLL_UP)
		zoom_at_mouse(f, x, y, 1.1);
	else if (button == SCROLL_DOWN)
		zoom_at_mouse(f, x, y, 1.0 / 1.1);
	else if (button == MOUSE_LEFT && f->type == JULIA)
		f->julia_locked = !f->julia_locked;
	re_render(f);
	return (0);
}
