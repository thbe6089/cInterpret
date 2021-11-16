#ifndef _INTERFACE_H
#define _INTERFACE_H

#define _VERSION "0.0"

/**
 * @brief Display the help message
 */
void disp_help_msg();

/**
 * @brief Iterate through the command line arguments
 * 
 * @param argc 
 * @param argv 
 * @param out_file Pointer to default output file
 * @return 1 if the help message should be output, -1 if the output file
 *         couldn't be found, otherwise 0
 */
int cmd_line_args(int argc, char **argv, FILE **out_file);

#endif