#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char* generate_random_string(size_t length)
{
    /* Alphanumeric character set (62 characters) */
    static const char charset[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
    
    /* Allocate space for the string + null terminator */
    char *random_string = malloc(length + 1);
    if (!random_string)
    {
        return NULL; /* Allocation failed */
    }

    /* Seed the RNG (do this once in your program, not necessarily every time) */
    /* If you do it in the function, either ensure it's done once or remove it if you're seeding elsewhere. */
    srand((unsigned int)time(NULL));

    for (size_t i = 0; i < length; i++)
    {
        int key = rand() % (int)(sizeof(charset) - 1);
        random_string[i] = charset[key];
    }
    random_string[length] = '\0';  /* Null-terminate the string */

    return random_string;
}