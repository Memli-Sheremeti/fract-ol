/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshereme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 15:41:29 by mshereme          #+#    #+#             */
/*   Updated: 2023/11/15 09:38:14 by mshereme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	len_d;
	size_t	len_s;
	size_t	i;

	len_s = ft_strlen(src);
	if (!dest && size == 0)
		return (len_s);
	len_d = ft_strlen(dest);
	i = 0;
	if (size <= len_d)
		return (len_s + size);
	while (src[i] != '\0' && i < size - len_d - 1)
	{
		dest[i + len_d] = src[i];
		i++;
	}
	dest[i + len_d] = '\0';
	return (len_s + len_d);
}
