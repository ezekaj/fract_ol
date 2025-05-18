/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tricorn.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasoline-eater <gasoline-eater@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 15:30:38 by ezekaj            #+#    #+#             */
/*   Updated: 2025/05/18 19:15:24 by gasoline-ea      ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "../../inc/fractol.h"

int	tricorn(double real, double imag, int max_i)
{
	double	z_real;
	double	z_imag;
	double	temp;
	int		i;

	z_real = real;
	z_imag = imag;
	i = 0;
	while (z_real * z_real + z_imag * z_imag < 4 && i < max_i)
	{
		temp = z_real * z_real - z_imag * z_imag + real;
		z_imag = -2 * z_real * z_imag + imag;
		z_real = temp;
		i++;
	}
	return (i);
}
