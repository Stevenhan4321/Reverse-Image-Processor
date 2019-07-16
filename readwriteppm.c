#include <stdio.h>
#include <stdlib.h> 
#include <time.h>
#include <math.h>
#include "a4.h"

PPM_IMAGE *read_ppm(const char *file_name){
  PPM_IMAGE *img;
  FILE *fp;
  //open PPM file for reading
  fp = fopen(file_name, "r");
  unsigned char x,y;
  int width, height, max;
  fscanf(fp, "%c%c%d%d%d", &x, &y,&width,&height,&max);
  //printf("%c%c\n%d\n%d\n%d\n", x, y,width,height,max );

  img = (PPM_IMAGE *)malloc(sizeof(PPM_IMAGE));
  int dimension = width * height;
  img->width = width; 
  img->height = height ;
  img->max_color = max ;

  img->data = (PIXEL *)malloc(dimension * (sizeof(PIXEL)));

  for (int i = 0; i < dimension; i++){
    int red, green, blue;
    fscanf(fp, "%d %d %d", &red, &green, &blue);
    img->data[i].r = red;
    img->data[i].g = green;
    img->data[i].b = blue;

    //printf("%d %d %d\n", img->data[i].r, img->data[i].g, img->data[i].b);
  }
  fclose(fp);
  return img;
}

void write_ppm(const char *file_name, const PPM_IMAGE *image){
  FILE *fp;
  fp = fopen(file_name, "w");
  int width = image->width;
  int height = image->height;
  //printf("%d %d", width, height);
  int max = image->max_color;
  fprintf(fp,"P3\n%d %d\n%d\n", width, height, max);
  int j = 0;
  for (int i = 0; i < height; i++){    
    for (int k = 0; k < width; k++){
      fprintf(fp, "%d %d %d ", image->data[j].r, image->data[j].g, image->data[j].b);    
      j++;
    }
    fprintf(fp,"\n");
  }
  fclose(fp);
}
