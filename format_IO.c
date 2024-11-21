/* Resham Vani, vanir1, November 21, 2024
 *
 * This program defines a function to read a 2d grid of floating-point numbers 
 * from standard input and create a 2d array of those values and a function
 * that accepts a 2d array and returns it to standard output.
 */

#include <stdlib.h>
#include <stdio.h>


/* read_data
 *
 * Parameters:
 * - rows: A pointer to a long integer where the number of rows will be stored.
 * - cols: A pointer to a long integer where the number of columns will be stored.
 *
 * This function reads the dimensions of an array (rows and columns) and its 
 * elements from standard input. It dynamically allocates memory for the 2d array 
 * and stores its elements.
 *
 * Return:
 * - A pointer to a dynamically allocated 2D array of floats, or NULL if memory 
 *   allocation fails.
 */
float **read_data(long *rows, long *cols) {
    scanf("%ld %ld", rows, cols);
    float **data = malloc((*rows)*sizeof(float *));
    if (data == NULL) return NULL;

    for (long i=0; i < *rows; i++) {
        data[i] = malloc((*cols)*sizeof(float));
        for (long j=0; j < *cols; j++) {
            scanf("%f", &data[i][j]);
        }
    }
    return data;
}

/* output_data
 *
 * Parameters:
 * - rows: The number of rows in the 2D array.
 * - cols: The number of columns in the 2D array.
 * - arr: A pointer to the 2D array to be printed.
 *
 * This function prints the dimensions of the array and its elements to 
 * standard output, formatting each floating-point number to three decimal 
 * places.
 *
 * Return:
 * - None (void function).
 */
void output_data(long rows, long cols, float **arr) {
    printf("%ld %ld \n", rows, cols);

    for (long i=0; i < rows; i++) { 
        for (long j=0; j < cols; j++) {
            printf("%.3f ", arr[i][j]);
        }
        puts("");
    }
}