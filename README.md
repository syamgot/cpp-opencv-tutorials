# cpp-opencv-tutorials

## インストール

### 本体

```
$ cd /usr/local/src
$ wget https://github.com/opencv/opencv/archive/3.1.0.tar.gz
$ mv 3.1.0.tar.gz opencv-3.1.0.tar.gz
$ tar xzvfp opencv-3.1.0.tar.gz
$ cd opencv-3.1.0
$ sudo cmake -DCMAKE_BUILD_TYPE=Release
$ sudo make && sudo make install
```

### 拡張機能

[https://github.com/opencv/opencv_contrib](https://github.com/opencv/opencv_contrib)

```
$ wget https://github.com/opencv/opencv_contrib/archive/3.1.0.tar.gz
$ mv 3.1.0.tar.gz opencv_contrib-3.1.0.tar.gz
$ cd opencv-3.1.0
$ sudo cmake -DCMAKE_BUILD_TYPE=Release  -DOPENCV_EXTRA_MODULES_PATH=../opencv_contrib-3.1.0/modules ./ 
$ sudo make -j5
$ sudo make install
```

## 一覧

### 編集

- [読み込み](https://github.com/syamgot/cpp-opencv-tutorials/tree/master/read)
- [書き込み](https://github.com/syamgot/cpp-opencv-tutorials/tree/master/write)
- [貼り付け](https://github.com/syamgot/cpp-opencv-tutorials/tree/master/paste)
- [ピクセルの操作](https://github.com/syamgot/cpp-opencv-tutorials/tree/master/access_to_pixel)
- [顔検出](https://github.com/syamgot/cpp-opencv-tutorials/tree/master/face_detect)
- [インペインティング(画像補完)](https://github.com/syamgot/cpp-opencv-tutorials/tree/master/inpaint)
- [マスク処理](https://github.com/syamgot/cpp-opencv-tutorials/tree/master/mask)
- [モザイク処理](https://github.com/syamgot/cpp-opencv-tutorials/tree/master/mosaic)
- [グレースケール変換](https://github.com/syamgot/cpp-opencv-tutorials/tree/master/rgb2gray)
- [2値化](https://github.com/syamgot/cpp-opencv-tutorials/tree/master/threshold)

### GUI

- [トラックバー](https://github.com/syamgot/cpp-opencv-tutorials/tree/master/trackbar)

### 描画

- [線分描画](https://github.com/syamgot/cpp-opencv-tutorials/tree/master/line)

### 動画

- [背景差分(MoG)による移動物体検出](https://github.com/syamgot/cpp-opencv-tutorials/tree/master/bgsub_mog2)
