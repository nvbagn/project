import socket

fd = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
fd.connect(("127.0.0.1", 8888))

while True:
    s = input()
    if not s:
        break
    fd.sendall(s.encode("utf-8"))

fd.close()