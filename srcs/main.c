/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnakahod <jnakahod@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 22:31:05 by jnakahod          #+#    #+#             */
/*   Updated: 2021/06/23 15:07:11 by jnakahod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>
// #include <float.h>

void ft_draw_to_window(t_data *data, void *mlx, void *win)
{
  int x;
  int y;

  y = 0;
  while (y < 180)
  {
    x = 0;
    while (x < 180)
    {
      data->addr[(data->line_len / (data->bits_per_piexel / 8)) * y + x] = data->buf[y][x];
      x++;
    }
    y++;
  }
  mlx_put_image_to_window(mlx, win, data->img, 0, 0);
}

void  set_pixel_mandelbrot(int x, int y, t_data *data)
{
  data->buf[y][x] = 0x00FFFF00;
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

void  calc_mandelbrot(t_data *data)
{
  long double a, b;
  long double i, j;
  long double tmp_i, tmp_j;
  for (int y = 0; y < 180; y++)
  {
    b = (double)y * 3 / 180 - 1.5;
    for(int x = 0; x < 180; x++)
    {
      a = (double)x * 3 / 180 - 1.5;
      i = 0;
      j = 0;
      for (int k = 0; 50 > k; k++)
      {
        tmp_i = i * i - j * j + a; 
        tmp_j = 2 * i * j + b;
        i = tmp_i;
        j = tmp_j;
        if (pow(i, 2) + pow(j, 2) > 4)
        {
          set_pixel_mandelbrot(x, y, data);
          break;
        }
      }
    }
  }
}

int main(int ac, char **av)
{
  void *mlx;
  void *win;
  t_data data;

  mlx = mlx_init();
  win = mlx_new_window(mlx, 180, 180, "fractol");
  data.img = mlx_new_image(mlx, 180, 180);
  data.addr = (int *)mlx_get_data_addr(data.img, &data.bits_per_piexel, &data.line_len, &data.endian);

  calc_mandelbrot(&data);

  ft_draw_to_window(&data, mlx, win);
  mlx_loop(mlx);
  // load_info_from_parameters(ac, av);
  return (0);
}
