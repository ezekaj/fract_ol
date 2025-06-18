/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezekaj <ezekaj@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 15:30:38 by ezekaj            #+#    #+#             */
/*   Updated: 2025/05/17 15:31:40 by ezekaj           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fractol.h"

int	parse_sign(const char *str, int *i)
{
	int	sign;

	sign = 1;
	if (str[*i] == '-')
	{
		sign = -1;
		(*i)++;
	}
	else if (str[*i] == '+')
		(*i)++;
	return (sign);
}

double	parse_integer_part(const char *str, int *i)
{
	double	result;

	result = 0.0;
	while (str[*i] >= '0' && str[*i] <= '9')
		result = result * 10 + (str[(*i)++] - '0');
	return (result);
}

double	parse_decimal_part(const char *str, int *i)
{
	double	decimal_value;
	double	decimal_place;

	decimal_value = 0.0;
	if (str[*i] == '.')
	{
		(*i)++;
		decimal_place = 0.1;
		while (str[*i] >= '0' && str[*i] <= '9')
		{
			decimal_value += (str[(*i)++] - '0') * decimal_place;
			decimal_place *= 0.1;
		}
	}
	return (decimal_value);
}

double	ft_atof(const char *str)
{
	double	result;
	double	decimal_value;
	int		sign;
	int		i;

	i = 0;
	sign = parse_sign(str, &i);
	result = parse_integer_part(str, &i);
	decimal_value = parse_decimal_part(str, &i);
	return ((result + decimal_value) * sign);
}
