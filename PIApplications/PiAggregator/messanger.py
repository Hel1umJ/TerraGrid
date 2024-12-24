import paho.mqtt.client as mqtt

# to see users and permissions sudo nano /etc/mosquitto/acl_file
class Messanger:





    def __init__(self, broker_address, broker_port, username, password, topic):
        self.broker_address = broker_address
        self.broker_port = broker_port
        self.username = username
        self.password = password
        self.topic = topic

        # Create MQTT client instance
        self.client = mqtt.Client()


        self.client.username_pw_set(username, password)

        # Assign the on_connect callback
        self.client.on_connect = self.on_connect

        # Connect to the broker
        print(f"Connecting to broker {broker_address}:{broker_port}...")
        self.client.connect(broker_address, broker_port, 60)



    def on_connect(client, userdata, flags, rc):
        """Callback for when the client connects to the broker."""
        if rc == 0:
            print("Connected to broker")
        else:
            print(f"Connection failed with code {rc}")



    def disconnect_client(self):
        # Disconnect from the broker
        self.client.disconnect()
        print("Disconnected from broker")

    def publish_message(self, message):
        # Publish a message
        print(f"Publishing message to topic '{self.topic}': {message}")
        self.client.publish(self.topic, message)


