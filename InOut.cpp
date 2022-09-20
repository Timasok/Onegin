#include "unit.hpp"

/// @brief Чтение текстового файла и перенос значений в буфер
/// @param FileName - имя файла
/// @param buf_length - указатель на длину буфера
/// @return buf - указатель на заполненный буфер
char* readFile(char* FileName, size_t* buf_length)
{
    //TODO вынести в отдельную функцм
    //assert(FileName != nullptr);
    //assert(buf_length != nullptr);

    FILE *f = fopen(FileName,"r+b");
    struct stat stbuf;
    //файл открылся
    assert(f != NULL);

    fstat (fileno (f), &stbuf);

    char* buf= (char *)calloc(stbuf.st_size, sizeof(char));
    fread(buf, sizeof(char), stbuf.st_size, f);
    buf[stbuf.st_size - 1] = '\0';

    fclose(f);

    *buf_length = stbuf.st_size;
    return buf;
}

/// @brief Функция замены '\n' на '\0' в буфере 
/// @param buf - указатель на первый элемент буфера
/// @param buf_length - длина буфера
void replaceSlashN(char* buf, size_t buf_length)
{
    //assert(buf != nullptr);
    //assert(isfinite(buf_length));

    for (int i = 0; i < buf_length; i++)
    {
        if(*(buf + i) == '\n')
        {
            *(buf + i) = '\0';
        }
    }


}

/// @brief Функция заполняет соответствующий массив указателями на начала строк
/// @param lines - указатель на массив структур
/// @param number_of_lines - количество строк склеенных в буфере
/// @param buf - указатель на начало буфера
/// @param buf_length - длина буфера
void fillStructfromBuf(Line *lines, int number_of_lines, char* buf, size_t buf_length)
{
    //assert(arr != nullptr);
    //assert(buf != nullptr);
    //assert(isfinite(number_of_lines));

    for (int i = 0; i < number_of_lines; i++)
    {
        lines[i].string = buf;
        lines[i].line_length = 1;

        while(*(++buf) != '\0')
        {
            lines[i].line_length++;
        }
        buf++;
    }
    
}

/// @brief Функция возвращает количество раз, которое данный символ встретился в строке
/// @param buf - указатель на строку
/// @param buf_length - длина строки
/// @param ch - символ, который надо проверить
/// @return количество раз, которое он встретился
int getNumberOfChar(char * buf, size_t buf_length, char ch)
{
    //assert(buf!= nullptr);

    int num = 1;

    for (size_t i = 0; i < buf_length; i++)
    {
        if(*(buf + i) == ch)
        {
            num++;
        }
    }   
   
    return num;
}

/// @brief Функция печатает строчки из массива структур
/// @param lines 
/// @param number_of_lines 
void printLines(Line* lines, int number_of_lines)
{
//TODO line_idx pfvtybnm
    assert(lines != nullptr);
    assert(isfinite(number_of_lines));

    for (int line_idx = 0; line_idx < number_of_lines; line_idx++)
    {
        printf("%s\n", lines[line_idx].string);
    }

}

void printBuf(char *buf, int buf_length)
{
    // assert(buf != nullptr);
    // assert(isfinite(buf_length));

    for (int i = 0; i < buf_length; i++)
    {
        if(buf[i] == '\0')
        {
            putchar('\n');
        }
        else
        {
            putchar(buf[i]);
        }
    }
}

void writeLinesInFile(char* file_name, Line * lines, int number_of_lines)
{
/**/
    ////asserts
    FILE *f = fopen(file_name,"ab");
{
    for (int i = 0; i < number_of_lines; i++)
    {
        fwrite(lines[i].string, sizeof(char), lines[i].line_length+1, f);
        fputc('\n', f);
    }

    fclose(f);

}