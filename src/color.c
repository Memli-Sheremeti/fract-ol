/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshereme <mshereme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 17:41:54 by mshereme          #+#    #+#             */
/*   Updated: 2023/12/28 07:53:44 by mshereme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

int	ft_apply_color(t_data *img)
{
	int		color;
	double	abs_z;

	abs_z = img->zx * img->zx + img->zy * img->zy;
	color = 0;
	if (img->color == 0)
		color = ft_color_base(img->iteration);
	else if (img->color == 1)
		color = 0xFCBE11 * sqrt(img->iteration + 10 \
		- log(log(abs_z)) / log(4));
	else if (img->color == 2)
		color = 0xFCFA01 * (img->iteration - 1 - log(log(abs_z) / log(10)));
	else
		color = ft_color_bs(img->iteration);
	return (color);
}

int	ft_color_base(int i)
{
	int		color[16];

	color[0] = 0x421E0F;
	color[1] = 0x19071A;
	color[2] = 0x09012F;
	color[3] = 0x040449;
	color[4] = 0x000764;
	color[5] = 0x0C2C8A;
	color[6] = 0x1852B1;
	color[7] = 0x397DD1;
	color[8] = 0x86B5E5;
	color[9] = 0xD3ECF8;
	color[10] = 0xF1E9BF;
	color[11] = 0xF8C95F;
	color[12] = 0xFFAA00;
	color[13] = 0xCC8000;
	color[14] = 0x995700;
	color[15] = 0x6A3403;
	return (color[i % 16]);
}

int	ft_color_bs(int i)
{
	int		colors[16];

	colors[0] = 0x000000;
	colors[1] = 0x180018;
	colors[2] = 0x300060;
	colors[3] = 0x602040;
	colors[4] = 0x404040;
	colors[5] = 0x8060A0;
	colors[6] = 0xA070C0;
	colors[7] = 0xC090E0;
	colors[8] = 0xD0B0F0;
	colors[9] = 0xE0D0FF;
	colors[10] = 0xF0E0FF;
	colors[11] = 0xFFE0F0;
	colors[12] = 0xFFD0C0;
	colors[13] = 0xFFC080;
	colors[14] = 0xFFD090;
	colors[15] = 0xFFE0A0;
	return (colors[i % 16]);
}
