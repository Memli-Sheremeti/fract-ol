/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshereme <mshereme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 16:00:36 by mshereme          #+#    #+#             */
/*   Updated: 2023/12/27 17:51:54 by mshereme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"
#include <stdio.h>

void	ft_display_data(t_data img)
{
	printf("IMG.img == %p\n", img.img);
	printf("IMG.bpp == %d\n", img.bpp);
	printf("IMG.sl == %d\n", img.sl);
	printf("IMG.endian == %d\n", img.endian);
	printf("IMG.mlx_ptr == %p\n", img.mlx);
	printf("IMG.win_ptr == %p\n", img.win);
	printf("IMG.name == %s\n", img.name);
	printf("IMG.color == %d\n", img.color);
	printf("IMG.px == %d\n", img.px);
	printf("IMG.py == %d\n", img.py);
	printf("IMG.scale_x == %f\n", img.scale_x);
	printf("IMG.scale_y == %f\n", img.scale_y);
	printf("IMG.zoom == %f\n", img.zoom);
	printf("IMG.arg X == %f\n", img.argument_cx);
	printf("IMG.arg Y == %f\n", img.argument_cy);
}

void	ft_get_init_fract(t_data *img, char **name)
{
	if (ft_strncmp(name[1], "mandelbrot", 10) == 0)
	{
		ft_get_init_mandelbrot(&(*img));
		img->name = "mandelbrot";
	}
	else if (ft_strncmp(name[1], "julia", 6) == 0)
	{
		ft_get_init_julia(&(*img), name);
		img->name = "julia";
	}
	else if (ft_strncmp(name[1], "burning", 8) == 0)
	{
		ft_get_init_burning(&(*img));
		img->name = "burning";
	}
	else if (ft_strncmp(name[1], "other", 6) == 0)
	{
		ft_get_init_other(&(*img));
		img->name = "other";
	}
	else
	{
		printf("wrong input");
		ft_close_mlx_data(img);
	}
}

void	ft_get_init_img(t_data *img, char **name)
{
	(*img).mlx = mlx_init();
	(*img).win = mlx_new_window((*img).mlx, WIN_SX, WIN_SY, "Fractal");
	(*img).img = mlx_new_image((*img).mlx, WIN_SX, WIN_SY);
	if (!((*img).img))
		ft_close_mlx_data(img);
	(*img).addr = mlx_get_data_addr((*img).img, &img->bpp, \
	&img->sl, &img->endian);
	if (!((*img).addr))
		ft_close_mlx_data(img);
	ft_get_init_fract(&(*img), name);
}

void	ft_pixel_put_image(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->sl + x * (data->bpp / 8));
	*(unsigned int *) dst = color;
}
