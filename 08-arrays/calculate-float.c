/* author: moemen.ahmed@gmail.com
 * date: 11 May 20
 * purpose: explore crating and manipulating arrays in C
 */


/* NOTICE: in this example I handled arrays by using the array name as a pointer to the first element of the array. There are other different ways to handle arrays in C */

#include <stdio.h>
#include <stdlib.h>

// declare the function calculate
float* calculate(float* numbers, float size);

int  main( int argc, char** argv) {
    // create an array of numbers carrying in the input
    float numbers[argc]; // the length of the array equals the number of arguments - 1
    // retrieve the data casting integer numbers into a new array
    for (int i = 0; i < (argc - 1); i++) {
        // TODO: I should check the input types first

        numbers[i] = atof(argv[i+1]); // (int) (*argv[i+1]) - 48;
        printf("Number : %f\n", numbers[i]);
    }

    float* results;
    results = calculate(numbers, (argc - 1));
    printf("The sum of the numbers is : %f\n", *results);
    printf("The avg of the numbers is : %f\n", *(results + 1));
    return 0;
}


float* calculate(float* numbers, float size) {

    float sum = 0.0;
    float avg = 0.0;
    // printf("the size : %f\n", size);
    for (int i = 0; i < size; i++) {
        printf("Number in calculation: %f\n", *(numbers + i));
        sum += *(numbers + i);
    }
    
    avg = sum /size;
    static float results[2];
    results[0] = sum;
    results[1] = avg;
    return results;
}

