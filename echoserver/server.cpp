#include <bits/stdc++.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

int main(void){
    struct sockaddr_in server_addr, client_addr;

    memset(&server_addr, 0, sizeof server_addr);
    memset(&client_addr, 0, sizeof client_addr);
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi("8888"));
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);

    int server_fd = socket(AF_INET, SOCK_STREAM, 0);

    if (server_fd == -1){
        std::cout << "socket() error" << std::endl;
        return 0;
    }

    if (bind(server_fd, (struct sockaddr*)&server_addr, sizeof server_addr) == -1){
        std::cout << "bind() error" << std::endl;
        return 0;
    }

    if (listen(server_fd, 5)){
        std::cout << "listen() error" << std::endl;
        return 0;
    }
    
    unsigned int client_addr_len = sizeof client_addr;
    int client_fd = accept(server_fd, (struct sockaddr *)&client_addr, &client_addr_len);

    if (client_fd == -1){
        std::cout << "accept() error" << std::endl;
        return 0;
    }

    while (true){
        char info[100];
        int info_len = recv(client_fd, info, 100, 0);
        if (!strcmp(info, "q")){
            break;
        }
        info[info_len] = 0;
        std::cout << info << std::endl;
    }

    close(server_fd);
    close(client_fd);

    return 0;
}
