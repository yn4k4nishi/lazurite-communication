from PyLaz.PyLaz import *
import signal
import os
import time
import csv
import datetime

import slack_notify

# log file path
file_path = "log.csv"

global cont
def receive_signal(signum,stack):
    global cont
    print("SIGINT")
    cont = False

cont = True

signal.signal(signal.SIGINT,receive_signal)

lazurite = PyLaz()

result = lazurite.init()
result = lazurite.begin(36,0xabcd,100,20)

result = lazurite.rxEnable()

print("--- start loop ---")
while cont:
    result = lazurite.available()
    if result > 0:
        payload = lazurite.read()['payload'].decode()

        date = datetime.datetime.today().strftime('%Y-%m-%d %H:%M:%S') 
        temp_act = payload.split(',')[0]
        press_act = payload.split(',')[1]
        hum_act = payload.split(',')[2]
        
        msg = date + " : " + temp_act + "[degree]\t" + press_act + "[hPa]\t" + hum_act + "[%]" 
        
        print(msg)
        slack_notify.notify(msg)

        # write CSV
        with open(file_path, 'a') as f:
            writer = csv.writer(f)
            writer.writerow([date,temp_act, press_act, hum_act])

    time.sleep(1)


result = lazurite.rxDisable()
result = lazurite.close()

print("end")
