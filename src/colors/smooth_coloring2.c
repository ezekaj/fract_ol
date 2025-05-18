/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smooth_coloring2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezekaj <ezekaj@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 15:30:38 by ezekaj            #+#    #+#             */
/*   Updated: 2025/05/19 01:30:00 by ezekaj           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fractol.h"

int	smooth_color_classic_animated(double smooth_iter, int max_i, double time)
{
	double	t;
	double	time_phase;
	int		r;
	int		g;
	int		b;

	if (smooth_iter >= max_i)
		return (0x000000FF);
	t = smooth_iter / max_i;
	time_phase = time * 0.3;
	r = (int)(200 + 55 * sin(t * 5.0 + time_phase));
	g = (int)(200 + 55 * sin(t * 5.0 + time_phase));
	b = (int)(255);
	if (r < 0)
		r = 0;
	else if (r > 255)
		r = 255;
	if (g < 0)
		g = 0;
	else if (g > 255)
		g = 255;
	return ((r << 24) | (g << 16) | (b << 8) | 0xFF);
}

int	smooth_color_fire_animated(double smooth_iter, int max_i, double time)
{
	double	t;
	double	time_phase;
	int		r;
	int		g;
	int		b;

	if (smooth_iter >= max_i)
		return (0x000000FF);
	t = smooth_iter / max_i;
	time_phase = time * 0.6;
	r = (int)(255);
	g = (int)(150 * t * (1.0 + 0.5 * sin(t * 12.0 + time_phase)));
	b = (int)(100 * t * t * (1.0 + 0.5 * sin(t * 16.0 + time_phase * 1.3)));
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
