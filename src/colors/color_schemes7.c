/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_schemes7.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezekaj <ezekaj@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 15:30:38 by ezekaj            #+#    #+#             */
/*   Updated: 2025/05/19 01:30:00 by ezekaj           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fractol.h"

int	color_blue_animated(int i, int max_i, double time)
{
	t_color	color;

	if (i == max_i)
		return (0x000000FF);
	color.t = (double)i / max_i;
	color.time_phase = time * 0.4;
	color.r = (int)(80 + 60 * sin(color.t * 4.0 + color.time_phase * 0.5));
	color.g = (int)(120 + 80 * sin(color.t * 6.0 + 1.0
				+ color.time_phase * 0.7));
	color.b = (int)(220 + 35 * sin(color.t * 8.0 + 2.0 + color.time_phase));
	if (color.r < 0)
		color.r = 0;
	else if (color.r > 255)
		color.r = 255;
	if (color.g < 0)
		color.g = 0;
	else if (color.g > 255)
		color.g = 255;
	if (color.b < 0)
		color.b = 0;
	else if (color.b > 255)
		color.b = 255;
	return ((color.r << 24) | (color.g << 16) | (color.b << 8) | 0xFF);
}
