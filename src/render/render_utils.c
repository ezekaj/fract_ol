/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasoline-eater <gasoline-eater@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 15:30:38 by ezekaj            #+#    #+#             */
/*   Updated: 2025/05/18 21:42:00 by gasoline-ea      ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "../../inc/fractol.h"

void	map(t_map_params *params, t_fractol *fractol)
{
	*(params->real) = (params->x - WIDTH / 2.0) * 4.0 / (WIDTH * fractol->zoom)
		+ fractol->offset_x;
	*(params->imag) = (params->y - HEIGHT / 2.0) * 4.0 / (HEIGHT * fractol->zoom)
		+ fractol->offset_y;
}
