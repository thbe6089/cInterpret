#include <stdio.h>

#include "interface.h"
#include "loop.h"

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