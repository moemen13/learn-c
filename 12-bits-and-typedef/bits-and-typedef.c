/* author: moemen.ahmed@gmail.com
 * date: 11 May 20
 * purpose: go through typedef, and data-bits in C language
 */

#include <stdio.h>
#include <string.h>

typedef struct Persons {
    char name[50];
    unsigned int age:6;
    unsigned int weight:7;
} Person;

int main( int argc, char** argv[] ) {
    Person p1;
    strcpy(p1.name, "Moemen Ahmed");
    // notice that the largest integer that can be presented in age:6 is 63; afterwards the compiler shall flip to 0 with a warning
    p1.age = 63;
    // notice that the largest integer that can be presented by Weigh is 127; afterwards the compiler shall flip to 0 with a warning
    p1.weight = 127;

    printf("P1 is a person; his name is %s\n", p1.name);
    printf("P1 age is %d\n", p1.age);
    printf("P1 weight is %d\n", p1.weight);


    return 0;
}

