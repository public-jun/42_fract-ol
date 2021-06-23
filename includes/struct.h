/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnakahod <jnakahod@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 15:04:57 by jnakahod          #+#    #+#             */
/*   Updated: 2021/06/23 15:09:20 by jnakahod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H 
# define STRUCT_H

typedef struct s_data
{
  void *img;
  int *addr;
  int bits_per_piexel;
  int line_len;
  int endian;
  int buf[180][180];
} t_data;

typedef struct s_key
{

} t_key;
#endif