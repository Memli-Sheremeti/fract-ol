/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshereme <mshereme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 11:12:01 by mshereme          #+#    #+#             */
/*   Updated: 2023/12/28 12:50:29 by mshereme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

int	ft_close_mlx_data(t_data *img)
{
	if (img->img)
		mlx_destroy_image(img->mlx, img->img);
	if (img->win)
		mlx_destroy_window(img->mlx, img->win);
	if (img->mlx)
	{
		mlx_destroy_display(img->mlx);
		free(img->mlx);
	}
	exit (1);
	return (0);
}
