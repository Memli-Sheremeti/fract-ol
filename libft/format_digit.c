/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_digit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshereme <mshereme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 10:50:33 by mshereme          #+#    #+#             */
/*   Updated: 2023/11/29 15:47:38 by mshereme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_num(long nb)
{
	int	count;

	count = 0;
	if (nb < 0)
	{
		ft_print_char('-');
		return (ft_print_num(-nb) + 1);
	}
	if (nb >= 10)
		count += ft_print_num(nb / 10);
	return (count + ft_print_char(nb % 10 + '0'));
}

int	ft_print_hex(unsigned int nb, char c)
{
	int	count;

	count = 0;
	if (nb < 16 && c == 'x')
		return (ft_print_char(BASEL[nb]));
	else if (nb < 16 && c == 'X')
		return (ft_print_char(BASEU[nb]));
	else
	{
		count = ft_print_hex(nb / 16, c);
		return (count + ft_print_hex(nb % 16, c));
	}
}
