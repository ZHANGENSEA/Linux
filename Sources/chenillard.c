#include <stdio.h>
#include <unistd.h> // For sleep()

#define NUM_LEDS 9

int main() {
    int position = 0; // Current position of the "on" LED

    while (1) { // Infinite loop to keep the effect running
        // Clear the screen (system-dependent, here for Unix-like systems)
        system("clear");

        // Loop to print the LEDs where only the current position is "on"
        for (int i = 0; i < NUM_LEDS; i++) {
            if (i == position)
                printf("*");
            else
                printf("-");
        }
        printf("\n");

        // Update the position of the "on" LED
        position = (position + 1) % NUM_LEDS;

        // Delay for a short period (e.g., 200 milliseconds)
        usleep(200000);
    }

    return 0;
}
