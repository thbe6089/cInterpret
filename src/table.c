#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "table.h"

/* Private function to find a row from its first element, returning
   character offset for fseek(), or -1 if the row isn't found, or
   1 otherwise */
long find_key(FILE *file, char *key) {
	if(!file) return 1;

	fseek(file, 0, SEEK_SET);

	/* Buffer to store the entire line in */
	size_t line_size = DEFAULT_LINE_SIZE;
	char *line = (char*) malloc(line_size);

	/* Buffer to store the characters from the first element in */
	size_t str_size = DEFAULT_BUFFER_SIZE;
	char *str = (char*) malloc(str_size);

	while(getline(&line, &line_size, file)) {
		for(size_t i = 0; i <= line_size; i++) {
			/* If the buffer is too small, double its size */
			if(i >= str_size) str = (char*) realloc(str, (str_size *= 2));

			if(i == line_size || line[i] == ',') {
				str[i] = '\0';
				break;
			} else {
				str[i] = line[i];
			}
		}

		if(strcmp(str, key) == 0) {
			free(line);
			free(str);
			/* Return position of start of line */
			return ftell(file) - strlen(line);
		}
	}

	free(line);
	free(str);
	return -1;
}

int csv_append_row(FILE *file, char **data, size_t size) {
	if(!file || !data || size < 1) return 1;

	fseek(file, 0, SEEK_END);

	fprintf(file, "%s", data[0]);
	for(size_t i = 1; i < size; i++) {
		fprintf(file, ",%s", data[i]);
	}
	fprintf(file, "\n");

	return 0;
}

int csv_get_row(FILE *file, char *key, char **data, size_t *size, size_t *str_size) {
	if(!file || !key) return 1;

	/* Get the position of the beginning of the line starting with the key */
	long pos = find_key(file, key);
	if(pos == -1) return -1;
	fseek(file, pos, SEEK_SET);

	/* If these parameters aren't useful values, assign default values */
	if(*size < 1) *size = DEFAULT_ARRAY_SIZE;
	if(*str_size < 1) *str_size = DEFAULT_BUFFER_SIZE;

	/* If the memory for the array hasn't been allocated, do so now */
	if(!data) data = (char**) malloc(*size * *str_size);

	/* Get characters one-by-one, keeping track of the current amount of elements and the current buffer position */
	size_t data_count = 0;
	size_t str_pos = 0;
	char curr;
	while(fscanf(file, "%c", &curr)) {
		if(data_count >= *size) data = (char**) realloc(data, (*size *= 2) * *str_size);
		if(str_pos >= *str_size) data = (char**) realloc(data, *size * (*str_size *= 2));

		if(curr == ',') {
			data[data_count][str_pos] = '\0';
			data_count++;
			str_pos = 0;
			continue;
		}

		if(curr == '\n') {
			data[data_count][str_pos] = '\0';
			data_count++;
			break;
		}

		data[data_count][str_pos] = curr;
		str_pos++;
	}

	/* Resize the array to fit */
	*size = data_count;
	data = (char**) realloc(data, *size * *str_size);
	return 0;
}

int csv_swap_rows(FILE *file, char *key1, char *key2) {
	
}

int csv_delete_row(FILE *file, char *key) {
	
}