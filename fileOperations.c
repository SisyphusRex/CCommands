#include <stdio.h>


void getStudentAverage(int mid1, int mid2, int finalScore, double* studentAvg, char* letter){
    *studentAvg = (double)(mid1 + mid2 + finalScore) / 3;
    if (*studentAvg >= 90) {
        *letter = 'A';
    }
    else if (*studentAvg >= 80) {
        *letter = 'B';
    }
    else if (*studentAvg >= 70) {
        *letter = 'C';
    }
    else if (*studentAvg >= 60) {
        *letter = 'D';
    }
    else {
        *letter = 'F';
    }

}

int main(void) {

   const int MAX_CHARS = 25;
   FILE* inputFile = NULL;
   FILE* outputFile = NULL;
   char filename[MAX_CHARS];
   char line[100];
   char lastName[MAX_CHARS];
   char firstName[MAX_CHARS];
   int midterm1, midterm2, finalScore;
   double midterm1Avg= 0.0, midterm2Avg= 0.0, finalScoreAvg= 0.0, studentAvg = 0.0;
   char letterGrade;
   int count = 0, midterm1Total = 0, midterm2Total = 0, finalTotal = 0;

      
      
   /* TODO: Read a file name from the user and read the tsv file here. */
   scanf("%s", filename);
   inputFile = fopen(filename, "r");
   outputFile = fopen("report.txt", "w");

   if (inputFile == NULL) {
    return 1;
   }

   while (fgets(line, 100, inputFile) != NULL) {
    sscanf(line, "%s %s %d %d %d", lastName, firstName, &midterm1, &midterm2, &finalScore);
    
    getStudentAverage(midterm1, midterm2, finalScore, &studentAvg, &letterGrade);
    count++;
    midterm1Total += midterm1;
    midterm2Total += midterm2;
    finalTotal += finalScore;
    fprintf(outputFile, "%s\t%s\t%d\t%d\t%d\t%c\n", lastName, firstName, midterm1, midterm2, finalScore, letterGrade);
    
   }

   midterm1Avg = (double)midterm1Total/count;
   midterm2Avg = (double)midterm2Total/count;
   finalScoreAvg = (double)finalTotal/count;
   fprintf(outputFile, "\n");
   fprintf(outputFile, "Averages: midterm1 %.2lf, midterm2 %.2lf, final %.2lf\n", midterm1Avg, midterm2Avg, finalScoreAvg);
   fclose(outputFile);
   
   /* TODO: Compute student grades and exam averages, then output results to a text file here. */

   return 0;
}
