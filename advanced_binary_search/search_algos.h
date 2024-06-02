#ifndef HEADER_FILE
#define HEADER_FILE

#include <stdio.h>
#include <stdlib.h>

int advanced_binary(int *array, size_t size, int value);
int advanced_binary_recursive(int *array, size_t left, size_t right, int value);
void print_array(int *array, size_t left, size_t right);

#endif /* HEADER FILE */