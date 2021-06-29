/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnakahod <jnakahod@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 15:04:57 by jnakahod          #+#    #+#             */
/*   Updated: 2021/06/25 08:50:18 by jnakahod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
#define STRUCT_H

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
    int     esc;
} t_key;

typedef struct s_all
{
    void    *mlx;
    void    *win;
    int     buf[180][180];
    t_key   key;
    t_data  data;
    long double   coordinate_len;
    int   win_size;
} t_all;

#endif