from messanger import Messanger
from listener import Listener
import json


"""
payload format
{
    moduleID:,
    temp:,
    humidity:,
    soilMoisture:,
    isLit:,
    hoursSinceLastWater:
}
"""
# Callback function when a message is received from the broker
def on_message(self, client, userdata, msg):
    """Callback for when a message is received."""
    print(f"Received message: {msg.payload.decode()} on topic: {msg.topic}")

# connect listener to broker
messanger = Messanger('192.168.87.51', 1883, 'test', 'test', 'Home/sensor_data')
listener = Listener('192.168.87.51', 1883, 'test', 'test', 'modules/1')
listener.on_message = on_message



def main():
    sample_data = {
        "moduleID": '1',
        "temp": "",
        "humidity": "",
        "soilMoisture": "",
        "isLit": "",
        "hoursSinceLastWater": ""
    }
    

    # send data
    messanger.publish_message(json.dumps(sample_data))
    listener.connect()

main()