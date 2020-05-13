/* author: moemen.ahmed@gmail.com
 * date: 11 May 20
 * purpose: test the looping  and recursion techniques in C language
 */

#include <stdio.h>

// note that the below purpose is to demonstrate the different looping techniques only.
// nothing specific is required to result, no determined pattern to match
int main( int argc, char** argv){
    for (int i = 0; i <= 9; i++) {
        int x = 0, y = 0;
        while (x <= i) {
            printf("-");
            x += 1;
        }
        printf("This is loop number : %d  ", i);

        do {
            printf("+");
            y += 1;
        } while (y < (10 - i));
        printf("\n");
    }
    return 0;
}


