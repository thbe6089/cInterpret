/**
 * The main program interface
 * 
 * @file main.c
 * @author Thomas Beatty (thomas.beatty@colorado.edu)
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define VERSION_ "0.1"

/**
 * Displays usage message
 * 
 * @see main()
 */
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

/**
 * Helper function to process command line arguments
 * 
 * @see main()
 * @param argc Same as main()
 * @param argv Same as main()
 * @param out_file Pointer to the FILE that should be opened
 * @return 1 to display the help message, -1 if the file couldn't be opened, or 0 if successful
 */
int cmd_line_args(int argc, char **argv, FILE **out_file) {
	for(int i = 1; i < argc; i++) {
		if(argv[i][0] == '-') {
			switch(argv[i][1]) {
			case '-':
				if(strcmp(argv[i], "--help") == 0) {
					return 1;
				} else if(strcmp(argv[i], "--version") == 0) {
					printf("cInterpreter v%s\n", VERSION_);
					return 0;
				} else {
					return 1;
				}
			
			case 'h':
				return 1;
			
			case 'v':
				printf("cInterpreter v%s\n", VERSION_);
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

/**
 * The main program loop
 * 
 * @see main()
 * @param out_file The file to output to as well as stdout
 * @return Error code
 */
int prog_loop(FILE *out_file) {
	

	return 0;
}

int main(int argc, char **argv) {
	int err;

	FILE *out_file = NULL;

	err = cmd_line_args(argc, argv, &out_file);
	if(err == 1) {
		disp_help_msg();
		return 0;
	} else if(err == -1) {
		fprintf(stderr, "Couldn't find file specified\n");
		return -1;
	}

	err = prog_loop(out_file);

	if(out_file) fclose(out_file);

	return 0;
}