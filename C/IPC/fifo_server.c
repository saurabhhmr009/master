#include "headers.h"

int main(void) {
    char *read_buff = NULL, *write_buff = NULL;
    int fd;

    /*ret = mkfifo(FIFO_PATH, 0666);
    if(ret < 0) {
        perror("mkfifo failed.\n");
        return 1;
    }*/
    read_buff = (char*)malloc(MAX_SIZE*sizeof(char));
    write_buff = (char*)malloc(MAX_SIZE*sizeof(char));

    while(1) {
        fd = open(FIFO_PATH, O_RDONLY);
        read(fd, read_buff, MAX_SIZE);
        printf("Server: %s\n", read_buff);
        close(fd);

        //scanf(" %[^\n]", write_buff);
        fgets(write_buff, MAX_SIZE, stdin);
        fd = open(FIFO_PATH, O_WRONLY);
        write(fd, write_buff, MAX_SIZE);
        close(fd);
    }
    return 0;
}