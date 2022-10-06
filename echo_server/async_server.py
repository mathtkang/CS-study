

import socket
import asyncio


total_conections = 0


async def async_task():
    await asyncio.sleep(1)


async def handle_asyncclient(
    reader: asyncio.StreamReader,
    writer: asyncio.StreamWriter,
):
    # reader: socket 과 비슷,
    global total_conections
    total_conections += 1
    print('client :', writer.get_extra_info('peername'))
    while True:
        data = await reader.read(32)
        if data != b'':
            writer.write(data)
            await writer.drain()
            print(f'{total_conections}: {data.decode()}')
        else:
            break


# Thread와 비슷하게 동작하나,
# 같은 stack을 공유하고 있기에 thread보다 context swiching 비용이 낮다
async def server_asyncmain():
    server = await asyncio.start_server(handle_asyncclient, 'localhost', 2345)
    if server is not None:
        print('server started')
        # Task == Coroutine == Future
        await asyncio.sleep(60)
        server.close()
        await server.wait_closed()
        print('server was closed')


if __name__ == "__main__":
    try:
        loop = asyncio.get_running_loop()
    except RuntimeError:
        loop = None  # type: ignore

    if loop and loop.is_running():
        print('Async event loop already running')
        tsk = loop.create_task(server_asyncmain())
    else:
        print('Starting new event loop')
        asyncio.run(server_asyncmain())


# async server: stateless한 서버에 많이 사용됨
# stateful server -> connection: read ready, write ready, pending, closed
# TCP server -> Game server, Websocket server, Chatting server

# stateless server -> connection: ready, pending, closed
# HTTP Server
