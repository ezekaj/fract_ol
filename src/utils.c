/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezekaj <ezekaj@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 15:30:19 by ezekaj            #+#    #+#             */
/*   Updated: 2025/05/17 15:34:21 by ezekaj           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

static double	ft_atof(const char *str)
{
	double	result;
	double	decimal;
	int		sign;
	int		i;

	result = 0.0;
	decimal = 0.0;
	sign = 1;
	i = 0;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
		result = result * 10 + (str[i++] - '0');
	if (str[i] == '.')
	{
		i++;
		decimal = 0.1;
		while (str[i] >= '0' && str[i] <= '9')
		{
			result += (str[i++] - '0') * decimal;
			decimal *= 0.1;
		}
	}
	return (result * sign);
}

void	init_fractol(t_fractol *fractol, int type, char **av)
{
	fractol->type = type;
	fractol->zoom = 1.0;
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
	if (type == JULIA)
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
}

void	handle_keys(mlx_key_data_t keydata, void *param)
{
	t_fractol	*fractol;
	double		move_speed;

	fractol = param;
	move_speed = 0.1 / fractol->zoom;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window(fractol->mlx);
	else if (keydata.key == MLX_KEY_UP && keydata.action == MLX_PRESS)
		fractol->offset_y -= move_speed;
	else if (keydata.key == MLX_KEY_DOWN && keydata.action == MLX_PRESS)
		fractol->offset_y += move_speed;
	else if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_PRESS)
		fractol->offset_x -= move_speed;
	else if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_PRESS)
		fractol->offset_x += move_speed;
	else if (keydata.key == MLX_KEY_EQUAL && keydata.action == MLX_PRESS)
	{
		fractol->zoom *= 1.1;
	}
	else if (keydata.key == MLX_KEY_MINUS && keydata.action == MLX_PRESS)
	{
		fractol->zoom /= 1.1;
	}
	else if (keydata.key == MLX_KEY_R && keydata.action == MLX_PRESS)
	{
		fractol->zoom = 1.0;
		if (fractol->type == MANDELBROT)
			fractol->offset_x = -0.5;
		else
			fractol->offset_x = 0.0;
		fractol->offset_y = 0.0;
	}
	if (keydata.action == MLX_PRESS)
		fractal_render(fractol);
}

void	handle_scroll(double xdelta, double ydelta, void *param)
{
	t_fractol	*fractol;
	int32_t		mouse_x;
	int32_t		mouse_y;
	double		real_before;
	double		imag_before;
	double		real_after;
	double		imag_after;
	double		zoom_factor;

	(void)xdelta;
	fractol = param;
	mlx_get_mouse_pos(fractol->mlx, &mouse_x, &mouse_y);
	map(mouse_x, mouse_y, &real_before, &imag_before, fractol);
	if (ydelta > 0)
		zoom_factor = 1.1;
	else
		zoom_factor = 0.9;
	fractol->zoom *= zoom_factor;
	map(mouse_x, mouse_y, &real_after, &imag_after, fractol);
	fractol->offset_x += (real_before - real_after);
	fractol->offset_y += (imag_before - imag_after);
	fractal_render(fractol);
}
