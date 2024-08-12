#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ImageProcessing.h"

int main(){
    /*image_t *color_img;
    char *input_file = "boat.256.pgm";

    // Charger l'image couleur
    color_img = load_image(input_file);
    if (!color_img) {
        fprintf(stderr, "Erreur : impossible de charger l'image\n");
        return 1;
    }*/

    image_t *original_img = load_image("Baboon.512.ppm");
    image_t *filtered_img1;
    if (original_img) {
        //image_t *contrasted_img = increase_contrast(original_img, 1.5);  // Augmente le contraste de 50%
        char *histogram_file = "histogram.pgm";
        /*if (contrasted_img) {
            save_image("contrasted_image.ppm", contrasted_img);
            // N'oubliez pas de libérer la mémoire
            free(contrasted_img->data);
            free(contrasted_img);
        }*/
        /*image_t *brightened_img = increase_brightness(original_img, 60);  // Augmente la luminosité de 50
        if (brightened_img) {
            save_image("brightened_image.ppm", brightened_img);
            // N'oubliez pas de libérer la mémoire
            free(brightened_img->data);
            free(brightened_img);
        }*/
        /*int *histogram = calculate_histogram(original_img);
        save_histogram_image(histogram, original_img->maxpixel, "histogram.ppm");*/

        // Création de l'image de destination pour le filtre médian
        filtered_img1 = (image_t *)malloc(sizeof(image_t));

        // Application du filtre médian à l'image "color_img"
        median_filter(original_img, filtered_img1, 3);

        // Enregistrement de l'image filtrée dans un fichier
        FILE *fp = fopen("filtered_image.ppm", "wb");
        fprintf(fp, "P6\n%d %d\n%d\n", filtered_img1->width, filtered_img1->height, filtered_img1->maxpixel);
        fwrite(filtered_img1->data, sizeof(unsigned char), filtered_img1->width * filtered_img1->height * 3, fp);*/
        
        //free(histogram_file);
        free(original_img->data);
        free(original_img);
        //fclose(fp);
    }

    
        
    //display_image(color_img);
    return 0;
}