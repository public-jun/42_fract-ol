/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_info_from_parameters.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnakahod <jnakahod@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 06:18:34 by jnakahod          #+#    #+#             */
/*   Updated: 2021/07/05 13:10:04 by jnakahod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

void    load_info_from_parameters(int ac, char **av, t_all *all)
{
    double  *tmp;

    (void)ac;
    if (!ft_strncmp(av[1], "mandelbrot", 11))
        all->type_fractol = MANDELBROT;
    else if (!ft_strncmp(av[1], "julia", 6))
        all->type_fractol = JULIA;
    else
        exit(1);
    if (av[2] && !ft_strncmp(av[2], "plain", 6))
        all->flag_cursor_effect = OFF;
    else if (av[2] && !ft_strncmp(av[2], "dynamic", 8))
        all->flag_cursor_effect = ON;
    else
        exit(1);
    all->constant_real_num = -0.8;
    tmp = NULL;
    if (av[3])
    {
        tmp = ft_atof(av[3]);
        if (!tmp)
            exit(1);
        all->constant_real_num = *tmp;
        free(tmp);
        tmp = NULL;
    }
    all->constant_imaginary_num = 0.15;
    if (av[3] && av[4])
    {
        tmp = ft_atof(av[4]);
        if (!tmp)
            exit(1);
        all->constant_imaginary_num = *tmp;
        free(tmp);
        tmp = NULL;
    }
    if (ac > 5)
        exit(1);
    printf("real = %f\n", all->constant_real_num);
    printf("img  = %f\n", all->constant_imaginary_num);
}