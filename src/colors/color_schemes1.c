/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_schemes1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasoline-eater <gasoline-eater@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 15:30:38 by ezekaj            #+#    #+#             */
/*   Updated: 2025/05/17 23:31:41 by gasoline-ea      ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "../../inc/fractol.h"

int	color_classic(int i, int max_i)
{
	double	t;
	int		r;
	int		g;
	int		b;

	if (i == max_i)
		return (0x000000FF);
	t = (double)i / max_i;
	r = (int)(200 + 55 * sin(t * 5.0));
	g = (int)(200 + 55 * sin(t * 5.0));
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

int	color_classic_animated(int i, int max_i, double time)
{
	double	t;
	double	time_phase;
	int		r;
	int		g;
	int		b;

	if (i == max_i)
		return (0x000000FF);
	t = (double)i / max_i;
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

int	color_blue(int i, int max_i)
{
	double	t;
	int		r;
	int		g;
	int		b;

	if (i == max_i)
		return (0x000000FF);
	t = (double)i / max_i;
	r = (int)(80 + 60 * sin(t * 4.0));
	g = (int)(120 + 80 * sin(t * 6.0 + 1.0));
	b = (int)(220 + 35 * sin(t * 8.0 + 2.0));
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

int	color_blue_animated(int i, int max_i, double time)
{
	double	t;
	double	time_phase;
	int		r;
	int		g;
	int		b;

	if (i == max_i)
		return (0x000000FF);
	t = (double)i / max_i;
	time_phase = time * 0.4;
	r = (int)(80 + 60 * sin(t * 4.0 + time_phase * 0.5));
	g = (int)(120 + 80 * sin(t * 6.0 + 1.0 + time_phase * 0.7));
	b = (int)(220 + 35 * sin(t * 8.0 + 2.0 + time_phase));
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

int	color_fire(int i, int max_i)
{
	double	t;
	int		r;
	int		g;
	int		b;

	if (i == max_i)
		return (0x000000FF);
	t = (double)i / max_i;
	r = (int)(255);
	g = (int)(150 * t * (1.0 + 0.5 * sin(t * 12.0)));
	b = (int)(100 * t * t * (1.0 + 0.5 * sin(t * 16.0)));
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

int	color_fire_animated(int i, int max_i, double time)
{
	double	t;
	double	time_phase;
	int		r;
	int		g;
	int		b;

	if (i == max_i)
		return (0x000000FF);
	t = (double)i / max_i;
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
