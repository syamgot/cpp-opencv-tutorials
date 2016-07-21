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

## Xcodeのセッティング

- ターゲットを選択してBuild Settingタブを選択する。
- "Header Search Paths"で検索して"/usr/local/include"を追加する。
- "Library Search Paths"で検索して"/usr/local/lib"を追加する。
- Build Phasesタブを選択する。
- Link Binary With Librariesを開いて必要なdylibを追加する。
- +で選択ウィンドウを開き、Add Othersをクリックする。
- ⌘+Gで"/usr/local/lib"へ移動する。
- 必要なdylibを追加する。

