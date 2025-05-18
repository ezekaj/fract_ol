/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smooth_coloring4.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezekaj <ezekaj@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 15:30:38 by ezekaj            #+#    #+#             */
/*   Updated: 2025/05/19 01:30:00 by ezekaj           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fractol.h"

double	calc_smooth_value(double z_real, double z_imag, int iter, int max_i)
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
	t_color	color;

	if (smooth_iter >= max_i)
		return (0x000000FF);
	color.t = smooth_iter / max_i;
	color.r = (int)(200 + 55 * sin(color.t * 5.0));
	color.g = (int)(200 + 55 * sin(color.t * 5.0));
	color.b = (int)(255);
	if (color.r < 0)
		color.r = 0;
	else if (color.r > 255)
		color.r = 255;
	if (color.g < 0)
		color.g = 0;
	else if (color.g > 255)
		color.g = 255;
	return ((color.r << 24) | (color.g << 16) | (color.b << 8) | 0xFF);
}
