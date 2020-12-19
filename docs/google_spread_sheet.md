## 手順
### スプレッドシートの作成
[PythonでGoogleスプレッドシートを編集](https://qiita.com/akabei/items/0eac37cb852ad476c6b9)
上の記事を参考に
- サービスアカウントキー取得
    - プロジェクト作成
    - Google Drive API を有効
    - Google Spread Sheet API を有効 
    - サービスアカウントキー作成
- スプレッドシート共有

までを行う。
ここで、生成されたjsonファイルは公開しないように

### パッケージのインストール
```bash
sudo apt install python3-pip
sudo pip3 install gspread oauth2client
```

### 設定
raspi/write_gspread.pyの10行目付近の2つの変数を変更する
- `json_path`は「サービースアカウントキー作成」時に生成したjsonファイルの絶対パス
- `sheet_name`は作成したスプレッドシートの名前

```python
json_path = '/home/pi/workspace/lazurite-communication/raspi/config.json'
sheet_name = 'ラズライト 環境センサ ログ'
```

## 参考サイト
[PythonでGoogleスプレッドシートを編集](https://qiita.com/akabei/items/0eac37cb852ad476c6b9)

