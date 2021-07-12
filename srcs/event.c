/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnakahod <jnakahod@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 06:01:24 by jnakahod          #+#    #+#             */
/*   Updated: 2021/07/12 21:25:53 by jnakahod         ###   ########.fr       */
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

int	ft_zoom_on(int key, int x, int y, t_all *all)
{
	double	mouse_re;
	double	mouse_im;

	mouse_re = ((double)x / WIDTH) * (all->end_re - all->start_re)
		+ all->start_re;
	mouse_im = ((double)y / HEIGHT) * (all->end_im - all->start_im)
		+ all->start_im;
	if (key == WHEEL_UP)
	{
		all->start_re = mouse_re + (all->start_re - mouse_re) * 0.9;
		all->start_im = mouse_im + (all->start_im - mouse_im) * 0.9;
		all->end_re = mouse_re + (all->end_re - mouse_re) * 0.9;
		all->end_im = mouse_im + (all->end_im - mouse_im) * 0.9;
	}
	else if (key == WHEEL_DOWN)
	{
		all->start_re = mouse_re + (all->start_re - mouse_re) * 1.1;
		all->start_im = mouse_im + (all->start_im - mouse_im) * 1.1;
		all->end_re = mouse_re + (all->end_re - mouse_re) * 1.1;
		all->end_im = mouse_im + (all->end_im - mouse_im) * 1.1;
	}
	else if (key == CLICK)
		ft_coordinate_init(all);
	return (0);
}
