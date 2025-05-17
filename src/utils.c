#include "../inc/fractol.h"

void	init_fractol(t_fractol *fractol, int type, char **av)
{
	fractol->type = type;
	fractol->zoom = 1.0;
	fractol->offset_x = 0.0;
	fractol->offset_y = 0.0;

	if (type == JULIA)
	{
		if (av[2] && av[3])
		{
			fractol->c_real = atof(av[2]);
			fractol->c_imag = atof(av[3]);
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

	fractol = param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window(fractol->mlx);
	else if (keydata.key == MLX_KEY_UP && keydata.action == MLX_PRESS)
		fractol->offset_y -= 0.1 / fractol->zoom;
	else if (keydata.key == MLX_KEY_DOWN && keydata.action == MLX_PRESS)
		fractol->offset_y += 0.1 / fractol->zoom;
	else if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_PRESS)
		fractol->offset_x -= 0.1 / fractol->zoom;
	else if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_PRESS)
		fractol->offset_x += 0.1 / fractol->zoom;

	if (keydata.action == MLX_PRESS)
		fractal_render(fractol);
}

void	handle_scroll(double xdelta, double ydelta, void *param)
{
	t_fractol	*fractol;

	(void)xdelta;
	fractol = param;

	if (ydelta > 0)
		fractol->zoom *= 1.1;
	else if (ydelta < 0)
		fractol->zoom /= 1.1;

	fractal_render(fractol);
}
