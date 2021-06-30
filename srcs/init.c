/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnakahod <jnakahod@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 05:12:24 by jnakahod          #+#    #+#             */
/*   Updated: 2021/06/30 08:03:43 by jnakahod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>


void    ft_key_init(t_all *all)
{
    all->key.esc = 0;
}

void    ft_coordinate_init(t_all *all)
{
    all->start_re = -2.0;
    all->start_im = -2.0;
    all->end_re = 2.0;
    all->end_im = 2.0;
}

void    ft_init_win(t_all *all)
{
    all->mlx = mlx_init();
    all->win = mlx_new_window(all->mlx, 180, 180, "fractol");
    all->data.img = mlx_new_image(all->mlx, 180, 180);
    all->data.addr = (int *)mlx_get_data_addr(all->data.img, &all->data.bpp, &all->data.size_l, &all->data.endian);
}

void    ft_init(t_all *all)
{
    ft_key_init(all);
    ft_coordinate_init(all);
    ft_init_win(all);
}