/**
 * Utilizes QDBM to store base vocabulary (see README.md for more in-depth description)
 * 
 * @file dictionary.h
 * @author Thomas Beatty (thomas.beatty@colorado.edu)
 * @see dictionary.c
 * @see README.md
 */

#ifndef DICTIONARY_H_
#define DICTIONARY_H_

#define NUM_BUCKETS 50000

#include "util.h"

typedef struct dictionary_ dictionary;

dictionary *open_dict(char *filename);
void close_dict(dictionary *dict);

#endif