/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezekaj <ezekaj@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 15:30:12 by ezekaj            #+#    #+#             */
/*   Updated: 2025/05/17 15:35:05 by ezekaj           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void	map(int x, int y, double *real, double *imag, t_fractol *fractol)
{
	*real = (x - WIDTH / 2.0) * 4.0 / (WIDTH * fractol->zoom) + fractol->offset_x;
	*imag = (y - HEIGHT / 2.0) * 4.0 / (HEIGHT * fractol->zoom) + fractol->offset_y;
}

int	colors(int i, int max_i)
{
	int	brightness;

	if (i == max_i)
		return (0x000000FF);
	brightness = (i * 255) / max_i;
	return ((brightness << 24) | (brightness << 16) | (0xFF << 8) | 0xFF);
}

void	fractal_render(t_fractol *fractol)
{
	int		x;
	int		y;
	double	real;
	double	imag;
	int		i;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			map(x, y, &real, &imag, fractol);
			if (fractol->type == MANDELBROT)
				i = mandelbrot(real, imag, 100);
			else if (fractol->type == JULIA)
				i = julia(real, imag, fractol->c_real, fractol->c_imag, 100);
			else
				i = 0;
			mlx_put_pixel(fractol->img, x, y, colors(i, 100));
			x++;
		}
		y++;
	}
}
