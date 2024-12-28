#include "g711.h"
#include <stdio.h>

int main(int argc, char** argv) {
    
    short linbuf[2] = {0, -1}; 
    short logbuf[2]; 
    long lseg = 2;

    if (argv[1][1] == 'u') {
        printf("\tMu-law Output\n");
        ulaw_compress(lseg , linbuf, logbuf);
    } else if (argv[1][1] == 'a') {
        printf("\tA-law Output\n");
        alaw_compress(lseg , linbuf, logbuf);
    }

    printf("%d => %d or %x\n", linbuf[0], logbuf[0], logbuf[0]);
    printf("%d => %d or %x\n", linbuf[1], logbuf[1], logbuf[1]);

    return 0;
}
