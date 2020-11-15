#!/bin/python3
#coding: UTF-8

import os
import slackweb
import datetime

def notify(msg):
    slack = slackweb.Slack(os.environ["SLACK_WEBHOOK"])
    slack.notify(text=msg)

if __name__ == '__main__':
    notify("pythonからslackへ投稿テスト" + datetime.datetime.today().strftime('(%Y-%m-%d %H:%M:%S)'))
