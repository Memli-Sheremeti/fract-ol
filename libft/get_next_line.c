/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshereme <mshereme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 08:40:29 by mshereme          #+#    #+#             */
/*   Updated: 2023/12/04 17:38:22 by mshereme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*str;

	if (!s1)
	{
		s1 = malloc(sizeof(char));
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	str = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!str)
		return (NULL);
	i = -1;
	j = 0;
	if (s1)
		while (s1[++i] != '\0')
			str[i] = s1[i];
	while (s2[j] != '\0')
		str[i++] = s2[j++];
	str[ft_strlen(s1) + ft_strlen(s2)] = '\0';
	free(s1);
	return (str);
}

char	*ft_creat_line(char *line, int fd)
{
	ssize_t	nb_bytes_read;
	char	*buf;

	buf = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buf)
		return (NULL);
	nb_bytes_read = 1;
	while (!ft_strchr_gnl(line, '\n') && nb_bytes_read != 0)
	{
		nb_bytes_read = read(fd, buf, BUFFER_SIZE);
		if (nb_bytes_read == -1)
		{
			free(buf);
			return (NULL);
		}
		buf[nb_bytes_read] = '\0';
		line = ft_strjoin_gnl(line, buf);
	}
	free(buf);
	return (line);
}

char	*get_next_line(int fd)
{
	char		*next_line;
	static char	*line[FOPEN_MAX];

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &next_line, 0) < 0)
		return (NULL);
	line[fd] = ft_creat_line(line[fd], fd);
	if (!line[fd])
		return (NULL);
	next_line = ft_get_line(line[fd]);
	line[fd] = ft_newline(line[fd]);
	return (next_line);
}

/*int	main(int ac, char **av)
{
	int	fd;
	char	*line;

	(void) ac;
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		return (0);
	line = get_next_line(fd);
	free(line);
	close(fd);
	return (1);
}
*/
