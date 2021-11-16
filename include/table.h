#ifndef TABLE_H_
#define TABLE_H_

/**
 * @brief Append data to provided CSV file
 * 
 * @param f_name File name
 * @param data Array of strings to append
 * @param size Size of array
 * @return 0 if successful, or 1 otherwise
 */
int csv_append_row(char *f_name, char **data, unsigned int size);

/**
 * @brief Get a row from the provided CSV file by first item
 * 
 * @param f_name File name
 * @param key First item of row
 * @param data Array of strings containing data
 * @param size Size of array
 * @return 0 if successful, or 1 otherwise
 */
int csv_get_row(char *f_name, char *key, char **data, unsigned int *size);

/**
 * @brief Swap two rows, specified by first item, in provided CSV file
 * 
 * @param f_name File name
 * @param key1 First item of first row
 * @param key2 First item of second row
 * @return 0 if successful, -1 if either row can't be found, or 1 otherwise
 */
int csv_swap_rows(char *f_name, char *key1, char *key2);

/**
 * @brief Delete a row from the provided CSV file, located by first item
 * 
 * @param f_name File name
 * @param key First item of row
 * @return 0 if successful, -1 if the row can't be found, or 1 otherwise
 */
int csv_delete_row(char *f_name, char *key);

#endif