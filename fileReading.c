#include <stdio.h>
#include <string.h>

int main(void) {

   FILE* inputFile = NULL;
   const int MAX_LENGTH = 100;
   char fileName[MAX_LENGTH];
   char line[MAX_LENGTH];

   scanf("%s", fileName);

   inputFile = fopen(fileName, "r");
   if (inputFile == NULL) {
    return 1;
   }

   while (fgets(line, MAX_LENGTH, inputFile) != NULL) {
    char newLine[MAX_LENGTH];
    sscanf(line, "%[^_]", newLine);
    strcat(newLine, "_info.txt");
    printf("%s\n", newLine);
   }






   return 0;
}
