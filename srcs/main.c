/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnakahod <jnakahod@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 22:31:05 by jnakahod          #+#    #+#             */
/*   Updated: 2021/07/13 05:45:25 by jnakahod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

void	branch_by_fractol(int x, int y, t_all *all)
{
	if (all->type_fractol == MANDELBROT)
		set_pixel_mandelbrot(x, y, all);
	else if (all->type_fractol == JULIA)
		set_pixel_julia(x, y, all);
	else if (all->type_fractol == BURNINGSHIP)
		set_pixel_burningship(x, y, all);
}

void	ft_draw_to_window(t_all *all, t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			branch_by_fractol(x, y, all);
			data->addr[(data->size_l / (data->bpp / 8)) *y + x]
				= all->buf[y][x];
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(all->mlx, all->win, data->img);
}

int	ft_main_loop(t_all *all)
{
	ft_draw_to_window(all, &all->data);
	return (0);
}

int	main(int ac, char **av)
{
	t_all	all;

	load_info_from_parameters(ac, av, &all);
	ft_init(&all);
	mlx_loop_hook(all.mlx, &ft_main_loop, &all);
	mlx_hook(all.win, KEYPRESS, 1L << 0, &ft_key_press, &all);
	mlx_hook(all.win, BUTTONPRESS, 1L << 2, &ft_zoom_on, &all);
	mlx_hook(all.win, 33, 1L << 17, &ft_exit, &all);
	if (all.type_fractol == JULIA && all.flag_cursor_effect == ON)
		mlx_hook(all.win, MOTIONNOTIFY, 1L << 6,
			 &ft_update_constant_of_julia, &all);
	if (all.type_fractol == MANDELBROT && all.flag_cursor_effect == ON)
		mlx_hook(all.win, MOTIONNOTIFY, 1L << 6,
			 &ft_update_color_of_mandelbrot, &all);
	mlx_loop(all.mlx);
	return (0);
}
