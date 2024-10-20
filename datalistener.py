import asyncio
import websockets

import websockets
# in seconds
WATER_FREQUENCY = 259200
DESIRED_MOISTURE = 600
MOISTURE_THRESHOLD = 90



CONTROL_URI = "localhost"

async def echo(websocket):
    async for message in websocket:
        await websocket.send(message)
        handle_message(message)

async def main():
    print("test")
    async with websockets.serve(echo, "10.42.0.1", 8765):
        await asyncio.get_running_loop().create_future()  # run forever


def handle_message(message):

    print(message)



# {
#   temperature
    # moisture
    # humidity
    # time_since_water
#}


def data_control_response(data):
    if (data.time_since_water >  WATER_FREQUENCY or data.moisture / DESIRED_MOISTURE < MOISTURE_THRESHOLD):
        water_duration = 500
        send_message(send_message(CONTROL_URI, {"request": "water", "enabled": 1}))






async def send_message(uri, message):
    async with websockets.connect(uri) as websocket:
        await websocket.send(message)
        print(f"Sent: {message}")


asyncio.run(main())
