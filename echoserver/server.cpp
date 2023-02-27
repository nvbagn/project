#include <bits/stdc++.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <pthread.h>

struct sockaddr_in server_addr;
int server_fd;

void *func(void *agrs){
    struct sockaddr_in client_addr;
    memset(&client_addr, 0, sizeof client_addr);
    unsigned int client_addr_len = sizeof client_addr;
    int client_fd = accept(server_fd, (struct sockaddr *)&client_addr, &client_addr_len);

    if (client_fd == -1){
        std::cout << "accept() error" << std::endl;
        exit(0);
    }

    while (true){
        char info[100];
        int info_len = recv(client_fd, info, 100, 0);

        if (!strcmp(info, "q")){
            return 0;
        }

        info[info_len] = 0;
        std::cout << info << std::endl;
    }

    close(client_fd);

    return 0;
}

int main(void){
    memset(&server_addr, 0, sizeof server_addr);
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi("8888"));
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_fd = socket(AF_INET, SOCK_STREAM, 0);

    if (server_fd == -1){
        std::cout << "socket() error" << std::endl;
        exit(0);
    }

    if (bind(server_fd, (struct sockaddr*)&server_addr, sizeof server_addr) == -1){
        std::cout << "bind() error" << std::endl;
        exit(0);
    }

    if (listen(server_fd, 5)){
        std::cout << "listen() error" << std::endl;
        exit(0);
    }
    
    pthread_t tids[10];

    for (int i = 0; i < 10; i++){
        if (pthread_create(&tids[i], NULL, func, NULL)){
            std::cout << "pthread_create() error" << std::endl;
            exit(0);
        }
    }

    pthread_exit(NULL);
    close(server_fd);

    return 0;
}
