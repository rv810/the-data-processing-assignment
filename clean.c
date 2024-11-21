/* Resham Vani, vanir1, November 21, 2024
 *
 * This is the main program to clean a 2d grid of floating-point numbers.
 * It has two ways it can run:
 * 1. Without arguments: Deletes rows containing NAN values.
 * 2. With the "-d" argument: Replaces NAN values with column averages.
 * The program reads the 2d grid from standard input and outputs the cleaned grid.
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "clean_data.h"
#include "format_IO.h"

/* main
 *
 * Parameters:
 * - argc: The number of command-line arguments passed to the program.
 * - argv: An array of strings representing the command-line arguments.
 *
 * The main function reads a 2d grid of floating-point numbers from standard input,
 * cleans the data based on the command-line argument, and outputs the cleaned grid:
 * - No argument: Deletes rows with NAN values.
 * - "-d": Replaces NAN values with the average of the column.
 *
 * Return:
 * - EXIT_SUCCESS (0) on successful execution.
 * - EXIT_FAILURE (1) if an invalid argument is provided.
 */
int main(int argc, char *argv[]) {
	long rows;
	long cols;

	float **data = read_data(&rows, &cols);

	if (argc == 2) {
		if (strcmp(argv[1], "-d") == 0) {
			float **clean_impute_data = clean_impute(&rows, &cols, data);
			output_data(rows, cols, clean_impute_data);
			free(clean_impute_data);
		}
		else {
			return EXIT_FAILURE;
		}
	}
	
	else {
		float **clean_delete_data = clean_delete(&rows, &cols, data);
		output_data(rows, cols, clean_delete_data);
		free(clean_delete_data);
	}
}
