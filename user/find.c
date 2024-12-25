

void find(char *path, char *target) {
    char buf[512], *p;
    int fd;            // file descriptor 文件描述符
    struct dirent de;  // directory entry 目录项
    struct stat st;    // file status 文件状态

    if(fd = open(path, 0) < 0) {
        fprintf(2, "");
        return;


    }

    if(fstat(fd, &st) < 0) {
        close(fd);
        return;
    }

    switch(st.type) {
        case T_FILE:
            break;
        case T_DIR:
            break;  
    }

    close(fd);
}

int main(int argCount, char *argVector) {

}
