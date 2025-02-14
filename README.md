1. #include <stdio.h>
2. int main() {
return 0;
}

* To compile from terminal
    1. move to directory containing your_program.c
    2. gcc your_program.c -o your_program
* Run
    1. ./your_program

* to scan string into array of strings
    1. char inputStr[100];
    2. char stringArray[20][100];
    * 20: number of strings
    * 100: length of strings
    3. scanf("%s", &inputStr);
    4. strcpy(stringArray[i], inputStr);