/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshereme <mshereme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 14:32:24 by mshereme          #+#    #+#             */
/*   Updated: 2023/12/27 17:05:09 by mshereme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	ft_calcul(const char *str)
{
	double	floater;
	double	x;

	floater = 0.0;
	x = 0.1;
	while (*str != '\0' && (*str >= 48 && *str <= 57))
	{
		floater += x * (*str - '0');
		str++;
		x *= 0.1;
	}
	return (floater);
}

double	ft_atof(const char *str)
{
	double	integer;
	double	floater;
	int		sign;

	sign = 1;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	integer = ft_atoi(str);
	if (integer < 0)
		return (0);
	floater = 0.0;
	while (*str != '.' && *str != '\0')
		str++;
	if (*str == '.')
		str++;
	floater = ft_calcul(str);
	return ((floater + integer) * sign);
}
