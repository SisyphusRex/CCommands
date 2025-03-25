// TODO: Modify the code so that the vector holds characters instead of integers -- a flexible string

#include <stdio.h>
#include <stdlib.h>
#include "vector.h"

// Initialize vector with specified size
void vector_create(vector* v, unsigned int vectorSize) {
   int i;

   if (v == NULL) return;

   v->elements = (char*)malloc(vectorSize * sizeof(char));
   v->size = vectorSize;
   for (i = 0; i < v->size; ++i) {
      v->elements[i] = 0;
   }
}

// Destroy vector
void vector_destroy(vector* v) {
   if (v == NULL) return;

   free(v->elements);
   v->elements = NULL;
   v->size = 0;
}

// Resize the size of the vector
void vector_resize(vector* v, unsigned int vectorSize) {
   int oldSize;
   int i;

   if (v == NULL) return;

   oldSize = v->size;
   v->elements = (char*)realloc(v->elements, vectorSize * sizeof(char));
   v->size = vectorSize;
   for (i = oldSize; i < v->size; ++i) {
      v->elements[i] = 0;
   }
}

// Return pointer to element at specified index
char* vector_at(vector* v, unsigned int index) {
   if (v == NULL || index >= v->size) return NULL;

   return &(v->elements[index]);
}

// Insert new value at specified index
void vector_insert(vector* v, unsigned int index, char value) {
   int i;

   if (v == NULL || index > v->size) return;

   vector_resize(v, v->size + 1);
   for (i = v->size - 1; i > index; --i) {
      v->elements[i] = v->elements[i-1];
   }
   v->elements[index] = value;
}

// Insert new value at end of vector
void vector_push_back(vector* v, char value) {
   vector_insert(v, v->size, value);
}

// Erase (remove) value at specified index
void vector_erase(vector* v, unsigned int index) {
   int i;

   if (v == NULL || index >= v->size) return;

   for (i = index; i < v->size - 1; ++i) {
      v->elements[i] = v->elements[i+1];
   }
   vector_resize(v, v->size - 1);
}

// Return number of elements within vector
int vector_size(vector* v) {
   if (v == NULL) return -1;

   return v->size;
}

// Convert an ordinary string to a vector
void vector_from_string(vector* v, char* string) {
   vector_create(v, strlen(string));

   for (int i = 0; i < strlen(string); i++) {
    v->elements[i] = string[i];
   }
   
}

// Print the elements of the vector (no final newline)
void vector_print(vector* v) {
   
   for (int i = 0; i < v->size;i++) {
    printf("%c", v->elements[i]);
   }
   
  
}
