/* Resham Vani, vanir1, November 21, 2024
 *
 * This program provides functions to clean a 2D array of floating-point numbers
 * by handling rows or cells with NAN values. The clean_delete function removes
 * rows containing NAN values, and the clean_impute function replaces NAN values
 * with the average of the corresponding column.
 */

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <stdbool.h>

/* clean_delete
 *
 * Parameters:
 * - rows: A pointer to a long integer representing the number of rows in the array.
 *         This value will be updated to reflect the new number of rows after cleaning.
 * - cols: A pointer to a long integer representing the number of columns in the array.
 * - arr: A pointer to the original 2D array of floats to be cleaned.
 *
 * This function removes all rows containing NAN values from a 2D array. A new array
 * is dynamically allocated to store the cleaned data. The number of rows is updated
 * to reflect the size of the new array.
 *
 * Return:
 * - A pointer to the cleaned 2D array, or NULL if memory allocation fails.
 */
float **clean_delete(long *rows, long *cols, float **arr) {
    float **clean_data = malloc(*rows*sizeof(float *));
    if (clean_data == NULL) return NULL;

    long new_data_rows = 0;
    for (long i=0; i < *rows; i++) {
        bool check_nan = false;
        for (long j=0; j < *cols; j++) {
            if (isnan(arr[i][j])) {
                check_nan = true;
                break;
            }
        }
        if (!check_nan) {
            clean_data[new_data_rows] = malloc(*cols * sizeof(float));
            for (long j = 0; j < *cols; j++) {
                clean_data[new_data_rows][j] = arr[i][j];
            }
            new_data_rows++;
        }
    }
    *rows = new_data_rows;
    clean_data = realloc(clean_data, new_data_rows * sizeof(float *));
    if (clean_data == NULL) return NULL;

    return clean_data;
}

/* clean_impute
 *
 * Parameters:
 * - rows: A pointer to a long integer representing the number of rows in the array.
 * - cols: A pointer to a long integer representing the number of columns in the array.
 * - arr: A pointer to the original 2D array of floats to be cleaned.
 *
 * This function replaces all NAN values in the array with the average of the
 * non-NAN values in the corresponding column. If an entire column contains only
 * NAN values, the NAN values are replaced with 0.0.
 *
 * Return:
 * - A pointer to the modified 2D array with NAN values replaced.
 */
float **clean_impute(long *rows, long *cols, float **arr) {
    for (long i=0; i < *rows; i++) { 
        for (long j=0; j < *cols; j++) {
            if (isnan(arr[i][j])) {
                float sum = 0.0;
                float average = 0.0;
                long counter = 0;

                for (long k=0; k < *rows; k++) {
                    if (!isnan(arr[k][j])) {
                        sum += arr[k][j];
                        counter++;
                    }   
                }
                
                if (counter > 0) {
                    average = sum/counter;
                }

                else {
                    average = 0.0;
                }
                
                arr[i][j] = average;
            }
        }
    }
    return arr;
}