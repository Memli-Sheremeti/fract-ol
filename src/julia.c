/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshereme <mshereme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 13:04:43 by mshereme          #+#    #+#             */
/*   Updated: 2023/12/27 18:17:41 by mshereme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

void	ft_calc_julia(t_data *img)
{
	int		i;
	double	x_temp;

	i = 0;
	while ((img->zx * img->zx) + (img->zy * img->zy) < 4 && i < M_IT)
	{
		x_temp = (img->zx * img->zx) - (img->zy * img->zy) + img->cx;
		img->zy = 2. * img->zx * img->zy + img->cy;
		img->zx = x_temp;
		i++;
	}
	img->iteration = i;
	if (i == M_IT)
		ft_pixel_put_image(img, img->px, img->py, 0x00000000);
	else
		ft_pixel_put_image(img, img->px, img->py, ft_apply_color(img));
}

void	ft_julia(t_data *img)
{
	img->name = "julia";
	img->zx = img->px / img->zoom + img->scale_x;
	img->zy = img->py / img->zoom + img->scale_y;
	if (!(img->argument_cx))
		img->cx = -0.745429;
	else
		img->cx = img->argument_cx;
	if (!(img->argument_cy))
		img->cy = 0.05;
	else
		img->cy = img->argument_cy;
	ft_calc_julia(img);
}

void	ft_draw_julia(t_data *img)
{
	img->px = 0;
	while (img->px < WIN_SX)
	{
		img->py = 0;
		while (img->py < WIN_SY)
		{
			ft_julia(img);
			img->py++;
		}
		img->px++;
	}
	return ;
}

void	ft_get_init_julia(t_data *img, char **name)
{
	(*img).px = 0;
	(*img).py = 0;
	(*img).color = 2;
	(*img).zoom = 230;
	(*img).scale_x = -1.50;
	(*img).scale_y = -1.50;
	if (name[2])
		(*img).argument_cx = ft_atof(name[2]);
	else
		(*img).argument_cx = 0;
	if (name[3])
		(*img).argument_cy = ft_atof(name[3]);
	else
		(*img).argument_cy = 0;
}
