/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smooth_coloring.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasoline-eater <gasoline-eater@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 15:30:38 by ezekaj            #+#    #+#             */
/*   Updated: 2025/05/17 22:55:50 by gasoline-ea      ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "../../inc/fractol.h"

double	calculate_smooth_value(double z_real, double z_imag, int iter, int max_i)
{
	double	log_zn;
	double	nu;

	if (iter == max_i)
		return ((double)iter);
	log_zn = log(z_real * z_real + z_imag * z_imag) / 2.0;
	nu = log(log_zn / log(2.0)) / log(2.0);
	return (iter + 1 - nu);
}

int	smooth_color_classic(double smooth_iter, int max_i)
{
	double	t;
	int		r;
	int		g;
	int		b;

	if (smooth_iter >= max_i)
		return (0x000000FF);
	t = smooth_iter / max_i;
	r = (int)(9 * (1 - t) * t * t * t * 255);
	g = (int)(15 * (1 - t) * (1 - t) * t * t * 255);
	b = (int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);
	return ((r << 24) | (g << 16) | (b << 8) | 0xFF);
}

int	smooth_color_fire(double smooth_iter, int max_i)
{
	double	t;
	int		r;
	int		g;
	int		b;

	if (smooth_iter >= max_i)
		return (0x000000FF);
	t = smooth_iter / max_i;
	r = (int)(255);
	g = (int)(t * t * 255);
	b = (int)(t * t * t * t * 255);
	return ((r << 24) | (g << 16) | (b << 8) | 0xFF);
}

int	smooth_color_psychedelic(double smooth_iter, int max_i)
{
	double	t;
	double	phase;
	int		r;
	int		g;
	int		b;

	if (smooth_iter >= max_i)
		return (0x000000FF);
	t = smooth_iter / max_i;
	phase = t * 15.0;
	r = (int)(127.5 + 127.5 * sin(phase));
	g = (int)(127.5 + 127.5 * sin(phase + 2.094));
	b = (int)(127.5 + 127.5 * sin(phase + 4.188));
	r = (int)(r * (0.8 + 0.2 * sin(t * 5.0)));
	g = (int)(g * (0.8 + 0.2 * cos(t * 7.0)));
	b = (int)(b * (0.8 + 0.2 * sin(t * 11.0)));
	if (r < 0)
		r = 0;
	else if (r > 255)
		r = 255;
	if (g < 0)
		g = 0;
	else if (g > 255)
		g = 255;
	if (b < 0)
		b = 0;
	else if (b > 255)
		b = 255;
	return ((r << 24) | (g << 16) | (b << 8) | 0xFF);
}
