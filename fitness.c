#include <stdio.h>
#include <stdlib.h> 
#include <time.h>
#include <math.h>
#include "a4.h"

double comp_distance(const PIXEL *A, const PIXEL *B, int image_size){
  double d = 0;
  int r, g, b;

 // printf("This is difference\n");
  for (int i = 0; i < image_size; i++){
    r = ((A[i].r) - (B[i].r));
    g = ((A[i].g) - (B[i].g));
    b = ((A[i].b) - (B[i].b));
    //printf("%d %d %d\n", r, g ,b);
    d += ((r * r) + (g * g) + (b *b));
  }
  //printf("This is d\n");
  //printf("%f\n", d);
  double distance;
  distance = sqrt(d);
  //printf("This is distance\n");
  //printf("%f\n", distance);
  return distance;
}
void comp_fitness_population(const PIXEL *image, Individual *individual, int population_size){
  int width = individual->image.width;
  int height = individual->image.height;
  int dimension = width * height;
  for (int i = 0; i < population_size; i++){
    double x;
    x = comp_distance(image, individual[i].image.data, dimension);
    //printf("fitness is %f\n", x);
    individual[i].fitness = x;
  }
}