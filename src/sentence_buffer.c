/**
 * Implementation of structures defined in sentence_buffer.h
 * 
 * @file sentence_buffer.c
 * @author Thomas Beatty (thomas.beatty@colorado.edu)
 * @see sentence_buffer.h
 */

#include "sentence_buffer.h"

/**
 * Struct to store the array
 */
struct s_buffer_ {
	token *data = NULL;
	size_t size = 0;
	size_t curr = 0; // Store current size
};

/**
 * Allocates new sentence buffer
 * 
 * @param size Array size desired (larger recommended)
 * @return Pointer to the new buffer
 */
s_buffer *new_buffer(size_t size) {
	s_buffer *out = (s_buffer*) malloc(sizeof(s_buffer));

	out->size = size;
	out->data = (token*) malloc(sizeof(token) * size);

	return out;
}

/**
 * Deletes buffer
 * 
 * @param buffer 
 */
void delete_buffer(s_buffer *buffer) {
	free(buffer->data);
	free(buffer);
	buffer = NULL;
}

/**
 * Resizes array to desired size
 * 
 * @param buffer Sentence buffer
 * @param size New size (double recommended)
 */
void resize_buffer(s_buffer *buffer, size_t size) {
	buffer = (token*) realloc(buffer, sizeof(token) * size);
}

/**
 * Returns information about the token at position specified
 * 
 * @param buffer Sentence buffer
 * @param pos Position in array
 * @param word Pointer to where the info will be stored
 * @return -1 if invalid input, 0 otherwise
 */
int token_at(s_buffer *buffer, size_t pos, token *word) {
	if(pos >= buffer->curr || pos <= 0) return -1;

	*word = buffer->data[pos];
	return 0;
}

/**
 * Appends token to sentence buffer
 * 
 * @param buffer Sentence buffer
 * @param word Token to append
 */
void push_back(s_buffer *buffer, token word) {
	buffer->curr++;

	// Array doubling
	if(buffer->curr >= buffer->size) {
		buffer->size *= 2;
		resize_buffer(buffer, buffer->size);
	}

	buffer->data[buffer->curr-1] = word;
}