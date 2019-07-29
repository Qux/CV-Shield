# CV-Shield
QuxのシンセサイザーのためのCV信号を、Arduinoの `analogWrite` 関数で生成できるようにした上で、オーディオジャックから出力できるようにするためのシールド用のライブラリです。

## Installing
ダウンロードもしくは`clone`した後、Arduinoの`myApps/libraries`フォルダに入れてください。

## Usage
### CV出力
CV出力をするためには、少しのセットアップが必要です。セットアップ自体は`setup()`関数内で一つ関数を呼ぶだけのシンプルな設定なのですが、CV信号をいくつ出力したいかによって、`setup()`内で呼ぶ関数が変わります。出力数は2,4,6つのいづれかから選ぶことが可能です。

- 2つ使う場合 : `setup2CVs()` -> D3,D13ピンがCV対応になります。
- 4つ使う場合 : `setup4CVs()` -> D9,D10ピンがCV対応になります。
- 6つ使う場合 : `setup6CVs()` -> D5,D6ピンがCV対応になります。（注意あり）

'setup()'内でいづれかの関数を呼びだせば、あとは'loop()'内などお好きなところでいつものように`analogWrite()`してください。

#### 注意
CVを5つ以上使う場合は、`delay()`や`mills()`, `Metro`などの挙動が変化します。
なお、その場合にも使えるオリジナルの代替関数として、以下の関数を用意しました。
- `QuxCV::wait(unsigned long msec)` -> `delay()`の代替。
- `QuxCV::msec()` -> `millis()`の代替
- `QuxCV::Metro()``Metro()`の代替

### 音声入力
Arduino Unoで音声入力をしても何がしきれるかは我々にとっても未知数なのですが、`setupAnalogRead()`関数を呼ぶことでanalogReadが高速化し、最大40kHz程度でサンプリングが可能になります。また、引数に`true`を与えるとサンプリングレートが最大80kHzにまで拡張できますが、精度が落ちる可能性もあります。

## Examples
ライブラリをインストール後、Arduino IDE内の`Files/Eaxmples/Qux CV Shield Library`から参照可能です。


## Licence
[MIT](https://github.com/Qux/CV-Shield/blob/master/LICENSE)

## Author
[Qux](https://blog.qux-jp.com)