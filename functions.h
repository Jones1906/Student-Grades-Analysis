/*******************************************************************
* Student Name: Jeffin Tom
* Student Number:041094535
* Course: 23S_CST8234
* Declaration:
* This is my own original work except where sources have been cited.
*******************************************************************/


#ifndef STUDENT_H
#define STUDENT_H

struct student {
    int studentID;
    double percentMark;
};

int readFile(const char* filename, struct student** students, int* numStudents);
int compareStudents(const void* a, const void* b);
char* calculateGrade(double percentMark);
double calculateAverageGrade(const struct student* students, int numStudents);
double calculateMedianGrade(const struct student* students, int numStudents);
int comparePercentMarks(const void* a, const void* b); 

#endif
