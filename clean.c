#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "clean_data.h"
#include "format_IO.h"

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
