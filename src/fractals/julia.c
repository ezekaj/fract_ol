#include "../../inc/fractol.h"

int	julia(double real, double imag, double c_real, double c_imag, int max_i)
{
	double	z_real;
	double	z_imag;
	double	temp;
	int		i;

	z_real = real;
	z_imag = imag;
	i = 0;
	while (z_real*z_real + z_imag*z_imag < 4 && i < max_i)
	{
		temp = z_real*z_real - z_imag*z_imag + c_real;
		z_imag = 2*z_real*z_imag + c_imag;
		z_real = temp;
		i++;
	}
	return (i);
}
