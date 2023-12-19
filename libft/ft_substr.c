/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshereme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 16:57:42 by mshereme          #+#    #+#             */
/*   Updated: 2023/11/15 09:42:09 by mshereme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	index;
	char	*substr;

	if (!s)
		return (0);
	if (start >= ft_strlen(s))
		len = 0;
	else if (len >= ft_strlen(s + start))
		len = ft_strlen(s + start);
	index = 0;
	substr = malloc((len + 1) * sizeof(char));
	if (!substr)
		return (NULL);
	while (index < len)
	{
		substr[index] = s[start + index];
		index++;
	}
	substr[index] = '\0';
	return (substr);
}
