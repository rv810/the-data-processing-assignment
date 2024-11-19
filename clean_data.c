#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <stdbool.h>

float **clean_delete(long *rows, long *cols, float **arr) {
    float **clean_data = malloc(*rows*sizeof(float *));
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

    return clean_data;
}

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