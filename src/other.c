/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshereme <mshereme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 11:00:24 by mshereme          #+#    #+#             */
/*   Updated: 2023/12/28 08:16:06 by mshereme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

void	ft_other(t_data *img)
{
	int		i;
	double	x_temp;

	img->name = "other";
	i = 0;
	img->zx = img->px / img->zoom + img->scale_x;
	img->zy = img->py / img->zoom + img->scale_y;
	img->cx = -0.9;
	img->cy = 10;
	while ((img->zx * img->zx) + (img->zy * img->zy) <= 10 && i < M_IT)
	{
		x_temp = pow((img->zx * img->zx + img->zy * img->zy), 10 / 2.) \
			* cos(10 * atan2(img->zy, img->zx)) + img->cx;
		img->zy = pow((img->zx * img->zx + img->zy * img->zy), 10 / 2.) \
			* sin(10 * atan2(img->zy, img->zx)) + img->cx;
		img->zx = x_temp;
		i++;
	}
	img->iteration = i;
	if (i == M_IT)
		ft_pixel_put_image(img, img->px, img->py, 0x00000000);
	else
		ft_pixel_put_image(img, img->px, img->py, ft_apply_color(img));
}

void	ft_draw_other(t_data *img)
{
	img->px = 0;
	while (img->px < WIN_SX)
	{
		img->py = 0;
		while (img->py < WIN_SY)
		{
			ft_other(img);
			img->py++;
		}
		img->px++;
	}
	return ;
}

void	ft_get_init_other(t_data *img)
{
	(*img).px = 0;
	(*img).py = 0;
	(*img).color = 2;
	(*img).zoom = 230;
	(*img).scale_x = -1.5;
	(*img).scale_y = -1.5;
	(*img).argument_cx = 0;
	(*img).argument_cy = 0;
}
