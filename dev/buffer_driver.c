#include <stdio.h>
#include <string.h>

#include "sentence_buffer.h"

int main() {
	s_buffer *buffer = new_buffer(4);
	printf("Created buffer of size %ld\n\n", get_buffer_size(buffer));

	//
	// First test
	//

	token t;
	printf("Adding \"hello\" to the buffer\n");
	strncpy(t.str, "hello", 16);
	push_back(buffer, t);

	if(token_at(buffer, 0, &t)) {
		printf("\nInvalid position\n");
		return -1;
	}
	
	printf("Got: \"%s\"\n", t.str);

	if(strcmp(t.str, "hello") != 0) {
		printf("\nThe returned string was not correct\n");
		return -2;
	}

	//
	// Second test
	//

	printf("Adding \"world\" to the buffer\n");
	strncpy(t.str, "world", 16);
	push_back(buffer, t);

	if(token_at(buffer, 1, &t)) {
		printf("\nInvalid position\n");
		return -1;
	}

	printf("Got: \"%s\"\n", t.str);

	if(strcmp(t.str, "world") != 0) {
		printf("\nThe returned string was not correct\n");
		return -2;
	}

	//
	// Third test
	//

	printf("Adding \"a\" to the buffer\n");
	strncpy(t.str, "a", 16);
	push_back(buffer, t);

	if(token_at(buffer, 2, &t)) {
		printf("\nInvalid position\n");
		return -1;
	}

	printf("Got: \"%s\"\n", t.str);

	if(strcmp(t.str, "a") != 0) {
		printf("\nThe returned string was not correct\n");
		return -2;
	}

	//
	// Fourth test
	//

	printf("Adding \"b\" to the buffer\n");
	strncpy(t.str, "b", 16);
	push_back(buffer, t);

	if(token_at(buffer, 3, &t)) {
		printf("\nInvalid position\n");
		return -1;
	}

	printf("Got: \"%s\"\n", t.str);

	if(strcmp(t.str, "b") != 0) {
		printf("\nThe returned string was not correct\n");
		return -2;
	}

	//
	// Fifth test (array doubles)
	//

	printf("Adding \"c\" to the buffer (array should double)\n");
	strncpy(t.str, "c", 16);
	push_back(buffer, t);
	
	printf("The buffer's new size is %ld\n", get_buffer_size(buffer));

	if(token_at(buffer, 4, &t)) {
		printf("\nInvalid position\n");
		return -1;
	}

	printf("Got: \"%s\"\n", t.str);

	if(strcmp(t.str, "c") != 0) {
		printf("\nThe returned string was not correct\n");
		return -2;
	}

	//
	// Sixth test
	//

	printf("\nTrying to access an index larger than the current size\n");
	if(!token_at(buffer, 5, &t)) {
		printf("\nNo error detected\n");
		return -3;
	}

	printf("\nPassed all tests!\n");

	return 0;
}