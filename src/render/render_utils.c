/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezekaj <ezekaj@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 15:30:38 by ezekaj            #+#    #+#             */
/*   Updated: 2025/05/17 15:31:40 by ezekaj           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fractol.h"

void	map(int x, int y, double *real, double *imag, t_fractol *fractol)
{
	*real = (x - WIDTH / 2.0) * 4.0 / (WIDTH * fractol->zoom)
		+ fractol->offset_x;
	*imag = (y - HEIGHT / 2.0) * 4.0 / (HEIGHT * fractol->zoom)
		+ fractol->offset_y;
}
