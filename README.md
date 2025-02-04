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
