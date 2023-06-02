/*
 * @Author       : Outsider
 * @Date         : 2023-05-08 18:23:14
 * @LastEditors  : Outsider
 * @LastEditTime : 2023-05-08 18:52:07
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
    // char oldstr1[] = {“abcdefg”};
    // char oldstr2[] = {“xyz”};
    char oldstr1[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g'};
    char oldstr2[] = {'x', 'y', 'z'};

    int counter;

    /*
    1. malloc 的返回值类型为 void*, 不能直接赋值给char* buf，应该使用强制类型转换
       buf=(char*)malloc(15);
    2. malloc 申请内存不一定会成功，应该检查是否返回 NULL
    */
    buf = malloc(15);

    // 此处输出的字符串有16个字符，而buf的申请的空间只有15个字符
    strcpy(buf, "CHANGE STRINGS.");

    fprintf(stdout, "%s\n", buf);

    free(buf);

    for (counter = 0; counter < sizeof(oldstr1); counter++)

    {
        putchar(oldstr1[counter]);
        // oldstr1和oldstr2的长度并不相同，会导致内存越界访问得到不正确的结果
        putchar(oldstr2[counter]);
    }

    newstr = upcase(oldstr1, sizeof(oldstr1));

    fprintf(stdout, "NEW STRING 1 : %s.\n", newstr);

    // 此处存在内存泄漏。upcase 中申请了内存，下面只进行了一次释放

    newstr = upcase(oldstr2, sizeof(oldstr2));

    fprintf(stdout, "NEW STRING 2 : %s.\n", newstr);

    free(newstr);

    strcpy(buf, "THE END.");

    fprintf(stdout, "%s\n", buf);

    free(buf);
}

char *upcase(char *string, int length)

{
    char *newstring;

    char temp;

    int counter;

    // calloc 返回的是 void*, 无法直接将 void* 赋值给 char*，应进行强制类型转换 
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