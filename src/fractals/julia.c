/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezekaj <ezekaj@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 15:30:29 by ezekaj            #+#    #+#             */
/*   Updated: 2025/05/18 21:50:27 by ezekaj           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fractol.h"

int	julia(t_julia_params *params)
{
	double	z_real;
	double	z_imag;
	double	temp;
	int		i;

	z_real = params->real;
	z_imag = params->imag;
	i = 0;
	while (z_real * z_real + z_imag * z_imag < 4 && i < params->max_i)
	{
		temp = z_real * z_real - z_imag * z_imag + params->c_real;
		z_imag = 2 * z_real * z_imag + params->c_imag;
		z_real = temp;
		i++;
	}
	return (i);
}
