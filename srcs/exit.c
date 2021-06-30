/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnakahod <jnakahod@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 07:09:49 by jnakahod          #+#    #+#             */
/*   Updated: 2021/06/30 06:16:12 by jnakahod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

void    ft_exit(t_all *all)
{
    if (all->win)
        mlx_destroy_window(all->mlx, all->win);
    if (all->data.img)
        mlx_destroy_image(all->mlx, all->data.img);
    if (all->mlx)
    {
        mlx_destroy_display(all->mlx);
        free(all->mlx);
    }
    exit(0);
}
