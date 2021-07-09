/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnakahod <jnakahod@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 05:25:05 by jnakahod          #+#    #+#             */
/*   Updated: 2021/07/09 14:07:54 by jnakahod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINE_H
# define DEFINE_H

/*
** type fractol
*/
# define MANDELBROT 1
# define JULIA 2
# define BURNINGSHIP 3

/*
** flag on off
*/
# define OFF 0
# define ON 1

/*
** event & mask
*/
# define KEYPRESS 2
# define KEYPRESSMASK 1L << 0
# define BUTTONPRESS 4
# define BUTTONPRESSMASK 1L << 2
# define MOTIONNOTIFY 6
# define POINTERMOTIONMASK 1L << 6 

/*
** window size
*/
# define WIDTH 200
# define HEIGHT 200

/*
** calc
*/
# define MAXCALC 60
#endif