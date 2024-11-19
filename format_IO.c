#include <stdlib.h>
#include <stdio.h>

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

void output_data(long rows, long cols, float **arr) {
    printf("%ld %ld \n", rows, cols);

    for (long i=0; i < rows; i++) { 
        for (long j=0; j < cols; j++) {
            printf("%.3f ", arr[i][j]);
        }
        puts("");
    }
}