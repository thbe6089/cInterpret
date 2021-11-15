#include <stdio.h>
#include <stdlib.h>

#include "loop.h"

int prog_loop(FILE *out_file) {
	size_t size = 64;
	char *str = (char*) malloc(sizeof(char) * size);

	while(getline(&str, &size, stdin) > 1) {
		/* Main loop */
	}

	free(str);

	return 0;
}