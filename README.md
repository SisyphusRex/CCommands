1. #include <stdio.h>
2. int main() {
return 0;
}

* To compile from terminal
    1. move to directory containing your_program.c
    2. gcc your_program.c -o your_program
* Run
    1. ./your_program

* to make print and scan work in Gitbash
  1. setbuf(stdout, NULL);
* to stop input in loop
    1. fflush(stdin);
    2. put at end of loop
      * EDIT:
          1. fflush(stdin) for some reason doesn't work
          2. do this scanf(" %c", inputChar); with space before %c:

  ```
  while (inputChar != '#')
    {

        printf("You entered %c.\n", inputChar);
        scanf(" %c", &inputChar);
    }
  ```
* to scan string into array of strings
    1. char inputStr[100];
    2. char stringArray[20][100];
    * 20: number of strings
    * 100: length of strings
    3. scanf("%s", &inputStr);
    4. strcpy(stringArray[i], inputStr);

* pass by pointer
    ```
    void DoSomething(int* x) {
        *x = 2 * x;
    }

    int main(void) {
        int myX = 1;

        DoSomething(&myX);
    }
    ```