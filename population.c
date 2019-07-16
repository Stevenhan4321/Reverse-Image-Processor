#include <stdio.h>
#include <stdlib.h> 
#include <time.h>
#include <math.h>
#include "a4.h"


PIXEL *generate_random_image(int width, int height, int max_color){

  int dimension = width * height;
  PIXEL *randimg;
  randimg = (PIXEL *)malloc(dimension * (sizeof(PIXEL)));

  for (int i = 0; i < dimension; i++){                //Looping to create random pixels 
    randimg[i].r = rand() % (max_color+1);
    randimg[i].g = rand() % (max_color+1);
    randimg[i].b = rand() % (max_color+1);
  }  
  //printf("This is random image\n");
  //PRINTING TO SEE IF IT IS CORRECT    
  //for (int i = 0; i < dimension; i++){
    //printf("%d %d %d\n", randimg[i].r, randimg[i].g, randimg[i].b);
  //}   
  return randimg;
}

Individual *generate_population(int population_size, int width, int height, int max_color){
  Individual *pop;           
  pop = (Individual *)malloc(population_size * (sizeof(Individual)));      //creates an array of Individuals
  int dimension = width * height;

  for(int i=0; i < population_size; i++){
    pop[i].image.data = generate_random_image(width, height, max_color);          //loops through the array, accesses the PPM_IMAGE structure and points to array of PIXELS
    pop[i].image.width = width ;    
    pop[i].image.height = height ;
    pop[i].image.max_color = max_color ;    
  }
  /*
  for(int i=0; i < population_size; i++){
    //printf("This is individual\n");    
    for(int j=0; j<dimension; j++)
      //printf("%d %d %d\n", pop[i].image.data[j].r, pop[i].image.data[j].g, pop[i].image.data[j].b);
  }*/
  return pop;
}
