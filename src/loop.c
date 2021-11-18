#include <stdio.h>
#include <stdlib.h>

#include "loop.h"

#include "table.h"

int prog_loop(FILE *out_file) {
	size_t size = DEFAULT_BUFFER_SIZE;
	char *str = (char*) malloc(size);

	FILE *file = fopen("dict/test.csv", "r+");

	size_t data_size = 10;
	size_t str_size = 10;
	char **data = (char**) malloc(data_size * str_size);

	while(getline(&str, &size, stdin) > 1) {
		csv_get_row(file, "Hello", data, &data_size, &str_size);
		for(size_t i = 0; i < data_size; i++) printf("%s\n", data[i]);
	}

	fclose(file);
	free(str);
	free(data);

	return 0;
}