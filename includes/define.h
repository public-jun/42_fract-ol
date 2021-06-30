/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnakahod <jnakahod@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 05:25:05 by jnakahod          #+#    #+#             */
/*   Updated: 2021/06/30 08:04:26 by jnakahod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINE_H
# define DEFINE_H

/*
** event & mask
*/
# define KEYPRESS 2
# define KEYPRESSMASK 1L << 0
# define BUTTONPRESS 4
# define BUTTONPRESSMASK 1L << 2

/*
** window size
*/
# define WIDTH 180
# define HEIGHT 180
#endif