#include "../inc/fractol.h"

void	map(int x, int y, double *real, double *imag, t_fractol *fractol)
{
	*real = (x - WIDTH / 2.0) * 4.0 / (WIDTH * fractol->zoom) + fractol->offset_x;
	*imag = (y - HEIGHT / 2.0) * 4.0 / (HEIGHT * fractol->zoom) + fractol->offset_y;
}

static int	color_classic(int i, int max_i)
{
	int	brightness;

	if (i == max_i)
		return (0x000000FF);
	brightness = (i * 255) / max_i;
	return ((brightness << 24) | (brightness << 16) | (0xFF << 8) | 0xFF);
}

static int	color_blue(int i, int max_i)
{
	int	r;
	int	g;
	int	b;

	if (i == max_i)
		return (0x000000FF);

	r = (i * 128) / max_i;
	g = (i * 192) / max_i;
	b = 255;

	return ((r << 24) | (g << 16) | (b << 8) | 0xFF);
}

static int	color_fire(int i, int max_i)
{
	int	r;
	int	g;
	int	b;
	int	scale;

	if (i == max_i)
		return (0x000000FF);

	scale = (i * 100) / max_i;

	r = 255;
	g = (scale < 50) ? scale * 5 : 255;
	b = (scale < 25) ? 0 : (scale - 25) * 3;

	return ((r << 24) | (g << 16) | (b << 8) | 0xFF);
}

static int	color_psychedelic(int i, int max_i)
{
	int	r;
	int	g;
	int	b;
	int	scale;

	if (i == max_i)
		return (0x000000FF);

	scale = (i * 300) / max_i;

	r = (scale % 256);
	g = ((scale + 85) % 256);
	b = ((scale + 170) % 256);

	return ((r << 24) | (g << 16) | (b << 8) | 0xFF);
}

static int	color_grayscale(int i, int max_i)
{
	int	brightness;

	if (i == max_i)
		return (0x000000FF);

	brightness = 255 - ((i * 255) / max_i);

	return ((brightness << 24) | (brightness << 16) | (brightness << 8) | 0xFF);
}

int	colors(int i, int max_i, int color_scheme)
{
	if (color_scheme == COLOR_SCHEME_BLUE)
		return (color_blue(i, max_i));
	else if (color_scheme == COLOR_SCHEME_FIRE)
		return (color_fire(i, max_i));
	else if (color_scheme == COLOR_SCHEME_PSYCHEDELIC)
		return (color_psychedelic(i, max_i));
	else if (color_scheme == COLOR_SCHEME_GRAYSCALE)
		return (color_grayscale(i, max_i));
	else // COLOR_SCHEME_CLASSIC
		return (color_classic(i, max_i));
}

void	fractal_render(t_fractol *fractol)
{
	int		x;
	int		y;
	double	real;
	double	imag;
	int		i;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			map(x, y, &real, &imag, fractol);
			if (fractol->type == MANDELBROT)
				i = mandelbrot(real, imag, fractol->max_iter);
			else if (fractol->type == JULIA)
				i = julia(real, imag, fractol->c_real, fractol->c_imag,
					fractol->max_iter);
			else
				i = 0;
			mlx_put_pixel(fractol->img, x, y,
				colors(i, fractol->max_iter, fractol->color_scheme));
			x++;
		}
		y++;
	}
}

