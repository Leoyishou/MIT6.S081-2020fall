#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int main(int argc, char *argv[]) {
    int p1[2], p2[2]; // 两个管道，每个管道有两个文件描述符/两个端点
    pipe(p1); // 创建管道
    pipe(p2); // 创建管道

    if(fork() == 0) {
        // 子进程
        close(p1[1]); // 1代表写
        close(p2[0]); // 0代表读

        char buf[20];
        read(p1[0], buf, 20);
        printf("%d: received ping from father\n", getpid());
        write(p2[1], "hi, father", 20);

    } else {
        // 父进程
        close(p1[0]);    // 关闭第一个管道的读取端
        close(p2[1]);    // 关闭第二个管道的写入端
    
        write(p1[1], "hi, son", 20);

        char buf[20];
        read(p2[0], buf, 20);
        printf("%d: received pong from son\n", getpid());
    }
    exit(0);
}
