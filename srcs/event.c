/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnakahod <jnakahod@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 06:01:24 by jnakahod          #+#    #+#             */
/*   Updated: 2021/06/30 06:14:46 by jnakahod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>
#include <stdio.h>

int ft_key_press(int key, t_all *all)
{
    if (key == K_ESC)
        ft_exit(all);
    return (0);
}

int ft_zoom_on(int key, int x, int y, t_all *all)
{
    double zoom;
    double mouse_re;
    double mouse_im;

    mouse_re = ((double)x / WIDTH) * (all->end_re - all->start_re) + all->start_re;
    mouse_im = ((double)y / HEIGHT) * (all->end_im - all->start_im) + all->start_im;

    // printf("mouse_re=%f, mouse_im=%f\n", mouse_re, mouse_im);
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
    {
        ft_coordinate_init(all);
    }
    printf("click = %d\n", key);
    printf("p: x=%d, y=%d\n", x, y);
    return (0);

}
