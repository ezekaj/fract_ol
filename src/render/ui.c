/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasoline-eater <gasoline-eater@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 15:30:38 by ezekaj            #+#    #+#             */
/*   Updated: 2025/05/17 23:23:35 by gasoline-ea      ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "../../inc/fractol.h"

void	get_color_scheme_name(int color_scheme, char *buffer)
{
	if (color_scheme == COLOR_SCHEME_CLASSIC)
		strcpy(buffer, "Classic");
	else if (color_scheme == COLOR_SCHEME_BLUE)
		strcpy(buffer, "Blue");
	else if (color_scheme == COLOR_SCHEME_FIRE)
		strcpy(buffer, "Fire");
	else if (color_scheme == COLOR_SCHEME_PSYCHEDELIC)
		strcpy(buffer, "Psychedelic");
	else if (color_scheme == COLOR_SCHEME_GRAYSCALE)
		strcpy(buffer, "Grayscale");
	else
		strcpy(buffer, "Unknown");
}

void	get_fractal_name(int type, char *buffer)
{
	if (type == MANDELBROT)
		strcpy(buffer, "Mandelbrot");
	else if (type == JULIA)
		strcpy(buffer, "Julia");
	else if (type == TRICORN)
		strcpy(buffer, "Tricorn");
	else
		strcpy(buffer, "Unknown");
}

void	render_ui_text(t_fractol *fractol)
{
	(void)fractol;
}
