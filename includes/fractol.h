/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnakahod <jnakahod@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 22:38:59 by jnakahod          #+#    #+#             */
/*   Updated: 2021/06/25 15:30:57 by jnakahod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

#include "../minilibx-linux/mlx.h"
#include <math.h>
#include <float.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>
#include <struct.h>
#include <define.h>
#include <key_linux.h>


/*
** init.c
*/
void    ft_init(t_all *all);

/*
** exit.c
*/
void    ft_exit(t_all *all);

/*
** event_key.c
*/
int ft_key_press(int key, t_all *all);
int ft_zoom_on(int key, int x,  int y, t_all *all);

/*
** load_info_from_parameters.c
*/
// void    load_info_from_parameters(int ac, char **av);

#endif
