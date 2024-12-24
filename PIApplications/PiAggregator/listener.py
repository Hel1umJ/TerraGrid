import paho.mqtt.client as mqtt

class Listener:


    def __init__(self, broker_address, broker_port, username, password, topic):
        self.broker_address = broker_address
        self.broker_port = broker_port
        self.username = username
        self.password = password
        self.topic = topic


                # Create MQTT client instance
        client = mqtt.Client()

        # Set username and password
        client.username_pw_set(username, password)

        # Assign the on_connect and on_message callbacks
        client.on_connect = self.on_connect
        client.on_message = self.on_message

        # Connect to the broker
        print(f"Connecting to broker {broker_address}:{broker_port}...")
        client.connect(broker_address, broker_port, 60)

        # Start the loop to listen for messages
        client.loop_forever()

    # Callback function when the client connects to the broker
    def on_connect(self, client, userdata, flags, rc):
        """Callback for when the client connects to the broker."""
        if rc == 0:
            print("Connected to broker")
            # Subscribe to the topic after connection
            client.subscribe(self.topic)
        else:
            print(f"Failed to connect, return code {rc}")

    # Callback function when a message is received from the broker
    def on_message(self, client, userdata, msg):
        """Callback for when a message is received."""
        print(f"Received message: {msg.payload.decode()} on topic: {msg.topic}")


