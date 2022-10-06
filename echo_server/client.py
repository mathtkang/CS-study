import socket
import threading
import sys


def receive(socket: socket.socket, signal):
    while signal:
        try:
            data = socket.recv(32)
            print(str(data.decode("utf-8")))
        except Exception:
            print("You have been disconnected from the server")
            signal = False
            break


# host = input("Host: ")
# port = int(input("Port: "))
host = 'localhost'
port = 2345

try:
    sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    sock.connect((host, port))
except Exception:
    print("Could not make a connection to the server")
    input("Press enter to quit")
    sys.exit(0)

# receiveThread = threading.Thread(target=receive, args=(sock, True))
# receiveThread.start()

# sync 코드로 계속 받고 있으니까
# while True:
#     message = input()
#     sock.sendall(str.encode(message))

sock.sendall(str.encode("message"))


# 실행했을 때 에러!!
# 계속 기다리고 있었으니까
# 데이터를 보냈는데, 데이터를 받을 애가 연결을 끊어버림 -> 그래서 broken pipe에러 발생


data = sock.recv(32)
print(str(data.decode("utf-8")))
