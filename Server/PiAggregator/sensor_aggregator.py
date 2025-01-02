from listener import Listener
from messanger import Messanger
import pandas as pd
import json

# connect listener to broker
# messanger = Messanger('192.168.87.51', 1883, 'test', 'test', 'modules/1')
listener = Listener('192.168.87.51', 1883, 'test', 'test', 'Home/sensor_data')


def main():
    listener = Listener('192.168.87.51', 1883, 'test', 'test', 'Home/sensor_data')
    listener.client.on_message = handle_message
    listener.connect()




def handle_message(client, userdata, msg):
    message = msg.payload.decode()
    if (message != None):
        message_json = json.loads(message)
        print(message_json)
        # if ("moduleID" in message_json):
        #     match message_json['moduleID']:
        #         case '1': 
        #             print('here')
        #         case _:
        #             print('pass')
        data_response(message_json)



def data_response(data):
    if ("moduleID" in data):
        # process data

        topic = f'modules/{data["moduleID"]}'
        print(topic)
        messanger = Messanger('192.168.87.51', 1883, 'test', 'test', topic)
        messanger.publish_message("response")
        messanger.disconnect_client()


        
    




main()