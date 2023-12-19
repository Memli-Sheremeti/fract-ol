/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshereme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 08:37:45 by mshereme          #+#    #+#             */
/*   Updated: 2023/11/15 09:40:29 by mshereme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_ischarset(char const c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

static char	*ft_del_s(void)
{
	char	*str;

	str = malloc(sizeof(char));
	if (!str)
		return (NULL);
	ft_strlcpy(str, "", 1);
	return (str);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	len_s1;
	size_t	end;
	size_t	start;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	while (ft_ischarset(s1[start], set))
		start++;
	len_s1 = ft_strlen(s1);
	end = len_s1 - 1;
	if (start == len_s1)
		return (ft_del_s());
	while (ft_ischarset(s1[end], set))
		end--;
	str = malloc((end - start + 2) * sizeof(char));
	if (!str)
		return (NULL);
	ft_strlcpy(str, (s1 + start), (end - start + 2));
	return (str);
}
