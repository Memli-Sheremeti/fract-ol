/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshereme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 16:53:48 by mshereme          #+#    #+#             */
/*   Updated: 2023/11/15 09:27:56 by mshereme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	size_t	bytes;

	bytes = nmemb * size;
	if (size && (bytes / size) != nmemb)
		return (NULL);
	ptr = (void *) malloc(bytes);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, (bytes));
	return (ptr);
}
