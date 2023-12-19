/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshereme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 14:41:31 by mshereme          #+#    #+#             */
/*   Updated: 2023/11/15 09:34:33 by mshereme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*to;
	int					i;

	to = (unsigned char *) dest;
	if (!to && !(unsigned char *)src)
		return (NULL);
	if (to > (unsigned char *)src)
	{
		i = n - 1;
		while (i >= 0)
		{
			to[i] = ((unsigned char *) src)[i];
			i--;
		}
	}
	else
	{
		i = 0;
		while ((size_t)i < n)
		{
			to[i] = ((unsigned char *) src)[i];
			i++;
		}
	}
	return (dest);
}
