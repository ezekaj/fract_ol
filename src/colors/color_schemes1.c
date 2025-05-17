/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_schemes1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezekaj <ezekaj@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 15:30:38 by ezekaj            #+#    #+#             */
/*   Updated: 2025/05/17 15:31:40 by ezekaj           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fractol.h"

int	color_classic(int i, int max_i)
{
	int	brightness;

	if (i == max_i)
		return (0x000000FF);
	brightness = (i * 255) / max_i;
	return ((brightness << 24) | (brightness << 16) | (0xFF << 8) | 0xFF);
}

int	color_blue(int i, int max_i)
{
	int	r;
	int	g;
	int	b;

	if (i == max_i)
		return (0x000000FF);
	r = (i * 128) / max_i;
	g = (i * 192) / max_i;
	b = 255;
	return ((r << 24) | (g << 16) | (b << 8) | 0xFF);
}

int	color_fire(int i, int max_i)
{
	int	r;
	int	g;
	int	b;
	int	scale;

	if (i == max_i)
		return (0x000000FF);
	scale = (i * 100) / max_i;
	r = 255;
	g = (scale < 50) ? scale * 5 : 255;
	b = (scale < 25) ? 0 : (scale - 25) * 3;
	return ((r << 24) | (g << 16) | (b << 8) | 0xFF);
}
