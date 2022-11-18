import asyncio
import socket


async def handle_client(client: socket.socket):
    loop = asyncio.get_event_loop()
    request = None
    while request != 'quit\n':
        # sock_recv: 내가 받을 수 있는 포트 별 다르게 받음
        request = (await loop.sock_recv(client, 255)).decode('utf8')
        print(str(client.getpeername()), request)  # getpeername: 시작포트를 알려줌
        # 클라로 리퀘스트 받은 것 다 보내줌
        await loop.sock_sendall(client, request.encode('utf8'))
    client.close()


async def run_server():
    server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    server.bind(('localhost', 2345))
    server.listen(8)
    server.setblocking(False)  # Non-blocking  (나중 네트워크 배울 때)

    loop = asyncio.get_event_loop()  # 이벤트루프(만약 없다면 생성을 해서 줌)

    while loop.is_running():
        client, _ = await loop.sock_accept(server)
        loop.create_task(handle_client(client))  # tcp 커넥션이 되면

asyncio.run(run_server())
