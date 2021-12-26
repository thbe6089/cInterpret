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

typedef enum part_of_speech_ { 
	interjection, pronoun, noun, verb, adjective, adverb, preposition, conjunction 
} p_speech;

typedef enum conjugation_ {
	fps, sps, tps, fpp, spp, tpp
} conjugation;

typedef struct token_ {
	char str[16]; // Arbitrary length that should store most words
	short is_too_long; // Flag for if the string length was too long
	p_speech part;
	conjugation subject;
} token;

typedef struct s_buffer_ s_buffer;

s_buffer *new_buffer(size_t size);
void delete_buffer(s_buffer *buffer);
void resize_buffer(s_buffer *buffer, size_t size);

int token_at(s_buffer *buffer, size_t pos, token *word);
void push_back(s_buffer *buffer, token word);

size_t get_buffer_size(s_buffer *buffer);

#endif