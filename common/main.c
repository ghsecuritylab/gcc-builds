#include <stdio.h>
#include "config.h"
#include "cli.h"
#include "timer.h"

void print_post_info(void) {
	printf("\r----------------------------------------------------------------------\r\n");
	printf("SystemCoreClock: %u kHz\r\n", (unsigned int) SystemCoreClock / 1000);
	printf("Use 'help' for a list of commands.\r\n");
	printf("----------------------------------------------------------------------\r\n");
	printPrompt();
}

int main(void) {

	unsigned int curr = 0, prev = 0;

	if (!board_init())
		fault();

	print_post_info();

	while(1) {

		/* Handle Button */
		if (readButton()) {
			setLED(1, true);
			setLED(2, true);
		}
		else {
			setLED(1, false);
			setLED(2, false);
		}

		check_input();

		/* Blink Red LED */
		curr = ticks / 1000;
		if (curr != prev) {
			(curr % 2) ? 
				setLED(0, true) : setLED(0, false);
		}
		prev = curr;
	}
}

