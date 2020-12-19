#!/bin/python3
#coding: UTF-8

import gspread
from oauth2client.service_account import ServiceAccountCredentials

scope = ['https://spreadsheets.google.com/feeds',
         'https://www.googleapis.com/auth/drive']

json_path = '/home/ynakanishi/workspace/lazurite-communication/raspi/config.json'
sheet_name = 'ラズライト 環境センサ ログ'

def writeGoogleSpredSheet(values):
    credentials = ServiceAccountCredentials.from_json_keyfile_name(json_path, scope)
    gc = gspread.authorize(credentials)
    wks = gc.open(sheet_name).sheet1

    wks.append_row(values, value_input_option='USER_ENTERED')
