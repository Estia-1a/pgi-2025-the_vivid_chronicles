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


void min_component(char *source_path, char component) {
    unsigned char *data = NULL;
    int width = 0, height = 0, channel_count = 0;
    read_image_data(source_path, &data, &width, &height, &channel_count);
    int min_value = 255;
    int min_x = 0;
    int min_y = 0;
    int channel = 0;
    if (component == 'R') {
        channel = 0;
    }
    if (component == 'G') {
        channel = 1;
    }
    if (component == 'B') {
        channel = 2;
    }

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int position = (y * width + x) * 3 + channel;
            int value = data[position];

            if (value < min_value) {
                min_value = value;
                min_x = x;
                min_y = y;
            }
        }
    }
    printf("min_component %c (%d, %d): %d\n", component, min_x, min_y, min_value);
}


void max_component(char *source_path, char *component) {
    unsigned char *data = NULL;
    int width, height, channel_count;
    read_image_data(source_path, &data, &width, &height, &channel_count);
    int max_valeur = -1;
    int max_x = 0, max_y = 0;
    int composant_index = 0;
    if (component[0] == 'G') {
        composant_index = 1;
    } else if (component[0] == 'B') {
        composant_index = 2;
    }
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int position = (y * width + x) * 3;
            int valeur = data[position + composant_index];
            if (valeur > max_valeur) {
                max_valeur = valeur;
                max_x = x;
                max_y = y;
            }
        }
    }
    printf("max_component %s (%d, %d): %d\n", component, max_x, max_y, max_valeur);
    free(data);
}


void color_red(const char *input_filename) {
    int width, height, channel_count;
    unsigned char *apres;
    unsigned char *avant;
    
    int result = read_image_data(input_filename, &apres, &width, &height, &channel_count);
    if (result == 0 || apres == NULL) {
        return;
    }
    avant = malloc(width * height * 3);
    if (avant == NULL) {
        free(avant);
        return;
    }
    
    for (int i = 0; i < width * height; i++) {
        avant[i * 3] = apres[i * 3];     
        avant[i * 3 + 1] = 0;                 
        avant[i * 3 + 2] = 0;                 
    }

    write_image_data("image_out.bmp", avant, width, height);
    free(apres);
    free(avant);
}
void color_green(const char *input_filename) {
    int width, height, channel_count;
    unsigned char *apres;
    unsigned char *avant;
    
    int result = read_image_data(input_filename, &apres, &width, &height, &channel_count);
    if (result == 0 || apres == NULL) {
        return;
    }
    avant = malloc(width * height * 3);
    if (avant == NULL) {
        free(avant);
        return;
    }
    
    for (int i = 0; i < width * height; i++) {
        avant[i * 3] = 0;     
        avant[i * 3 + 1] = apres[i*3+1];                 
        avant[i * 3 + 2] = 0;                 
    }

    write_image_data("image_out.bmp", avant, width, height);
    free(apres);
    free(avant);
}


void color_bleu(const char *input_filename) {
    int width, height, channel_count;
    unsigned char *apres;
    unsigned char *avant;
    
    int result = read_image_data(input_filename, &apres, &width, &height, &channel_count);
    if (result == 0 || apres == NULL) {
        return;
    }
    avant = malloc(width * height * 3);
    if (avant == NULL) {
        free(avant);
        return;
    }
    
    for (int i = 0; i < width * height; i++) {
        avant[i * 3] = 0;     
        avant[i * 3 + 1] = 0;                 
        avant[i * 3 + 2] = apres[i*3+2];                 
    }

    write_image_data("image_out.bmp", avant, width, height);
    free(apres);
    free(avant);
}

void color_gris(const char *input_filename) {
    int width, height, channel_count;
    unsigned char *apres;
    unsigned char *avant;
    
    int result = read_image_data(input_filename, &apres, &width, &height, &channel_count);
    if (result == 0 || apres == NULL) {
        return;
    }
    
    avant = malloc(width * height * 3);
    if (avant == NULL) {
        free(apres);  
        return;
    }
    
    for (int i = 0; i < width * height; i++) {
        unsigned char gray_value =(apres[i * 3] + apres[i * 3 + 1] + apres[i * 3 + 2]) / 3;
        avant[i * 3] = gray_value;     
        avant[i * 3 + 1] = gray_value; 
        avant[i * 3 + 2] = gray_value; 
    }
    
    write_image_data("image_out.bmp", avant, width, height);
    free(apres);
    free(avant);
}

void color_invert(char *source_path) {
    unsigned char *data = NULL;
    int width, height, channel_count;
    read_image_data(source_path, &data, &width, &height, &channel_count);
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int position = (y * width + x) * 3;
            int rouge = data[position];
            int vert = data[position + 1];
            int bleu = data[position + 2];
            data[position] = 255 - rouge;
            data[position + 1] = 255 - vert;
            data[position + 2] = 255 - bleu;
        }
    }
    write_image_data("image_out.bmp", data, width, height);
    printf("Image inversée sauvegardée dans image_out.bmp\n");
    free(data);
}
void color_gray_luminance(char *source_path) {
    unsigned char *data = NULL;
    int width, height, channel_count;
    read_image_data(source_path, &data, &width, &height, &channel_count);
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int position = (y * width + x) * 3;
            int rouge = data[position];
            int vert = data[position + 1];
            int bleu = data[position + 2];
            unsigned char valeur_gris = (unsigned char)(0.21 * rouge + 0.72 * vert + 0.07 * bleu);
            data[position] = valeur_gris;
            data[position + 1] = valeur_gris;
            data[position + 2] = valeur_gris;
        }
    }
    write_image_data("image_out.bmp", data, width, height);
    printf("Image en niveaux de gris sauvegardée dans image_out.bmp\n");
    free(data);
}

void mirror_horizontal(char *source_path) {
    unsigned char *data = NULL;
    int width = 0, height = 0, channel_count = 0;
    read_image_data(source_path, &data, &width, &height, &channel_count);
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width / 2; x++) {
            int left_pos = (y * width + x) * channel_count;
            int right_x = width - 1 - x;
            int right_pos = (y * width + right_x) * channel_count;
            for (int c = 0; c < channel_count; c++) {
                unsigned char temp = data[left_pos + c];
                data[left_pos + c] = data[right_pos + c];
                data[right_pos + c] = temp;
            }
        }
    }

    char output_path[] = "image_out.bmp";
    write_image_data(output_path, data, width, height);
    printf("A new image %s that is horizontal symmetry of the input image\n", output_path);
}void rotate_cw(char *source_path) {
    unsigned char *data = NULL;
    int width, height, channel_count;
    read_image_data(source_path, &data, &width, &height, &channel_count);
    int new_width = height;
    int new_height = width;
    unsigned char temp_data[new_width * new_height * 3];
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int old_position = (y * width + x) * 3;
            int new_x = y;
            int new_y = width - 1 - x;
            int new_position = (new_y * new_width + new_x) * 3;
            
            temp_data[new_position] = data[old_position];
            temp_data[new_position + 1] = data[old_position + 1];
            temp_data[new_position + 2] = data[old_position + 2];
        }
    }
    write_image_data("image_out.bmp", temp_data, new_width, new_height);
    printf("Image tournée de 90° sauvegardée dans image_out.bmp\n");
    free(data);
}

void rotate_acw(char *source_path) {
    unsigned char *data = NULL;
    int width, height, channel_count;
    read_image_data(source_path, &data, &width, &height, &channel_count);
    int new_width = height;
    int new_height = width;
    unsigned char temp_data[new_width * new_height * 3];
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int old_position = (y * width + x) * 3;
            int new_x = height - 1 - y;
            int new_y = x;
            int new_position = (new_y * new_width + new_x) * 3;
            temp_data[new_position] = data[old_position];
            temp_data[new_position + 1] = data[old_position + 1];
            temp_data[new_position + 2] = data[old_position + 2];
        }
    }
    write_image_data("image_out.bmp", temp_data, new_width, new_height);
    printf("Image tournée de 90° anti-horaire sauvegardée dans image_out.bmp\n");
    free(data);
}