#include <stdio.h>
#include <stdlib.h> 
#include <time.h>
#include <math.h>
#include "a4.h"

void mutate(Individual *individual, double rate){


  int n = individual[0].image.width * individual[0].image.height;
  //printf("This is PIXEL:\n");
  //printf("%d \n", n);
  int mpixel= (rate/100)*n;
  //printf("This is # of mutation:\n");
  //printf("%d\n", mpixel);
  for (int i = 0; i < mpixel; i++){
    int x = rand() %n;
    //printf("This is random index:\n");
    //printf("%d\n", x);
    //printf("This is old PiXEL:\n");
    //printf("%d %d %d\n", individual->image.data[x].r, individual->image.data[x].g, individual->image.data[x].b);
    individual->image.data[x].r = (rand() %256);
    individual->image.data[x].g = (rand() %256);
    individual->image.data[x].b = (rand() %256);
    //printf("This is New pIxel:\n");
    //printf("%d %d %d\n", individual->image.data[x].r, individual->image.data[x].g, individual->image.data[x].b);
  }
}

void mutate_population(Individual *individual, int population_size, double rate){
  int i = (population_size / 4);

  for(i; i< population_size; i++){
    mutate(individual+i, rate);
  }
}
