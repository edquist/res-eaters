#include <stdio.h>       // printf, perror
#include <stdlib.h>      // atol
#include <string.h>      // memset
#include <sys/select.h>  // select

int main(int argc, char **argv)
{
    size_t bufsz;
    char *buf;

    if (argc != 2 || (bufsz = atol(argv[1]) * 1024 * 1024) <= 0) {
        printf("usage: %s MEM_IN_MB\n", argv[0]);
        return 0;
    }
    
    buf = malloc(bufsz);
    if (!buf) {
        perror("malloc");
        return 1;
    }

    memset(buf, 0, bufsz);  // zero allocated memory

    select(0, NULL, NULL, NULL, NULL);  // sleep 4eva

    return 0;
}

