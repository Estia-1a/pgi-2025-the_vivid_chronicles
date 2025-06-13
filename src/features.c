#include "estia-image.h"
#include <stdio.h>

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
  