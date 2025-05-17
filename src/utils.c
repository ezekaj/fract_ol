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
	fractol->color_scheme = COLOR_SCHEME_CLASSIC;
	fractol->max_iter = DEFAULT_MAX_ITER;

	// Set default offsets based on fractal type
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

	if (keydata.action != MLX_PRESS)
		return ;
	fractol = param;
	move_speed = 0.1 / fractol->zoom;

	// Navigation keys
	if (keydata.key == MLX_KEY_ESCAPE)
		mlx_close_window(fractol->mlx);
	else if (keydata.key == MLX_KEY_UP || keydata.key == MLX_KEY_W)
		fractol->offset_y -= move_speed;
	else if (keydata.key == MLX_KEY_DOWN || keydata.key == MLX_KEY_S)
		fractol->offset_y += move_speed;
	else if (keydata.key == MLX_KEY_LEFT || keydata.key == MLX_KEY_A)
		fractol->offset_x -= move_speed;
	else if (keydata.key == MLX_KEY_RIGHT || keydata.key == MLX_KEY_D)
		fractol->offset_x += move_speed;
	// Color cycling with C key
	else if (keydata.key == MLX_KEY_C)
		fractol->color_scheme = (fractol->color_scheme + 1) % NUM_COLOR_SCHEMES;
	// Zoom with +/- keys
	else if (keydata.key == MLX_KEY_EQUAL || keydata.key == MLX_KEY_KP_ADD)
		fractol->zoom = (fractol->zoom < 1e10) ? fractol->zoom * 1.1 : fractol->zoom;
	else if (keydata.key == MLX_KEY_MINUS || keydata.key == MLX_KEY_KP_SUBTRACT)
		fractol->zoom = (fractol->zoom > 0.1) ? fractol->zoom / 1.1 : fractol->zoom;
	// Reset view with R key
	else if (keydata.key == MLX_KEY_R)
	{
		fractol->zoom = 1.0;
		fractol->offset_x = (fractol->type == MANDELBROT) ? -0.5 : 0.0;
		fractol->offset_y = 0.0;
		fractol->max_iter = DEFAULT_MAX_ITER;
	}
	// Adjust iterations with I/D keys
	else if (keydata.key == MLX_KEY_I)
		fractol->max_iter += 50;
	else if (keydata.key == MLX_KEY_D && fractol->max_iter > 50)
		fractol->max_iter -= 50;

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

	// Get mouse position
	mlx_get_mouse_pos(fractol->mlx, &mouse_x, &mouse_y);

	// Calculate the complex coordinates before zoom
	map(mouse_x, mouse_y, &real_before, &imag_before, fractol);

	// Apply zoom factor with limits to prevent numerical issues
	if (ydelta > 0)
	{
		// Zoom in - limit maximum zoom to prevent numerical issues
		if (fractol->zoom < 1e10)
			zoom_factor = 1.1;
		else
			zoom_factor = 1.0;
	}
	else
	{
		// Zoom out - limit minimum zoom to prevent numerical issues
		if (fractol->zoom > 0.1)
			zoom_factor = 0.9;
		else
			zoom_factor = 1.0;
	}

	fractol->zoom *= zoom_factor;

	// Calculate the complex coordinates after zoom
	map(mouse_x, mouse_y, &real_after, &imag_after, fractol);

	// Adjust offset to keep the point under the cursor fixed
	fractol->offset_x += (real_before - real_after);
	fractol->offset_y += (imag_before - imag_after);

	// Adjust max iterations based on zoom level for better detail
	if (ydelta > 0 && fractol->zoom > 10)
		fractol->max_iter = DEFAULT_MAX_ITER + (int)(50 * log10(fractol->zoom));

	fractal_render(fractol);
}
