###### tcp echo server

执行

```
g++ server.cpp -o server -lpthread
g++ client.cpp -o client
```

开一个进程执行

```
./server
```

再开10个以内的进程执行

```
./client
```

此时在每个client窗口中输入的字符串都会在server窗口中出现

输入字符q退出程序