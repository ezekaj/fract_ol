#include "../inc/fractol.h"

void	map(int x, int y, double *real, double *imag, t_fractol *fractol)
{
	*real = (x - WIDTH / 2.0) * 3.0 / WIDTH - 0.5;
	*imag = (y - HEIGHT / 2.0) * 3.0 / HEIGHT;
}

int	colors(int i, int max_i)
{
	int	brightness;

	if (i == max_i)
		return (0x000000FF);
	brightness = (i * 255) / max_i;
	return ((brightness << 24) | (brightness << 16) | (0xFF << 8) | 0xFF);
}

void	fractal_render(t_fractol *fractol)
{
	int		x;
	int		y;
	double	real;
	double	imag;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			map(x, y, &real, &imag, fractol);
			mlx_put_pixel(fractol->img, x, y, colors(mandelbrot(real, imag, 100), 100));
			x++;
		}
		y++;
	}
}

