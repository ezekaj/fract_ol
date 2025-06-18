/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_schemes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezekaj <ezekaj@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 15:30:38 by ezekaj            #+#    #+#             */
/*   Updated: 2025/06/18 00:00:00 by ezekaj           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fractol.h"

int	color_classic(int i, int max_i)
{
	t_color	color;

	if (i == max_i)
		return (0x000000FF);
	color.t = (double)i / max_i;
	color.r = (int)(200 + 55 * sin(color.t * 5.0));
	color.g = (int)(200 + 55 * sin(color.t * 5.0));
	color.b = (int)(255);
	clamp_color_values(&color);
	return ((color.r << 24) | (color.g << 16) | (color.b << 8) | 0xFF);
}

int	color_blue(int i, int max_i)
{
	t_color	color;

	if (i == max_i)
		return (0x000000FF);
	color.t = (double)i / max_i;
	color.r = (int)(80 + 60 * sin(color.t * 4.0));
	color.g = (int)(120 + 80 * sin(color.t * 6.0 + 1.0));
	color.b = (int)(220 + 35 * sin(color.t * 8.0 + 2.0));
	clamp_color_values(&color);
	return ((color.r << 24) | (color.g << 16) | (color.b << 8) | 0xFF);
}

int	color_fire(int i, int max_i)
{
	t_color	color;

	if (i == max_i)
		return (0x000000FF);
	color.t = (double)i / max_i;
	color.r = (int)(255);
	color.g = (int)(150 * color.t * (1.0 + 0.5 * sin(color.t * 12.0)));
	color.b = (int)(100 * color.t * color.t
			* (1.0 + 0.5 * sin(color.t * 16.0)));
	clamp_color_values(&color);
	return ((color.r << 24) | (color.g << 16) | (color.b << 8) | 0xFF);
}
