#include "unit.hpp"


int main()
{

    char FileName[] = "boba.txt";
    int number_of_lines = 0;
    size_t buf_length = 0;

    char* buf = readFile(FileName, &buf_length);
    // printf("%s\n", buf);

    number_of_lines = getNumberOfChar(buf, buf_length, '\n');    
    replaceSlashN(buf, buf_length);  
    // printBuf(buf, buf_length);

    // char **basic = (char **)calloc(number_of_lines, sizeof(char *));
    Line * Basic = (Line *)calloc(number_of_lines, sizeof(Line));

    fillStructfromBuf(Basic, number_of_lines, buf, buf_length);

    printf("Buffer: \n");    
    printBuf(buf, buf_length);
    // printLines(Basic, number_of_lines);

    // printf("\tStraight sort\n");    
    // qsort((void *)Basic, number_of_lines, sizeof(Line), straightCmp);
    // printLines(Basic, number_of_lines);

    // char outputFile[] = "output.txt";
    // writeLinesInFile(outputFile, Basic, number_of_lines);

    printf("\nReverse sort\n");    
    qsort((void *)Basic, number_of_lines, sizeof(Line), reverseCmp);
    printLines(Basic, number_of_lines);

    ////////////////////////////////////////////
    // printf("%d\n", reverseCmp((void *)Basic, (void *)(Basic + 1)));


    // printf("%d %s\n", Basic->line_length, Basic->string);
    // printf("%d %s\n", (Basic+1)->line_length, (Basic+1)->string);
    // printf("%d %s\n", (Basic+2)->line_length, (Basic+2)->string);

    // qsort(basic, number_of_lines, sizeof(Line), *straightCmp);
    // // printf("%d\n", '8');
    // printf("%d\n", straightCmp((void *)Basic, (void *)(Basic + 1)));

    // printf("%d\n", cmpChars('a', 'b'));
    // printf("%d\n", cmpChars('a', 'B'));
    // printf("%d\n", cmpChars('A', 'b'));
    // printf("%d\n", cmpChars('A', 'a'));

    // for (int i = 0; i < number_of_lines; i++)
    // {
    //     Basic[i].string = "wow";      
    // }

    // printLines(Basic, number_of_lines);
    // for (int i = 0; i < number_of_lines; i++)
    // {
    //     printf("%d\n", Basic[i].line_length);         
    // }

// printf("Compiled nicely -line: %d file: %s\n", __LINE__, __FILE__);






    return 0; 
}