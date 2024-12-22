// 定义了基本数据类型，比如:uint (无符号整型)uint64 (64位无符号整型)uchar (无符号字符) 这些是系统编程常用的类型定义
#include "kernel/types.h"
// 定义了文件系统相关的结构体和常量, 包含文件状态信息(比如文件大小、创建时间等), 虽然在 sleep 程序中没有直接使用，但这是 xv6 用户程序的标准包含文件
#include "kernel/stat.h" 
//定义了用户程序可以使用的系统调用接口, 包含了 sleep、fork、exit 等函数的声明
#include "user/user.h" 

int main(int argc, char *argv[]) {
    // argc 表示命令行参数的个数，比如 sleep 100 那么 argc 就是 2
    if(argc != 2) {
        fprintf(2, "Usage: sleep fucking ticks\n");
        // 异常退出
        exit(1);
    }
    int ticks = atoi(argv[1]);
    sleep(ticks);
    // 正常退出
    exit(0);
}