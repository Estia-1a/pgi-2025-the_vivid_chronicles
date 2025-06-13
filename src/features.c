#include "estia-image.h"
#include <stdio.h>
#include <stdlib.h>

#include "features.h"
#include "utils.h"

/**
 * @brief Here, you have to code features of the project.
 * Do not forget to commit regurlarly your changes.
 * Your commit messages must contain "#n" with: n = number of the corresponding feature issue.
 * When the feature is totally implemented, your commit message must contain "close #n".
 */

void helloWorld() {
    printf("Hello World !!!!!!!!!!!");
}


void dimension(char*source_path){
    unsigned char *data = NULL;
    int width = 0,height = 0, channels_count =0;
    read_image_data(source_path, &data, &width, &height, &channels_count);
    printf("dimension: %d, %d\n", width, height);
}

void first_pixel(char *source_path) {
    unsigned char *data = NULL;
    int width = 0, height = 0, channel_count = 0;
    read_image_data(source_path, &data, &width, &height, &channel_count);
    printf("first_pixel: %d, %d, %d\n", data[0],data[1], data[2]);
}
void tenth_pixel(char *source_path){
    unsigned char *data = NULL;
    int width, height, channel_count;
    read_image_data(source_path, &data, &width, &height, &channel_count);
    int position= 9*3;
    int rouge = data[position];
    int vert = data[position+1];
    int bleu = data[position+2];
    printf("tenth_pixel: %d, %d, %d\n", rouge, vert, bleu);
    free(data);
}
void print_pixel(char *filename, int x, int y) {
    unsigned char *data = NULL;
    int width = 0, height = 0, channels_count = 0;
    read_image_data(filename, &data, &width, &height, &channels_count);
    
    if (data == NULL) {
        printf("Erreur : impossible\n");
        return;
    }
    pixel *p = get_pixel(data, width, height, channels_count, x, y);
    
    if (p == NULL) {
        printf("Erreur : coordonnées invalid\n");
        free(data);
        return;
    }
    printf("print_pixel (%d, %d): %d, %d, %d\n", x, y, p->r, p->g, p->b);

    free(p);
    free(data);
}

void max_pixel(char *source_path) {
    unsigned char *data = NULL;
    int width = 0, height = 0, channel_count = 0;
    read_image_data(source_path, &data, &width, &height, &channel_count);
    int max_sum = 0;
    int max_x = 0, max_y = 0;
    int max_r = 0, max_g = 0, max_b = 0;
    for (int y = 0; y < width; y++) {
        for (int x = 0; x < width; x++) {
            int position = (y * width + x) * channel_count;
            int r = data[position];
            int g = data[position + 1];
            int b = data[position + 2];
            int sum = r + g + b;
            if (sum > max_sum) {
                max_sum = sum;
                max_x = x;
                max_y = y;
                max_r = r;
                max_g = g;
                max_b = b;
            }
        }
    }

    printf("max_pixel (%d, %d): %d, %d, %d\n", max_x, max_y, max_r, max_g, max_b);
}
void second_line(char *source_path){
  int width=0, height=0, channel_count=0;
  unsigned char *data;
  
  read_image_data(source_path, &data, &width,&height,&channel_count);
  
  if (height < 2) {
        printf("Erreur de lecture de l'image\n");
        return;
  }
  int position = 1 * width * 3;
  int r=data[position];
  int g=data[position+1];
  int b=data[position+2];

  printf("second_line : %d, %d, %d\n",r,g,b);

}
  

void min_pixel(char *source_path) {
    unsigned char *data = NULL;
    int width, height, channel_count;
    read_image_data(source_path, &data, &width, &height, &channel_count);
    int min_somme = 999999; 
    int min_x = 0, min_y = 0;
    int min_rouge = 0, min_vert = 0, min_bleu = 0;
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int position = (y * width + x) * 3;
            int rouge = data[position];
            int vert = data[position + 1];
            int bleu = data[position + 2];
            int somme = rouge + vert + bleu;
            if (somme < min_somme) {
                min_somme = somme;
                min_x = x;
                min_y = y;
                min_rouge = rouge;
                min_vert = vert;
                min_bleu = bleu;
            }
        }
    }
    printf("min_pixel (%d, %d): %d, %d, %d\n", min_x, min_y, min_rouge, min_vert, min_bleu);
    free(data);
}