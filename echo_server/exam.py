import socket
import asyncio


connections: list[socket.socket] = []
total_connections = 0


async def async_task():
    asyncio.sleep(1)


async def client_handler(
    socket: socket.socket,
    address: str,
    id: int,
    signal: bool,
) -> None:
    while signal:
        try:
            signal = bool(socket.send('heartbeat'.encode()))
            data = socket.recv(32)  # read from socket buffer

            if data != b"":
                print("ID " + str(id) + ": " + "task started")
                await async_task()  # long task
                print("ID " + str(id) + ": " + "task completed")
                socket.send(data)

        except Exception:
            break

    print("Client " + str(address) + " has disconnected")
    signal = False
    connections.remove(socket)
    socket.close()


async def newConnections(socket: socket.socket):
    while True:
        sock, address = socket.accept()
        global total_connections
        connections.append(sock)
        print("New connection at ID " + str(connections[len(connections) - 1]))
        await client_handler(sock, address, total_connections, True)
        total_connections += 1


async def main():
    sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    sock.bind(('localhost', 2345))
    sock.listen(5)

    await newConnections(sock)


if __name__ == "__main__":
    asyncio.run(main())
