/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnakahod <jnakahod@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 15:04:57 by jnakahod          #+#    #+#             */
/*   Updated: 2021/06/30 10:35:58 by jnakahod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
#define STRUCT_H

#include <define.h>

typedef struct s_data
{
    void    *img;
    int     *addr;
    int     bpp;
    int     size_l;
    int     endian;
} t_data;

typedef struct s_key
{
    int esc;
} t_key;

typedef struct s_complex
{
    double x;
    double y;
} t_complex;

typedef struct s_all
{
    void    *mlx;
    void    *win;
    int     buf[HEIGHT][WIDTH];
    t_key   key;
    t_data  data;
    double  start_re;
    double  start_im;
    double  end_re;
    double  end_im;
    int     type_fractol;
} t_all;

#endif