#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

// enum Errors{
//     OPEN_FILE_ERR = 0
//     LENGTH_FILE_ERR = 1

// };
//выводить в stderr

struct Line
{
    char *string;
    int line_length;//за исключением \0
};

// int IntCmp(const void *aPtr, const void* bPtr);
// int strcmp1(const char *s, const char *t);

int cmpChars(char c1, char c2);
int straightCmp(const void* line1Ptr, const void* line2Ptr);
int reverseCmp (const void* line1Ptr, const void* line2Ptr);

char* readFile(char* FileName, size_t* buf_length);
void replaceSlashN(char* buf, size_t buf_length);
void fillStructfromBuf(Line *lines, int number_of_lines, char* buf, size_t buf_length);
int getNumberOfChar(char * buf, size_t buf_length, char ch);
void printLines(Line* lines, int number_of_lines);
void printBuf(char *buf, int buf_length);
void writeLinesInFile(char* FileName, Line * lines, int number_of_lines);