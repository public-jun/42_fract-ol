/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_info_from_parameters.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnakahod <jnakahod@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 06:18:34 by jnakahod          #+#    #+#             */
/*   Updated: 2021/06/30 15:41:02 by jnakahod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

void    load_info_from_parameters(int ac, char **av, t_all *all)
{
    (void)ac;
    if (!ft_strncmp(av[1], "mandelbrot", 11))
        all->type_fractol = MANDELBROT;
    else if (!ft_strncmp(av[1], "julia", 6))
        all->type_fractol = JULIA;
    else
        exit(1);
    //get real and img num
    // if (all->type_fractol == JULIA)
}