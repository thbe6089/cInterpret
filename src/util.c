#include <stdio.h>

#include "helper.h"

int streq(char *str1, char *str2) {
	for(int i = 0; str1[i] == str2[i]; i++) {
		if(str1[i] == '\0') return 1;
	}

	return 0;
}