/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezekaj <ezekaj@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 15:30:00 by ezekaj            #+#    #+#             */
/*   Updated: 2025/05/19 01:30:00 by ezekaj           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol_bonus.h"

static int	init_mlx(t_fractol *f)
{
	f->mlx = mlx_init();
	if (!f->mlx)
		return (1);
	f->win = mlx_new_window(f->mlx, WIDTH, HEIGHT, "fractol");
	if (!f->win)
		return (free(f->mlx), 1);
	f->img = mlx_new_image(f->mlx, WIDTH, HEIGHT);
	if (!f->img)
		return (mlx_destroy_window(f->mlx, f->win), free(f->mlx), 1);
	f->addr = mlx_get_data_addr(f->img, &f->bpp, &f->line_len, &f->endian);
	return (0);
}

static void	setup_hooks(t_fractol *f)
{
	mlx_hook(f->win, 2, 1L << 0, handle_key, f);
	mlx_hook(f->win, 4, 1L << 2, handle_mouse, f);
	mlx_hook(f->win, 17, 0, handle_close, f);
	mlx_loop_hook(f->mlx, animation_loop, f);
}

void	print_usage(void)
{
	ft_putstr_fd("Usage: ./fractol [fractal_type] [params]\n\n", 1);
	ft_putstr_fd("Fractal types:\n", 1);
	ft_putstr_fd("  mandelbrot\n", 1);
	ft_putstr_fd("  julia [c_real] [c_imag]\n", 1);
	ft_putstr_fd("  tricorn\n\n", 1);
	ft_putstr_fd("Examples:\n", 1);
	ft_putstr_fd("  ./fractol mandelbrot\n", 1);
	ft_putstr_fd("  ./fractol julia -0.7 0.27015\n", 1);
	exit(0);
}

int	main(int ac, char **av)
{
	t_fractol	f;

	f.type = parse_args(ac, av);
	if (!f.type)
		print_usage();
	if (init_mlx(&f) != 0)
		return (1);
	init_fractol(&f, f.type, av);
	setup_hooks(&f);
	fractal_render(&f);
	mlx_loop(f.mlx);
	return (0);
}
