import asyncio
import websockets


async def hello():
    async with websockets.connect("ws://10.42.0.1:8765") as websocket:
        await websocket.send("Save me")
        message = await websocket.recv()
        print (f"recieved: {message}")


asyncio.run(hello())