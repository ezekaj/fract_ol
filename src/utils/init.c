/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezekaj <ezekaj@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 15:30:38 by ezekaj            #+#    #+#             */
/*   Updated: 2025/05/17 15:31:40 by ezekaj           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fractol.h"

void	set_default_values(t_fractol *fractol, int type)
{
	fractol->type = type;
	fractol->zoom = 1.0;
	fractol->color_scheme = COLOR_SCHEME_CLASSIC;
	fractol->max_iter = DEFAULT_MAX_ITER;
}

void	set_offsets(t_fractol *fractol, int type)
{
	if (type == MANDELBROT)
	{
		fractol->offset_x = -0.5;
		fractol->offset_y = 0.0;
	}
	else
	{
		fractol->offset_x = 0.0;
		fractol->offset_y = 0.0;
	}
}

void	set_julia_params(t_fractol *fractol, char **av)
{
	if (av[2] && av[3])
	{
		fractol->c_real = ft_atof(av[2]);
		fractol->c_imag = ft_atof(av[3]);
	}
	else
	{
		fractol->c_real = -0.7;
		fractol->c_imag = 0.27015;
	}
}

void	init_fractol(t_fractol *fractol, int type, char **av)
{
	set_default_values(fractol, type);
	set_offsets(fractol, type);
	if (type == JULIA)
		set_julia_params(fractol, av);
}
