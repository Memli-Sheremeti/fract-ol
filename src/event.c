/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshereme <mshereme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 18:27:07 by mshereme          #+#    #+#             */
/*   Updated: 2023/12/28 07:53:50 by mshereme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

int	ft_key_hook(int key, t_data *img)
{
	if (key == ESC)
		ft_close_mlx_data(img);
	else if (key == 0xFF52)
		img->scale_y -= 42 / img->zoom;
	else if (key == 0xFF54)
		img->scale_y += 42 / img->zoom;
	else if (key == 0xFF51)
		img->scale_x -= 42 / img->zoom;
	else if (key == 0xFF53)
		img->scale_x += 42 / img->zoom;
	else if (key == 0x6d)
		ft_change_color(img);
	ft_draw_fractal(img);
	return (0);
}

void	ft_zoom(t_data *img, int x, int y, int scroll)
{
	double	scale;

	scale = 1.3;
	if (scroll == UP)
	{
		img->scale_x = (x / img->zoom + img->scale_x) - \
		(x / (img->zoom * scale));
		img->scale_y = (y / img->zoom + img->scale_y) - \
		(y / (img->zoom * scale));
		img->zoom *= scale;
	}
	else if (scroll == DOWN)
	{
		img->scale_x = (x / img->zoom + img->scale_x) - \
		(x / (img->zoom / scale));
		img->scale_y = (y / img->zoom + img->scale_y) - \
		(y / (img->zoom / scale));
		img->zoom /= scale;
	}
	else
		return ;
}

int	ft_mouse_hook(int button, int x, int y, t_data *img)
{
	if (button == UP)
		ft_zoom(img, x, y, UP);
	else if (button == DOWN)
		ft_zoom(img, x, y, DOWN);
	ft_draw_fractal(img);
	return (0);
}

void	ft_change_color(t_data *img)
{
	img->color = (img->color + 1) % 4;
}
