/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_colors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezekaj <ezekaj@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 15:30:38 by ezekaj            #+#    #+#             */
/*   Updated: 2025/05/19 01:30:00 by ezekaj           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fractol.h"

int	get_animated_smooth_color(t_fractol *fractol, double smooth_i, int i)
{
	if (fractol->color_scheme == COLOR_SCHEME_CLASSIC)
		return (smooth_color_classic_animated(smooth_i, fractol->max_iter,
				fractol->animation_time));
	else if (fractol->color_scheme == COLOR_SCHEME_BLUE)
		return (smooth_color_blue_animated(smooth_i, fractol->max_iter,
				fractol->animation_time));
	else if (fractol->color_scheme == COLOR_SCHEME_FIRE)
		return (smooth_color_fire_animated(smooth_i, fractol->max_iter,
				fractol->animation_time));
	else if (fractol->color_scheme == COLOR_SCHEME_PSYCHEDELIC)
		return (psychedelic_animated(smooth_i, fractol->max_iter,
				fractol->animation_time));
	else if (fractol->color_scheme == COLOR_SCHEME_GRAYSCALE)
		return (smooth_color_grayscale_animated(smooth_i, fractol->max_iter,
				fractol->animation_time));
	else
		return (colors(i, fractol->max_iter, fractol->color_scheme));
}

int	get_smooth_color(t_fractol *fractol, double smooth_i, int i)
{
	if (fractol->color_scheme == COLOR_SCHEME_CLASSIC)
		return (smooth_color_classic(smooth_i, fractol->max_iter));
	else if (fractol->color_scheme == COLOR_SCHEME_BLUE)
		return (smooth_color_blue(smooth_i, fractol->max_iter));
	else if (fractol->color_scheme == COLOR_SCHEME_FIRE)
		return (smooth_color_fire(smooth_i, fractol->max_iter));
	else if (fractol->color_scheme == COLOR_SCHEME_PSYCHEDELIC)
		return (smooth_color_psychedelic(smooth_i, fractol->max_iter));
	else if (fractol->color_scheme == COLOR_SCHEME_GRAYSCALE)
		return (smooth_color_grayscale(smooth_i, fractol->max_iter));
	else
		return (colors(i, fractol->max_iter, fractol->color_scheme));
}

void	process_smooth_color(t_render_vars *vars, t_fractol *fractol)
{
	t_smooth_calc	calc;

	calc.real = vars->real;
	calc.imag = vars->imag;
	calc.i = vars->i;
	calc.fractol = fractol;
	calc.smooth_i = &vars->smooth_i;
	calculate_smooth_values(&calc);
	if (fractol->animate_colors)
		vars->color = get_animated_smooth_color(fractol,
				vars->smooth_i, vars->i);
	else
		vars->color = get_smooth_color(fractol, vars->smooth_i, vars->i);
}

void	process_standard_color(t_render_vars *vars, t_fractol *fractol)
{
	if (fractol->animate_colors)
		vars->color = colors_animated(vars->i, fractol->max_iter,
				fractol->color_scheme, fractol->animation_time);
	else
		vars->color = colors(vars->i, fractol->max_iter,
				fractol->color_scheme);
}

void	process_pixel_color(t_render_vars *vars, t_fractol *fractol, int y)
{
	if (fractol->smooth_color && vars->i < fractol->max_iter)
		process_smooth_color(vars, fractol);
	else
		process_standard_color(vars, fractol);
	mlx_put_pixel(fractol->img, vars->x, y, vars->color);
}
