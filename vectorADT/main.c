#include <stdio.h>
#include "vector.h"

int main(void) {
   int a;
   int b;
   char char1;
   char char2;
   vector v;
   char string[50];
   
   // Read a string
   scanf("%s\n", string);

   // TODO: Create a vector from the input string

   vector_from_string(&v, string);
   
   vector_print(&v);
   printf("\n");
   
   // Read a character char1
   scanf("%c", &char1);
   
   // TODDO: Add char1 to the end of the string
   vector_push_back(&v, char1);
   
   vector_print(&v);
   printf("\n");

   // Read two indices a and b
   scanf("%d %d", &a, &b);
   
   // TODO: Remove the character at index a from the vector,
   // then remove the character at index b of the modified vector
   vector_erase(&v, a);
   vector_erase(&v, b);
   
   vector_print(&v);
   printf("\n");

   // Read two pairs of index and character
   scanf("%d %c %d %c", &a, &char1, &b, &char2);
   
   // TODO: Replace the character at index a with char1 and
   // the character at index b with char2
   vector_erase(&v, a);
   vector_insert(&v, a, char1);
   vector_erase(&v, b);
   vector_insert(&v, b, char2);


   
   vector_print(&v);
   printf("\n");

   // Read two pairs of index and character
   scanf("%d %c %d %c", &a, &char1, &b, &char2);
   
   // TODO: Insert character char1 before index a of the vector, then
   // insert character char2 before index b of the modified vector
   vector_insert(&v, a, char1);
   vector_insert(&v, b, char2);
   vector_print(&v);
   printf("\n");

   // TODO: Free the memory allocated to the vectort
   vector_destroy(&v);

   return 0;
}
