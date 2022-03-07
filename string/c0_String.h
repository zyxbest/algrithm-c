#if !defined(String_H)
#define String_H

#define MAXSIZE 40
typedef struct String
{
    char data[MAXSIZE];
    int length;
} String;

#endif // String_H
