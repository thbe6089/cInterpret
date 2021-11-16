#include <stdio.h>
#include <stdlib.h>

#include "interface.h"

#include "helper.h"

void disp_help_msg() {
	fprintf(stderr, "usage: cinterpreter [options] [< in_file] [> out_file]\n\n");
	fprintf(stderr, "in_file:  Where to redirect stdin\n");
	fprintf(stderr, "out_file: Where to redirect stdout\n\n");
	fprintf(stderr, "Options:\n");
	fprintf(stderr, " --version       Display the current version\n");
	fprintf(stderr, " --help          Display this message\n");
	fprintf(stderr, " -v              Same as --version\n");
	fprintf(stderr, " -h              Same as --help\n");
	fprintf(stderr, " -f <file_name>  Output to <file_name> as well as stdout\n");
}

int cmd_line_args(int argc, char **argv, FILE **out_file) {
	for(int i = 1; i < argc; i++) {
		if(argv[i][0] == '-') {
			switch(argv[i][1]) {
			case '-':
				if(streq(argv[i], "--help")) {
					return 1;
				} else if(streq(argv[i], "--version")) {
					printf("cInterpreter v%s\n", _VERSION_);
					return 0;
				} else {
					return 1;
				}
			
			case 'h':
				return 1;
			
			case 'v':
				printf("cInterpreter v%s\n", _VERSION);
				return 0;
			
			case 'f':
				if(argv[i][2] == '\0') {
					if(i <= argc) i++;
					else return 1;

					*out_file = fopen(argv[i], "w");
					if(!out_file) return -1;
				} else {
					int f_name_size = 64;
					char *f_name = (char*) malloc(sizeof(char) * f_name_size);
					for(int j = 0; argv[i][j+2] != '\0'; j++) {
						if(j >= f_name_size) {
							f_name_size *= 2;
							f_name = (char*) realloc(f_name, sizeof(char) * f_name_size);
						}

						f_name[j] = argv[i][j+2];
					}

					*out_file = fopen(f_name, "w");
					free(f_name);
					if(!out_file) return -1;
				}
				break;
			}
		} else if(argv[i][0] == '<') {
			if(argv[i][1] != '\0') {
				i++;
				continue;
			} else {
				continue;
			}
		} else if(argv[i][0] == '>') {
			if(argv[i][1] != '\0') {
				i++;
				continue;
			} else {
				continue;
			}
		} else {
			return 1;
		}
	}

	return 0;
}