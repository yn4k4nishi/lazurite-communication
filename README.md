# lazurite-communication
920jに繋がった環境センサ基板からデータをとり、Sub-GHzに送信しPCにシリアル通信で値を送信。

## 環境
- [Lazurite Sub-GHz](https://www.switch-science.com/catalog/2959/)
  - PC(Windows10)とUSB接続する
- [Lazurite 920J(Lazurite Miniシリーズ)](https://www.switch-science.com/catalog/2955/)
  - [Lazurite mini用環境センサ基板](https://www.switch-science.com/catalog/3128/)に接続
  
## プログラム
- 920jに[examples/07.SwitchScience/EnvShield_subghz/](https://github.com/LAPIS-Lazurite/LazuriteIDE_0.10.x/blob/release-Mar2020/examples/07.SwitchScience/EnvShield_subghz/EnvShield_subghz.c)を書き込む
- Sub-GHzにreceiver.cを書き込む

## シリアル通信
![serial_monitor](https://user-images.githubusercontent.com/45725019/97701158-4e1e1680-1af0-11eb-9b71-5a77be0029f3.png)

