/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_burningship.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnakahod <jnakahod@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 15:02:38 by jnakahod          #+#    #+#             */
/*   Updated: 2021/07/09 15:14:40 by jnakahod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

static int  calc_burningship(int x, int y, t_all *all)
{
    int         i;
    t_complex   constant;
    t_complex   standard;
    t_complex   tmp;

    standard.x = 0;
    standard.y = 0;
    constant.x = (double)x * (all->end_re - all->start_re) / WIDTH + all->start_re;
    constant.y = (double)y * (all->end_im - all->start_im) / HEIGHT + all->start_im;
    i = 0;
    while (i < MAXCALC && abs(standard.x + standard.y) <= 2)
    {
        tmp.x = fabs(standard.x);
        tmp.y = fabs(standard.y);
        standard.x = pow(tmp.x, 2) - pow(tmp.y, 2) + constant.x;
        standard.y = 2 * tmp.x * tmp.y + constant.y;
        i++;
    }
    return (i);
}
    
void    set_pixel_burningship(int x, int y, t_all *all)
{
    int count_calc;
    int color;

    count_calc = calc_burningship(x, y, all);
    color = count_calc * 10000 + x + y;
    if (count_calc == MAXCALC)
        all->buf[y][x] = 0x00000000;
    else
        all->buf[y][x] = color;
}