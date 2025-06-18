/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezekaj <ezekaj@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 15:30:00 by ezekaj            #+#    #+#             */
/*   Updated: 2025/05/18 21:52:04 by ezekaj           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"



static int	init_mlx(t_fractol *fractol)
{
	fractol->mlx = mlx_init(WIDTH, HEIGHT, TITLE, 1);
	if (!fractol->mlx)
		return (1);
	fractol->img = mlx_new_image(fractol->mlx, WIDTH, HEIGHT);
	if (!fractol->img)
		return (mlx_terminate(fractol->mlx), 1);
	mlx_set_setting(MLX_STRETCH_IMAGE, true);
	return (0);
}

static void	setup_hooks(t_fractol *fractol)
{
	mlx_image_to_window(fractol->mlx, fractol->img, 0, 0);
	mlx_key_hook(fractol->mlx, &handle_keys, fractol);
	mlx_scroll_hook(fractol->mlx, &handle_scroll, fractol);
	mlx_mouse_hook(fractol->mlx, &handle_mouse_click, fractol);
}

static void	render_and_run(t_fractol *fractol)
{
	if (fractol->use_threads)
		threaded_fractal_render(fractol);
	else
		fractal_render(fractol);
	mlx_loop_hook(fractol->mlx, &animation_loop, fractol);
	mlx_loop(fractol->mlx);
	mlx_terminate(fractol->mlx);
}

int	main(int ac, char **av)
{
	t_fractol	fractol;

	fractol.type = parse_args(ac, av);
	if (!fractol.type)
		print_usage();
	if (init_mlx(&fractol) != 0)
		return (1);
	init_fractol(&fractol, fractol.type, av);
	setup_hooks(&fractol);
	render_and_run(&fractol);
	return (0);
}
