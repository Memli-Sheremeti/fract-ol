/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshereme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 13:44:47 by mshereme          #+#    #+#             */
/*   Updated: 2023/11/15 09:33:03 by mshereme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*begin;

	begin = malloc(sizeof(*begin));
	if (!begin)
		return (NULL);
	begin->content = content;
	begin->next = NULL;
	return (begin);
}
