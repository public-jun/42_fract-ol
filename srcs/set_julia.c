/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_julia.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnakahod <jnakahod@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 15:29:28 by jnakahod          #+#    #+#             */
/*   Updated: 2021/06/30 16:18:01 by jnakahod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>


static int  calc_julia(int x, int y, t_all *all)
{
    int i;
    t_complex   constant;
    t_complex   standard;
    t_complex   tmp;

    standard.x = (double)x * (all->end_re - all->start_re) / WIDTH + all->start_re;
    standard.y = (double)y * (all->end_im - all->start_im) / HEIGHT + all->start_im;
    constant.x = -0.8;
    constant.y = 0.15;
    i = 0;
    while (i < MAXCALC && abs(standard.x + standard.y) <= 2)
    {
        tmp.x = standard.x * standard.x - standard.y * standard.y + constant.x;
        tmp.y = 2 * standard.x * standard.y + constant.y;
        standard.x = tmp.x;
        standard.y = tmp.y;
        i++;
    }
    return (i);
}

void    set_pixel_julia(int x, int y, t_all *all)
{
    int count_calc;
    int color;

    count_calc = calc_julia(x, y, all);
    color = count_calc * 10000 + x + y;
    if (count_calc == MAXCALC)
        all->buf[y][x] = 0x00000000;
    else
        all->buf[y][x] = color;
}