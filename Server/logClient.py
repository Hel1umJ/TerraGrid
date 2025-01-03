#!/usr/bin/env python3
import paho.mqtt.client as mqtt
import sys

# Broker settings
BROKER_ADDRESS = "localhost"
CLIENT_ID = "AsyncSubscriber"
TOPIC = "test/topic"
QOS = 1

# Callback if the connection is lost or disconnected
def on_disconnect(client, userdata, rc):
    print("[ASYNC] Disconnected from broker with return code:", rc)

# Callback when the client receives a CONNACK response from the broker
def on_connect(client, userdata, flags, rc):
    if rc == 0:
        print(f"[ASYNC] Connected to broker at {BROKER_ADDRESS}")
        # Now subscribe to the topic
        client.subscribe(TOPIC, qos=QOS)
        print(f"[ASYNC] Subscribed to topic: {TOPIC}")
    else:
        print("Failed to connect, return code %d" % rc)

# Callback when a PUBLISH message is received from the broker
def on_message(client, userdata, msg):
    print(f"[ASYNC] Message arrived on topic '{msg.topic}': {msg.payload.decode()}")

# Optionally, callback when a message with QoS>0 is delivered
def on_publish(client, userdata, mid):
    print("[ASYNC] Delivery confirmed for mid:", mid)

def main():
    # Create a new MQTT client instance
    client = mqtt.Client(client_id=CLIENT_ID)

    # Set callbacks
    client.on_connect = on_connect
    client.on_message = on_message
    client.on_disconnect = on_disconnect
    client.on_publish = on_publish

    # Connect to the broker
    try:
        client.connect(BROKER_ADDRESS, 1883, 60)
    except Exception as e:
        print(f"Failed to connect: {e}")
        sys.exit(1)

    print("[ASYNC] Press Ctrl+C to quit...")

    # Start the network loop, which runs in the foreground here.
    # This call will block and automatically handle reconnections, pinging, etc.
    client.loop_forever()

if __name__ == "__main__":
    main()