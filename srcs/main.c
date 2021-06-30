/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnakahod <jnakahod@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 22:31:05 by jnakahod          #+#    #+#             */
/*   Updated: 2021/06/30 08:03:49 by jnakahod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

void ft_draw_to_window(t_all *all, t_data *data)
{
    int x;
    int y;

    y = 0;
    while (y < 180)
    {
        x = 0;
        while (x < 180)
        {
            data->addr[(data->size_l / (data->bpp / 8)) * y + x] = all->buf[y][x];
            x++;
        }
        y++;
    }
    mlx_put_image_to_window(all->mlx, all->win, data->img, 0, 0);
}

void set_pixel_mandelbrot(int x, int y, t_all *all)
{
    all->buf[y][x] = 0x00FFFF00;
}

// for (i = 0; pixel > i; i++) {            // x（実部）方向のループ
//     x = i * size / pixel - size / 2;     // 定数Cの実部
//     for (j = 0; pixel > j; j++) {        // y（虚部）方向のループ
//         y = j * size / pixel - size / 2; // 定数Cの虚部
//         a = 0;                           // くり返し計算に使う複素数zの実部
//         b = 0;                           // くり返し計算に使う複素数zの虚部
//         for (k = 0; 50 > k; k++) {       // 上限を50回とするくり返し計算
//             _a = a * a - b * b + x;      // z^2+Cの計算（実部）
//             _b = 2 * a * b + y;          // z^2+Cの計算（虚部）
//             a = _a;                      // zの値を更新（実部）
//             b = _b;                      // zの値を更新（虚部）
//             if (a * a + b * b > 4) {     // もし絶対値が2を（絶対値の2乗が4を）超えていたら
//                 draw(i, j);              // (i,j)の位置のピクセルを「マンデルブロ集合でない色」で塗りつぶして
//                 break;                   // 次の点の計算へ
//             }
//         }
//     }
// }

void calc_mandelbrot(t_all *all)
{
    double a, b;
    double i, j;
    double tmp_i, tmp_j;
    for (int y = 0; y < 180; y++)
    {
        b = (double)y * (all->end_im - all->start_im) / all->win_size + all->start_im;
        for (int x = 0; x < 180; x++)
        {
            a = (double)x * (all->end_re - all->start_re) / all->win_size + all->start_re;
            i = 0;
            j = 0;
            for (int k = 0; 60 > k; k++)
            {
                tmp_i = i * i - j * j + a;
                tmp_j = 2 * i * j + b;
                i = tmp_i;
                j = tmp_j;
                if (abs(i + j) > 2)
                {
                    set_pixel_mandelbrot(x, y, all);
                    break;
                }
                else if (k == 59)
                    all->buf[y][x] = 0x00000000;
            }
        }
    }
}

int    ft_main_loop(t_all *all)
{
    //calc
    calc_mandelbrot(all);
    //draw
    ft_draw_to_window(all, &all->data);
}

int main(int ac, char **av)
{
    t_all all;

    ft_init(&all);
    // all.mlx = mlx_init();
    // all.win = mlx_new_window(all.mlx, 180, 180, "fractol");
    // all.data.img = mlx_new_image(all.mlx, 180, 180);
    // all.data.addr = (int *)mlx_get_data_addr(all.data.img, &all.data.bpp, &all.data.size_l, &all.data.endian);

    all.coordinate_len = 3.0;
    all.win_size  = 180;
    
    errno = 0;
    mlx_loop_hook(all.mlx, &ft_main_loop, &all);

    mlx_hook(all.win, KEYPRESS, KEYPRESSMASK, &ft_key_press, &all);
    mlx_hook(all.win, BUTTONPRESS, BUTTONPRESSMASK, &ft_zoom_on, &all);
    // mlx_mouse_show(all.mlx, all.win);
    // mlx_mouse_move(all.mlx, all.win, 20, 20);
    mlx_loop(all.mlx);
    // load_info_from_parameters(ac, av);
    return (0);
}
