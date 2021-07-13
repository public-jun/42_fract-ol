/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnakahod <jnakahod@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 05:42:41 by jnakahod          #+#    #+#             */
/*   Updated: 2021/07/13 05:43:44 by jnakahod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MLX_H
# define FT_MLX_H

void	*mlx_init(void);
void	*mlx_new_image(void *m_p, int width, int height);
char	*mlx_get_data_addr(void *img_p, int *bpp_p, int *sl_p, int *bo_p);
void	*mlx_new_window(void *m_p, int size_x, int size_y, char *title);
int		mlx_put_image_to_window(void *m_p, void *win_p, void *img_p);
int		mlx_hook(void *win_p, int event, int mask, int (*func)(), void *param);
int		mlx_loop_hook(void *m_p, int (*func_p)(), void *param);
int		mlx_loop(void *m_p);
int		mlx_destroy_image(void *m_p, void *img_p);
int		mlx_destroy_window(void *m_p, void *win_p);
int		mlx_destroy_display(void *m_p);

#endif