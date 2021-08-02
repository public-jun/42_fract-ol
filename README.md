# 42_fract-ol
フラクタル集合をウィンドウに描画するプログラム

## 実行環境
Ubuntu 18.04.5 LTS (Bionic Beaver)

gcc (Ubuntu 7.5.0-3ubuntu1~18.04) 7.5.0

## 使い方
```bash
$ git clone https://github.com/public-jun/42_fract-ol.git
$ make
$ ./fractol [fractol name] [type] [real number] [imaginary number]
```
ex

```bash
$ ./fractol julia dynamic
```
![julia](https://user-images.githubusercontent.com/60804160/127802780-3e54e6fd-44ec-4ceb-8b9e-02b15b7647cc.gif)

```bash
$ ./fractol mandelbrot dynamic
```
![mandelbrot](https://user-images.githubusercontent.com/60804160/127803082-8c975168-4ee9-49ea-abda-9a1b1a58b3bb.gif)
