//Rallysort: sort values using game loop
//
//Run:     ./rallysort 2 7 1 8 2 8 1 8 2 8 4

#include <stdio.h>
#include <stdlib.h>

typedef struct rallycar {
    double speed;   //gather as input
    double position;//derived
    int finished;   //derived
} Rallycar;

#define FLOAT_FMT "%.1f"

int main(int argc, char *argv[])
{
    Rallycar cars[argc];
    int i;

    //Initialize cars
    for (i = 0; i < argc; i++)
    {
        Rallycar car;
        car.speed = atof(argv[i]);//read from command line args, atof(const char *str) is for convert a character string to a double precision format floating point
        car.position = 0;
        car.finished = 0;

        if (car.speed <= 0)
            car.finished = 1; //ignore

        //printf("Read car with speed: " FLOAT_FMT "\n", car.speed);
        cars[i] = car;
    }

    double time = 0;
    double time_delta = 0.1;
    double finish_line = 123456.00;
    int num_cars = argc;

    //Game loop or physics loop
    while(1)
    {
        int cars_racing_still = 0;
        for (i = 0; i < num_cars; i++)
        {
            Rallycar car = cars[i];

            if (car.finished)
                continue;

            car.position += time_delta * car.speed;

            if (car.position >= finish_line)
            {
                car.finished = 1;
                //printf("Output: " FLOAT_FMT "\n", car.speed);
                printf(FLOAT_FMT "\t", car.speed);
            }
            else
            {
                cars_racing_still = 1;
            }

            cars[i] = car;
        }

        time += time_delta;

        if (!cars_racing_still)
            break;
    }
    //printf("Done\n");
    return 0;
}

/*
Like sleepsort, rallysort is a suboptimal sorting algorithm whose usefulness lies in indicating a particular approach to
computation: in this case the use of a time-based game loop to solve problems. A game loop that tracks the positions of moving
to racecars. A race is simulated, and the cars are returned in the order they cross the finish line. The natural rallysort
implementation sorts values in descending sort order.
objects can be used to provide answers to computational questions. Rallysort works by assigning the values to be sorted as speeds

While rallysort is a toy example, it is a representation of how game loops can be applied to more interesting questions. Game
simulation is useful for objects with analogues in the physical world. Instead of an analytical solution, game simulation could be
used to sort cars with tires of various coefficients of friction in terms of time to completion over a given terrain of piecewise
varying type. Game simulation is also useful for questions about objects whose comparison function is adversarially competitive or
is rooted in some linked, interacting physical model of the world: for instance, which bot AI lives longest in a Quake match, or
which ant colony collects the most food.

 */
