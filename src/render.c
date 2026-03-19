/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezekaj <ezekaj@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 15:30:38 by ezekaj            #+#    #+#             */
/*   Updated: 2025/05/19 01:30:00 by ezekaj           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void	my_pixel_put(t_fractol *f, int x, int y, int color)
{
	char	*dst;

	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
	{
		dst = f->addr + (y * f->line_len + x * (f->bpp / 8));
		*(unsigned int *)dst = color;
	}
}

static int	get_color(int iter, int max_iter)
{
	double	t;
	int		r;
	int		g;
	int		b;

	if (iter == max_iter)
		return (0x000000);
	t = (double)iter / max_iter;
	r = (int)(9 * (1 - t) * t * t * t * 255);
	g = (int)(15 * (1 - t) * (1 - t) * t * t * 255);
	b = (int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);
	return ((r << 16) | (g << 8) | b);
}

static void	render_row(int y, t_fractol *f)
{
	int		x;
	double	real;
	double	imag;
	int		iter;

	x = 0;
	imag = (y - HEIGHT / 2.0) * 4.0 / (HEIGHT * f->zoom) + f->offset_y;
	while (x < WIDTH)
	{
		real = (x - WIDTH / 2.0) * 4.0 / (WIDTH * f->zoom) + f->offset_x;
		iter = calc_pixel(real, imag, f);
		my_pixel_put(f, x, y, get_color(iter, f->max_iter));
		x++;
	}
}

void	fractal_render(t_fractol *f)
{
	int	y;

	y = 0;
	while (y < HEIGHT)
	{
		render_row(y, f);
		y++;
	}
	mlx_put_image_to_window(f->mlx, f->win, f->img, 0, 0);
}
