/**
 * Implementation of structures defined in dicitonary.h
 * 
 * @file dictionary.c
 * @author Thomas Beatty (thomas.beatty@colorado.edu)
 * @see dictionary.h
 */

#include <depot.h>

#include "dictionary.h"

struct dictionary_ {
	DEPOT *file;
};

dictionary *open_dict(char *filename) {
	dictionary *dict;
	dict->file = dpopen(filename, DP_OREADER, NUM_BUCKETS);

	return dict;
}

void close_dict(dictionary *dict) {
	dpclose(dict->file);
}