#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct {

   char   name[20];
   double diameter;
   int    moons;
   double orbit_time;
   double rotation_time;

} planets;

void print_planet(planets pl);
int planet_equal(planets planet1,planets planet2);
int scan_planet(planets *plnp);
planets get_planet(void);


int main()
{

    planets current_planet;
    strcpy(current_planet.name, "Jupiter");
    current_planet.diameter = 142800;
    current_planet.moons = 16;
    current_planet.orbit_time = 11.9;
    current_planet.rotation_time = 19.3;

    /** input parameteren er en type af struct kaldt "current_planet"; */
    print_planet(current_planet);

    /** printf("Accessing our struct: %s, %lf , %d %lf %lf \n",current_planet.name,current_planet.diameter,current_planet.moons,current_planet.orbit_time,current_planet.rotation_time); */

    printf("\n");

    planets current_planet2;
    strcpy(current_planet2.name, "Dennis");
    current_planet2.diameter = 14280;
    current_planet2.moons = 28;
    current_planet2.orbit_time = 14.9;
    current_planet2.rotation_time = 13.3;
    print_planet(current_planet2);

    int result = planet_equal(current_planet,current_planet2);
    /** below result returns 1 if all components in the structs match with each other, 0 if not */

    (result == 0) ? printf("Structures do not match") : printf("Structures do match");
    printf("\n");

    /** scan planet needs an address (of our structure and we display it afterwards) */

    result = scan_planet(&current_planet);
    printf("result is %d \n",result);

    print_planet(current_planet);



    return 0;
}

/** procedure that takes a struct as an argument and prints it */

void print_planet(planets pl)         /* input - one planet structure */
 {
 printf(" %s \n", pl.name);
 printf(" Equatorial diameter: %.0f km\n", pl.diameter);
 printf(" Number of moons: %d\n", pl.moons);
 printf(" Time to complete one orbit of the sun: %.2f years\n", pl.orbit_time);
 printf(" Time to complete one rotation on axis: %.4f hours\n", pl.rotation_time);
}

/**
 * Determines whether or not the components of planet1 and planet2 match (two input arguments)
 */

int planet_equal(planets planet_1,planets planet_2)
{
    /** compares each type's value with planet1/2 , if they are equal we print out 1 if both planets are equal */

    return ((strcmp(planet_1.name, planet_2.name) == 0) &&
            planet_1.diameter == planet_2.diameter &&
            planet_1.moons == planet_2.moons &&
            planet_1.orbit_time == planet_2.orbit_time &&
            planet_1.rotation_time == planet_2.rotation_time);

}




/**
2. * Fills a type planet_t structure with input data. Integer returned as
3. * function result is success/failure/EOF indicator.
4. * 1 => successful input of one planet
5. * 0 => error encountered
6. * EOF => insufficient data before end of file
7. * In case of error or EOF, value of type planet_t output argument is
8. * undefined.
9. */

int scan_planet(planets *plnp) /** output - address of planet_t structure (called planets for me) */
{
 int result;

 result = scanf("%s%lf%d%lf%lf", (*plnp).name, &(*plnp).diameter, &(*plnp).moons, &(*plnp).orbit_time, &(*plnp).rotation_time);

     /** if result is 1, we have succesfully copied data into our struct */

     if (result == 5)
         result = 1;
     else if (result != EOF)
         result = 0;

     return (result);


 }

/** below same as line 109 scanf inputs, more readible*/
/** result = scanf("%s%lf%d%lf%lf", plnp->name,
 &plnp->diameter,
 &plnp->moons,
 &plnp->orbit_time,
 &plnp->rotation_time); equivalent to above function (*) statements */

 /** below function gets and returns a "planets" structure
 /** same effect as scan planet, but scanplanet has more usability as we know if the result returned is corresponding to our input parameters being filled up appropriately */

planets get_planet(void)
{
   planets planet;

   scanf("%s%lf%d%lf%lf", planet.name,
   &planet.diameter,
   &planet.moons,
   &planet.orbit_time,
   &planet.rotation_time);
    return (planet);
 }



