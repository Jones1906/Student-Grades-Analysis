/*******************************************************************
* Student Name: Jeffin Tom
* Student Number:041094535
* Course: 23S_CST8234
* Declaration:
* This is my own original work except where sources have been cited.
*******************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

int main(int argc, char* argv[]) {
    const char* filename = argv[1];
    struct student* students;
    int numStudents;
    int i;
    double averageGrade; 
    double medianGrade;

    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    if (readFile(filename, &students, &numStudents) != 0) {
        printf("Error reading student data from file: %s\n", filename);
        return 1;
    }

    averageGrade = calculateAverageGrade(students, numStudents);
    medianGrade = calculateMedianGrade(students, numStudents);

    qsort(students, numStudents, sizeof(struct student), compareStudents);
    printf("Student Data Sorted by studentID:\n");
    for (i = 0; i < numStudents; ++i) {
        printf("Student ID: %d, Percent Grade: %.2f, Letter Grade: %s\n",
               students[i].studentID, students[i].percentMark, calculateGrade(students[i].percentMark));
    }

    printf("\nMedian Percent Mark: %.2f\n", medianGrade);
    printf("Average Percent Mark: %.2f\n", averageGrade);

    free(students);

    return 0;
}
