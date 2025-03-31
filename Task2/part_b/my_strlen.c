/* Custom strlen implementation
 * May 16, 2019
 * This code is intended to run on x86-64 little-endian architecture.
 * my_strlen() should work as the libc's strlen() function, assuming that:
 *   1. str points to a valid string.
 *   2. That string is zero-terminated.
 */
 
#include <stdlib.h>
#include <stdint.h>
#define MAX_LEN 100
 
/* https://jameshfisher.com/2017/01/24/bitwise-check-for-zero-byte */
#define zero(v) ((v - 0x0101010101010101) & ~v & 0x8080808080808080)
 
size_t my_strlen(const char * str) {
    uint64_t ans = zero(*(uint64_t *)str);
    size_t z = 0;

    // Check for early null-termination
    if (*str == '\0') return 0;
 
    /* ans = 0 means that the argument does not contain any zero byte */
    while (ans == 0) {
        /* Shift the string and find any zero in the next chunk */
        str += 8;
        z += 8;
        ans = zero(*(uint64_t *)str);
    }
 
    /* Find the first non-null byte, starting by the least significant one */
    while ((ans & 0xFF) == 0) {
        ans >>= 8;
        ++z;
    }
 
    return z;
}
 
/******************************************************************************/
 
#include <stdio.h>
#define strlen my_strlen
 
int main(int argc, char ** argv) {


    if (argc > 1) {
        printf("%lu\n", strlen(argv[1]));
    } else {
        fprintf(stderr, "Syntax: %s <string>\n", argv[0]);
    }

    //char *str = malloc(8);
    //memcpy(str, "ABCDEFG", 6); // no null terminator
    //printf("%lu\n", strlen(str));

    // Create a buffer (not null-terminated)
    //char buffer[] = {'H', 'e', 'l', 'l', 'o', ' ', 'w', 'o', 'r', 'l', 'd','\0'}; // no '\0' at the end


    /*
    // Allocate only 16 bytes, but we'll read more than that
    char *buf = malloc(16);
    if (!buf) {
        perror("malloc failed");
        return 1;
    }

    // Fill with non-null characters, no null terminator
    memcpy(buf, "ABCDEFGHIJKLMNO", 15); // 15 non-null characters
    buf[15] = '\0'; // Only 1 null byte at the very end

    // Create a pointer near the end of the buffer (this is dangerous!)
    char *near_end = buf + 14; // Only 7 bytes left until null terminator

    printf("Calling unsafe strlen on near_end...\n");
    size_t len = my_strlen(near_end); // May cause segfault or undefined behavior

    printf("Length: %zu\n", len);
    free(buf);
*/

    return 0;


}