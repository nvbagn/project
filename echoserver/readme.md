###### tcp echo server

执行

```
g++ server.cpp -o server
g++ client.cpp -o client
```

开两个进程分别运行

```
./server
./client
```

此时在client窗口中输入的字符串会在server窗口中出现

输入字符q退出程序