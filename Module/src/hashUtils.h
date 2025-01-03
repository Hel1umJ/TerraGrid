#ifndef HASHUTILS
#define HASHUTILS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * Generates a random alphanumeric string of the specified length.
 * 
 * @param length The desired length of the random string (not counting the null terminator).
 * @return A pointer to a newly allocated null-terminated string.
 *         The caller is responsible for freeing the returned pointer.
 */
char* generate_random_string(size_t length);

#endif