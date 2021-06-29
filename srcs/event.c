/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnakahod <jnakahod@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 06:01:24 by jnakahod          #+#    #+#             */
<<<<<<< HEAD:srcs/event_key.c
/*   Updated: 2021/06/29 12:36:54 by jnakahod         ###   ########.fr       */
=======
/*   Updated: 2021/06/25 15:52:42 by jnakahod         ###   ########.fr       */
>>>>>>> 5fe25003709731ac7c45b6d6960d5c9bb384fee2:srcs/event.c
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>
#include <stdio.h>

int ft_key_press(int key, t_all *all)
{
    if (key == K_ESC)
        ft_exit(all);
<<<<<<< HEAD:srcs/event_key.c
	return (0);
}
=======
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
>>>>>>> 5fe25003709731ac7c45b6d6960d5c9bb384fee2:srcs/event.c
