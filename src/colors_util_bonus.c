/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors_util_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezekaj <ezekaj@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 15:30:38 by ezekaj            #+#    #+#             */
/*   Updated: 2025/05/19 01:30:00 by ezekaj           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol_bonus.h"

void	clamp_color(t_color *c)
{
	if (c->r < 0)
		c->r = 0;
	else if (c->r > 255)
		c->r = 255;
	if (c->g < 0)
		c->g = 0;
	else if (c->g > 255)
		c->g = 255;
	if (c->b < 0)
		c->b = 0;
	else if (c->b > 255)
		c->b = 255;
}

int	pack_color(t_color *c)
{
	return ((c->r << 16) | (c->g << 8) | c->b);
}

int	color_inside(void)
{
	return (0x000000);
}

int	get_color(int scheme, double t, double tp)
{
	if (scheme == SCHEME_CLASSIC)
		return (color_classic(t, tp));
	if (scheme == SCHEME_BLUE)
		return (color_blue(t, tp));
	if (scheme == SCHEME_FIRE)
		return (color_fire(t, tp));
	if (scheme == SCHEME_PSYCHEDELIC)
		return (color_psychedelic(t, tp));
	return (color_grayscale(t, tp));
}
