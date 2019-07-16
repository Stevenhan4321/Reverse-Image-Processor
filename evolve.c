#include <stdio.h>
#include <stdlib.h> 
#include <time.h>
#include <math.h>
#include "a4.h"

void swap(Individual *a, Individual *b) 
{ 
    Individual t = *a; 
    *a = *b; 
    *b = t; 
} 

int partition (Individual a[], int low, int high) 
{ 
    int pivot = a[high].fitness;    // pivot 
    int i = (low - 1);  // Index of smaller element   
    for (int j = low; j <= high- 1; j++) 
    { 
        // If current element is smaller than or 
        // equal to pivot 
        if (a[j].fitness <= pivot) 
        { 
            i++;    // increment index of smaller element 
            swap(&a[i], &a[j]); 
        } 
    } 
    swap(&a[i + 1], &a[high]); 
    return (i + 1); 
} 

void quickSort(Individual a[] , int low, int high) 
{ 
    if (low < high) 
    { 
        /* pi is partitioning index, arr[p] is now 
           at right place */
        int pi = partition(a, low, high); 
  
        // Separately sort elements before 
        // partition and after partition 
        quickSort(a, low, pi - 1); 
        quickSort(a, pi + 1, high); 
    } 
} 

void printArr(Individual *a, int n) 
{ 
    int i; 
    for (i = 0; i < n; ++i) 
        printf("%f ", a[i].fitness); 
  printf("\n");
} 


// Compute image
PPM_IMAGE *evolve_image(const PPM_IMAGE *image, int num_generations, int population_size, double rate){

  srand((unsigned)time(NULL));
  int width = image->width;
  int height = image->height; 
  int max = image->max_color;

  Individual *pop;
  pop = generate_population(population_size, width, height, max);
  comp_fitness_population(image->data, pop, population_size);
  quickSort( pop, 0, (population_size-1));
  //printf("Sorted array: "); 
  //printf("%f %f %f %f\n", pop[0].fitness, pop[1].fitness, pop[2].fitness, pop[3].fitness);
  //printArr(pop, population_size);   
  
  for (int i = 1; i <= num_generations; i++){
    crossover(pop, population_size);
    mutate_population(pop, population_size, rate);
    comp_fitness_population(image->data, pop, population_size);
    quickSort(pop, 0, (population_size-1));
    printf("Generation : %d", i );
    printf(" fitness: %f\n", pop[0].fitness);
    //printArr(pop, population_size);   
  } 
  
  PPM_IMAGE *img;
  img = (PPM_IMAGE *)malloc(sizeof(PPM_IMAGE));
  
  img->width = width;
  img->height = height;
  img->max_color = max;
  img->data = pop[0].image.data;
  //printf("%d %d %d\n", img->width, img->height, img->max_color);
  return img ;
}
