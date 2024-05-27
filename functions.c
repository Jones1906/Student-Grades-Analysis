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

/***
 * Function to read student data from a file.
 * 
 * @param filename The name of the file to read.
 * @param students A pointer to the array of student structures.
 * @param numStudents A pointer to the variable to store the number of students.
 * @return 0 if successful, 1 if an error occurs.
 */
int readFile(const char* filename, struct student** students, int* numStudents) {
   
    long fileSize; 
   
    FILE* file = fopen(filename, "r");
    if (!file) {
        return 1;
    }
    fseek(file, 0, SEEK_END);
    fileSize = ftell(file);
    fseek(file, 0, SEEK_SET);

    *numStudents = fileSize / sizeof(struct student);
    *students = (struct student*)malloc(*numStudents * sizeof(struct student));

    if (*students == NULL) {
        fclose(file);
        return 1;
    }

    fread(*students, sizeof(struct student), *numStudents, file);
    fclose(file);

    return 0;
}

/***
 * Function to compare students based on their studentID.
 * 
 * @param a Pointer to the first student structure.
 * @param b Pointer to the second student structure.
 * @return The difference between studentIDs.
 */
int compareStudents(const void* a, const void* b) {
    return ((struct student*)a)->studentID - ((struct student*)b)->studentID;
}

/***
 * Function to calculate the letter grade based on the percent mark.
 * 
 * @param percentMark The percentage mark of the student.
 * @return The letter grade.
 */
char* calculateGrade(double percentMark) {
    if (percentMark >= 90.0) {
        return "A+";
    } else if (percentMark >= 85.0) {
        return "A";
    } else if (percentMark >= 80.0) {
        return "A-";
    } else if (percentMark >= 77.0) {
        return "B+";
    } else if (percentMark >= 73.0) {
        return "B";
    } else if (percentMark >= 70.0) {
        return "B-";
    } else if (percentMark >= 67.0) {
        return "C+";
    } else if (percentMark >= 63.0) {
        return "C";
    } else if (percentMark >= 60.0) {
        return "C-";
    } else if (percentMark >= 57.0) {
        return "D+";
    } else if (percentMark >= 53.0) {
        return "D";
    } else if (percentMark >= 50.0) {
        return "D-";
    } else {
        return "F";
    }
}


/***
 * Function to calculate the average grade of a group of students.
 * 
 * @param students Array of student structures.
 * @param numStudents Number of students in the array.
 * @return The average percent grade.
 */
double calculateAverageGrade(const struct student* students, int numStudents) {
    double sum = 0.0;
    int i;
    for ( i = 0; i < numStudents; ++i) {
        sum += students[i].percentMark;
    }

    return sum / numStudents;
}


/***
 * Function to calculate the median grade of a group of students.
 * 
 * @param students Array of student structures.
 * @param numStudents Number of students in the array.
 * @return The median percent grade.
 */
double calculateMedianGrade(const struct student* students, int numStudents) {
    double median = 0.0;
    int middle;
    double* percentMarks = (double*)malloc(numStudents * sizeof(double));
    int i;

    for (i = 0; i < numStudents; ++i) {
        percentMarks[i] = students[i].percentMark;
    }

    qsort(percentMarks, numStudents, sizeof(double), comparePercentMarks);

    middle = numStudents / 2;

    if (numStudents % 2 == 0) {
        median = (percentMarks[middle - 1] + percentMarks[middle]) / 2.0;
    } else {
        median = percentMarks[middle];
    }

    free(percentMarks);
    return median;
}
/***
 * Function to compare percent marks for sorting.
 * 
 * @param a Pointer to the first percent mark.
 * @param b Pointer to the second percent mark.
 * @return -1 if a < b, 0 if a == b, 1 if a > b.
 */
int comparePercentMarks(const void* a, const void* b) {
    double diff = *((double*)a) - *((double*)b);
    return (diff > 0) - (diff < 0);
}