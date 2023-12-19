/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshereme <mshereme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 08:45:24 by mshereme          #+#    #+#             */
/*   Updated: 2023/11/29 10:43:43 by mshereme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_free(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (1);
}

static int	ft_count_words(char const *s, char c)
{
	int	i;
	int	words;
	int	bit;

	i = 0;
	words = 0;
	bit = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && bit == 0)
		{
			words++;
			bit = 1;
		}
		if (s[i] == c && bit == 1)
			bit = 0;
		i++;
	}
	return (words);
}

static	char	*ft_get_word(char const *s, char c)
{
	int		i;
	int		j;
	char	*word;

	i = 0;
	j = 0;
	while (s[i] != '\0' && s[i] != c)
		i++;
	word = (char *) malloc((i + 1) * sizeof(char));
	if (!word)
		return (NULL);
	while (j < i)
	{
		word[j] = s[j];
		j++;
	}
	word[j] = '\0';
	return (word);
}

static void	ft_inscribe(char **tab, char const *s, char c)
{
	int	words_check;
	int	i;

	i = 0;
	words_check = 0;
	while (*s != '\0')
	{
		while (*s != c && *s != '\0')
		{
			words_check++;
			s++;
		}
		if (words_check > 0)
		{
			tab[i] = ft_get_word(s - words_check, c);
			if (tab[i] == NULL && ft_free(tab))
				return ;
			i++;
		}
		words_check = 0;
		while (*s == c && *s != '\0')
		s++;
	}
	tab[i] = 0;
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	int		words;

	words = 0;
	if (!s)
		return (0);
	words = ft_count_words(s, c);
	tab = (char **) malloc((words + 1) * sizeof(char *));
	if (!tab)
		return (NULL);
	ft_inscribe(tab, s, c);
	return (tab);
}
