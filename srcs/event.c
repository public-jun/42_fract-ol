/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnakahod <jnakahod@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 06:01:24 by jnakahod          #+#    #+#             */
/*   Updated: 2021/06/29 17:17:26 by jnakahod         ###   ########.fr       */
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
    long double zoom;

    printf("p: x=%d, y=%d\n", x, y);
    if (key == WHEEL_UP)
        zoom = 0.9;
    else if (key == WHEEL_DOWN)
        zoom = 1.1;
    // perror("a");
    // errno= 0;
    all->coordinate_len *= zoom;
    return (0);

}
