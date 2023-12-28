/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshereme <mshereme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 13:04:43 by mshereme          #+#    #+#             */
/*   Updated: 2023/12/27 18:12:22 by mshereme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

void	ft_mandelbrot(t_data *img)
{
	int		i;
	double	x_temp;

	img->name = "mandelbrot";
	i = 0;
	img->zx = 0.0;
	img->zy = 0.0;
	img->cx = (img->px / img->zoom) + img->scale_x;
	img->cy = (img->py / img->zoom) + img->scale_y;
	while ((img->zx * img->zx) + (img->zy * img->zy) <= 4 && i < M_IT)
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

void	ft_draw_mandelbrot(t_data *img)
{
	img->px = 0;
	while (img->px < WIN_SX)
	{
		img->py = 0;
		while (img->py < WIN_SY)
		{
			ft_mandelbrot(img);
			img->py++;
		}
		img->px++;
	}
	return ;
}

void	ft_get_init_mandelbrot(t_data *img)
{
	(*img).px = 0;
	(*img).py = 0;
	(*img).color = 0;
	(*img).zoom = 270;
	(*img).scale_x = -1.5;
	(*img).scale_y = -1.20;
	(*img).argument_cx = 0;
	(*img).argument_cy = 0;
}
