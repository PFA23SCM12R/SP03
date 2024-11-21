#include <stdio.h>
#include <stdlib.h>
#include <math.h> // For sqrt()

// Function prototypes
void read_data(const char *filename, float **data, int *size, int *capacity);
float calculate_mean(const float *data, int size);
float calculate_median(float *data, int size);
float calculate_stddev(const float *data, int size, float mean);
void sort_data(float *data, int size);
void reallocate_array(float **data, int *capacity);

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    float *data = NULL;
    int size = 0, capacity = 20; // Initial capacity
    data = (float *)malloc(capacity * sizeof(float));
    if (data == NULL) {
        fprintf(stderr, "Error allocating memory.\n");
        return 1;
    }

    // Read data from file
    read_data(argv[1], &data, &size, &capacity);

    // Calculate statistics
    float mean = calculate_mean(data, size);
    sort_data(data, size); // Sorting needed for median
    float median = calculate_median(data, size);
    float stddev = calculate_stddev(data, size, mean);
    float sum = mean * size;

    // Find min and max
    float min = data[0];
    float max = data[size - 1];

    // Print results
    printf("Results:\n");
    printf("--------\n");
    printf("Num values: %d\n", size);
    printf("min: %.4f\n", min);
    printf("max: %.4f\n", max);
    printf("mean: %.4f\n", mean);
    printf("median: %.4f\n", median);
    printf("stddev: %.4f\n", stddev);
    printf("sum: %.2f\n", sum);
    printf("Unused array capacity: %d\n", capacity - size);

    // Free allocated memory
    free(data);

    return 0;
}

// Function to read data from a file
void read_data(const char *filename, float **data, int *size, int *capacity) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Error opening file: %s\n", filename);
        exit(1);
    }

    float value;
    while (fscanf(file, "%f", &value) == 1) {
        if (*size == *capacity) {
            reallocate_array(data, capacity);
        }
        (*data)[(*size)++] = value;
    }

    fclose(file);
}

// Function to calculate mean
float calculate_mean(const float *data, int size) {
    float sum = 0.0;
    for (int i = 0; i < size; i++) {
        sum += data[i];
    }
    return sum / size;
}

// Function to calculate median
float calculate_median(float *data, int size) {
    if (size % 2 == 0) {
        return (data[size / 2 - 1] + data[size / 2]) / 2.0;
    } else {
        return data[size / 2];
    }
}

// Function to calculate standard deviation
float calculate_stddev(const float *data, int size, float mean) {
    float sum = 0.0;
    for (int i = 0; i < size; i++) {
        sum += (data[i] - mean) * (data[i] - mean);
    }
    return sqrt(sum / size);
}

// Function to sort data
void sort_data(float *data, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (data[j] > data[j + 1]) {
                float temp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = temp;
            }
        }
    }
}

// Function to reallocate array when capacity is reached
void reallocate_array(float **data, int *capacity) {
    *capacity *= 2;
    *data = (float *)realloc(*data, (*capacity) * sizeof(float));
    if (*data == NULL) {
        fprintf(stderr, "Error reallocating memory.\n");
        exit(1);
    }
}

