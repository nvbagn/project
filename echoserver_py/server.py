import socket
import threading

def func():
    while True:
        client_fd, client_addr = server_fd.accept()

        while True:
            print("connection from client %s" % str(client_addr))
            info = client_fd.recv(10)
            if not info:
                break
            print(info.decode("utf-8"))
            
        client_fd.close()
        print("connection from client %s is closed" % str(client_addr))

server_fd = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
server_fd.bind(("0.0.0.0", 8888))
server_fd.listen()

threads = []
for _ in range(3):
    t = threading.Thread(target = func)
    t.start()
    threads.append(t)

# Wait for all threads to finish
for t in threads:
    t.join()

server_fd.close()