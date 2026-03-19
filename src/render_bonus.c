/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezekaj <ezekaj@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 15:30:38 by ezekaj            #+#    #+#             */
/*   Updated: 2025/05/19 01:30:00 by ezekaj           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol_bonus.h"

void	my_pixel_put(t_fractol *f, int x, int y, int color)
{
	char	*dst;

	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
	{
		dst = f->addr + (y * f->line_len + x * (f->bpp / 8));
		*(unsigned int *)dst = color;
	}
}

double	calc_smooth_value(t_fractol *f, int iter)
{
	double	log_zn;
	double	nu;

	if (iter == f->max_iter)
		return ((double)iter);
	log_zn = log(f->z_real * f->z_real + f->z_imag * f->z_imag) / 2.0;
	nu = log(log_zn / log(2.0)) / log(2.0);
	return (iter + 1 - nu);
}

static double	get_t_value(t_fractol *f, int iter)
{
	double	smooth;

	if (f->smooth_color)
	{
		smooth = calc_smooth_value(f, iter);
		return (smooth / f->max_iter);
	}
	return ((double)iter / f->max_iter);
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
		if (iter == f->max_iter)
			my_pixel_put(f, x, y, color_inside());
		else
			my_pixel_put(f, x, y, get_color(f->color_scheme,
					get_t_value(f, iter), f->color_shift));
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
