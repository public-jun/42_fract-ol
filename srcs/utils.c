/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnakahod <jnakahod@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 05:29:50 by jnakahod          #+#    #+#             */
/*   Updated: 2021/07/22 13:28:37 by jnakahod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

static bool	is_double(char *str, int i)
{
	if (str[i] == '.')
		return (false);
	while (ft_isdigit(str[i]))
		i++;
	if (str[i] == '.' && str[i + 1])
	{
		i++;
		while (ft_isdigit(str[i]))
			i++;
		if (str[i])
			return (false);
	}
	else if (!str[i])
		return (true);
	else
		return (false);
	return (true);
}

static double	get_double(char *str, int i, int sign)
{
	double	number;
	double	divisor;

	number = 0;
	while (ft_isdigit(str[i]))
		number = str[i++] - '0' + number * 10;
	if (str[i] == '.')
		i++;
	divisor = 1;
	while (ft_isdigit(str[i]))
	{
		number = str[i++] - '0' + number * 10;
		divisor *= 10;
	}
	return (sign * number / divisor);
}

double	*ft_atof(char *str)
{
	double	*number;
	double	tmp;
	int		sign;
	int		i;

	if (!str)
		return (NULL);
	i = 0;
	while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
		i++;
	sign = 1;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	if (is_double(str, i) == false)
		return (NULL);
	number = (double *)malloc(sizeof(double));
	if (!number)
		return (NULL);
	tmp = get_double(str, i, sign);
	*number = tmp;
	return (number);
}
