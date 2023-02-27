import socket
import threading

def func():
    client_fd, client_addr = server_fd.accept()

    while True:
        info = client_fd.recv(10)
        if not info:
            break
        print(info.decode("utf-8"))
    
    client_fd.close()

server_fd = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
server_fd.bind(("0.0.0.0", 8888))
server_fd.listen()

for _ in range(10):
    threading.Thread(target = func).start()

server_fd.close()