import random
import urllib.request
import requests
import threading


def thingspeak_post():
    threading.Timer(15,thingspeak_post).start()
    val=random.randint(2,30)
    URL='https://api.thingspeak.com/update?api_key='
    KEY='9JXPFJXBOA78VIV6'
    HEADER='&field1={}'.format(val)
    NEW_URL=URL+KEY+HEADER
    print(NEW_URL)
    data=urllib.request.urlopen(NEW_URL)
    print(data)

if __name__=='__main__':
    thingspeak_post()
