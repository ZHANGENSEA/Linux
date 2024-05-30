#include <stdio.h>
#include <sys/mman.h>
#include <unistd.h> 
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>



int main(void) {

    u_int32_t *p;
    int fd = open ("/dev/mem",O_RDWR);
    p = (u_int32_t*)mmap(NULL,4, PROT_WRITE|PROT_READ, MAP_SHARED, fd, 0xFF203000);
    *p = (1<<8);
}
    