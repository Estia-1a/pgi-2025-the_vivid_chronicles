#ifndef FEATURES_H
#define FEATURES_H


void helloWorld();
void dimension(char *source_path);
void second_line(char *source_path);
void first_pixel(char *source_path);
void tenth_pixel(char *source_path);
void print_pixel(char *filename, int x, int y);
void max_pixel(char *source_path);
void min_pixel(char *source_path);
void min_component(char *source_path, char component);
void max_component(char *source_path, char *component);
void color_red(const char *input_file);
void color_green(const char *input_file);
void color_bleu(const char *input_file);
void color_gris(const char *input_file);
void color_invert(char *source_path);
void color_gray_luminance(char *source_path);
void rotate_cw(char *source_path);
#endif