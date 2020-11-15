## デバイス
rasberry pi 3B+

## 環境構築
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

## 参考サイト
- [Lazurite Linuxライブラリ用日本語リファレンス](https://www.lapis-tech.com/lazurite-jp/contents/gateway/reference/default.html)
- [LAPIS-Lazurite/PyLaz](https://github.com/LAPIS-Lazurite/PyLaz)
