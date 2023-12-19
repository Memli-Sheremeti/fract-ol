/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshereme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 16:15:31 by mshereme          #+#    #+#             */
/*   Updated: 2023/11/15 09:40:08 by mshereme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*str;

	str = NULL;
	while (*s != '\0')
	{
		if (*s == (unsigned char) c)
			str = (char *) s;
		s++;
	}
	if (c == '\0')
		return ((char *) s);
	return (str);
}
