/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshereme <mshereme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 11:30:18 by mshereme          #+#    #+#             */
/*   Updated: 2023/12/27 18:27:17 by mshereme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_H
# define FRACT_H

# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include "../minilibx-linux/mlx_int.h"
# include <math.h>

# define WIN_SX 700
# define WIN_SY 700
# define M_IT 50
# ifndef M_PI
#  define M_PI 3.1415926535897932384626433
# endif
# define ESC 0xFF1B
# define P
# define X

enum e_SCROLL
{
	UP = 4,
	DOWN
};

typedef struct s_data
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	char	*name;
	int		bpp;
	int		sl;
	int		endian;
	int		color;
	int		iteration;
	int		px;
	int		py;
	double	zx;
	double	zy;
	double	cx;
	double	cy;
	double	scale_x;
	double	scale_y;
	double	zoom;
	double	argument_cx;
	double	argument_cy;

}	t_data;

/* Initialize data */
void	ft_get_init_img(t_data *img, char **name);
void	ft_get_init_fract(t_data *img, char **name);
void	ft_get_init_mandelbrot(t_data *img);
void	ft_get_init_julia(t_data *img, char **name);
void	ft_get_init_other(t_data *img);
void	ft_get_init_burning(t_data *img);

/* Error Gestion */
int		ft_close_mlx_data(t_data *img);

/* Draw tools */
void	ft_draw_fractal(t_data *img);
void	ft_pixel_put_image(t_data *data, int x, int y, int color);
void	ft_display_data(t_data img);
int		ft_color_base(int i);
int		ft_color_bs(int i);
int		ft_apply_color(t_data *img);
void	ft_change_color(t_data *img);

/* FRACATAL : MANDELBROT */
void	ft_draw_mandelbrot(t_data *img);
void	ft_mandelbrot(t_data *img);

/* FRACATAL : JULIA */
void	ft_draw_julia(t_data *img);
void	ft_julia(t_data *img);

/* FRACATAL : OTHER */
void	ft_draw_other(t_data *img);
void	ft_other(t_data *img);

/* FRACATAL : BURNING */
void	ft_draw_burning(t_data *img);
void	ft_burning(t_data *img);

/* Events*/
int		ft_key_hook(int key, t_data *img);
int		ft_mouse_hook(int button, int x, int y, t_data *img);

#endif
