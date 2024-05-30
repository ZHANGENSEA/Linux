#include <stdio.h>
#include <unistd.h> 
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>

#define NUM_LEDS 9

char path[] = "/sys/class/leds/fpga_led5/brightness";

int main(void) {

    int etat[10];

        for (int i = 0; i <= NUM_LEDS; i++) {
            sprintf(path, "/sys/class/leds/fpga_led%d/brightness",i);
            etat[i] = open (path,O_RDWR);
        }

     while (1) { 
        for(int i = 0; i <= NUM_LEDS; i++){
            write(etat[i], "1", 1);
            usleep(200000);
            write(etat[i], "0", 1);
        }
    }

    for(int i = 0; i <= NUM_LEDS; i++){
        close(etat[i]);
    }

}
