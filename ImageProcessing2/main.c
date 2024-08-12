#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdint.h>
#include "imageprocessing.h"

int main(){

    image_t *color_img, *gray_img, *mask_img, *filtered_img1;
    //int histogram[256][3];
    char *input_file = "Baboon.512.ppm";
    //char *output_file = "output.pgm";
    char *histogram_file = "histogram.pgm";
    char *bright_file = "bright_file.ppm";

    // Charger l'image couleur
    color_img = load_image(input_file);
    if (!color_img) {
        fprintf(stderr, "Erreur : impossible de charger l'image\n");
        return 1;
    }

    // Création de l'image de destination pour le filtre médian
    filtered_img1 = (image_t *)malloc(sizeof(image_t));

    // Application du filtre médian à l'image "color_img"
    median_filter(color_img, filtered_img1, 3);

    // Enregistrement de l'image filtrée dans un fichier
    FILE *fp = fopen("filtered_image.ppm", "wb");
    fprintf(fp, "P6\n%d %d\n%d\n", filtered_img1->width, filtered_img1->height, filtered_img1->maxpixel);
    fwrite(filtered_img1->data, sizeof(unsigned char), filtered_img1->width * filtered_img1->height * 3, fp);
    fclose(fp);

    /*int *histogram = calculate_histogram(color_img);
    save_histogram_image(histogram, color_img->maxpixel, "histogram.ppm");*/

    // Convertir l'image en niveaux de gris
    //gray_img = convert_to_grayscale(color_img);

    // Calculer l'histogramme des couleurs
    //compute_color_histogram(color_img, histogram);

    // Visualiser l'histogramme sur une image de masque
    //mask_img = visualize_color_histogram(histogram, color_img->width, color_img->height);

    /*// Enregistrer l'image en niveaux de gris
    if (!save_image(output_file, gray_img)) {
        fprintf(stderr, "Erreur : impossible d'enregistrer l'image\n");
        free(color_img->data);
        free(color_img);
        free(gray_img->data);
        free(gray_img);
        return 1;
    }
    printf("Image convertie et enregistrée avec succès dans %s\n", output_file);*/

    // Enregistrer l'image de masque
    /*if (!save_image(histogram_file, mask_img)) {
        fprintf(stderr, "Erreur : impossible d'enregistrer l'image\n");
        free(color_img->data);
        free(color_img);
        free(mask_img->data);
        free(mask_img);
        return 1;
    }
    printf("Histogramme des couleurs affiché et enregistré dans %s\n", histogram_file);*/

    /*// Libérer la mémoire
    free(color_img->data);
    free(color_img);
    free(gray_img->data);
    free(gray_img);*/

    // Chargement de l'image source dans src
    median_filter(color_img, filtered_img1, 3); // Taille du filtre médian = 3x3
    // Enregistrement de l'image de destination dst

    // Libérer la mémoire
    //free(histogram);
    free(color_img->data);
    free(color_img);


    return 0;

}