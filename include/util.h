/**
 * A utility header that includes basic structures used throughout the program
 * 
 * @file util.h
 * @author Thomas Beatty (thomas.beatty@colorado.edu)
 */

#ifndef UTIL_H_
#define UTIL_H_

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

#endif