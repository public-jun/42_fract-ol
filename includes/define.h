/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnakahod <jnakahod@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 05:25:05 by jnakahod          #+#    #+#             */
/*   Updated: 2021/07/05 11:27:09 by jnakahod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINE_H
# define DEFINE_H

/*
** type fractol
*/
# define MANDELBROT 1
# define JULIA 2

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