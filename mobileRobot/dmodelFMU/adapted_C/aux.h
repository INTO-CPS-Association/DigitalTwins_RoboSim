#ifndef AUX__H
#define AUX__H

#ifdef DEBUG
#define DPRINTF(arg) printf arg
#else
#define DPRINTF(arg)
#endif

#include <string.h>
#include <stdlib.h>

FILE *log_file;

#define err_abort(code, text)                              \
    do                                                     \
    {                                                      \
        fprintf(stderr, "%s at \"%s\":%d: %s\n",           \
                text, __FILE__, __LINE__, strerror(code)); \
        abort();                                           \
    } while (0)

#define errno_abort(text)                                   \
    do                                                      \
    {                                                       \
        fprintf(stderr, "%s at \"%s\":%d: %s\n",            \
                text, __FILE__, __LINE__, strerror(errno)); \
        abort();                                            \
    } while (0)

char *concat(char *str1, char *str2)
{
    char *result = (char *)malloc(sizeof(char) * (strlen(str1) + strlen(str2) + 1));
    strcpy(result, str1);
    strcpy(result + strlen(str1), str2);
    return result;
}

// Temporary solution to trim strings taken from http://www.martinbroadhurst.com/trim-a-string-in-c.html

char *ltrim(char *str, const char *seps)
{
    size_t totrim;
    if (seps == NULL)
    {
        seps = "\t\n\v\f\r ";
    }
    totrim = strspn(str, seps);
    if (totrim > 0)
    {
        size_t len = strlen(str);
        if (totrim == len)
        {
            str[0] = '\0';
        }
        else
        {
            memmove(str, str + totrim, len + 1 - totrim);
        }
    }
    return str;
}

char *rtrim(char *str, const char *seps)
{
    int i;
    if (seps == NULL)
    {
        seps = "\t\n\v\f\r ";
    }
    i = strlen(str) - 1;
    while (i >= 0 && strchr(seps, str[i]) != NULL)
    {
        str[i] = '\0';
        i--;
    }
    return str;
}

char *trim(char *str, const char *seps)
{
    return ltrim(rtrim(str, seps), seps);
}

float randnat()
{
    // This procedure was not defined and must be completed
}
// int random_sign()
// {
//     // This procedure was not defined and must be completed
// }

float dot(float x1[2], float x2[2])
{
    // This procedure was not defined and must be completed
}
float distance(float x1[2], float x2[2])
{
    // This procedure was not defined and must be completed
}
float unit(float x[2])
{
    // This procedure was not defined and must be completed
}
float angle_between(float x1[2], float x2[2])
{
    // This procedure was not defined and must be completed
}
float randomcoef()
{
    // This procedure was not defined and must be completed
}
int randomnat()
{
    // This procedure was not defined and must be completed
}

float randcoef()
{
    // This procedure was not defined and must be completed
}
float calculate_turn_angle(float x1[2], float x2[2])
{
    // This procedure was not defined and must be completed
}
float L2(float x[2])
{
    // This procedure was not defined and must be completed
}

#endif