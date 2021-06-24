/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnakahod <jnakahod@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 05:12:24 by jnakahod          #+#    #+#             */
/*   Updated: 2021/06/24 05:17:56 by jnakahod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

void    ft_key_init(t_all *all)
{
    all->key.esc = 0;
}


void    ft_init(t_all *all)
{
    ft_key_init(all);
}