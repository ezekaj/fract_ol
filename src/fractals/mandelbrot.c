#include "../../inc/fractol.h"

int	mandelbrot(double real, double imag, int max_i)
{
	double	z_real;
	double	z_imag;
	double	temp;
	int		i;

	z_imag = 0;
	z_real = 0;
	i = 0;
	while (z_real*z_real + z_imag*z_imag < 4 && i < max_i)
	{
		temp = z_real*z_real - z_imag*z_imag + real;
		z_imag = 2*z_real*z_imag + imag;
		z_real = temp;
		i++;
	}
	return (i);
}
