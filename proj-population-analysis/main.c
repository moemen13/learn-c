/** by: moemen.ahmed@gmail.com
 * date: 16 May 20
 * referencei to stackoverflow: https://stackoverflow.com/questions/61830512/how-can-i-make-fread-work-properly-in-c-it-fills-my-dynamic-array-with-zeroes 
 * purpose: collect and store countires population input in a binary file, then re-read the file, and sort it by population.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NCHAR 64

// define the main Country struct
typedef
    struct Country_
    {
        char country[NCHAR];
        long int population;
        float world_share;
    }
Country;

// store countries count in a global variable
int count = 0;
// store total population in a global variable
long int totalPopulation = 0;
// declare the global list of countries as pointer to an array of Country
Country* countries;

// functions declaration
// receives the user input and store it in memory
void addCountry();
// update the world_share% in each of the structs in memory
void updateWorldShare();
// list countries data from memory
void listCountries();
// write the list of countries to the file world.dat
void writeCountries(); 
// read the data from the file to memory
void readCountries ();
// calculate the number of records in the file; update the global variable 'count'
int fsize(FILE* file); 
// sort the records in the memory
void sortCountriesByPopulation();

// main function
int main(int argc, char **argv) {
    int x = 0;
    while (x < 5) {
        addCountry();
        x += 1;
    }
    updateWorldShare();
    listCountries();
    writeCountries();
    // let us reset the data, so everything comes from reading the file afterwards.
    free(countries);
    totalPopulation = 0;
    count = 0;
    // read the binary file
    readCountries();
    sortCountriesByPopulation();
    listCountries();
    free(countries);
    return 0;
}

void listCountries(){
    // int count = getCountriesCount();
    Country* currCountry;
    for (int i = 0; i < count; i++) 
    {
        currCountry = countries + (i * sizeof(Country));
        printf("Country: %s - Population: %ld - World Share: %f %%\n", currCountry->country, (long int) currCountry->population, (float) currCountry->world_share * 100);
    }
    return;
}


void addCountry()
{
    Country new;
    printf("Enter Country Name.");
    scanf("%s", new.country);
    printf("Enter Population.");
    scanf("%ld", &new.population); 
    // ignore calculating world-share% during input.
    new.world_share = 0.0;
    countries = (Country *) realloc( countries, (count + 1) * sizeof(Country));
    *(countries + (count ) * sizeof(Country)) = new;
    // update the goabl count and totalPopulation
    totalPopulation += new.population;
    count += 1;
    return ;
}

void updateWorldShare(long int population){
    printf("... updadting world share %% \n");
    printf("... total population : %ld\n", (long int) totalPopulation);
    Country* currCountry;
    for (int i = 0; i < count; i++) {
        currCountry = countries + (i * sizeof(Country));
        currCountry->world_share = ((float) currCountry->population )/ ((float) totalPopulation);
    }
    return;
}

void updateTotalPopulation(){
    printf("... updadting TotalPopulation\n");
    totalPopulation = 0;
    Country* currCountry;
    for (int i = 0; i < count; i++) {
        currCountry = countries + (i * sizeof(Country));
        totalPopulation += currCountry->population; 
    }
    printf("... total population : %ld\n", (long int) totalPopulation);
    return;
}

void sortCountriesByPopulation(){
    printf("... sorting countries by population, Count: %d\n", count);
    Country *xCountry, *yCountry;
    for (int i = 0; i < (count - 1); i++) {
        for (int j = 0; j < (count - 1 - i ); j++) {
            xCountry = countries + (j * sizeof(Country));
            yCountry = countries + ((j+1) * sizeof(Country));
            if (xCountry->population > yCountry->population){
                // do a swap
                Country tempCountry; 
                tempCountry = *xCountry;
                *xCountry = *yCountry;
                *yCountry = tempCountry;
            }
        }
    }
    printf("Sort is completed successfully using bubble-sorting technique!\n");

    return;
}

void readCountries(void)//main
{
     printf("reading ...... \n");
     FILE * worldData;
     worldData = fopen("world.dat", "rb");
     if(worldData == NULL)
     {
         printf("NO FILE CAN BE ACSESSED\n");
         exit(1);
     }
     long size = fsize(worldData);
     count = size / sizeof(Country);
     Country * countries;
     countries = (Country *) malloc(size);
     fread(countries, sizeof(Country), count, worldData); 
     fclose(worldData);
     updateTotalPopulation();
     return;
}

int fsize(FILE* file) {
    fseek(file, 0L, SEEK_END);
    int size = ftell(file);
    fseek(file, 0L, SEEK_SET);
    return size;
}


void writeCountries( void) 
{
     FILE * worldData;
     worldData = fopen("world.dat", "wb");
     fwrite(countries, sizeof(Country), count, worldData); 
     fclose(worldData);
 }
