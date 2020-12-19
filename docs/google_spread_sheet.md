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
pip3 install gspread
pip3 install oauth2client
```

## 参考サイト
[PythonでGoogleスプレッドシートを編集](https://qiita.com/akabei/items/0eac37cb852ad476c6b9)

