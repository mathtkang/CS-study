import socket
import threading
from time import sleep


connections = []  # type: ignore
total_connections = 0


def task():
    # sleep(1)  # 1초 쉬겠다. (db에 쿼리를 보낼 때 1초 걸린다는 생각으로) => 이 경우 비동기 (GIL을 실행시키는)

    # 이 경우 동기적
    a = 0
    for i in range(10000000):  # cpu bound 작업 (싱글프로세스)
        a += i

    # 파이썬: 싱글코어밖에 못 굴린다
    # 쉬게 두면 다른 스레드에게 우선권이 돌아가서 주도권을 넘겨주게 되어, 왔다갔다 하게됨 (그만큼 컨텍스트 스위칭 간격이 높구, cpu를 굴리는 작업을 병렬적으로 할 때는 한개만 굴릴 때보다 못한결과를 가져올 수 있다.) => io바운드(시간을 많이 잡아먹는 작업, http서버, 백엔드 서버)
    # backend server ()


class Client(threading.Thread):
    def __init__(self, socket: socket.socket, address, id, name, signal):
        threading.Thread.__init__(self)
        self.socket = socket
        self.address = address
        self.id = id
        self.name = name
        self.signal = signal

    def __str__(self):
        return str(self.id) + " " + str(self.address)

    def run(self):
        while self.signal:
            try:
                # read from socket buffer (32bit씩), signal이 true면 계속 읽어옴
                data = self.socket.recv(32)
                # 클라이어트가 살아있는지 확인해야함
                # web의 경우 send 1회 후 자동으로 끊어짐(그래서 요 코드가 자동으로 이루어진다) -> 게임, 채팅 서버의 경우 이 코드를 안쓰고 계속 커넥션을 이룬다.
                self.signal = bool(self.socket.send('heartbeat'.encode()))

                if data != b"":  # 버퍼가 비지 않았다면
                    print("ID " + str(self.id) + ": " + "task started")
                    task()
                    print("ID " + str(self.id) + ": " + "task completed")
                    # result = self.socket.send(data)
                    # if result == 0:
                    #     raise Exception()
                    # self.signal = bool(self.socket.send(data))

                    self.socket.send(data)

            except Exception:
                break

        print("Client " + str(self.address) + " has disconnected")
        self.signal = False
        connections.remove(self)
        self.socket.close()


def newConnections(socket: socket.socket):
    while True:
        sock, address = socket.accept()
        global total_connections
        connections.append(
            Client(sock, address, total_connections, "Name", True)
        )
        connections[len(connections) - 1].start()
        print("New connection at ID " + str(connections[len(connections) - 1]))
        total_connections += 1


def main():
    host = input("Host: ")
    port = int(input("Port: "))
    sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    sock.bind((host, port))
    sock.listen(5)

    newConnectionsThread = threading.Thread(
        target=newConnections, args=(sock,)
    )
    newConnectionsThread.start()


if __name__ == "__main__":
    main()
