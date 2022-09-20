#include "unit.hpp"

int IntCmp(const void* aPtr, const void* bPtr)
{
    const int *a = (const int*)aPtr;
    const int *b = (const int*)bPtr;
    return *a - *b;
    // return *(const int*)aPtr - *(const int*)bPtr;   
}

/// @brief Функция сравнивает буквы английского алфавита не зависимо от их регистра
/// @param c1 первая буква
/// @param c2 вторая буква
/// @return разность этих нижних регистров этих букв в int-овом представлении
int cmpChars(char c1, char c2)
{
    //if(isupper(c1))
    c1 = tolower(c1);
    //if(isupper(c2))
    c2 = tolower(c2);

    return c1 - c2;
    
}


int straightCmp(const void* line1Ptr, const void* line2Ptr)
{
    Line *line1 = (Line *)line1Ptr;
    Line *line2 = (Line *)line2Ptr;
    // printf("%s\n%s", (*line1).string, ((*line2).string));
    
    do{
        if(*((*line1).string) == '\0')
            return *((*line1).string);

        if(*((*line2).string) == '\0')
            return -*((*line2).string);

        while(!isalpha(*((*line1).string)))
           (*line1).string++;

        while (!isalpha(*((*line2).string)))
            (*line2).string++;
        
        if(cmpChars(*((*line1).string),*((*line2).string)) != 0)
            return cmpChars(*((*line1).string),*((*line2).string));        
    
    } while (!((*((*line1).string++) == '\0') && (*((*line2).string++) == '\0')));

    return 0; 
}


int reverseCmp(const void* line1Ptr, const void* line2Ptr)
{   
    assert(line1Ptr);
    assert(line2Ptr);
    
    Line *line1 = (Line *)line1Ptr;
    Line *line2 = (Line *)line2Ptr;
    assert(line1->string);
    assert(line2->string);

    // printf("%s\n%s", (*line1).string, ((*line2).string));
    // assert(line1 != nullptr);
    // assert(line2 != nullptr);

    int length_first = line1->line_length, k2 = line2->line_length;    

    while ((length_first-- >= 0) && (k2-- >= 0)){

        // if (k2 == 0)
        //    return *((*(line1+length_first)).string);

        // if (length_first == 0)
        //    return -*((*(line2+k2)).string);

        while (!isalpha(line1->string[length_first]))
            length_first--;

        while (!isalpha(line2->string[k2]))
            k2--;

        if (int cmp_res = cmpChars(line1->string[length_first], line2->string[k2]) != 0)
            return cmp_res;        
    
    }

    return 0; 
}

// void mySort(void * lines, size_t number_of_lines, size_t sizeOfElement, int (*compar)   )