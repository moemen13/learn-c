/* author: moemen.ahmed@gmail.com
 * date : 11May20
 * purpose: experiement with files functions 
 */

#include <stdio.h>
#include <string.h>

int main( int argc, char** argv[] ){
    FILE* f;
    char st[100];
    f = fopen("./test.txt", "r+");
    // reading the file using fgets()
    fgets(st, 50, f);
    printf("The statement reads: %s.\n", st);
    fclose(f);

    // appending to the file using fputs()
    f = fopen("./test.txt", "a");
    fputs("I am a project manager.\n", f);
    fclose(f);


    // writing to the file using fprintf()
    f = fopen("./test.txt", "a");
    fprintf(f, "I am a tall man, and I like it :-)\n");
    fclose(f);

    return 0;
}

    
