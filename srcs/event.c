/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnakahod <jnakahod@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 06:01:24 by jnakahod          #+#    #+#             */
/*   Updated: 2021/07/23 05:09:50 by jnakahod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>
#include <stdio.h>

static void	ft_move(int key, t_all *all)
{
	if (key == K_LEFT)
	{
		all->start_re = all->start_re
			- (all->end_re - all->start_re) * 10 / WIDTH;
		all->end_re = all->end_re - (all->end_re - all->start_re) * 10 / WIDTH;
	}
	else if (key == K_RIGHT)
	{
		all->start_re = all->start_re
			+ (all->end_re - all->start_re) * 10 / WIDTH;
		all->end_re = all->end_re + (all->end_re - all->start_re) * 10 / WIDTH;
	}
	else if (key == K_DOWN)
	{
		all->start_im = all->start_im
			+ (all->end_im - all->start_im) * 10 / HEIGHT;
		all->end_im = all->end_im + (all->end_im - all->start_im) * 10 / HEIGHT;
	}
	else if (key == K_UP)
	{
		all->start_im = all->start_im
			- (all->end_im - all->start_im) * 10 / HEIGHT;
		all->end_im = all->end_im - (all->end_im - all->start_im) * 10 / HEIGHT;
	}
}

int	ft_key_press(int key, t_all *all)
{
	if (key == K_ESC)
		ft_exit(all);
	else if (key == K_LEFT || key == K_RIGHT
		|| key == K_DOWN || key == K_UP)
		ft_move(key, all);
	return (0);
}

static double	set_mouse_cordinate(int n, int size, double start, double end)
{
	double	res;

	res = ((double)n / size) * (end - start) + start;
	return (res);
}

int	ft_zoom_on(int key, int x, int y, t_all *all)
{
	double	mouse_re;
	double	mouse_im;

	mouse_re = set_mouse_cordinate(x, WIDTH, all->start_re, all->end_re);
	mouse_im = set_mouse_cordinate(y, HEIGHT, all->start_im, all->end_im);
	if (key == WHEEL_UP && (all->end_re - all->start_re) > 0.0000000001
		&& (all->end_im - all->start_im) > 0.0000000001)
	{
		all->start_re = mouse_re + (all->start_re - mouse_re) * 0.95;
		all->start_im = mouse_im + (all->start_im - mouse_im) * 0.95;
		all->end_re = mouse_re + (all->end_re - mouse_re) * 0.95;
		all->end_im = mouse_im + (all->end_im - mouse_im) * 0.95;
	}
	else if (key == WHEEL_DOWN && (all->end_re - all->start_re) < 1000
		&& (all->end_im - all->start_im) < 1000)
	{
		all->start_re = mouse_re + (all->start_re - mouse_re) * 1.05;
		all->start_im = mouse_im + (all->start_im - mouse_im) * 1.05;
		all->end_re = mouse_re + (all->end_re - mouse_re) * 1.05;
		all->end_im = mouse_im + (all->end_im - mouse_im) * 1.05;
	}
	else if (key == CLICK)
		ft_coordinate_init(all);
	return (0);
}
