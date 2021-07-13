import paho.mqtt.client as mqtt
import time


def on_connect(client,userdata,flags,rc):
    if(rc==0):#rc=0 marks a connection successful of the client with the broker
        client.connect_flag=True # set flag
        print("connected ok")
    else:
        print("not connected returned code= ",rc)

def on_message(client,userdata,message):
    print("the topic of message is",message.topic)
    if(str(message.topic) != pubtop):
        print(str(message.topic),str(message.payload.decode('utf-8')))


def on_subscribe(client,userdata,mid,granted_qos):
    print("subscribed",str(mid),str(granted_qos))

def on_unsubscribe(client,userdata,mid,granted_qos):
    print("un-subscribed",str(mid))

def on_disconnect(client,userdata,rc):
    if(rc!=0):
        print("unexpected disconnection")

broker_addr="broker.hivemq.com"
port=1883

client=mqtt.Client()
client.on_subscribe=on_subscribe
client.on_unsubscribe=on_unsubscribe
client.on_connect=on_connect
client.on_message=on_message
client.connect(broker_addr,port)

pubtop=input("Topic to be published:")
subtop=input("Topic to be subscribed:")
client.loop_start()
client.subscribe(subtop)

while(1):
    chat=input()
    if(chat=="quit"):
        break
    elif(chat=="subscribe"):
        new_subtop=input("Subscribe to topic:")
        client.subscribe(new_subtop)
    elif(chat=="unsubscribe"):
        unsubtop=input("unsubscribe the topic")
        client.unsubscribe(unsubtop)
    elif(chat=="publish"):
        pubtop=input("publish the topic")
    else:
        client.publish(pubtop,chat)
    client.disconnect()
    client.loop_stop()
