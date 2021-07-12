/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnakahod <jnakahod@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 22:38:59 by jnakahod          #+#    #+#             */
/*   Updated: 2021/07/12 22:24:32 by jnakahod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

/*
** #include "../minilibx_mms_20200219/mlx.h"
*/
# include "../minilibx-linux/mlx.h"
# include <libft.h>
# include <math.h>
# include <float.h>
# include <unistd.h>
# include <errno.h>
# include <stdlib.h>
# include <stdbool.h>
# include <struct.h>
# include <define.h>
# include <key_linux.h>
# include <color.h>

/*
** init.c
*/
void	ft_init(t_all *all);
void	ft_coordinate_init(t_all *all);

/*
** exit.c
*/
void	print_err_message(void);
int		ft_exit(t_all *all);

/*
** event_key.c
*/
int		ft_key_press(int key, t_all *all);
int		ft_zoom_on(int key, int x, int y, t_all *all);

/*
** load_info_from_parameters.c
*/
void	load_info_from_parameters(int ac, char **av, t_all *all);
double	*ft_atof(char *str);

/*
** set_mandelbrot.c
*/
void	set_pixel_mandelbrot(int x, int y, t_all *all);
int		ft_update_color_of_mandelbrot(int x, int y, t_all *all);

/*
** set_julia.c
*/
void	set_pixel_julia(int x, int y, t_all *all);
int		ft_update_constant_of_julia(int x, int y, t_all *all);

/*
** set_burningship.c
*/
void	set_pixel_burningship(int x, int y, t_all *all);

/*
** utils.c
*/
double	*ft_atof(char *str);

#endif
