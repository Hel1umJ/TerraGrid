#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "MQTTClient.h"

/* Define broker settings */
#define ADDRESS     "tcp://localhost:1883"
#define CLIENTID    "AsyncSubscriber"
#define TOPIC       "test/topic"
#define QOS         1

/* Callback if the connection is lost unexpectedly */
void connectionLost(void* context, char* cause)
{
    printf("[ASYNC] Connection lost: %s\n", cause);
}

/* Callback when a subscribed message arrives */
int messageArrived(void* context, char* topicName, int topicLen, MQTTClient_message* message)
{
    /* Print the payload as a string */
    printf("[ASYNC] Message arrived on topic '%s': %.*s\n",
           topicName,
           message->payloadlen,
           (char*)message->payload);

    /* Free the message and the topic name memory allocated by the library */
    MQTTClient_freeMessage(&message);
    MQTTClient_free(topicName);

    /* Return 1 to indicate that the message has been fully processed */
    return 1;
}

/* Callback when a message published with QoS>0 is delivered */
void deliveryComplete(void* context, MQTTClient_deliveryToken dt)
{
    printf("[ASYNC] Delivery confirmed for token %d\n", dt);
}

int main(int argc, char* argv[])
{
    MQTTClient client;
    MQTTClient_connectOptions conn_opts = MQTTClient_connectOptions_initializer;
    int rc;

    /* 1) Create the asynchronous client */
    rc = MQTTClient_create(&client, ADDRESS, CLIENTID,
                           MQTTCLIENT_PERSISTENCE_NONE, NULL);
    if (rc != MQTTCLIENT_SUCCESS)
    {
        printf("Failed to create client, return code %d\n", rc);
        return EXIT_FAILURE;
    }

    /* 2) Set callbacks: connection lost, message arrived, delivery complete */
    MQTTClient_setCallbacks(client, NULL, connectionLost, messageArrived, deliveryComplete);

    /* 3) Connect to the broker */
    conn_opts.keepAliveInterval = 20;
    conn_opts.cleansession = 1;
    rc = MQTTClient_connect(client, &conn_opts);
    if (rc != MQTTCLIENT_SUCCESS)
    {
        printf("Failed to connect, return code %d\n", rc);
        return EXIT_FAILURE;
    }
    printf("[ASYNC] Connected to broker at %s\n", ADDRESS);

    /* 4) Subscribe to a topic */
    rc = MQTTClient_subscribe(client, TOPIC, QOS);
    if (rc != MQTTCLIENT_SUCCESS)
    {
        printf("Failed to subscribe, return code %d\n", rc);
        return EXIT_FAILURE;
    }
    printf("[ASYNC] Subscribed to topic: %s\n", TOPIC);

    /* 5) Let the main thread continue. The library handles incoming messages
          in a background thread and invokes the callbacks automatically.
          For demo, we just wait until the user presses Enter to exit. */
    printf("[ASYNC] Press Enter to quit...\n");
    getchar();

    /* 6) Disconnect and cleanup */
    MQTTClient_disconnect(client, 10000);
    MQTTClient_destroy(&client);

    return EXIT_SUCCESS;
}