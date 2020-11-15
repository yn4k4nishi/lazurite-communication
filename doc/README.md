## slack
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

自動起動を有効にする。
```bash
sudo systemctl enable test.service
```
