#ifndef TABLE_H_
#define TABLE_H_

#define DEFAULT_LINE_SIZE 256
#define DEFAULT_BUFFER_SIZE 64
#define DEFAULT_ARRAY_SIZE 16

/**
 * @brief Append data to provided CSV file
 * 
 * @param file 
 * @param data Array of strings to append
 * @param size Size of data
 * @return 0 if successful, or 1 otherwise
 */
int csv_append_row(FILE *file, char **data, size_t size);

/**
 * @brief Get a row from the provided CSV file by first item. Dynamically
 *        allocated memory to data array
 * 
 * @param file
 * @param key First item of row
 * @param data Array of strings containing data
 * @param size Size of array
 * @param str_size Size of strings in array
 * @return 0 if successful, -1 if the row cannot be found, or 1 otherwise
 */
int csv_get_row(FILE *file, char *key, char **data, size_t *size, size_t *str_size);

/**
 * @brief Swap two rows, specified by first item, in provided CSV file
 * 
 * @param file 
 * @param key1 First item of first row
 * @param key2 First item of second row
 * @return 0 if successful, -1 if either row can't be found, or 1 otherwise
 */
int csv_swap_rows(FILE *file, char *key1, char *key2);

/**
 * @brief Delete a row from the provided CSV file, located by first item
 * 
 * @param file 
 * @param key First item of row
 * @return 0 if successful, -1 if the row can't be found, or 1 otherwise
 */
int csv_delete_row(FILE *file, char *key);

#endif