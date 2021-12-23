/**
 * A basic dynamic array implementation to store words and their attributes
 * 
 * @file sentence_buffer.h
 * @author Thomas Beatty (thomas.beatty@colorado.edu)
 * @see sentence_buffer.c
 */

#ifndef S_BUFFER_H_
#define S_BUFFER_H_

#include <stddef.h>

enum p_speech { interjection, pronoun, noun, verb, adjective, adverb, preposition, conjunction };
enum conjugation { fps, sps, tps, fpp, spp, tpp };

struct token {
	char str[25] = ""; // Arbitrary length that should store most words
	short is_too_long = 0; // Flag for if the string length was too long
	p_speech part;
	conjugation subject;
};

typedef struct s_buffer_ s_buffer;

s_buffer *new_buffer(size_t size);
void delete_buffer(s_buffer *buffer);
void resize_buffer(s_buffer *buffer, size_t size);

int token_at(s_buffer *buffer, size_t pos, token *word);
void push_back(s_buffer *buffer, token word);


#endif