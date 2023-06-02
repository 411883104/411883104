/*
 * @Author       : Outsider
 * @Date         : 2023-05-08 18:23:14
 * @LastEditors  : Outsider
 * @LastEditTime : 2023-05-08 18:34:18
 * @Description  : In User Settings Edit
 * @FilePath     : \Lq\other\linux_text.cc
 */
#include <stdlib.h>

#include <stdio.h>

#include <string.h>

char *upcase(char *string, int length);

int main(void)

{
    char *buf, *newstr;

    /*
    这里初始化字符数组错误
    因为 oldstr1 和 oldstr2 被定义为字符数组，使用{}初始化时应该使用{'char',...}初始化
    char oldstr1[] = {'a','b','c','d','e','f','g'};
    char oldstr2[] = {'x','y','z'};
    
    */
    char oldstr1[] = {“abcdefg”};
    char oldstr2[] = {“xyz”};

    int counter;

    /*
    1. malloc 的返回值类型为 void*, 不能直接赋值给char* buf,
    */
    buf = malloc(15);

    strcpy(buf, "CHANGE STRINGS.");

    fprintf(stdout, "% s\n", buf);

    free(buf);

    for (counter = 0; counter < sizeof(oldstr1); counter++)

    {
        putchar(oldstr1[counter]);

        putchar(oldstr2[counter]);
    }

    newstr = upcase(oldstr1, sizeof(oldstr1));

    fprintf(stdout, "NEW STRING 1 : % s.\n", newstr);

    newstr = upcase(oldstr2, sizeof(oldstr2));

    fprintf(stdout,"NEW STRING 2 : % s.\n", newstr);

    free(newstr);

    strcpy(buf, "THE END.");

    fprintf(stdout, "% s\n", buf);

    free(buf);
}

char *upcase(char *string, int length)

{
    char *newstring;

    char temp;

    int counter;

    newstring = calloc(length, sizeof(char));

    for (counter = 0; counter < length; counter++)

    {
        temp = *(string + counter);

        if (temp >= 97 && temp <= 122)

            *(newstring + counter) = temp - 32;

        else

            *(newstring + counter) = temp;
    }

    return newstring;
}