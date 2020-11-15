## 概要
switch sienceの環境センサ基板とlazurite gateway(rasberry pi)で通信し
環境センサ基板で得たセンサーの値をslackに流す

## デバイス
- 環境センサ基板
- rasberry pi 3B+

## 環境構築
### 環境センサ基板
subGHzの時と同じ(host addressだけ変更)

### rasberry pi
rasberry pi osを書き込み、sshで接続できるようにした。

rootディレクトリにインストーラをクローン
```bash
git clone git://github.com/LAPIS-Lazurite/LazuriteInstaller
```

セットアップ
```bash
cd LazuriteInstaller
./setup.sh
```

セットアップが終わったら再起動
```bash
sudo reboot
```

インストール
```bash
cd LazuriteInstaller
./install.sh
```

## データを受信する
作業用ディレクトリを作成し、Pythonのサンプルをクローン
```bash
mkdir workspace
cd worksace
git clone https://github.com/LAPIS-Lazurite/PyLaz.git
```

サンプルを実行する。
```bash
cd workspace/PyLaz
python3 sample/rxsample.py
```

※2回目以降の実行でカーネル関連のエラーが出るが無視しても動く。

## slackに投稿
webhookを使ってslackに投稿する。
- https://qiita.com/shtnkgm/items/4f0e4dcbb9eb52fdf316

webhook URLは環境変数に設定する
.bashrcに以下を追記
```bash
## slack webhook
export SLACK_WEBHOOK="https://hooks.slack.com/services/xxxXXXXXXXX/XXXXXXXXXXX/XXXXXXXXXXXXXXXXXXXXXXXX"
```

webhookのテストは以下を走らせればできます。
```bash
python3 slack_notify.py
```

データを受け取ってslackに流すのは以下のスクリプト
```bash
python3 main.py
```

## rasberry pi で起動時に自動的に実行する
systemdを使う
- https://www.raspberrypirulo.net/entry/systemd

/lib/systemd/system/laz-com.serviceを作成

service用に環境変数を設定する
/etc/sysconfig/slack_webhookを作成
``` 
SLACK_WEBHOOK="https://hooks.slack.com/services/xxxXXXXXXXX/XXXXXXXXXXX/XXXXXXXXXXXXXXXXXXXXXXXX"
```
/etc/systemd/system/laz-com.serviceを作成する。
```laz-com.service
[Unit]
Description = lazurite-communication

[Service]
EnvironmentFile=/etc/sysconfig/slack_webhook
ExecStart=/usr/bin/python3 home/pi/workspace/lazurite-communication/raspi/main.py
Restart=always
Type=simple

[Install]
WantedBy=multi-user.target
```

デーモンをリロードしてサービスを開始、ステータスで特にエラーが出ずに実行できればok
```bash
sudo systemd daemon-reload
sudo systemd start laz-com.service
systemd status laz-com.service
```

自動起動を有効にする。
```bash
sudo systemctl enable test.service
```

以上で、電源投入時に自動でスクリプトが走り、slackに通知が飛ぶ。

## 参考サイト
- [Lazurite Linuxライブラリ用日本語リファレンス](https://www.lapis-tech.com/lazurite-jp/contents/gateway/reference/default.html)
- [LAPIS-Lazurite/PyLaz](https://github.com/LAPIS-Lazurite/PyLaz)
