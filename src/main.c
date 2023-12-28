/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshereme <mshereme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 09:01:06 by mshereme          #+#    #+#             */
/*   Updated: 2023/12/28 08:05:20 by mshereme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

void	ft_draw_fractal(t_data *img)
{
	if (ft_strncmp(img->name, "mandelbrot", 10) == 0)
		ft_draw_mandelbrot(img);
	else if (ft_strncmp(img->name, "julia", 6) == 0)
		ft_draw_julia(img);
	else if (ft_strncmp(img->name, "burning", 8) == 0)
		ft_draw_burning(img);
	else if (ft_strncmp(img->name, "other", 6) == 0)
		ft_draw_other(img);
	else
	{
		ft_printf("Wrong Input\n");
		ft_printf("fractal: mandelbrot, julia, burning\n");
		ft_close_mlx_data(img);
	}
	mlx_put_image_to_window((*img).mlx, (*img).win, (*img).img, 0, 0);
	return ;
}

int	main(int ac, char **av)
{
	t_data	img;

	if (ac < 2)
	{
		ft_printf("Input: ./libix fractal\n");
		ft_printf("fractal: mandelbrot, julia, burning\n");
		return (0);
	}
	ft_get_init_img(&img, av);
	ft_display_data(img);
	mlx_key_hook(img.win, ft_key_hook, &img);
	mlx_mouse_hook(img.win, ft_mouse_hook, &img);
	mlx_hook(img.win, 17, 0L, ft_close_mlx_data, &img);
	ft_draw_fractal(&img);
	mlx_loop(img.mlx);
}
