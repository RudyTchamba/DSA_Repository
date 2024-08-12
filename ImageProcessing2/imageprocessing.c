#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "imageprocessing.h"


image_t *load_image(const char *filename) {
    FILE *fp;
    image_t *img;
    int i, j, val;
    char c;

    // Allouer la mémoire pour l'image
    img = (image_t *)malloc(sizeof(image_t));

    // Ouvrir le fichier
    fp = fopen(filename, "r");
    if (!fp) {
        fprintf(stderr, "Erreur : impossible d'ouvrir le fichier %s\n", filename);
        free(img);
        return NULL;
    }

    // Lire l'en-tête
    if (fscanf(fp, "%2s", img->format) != 1) {
        fprintf(stderr, "Erreur : impossible de lire le format d'image\n");
        fclose(fp);
        free(img);
        return NULL;
    }
    if (img->format[0] != 'P') {
        fprintf(stderr, "Erreur : format d'image non reconnu\n");
        fclose(fp);
        free(img);
        return NULL;
    }
    if (fscanf(fp, "\n") != 0) {
        fprintf(stderr, "Erreur : impossible de lire le caractère de fin de ligne\n");
        fclose(fp);
        free(img);
        return NULL;
    }

    // Lire les dimensions de l'image
    if (fscanf(fp, "%d %d", &img->width, &img->height) != 2) {
        fprintf(stderr, "Erreur : impossible de lire les dimensions de l'image\n");
        fclose(fp);
        free(img);
        return NULL;
    }

    // Lire la valeur maximale des pixels
    if (fscanf(fp, "%d", &img->maxpixel) != 1) {
        fprintf(stderr, "Erreur : impossible de lire la valeur maximale des pixels\n");
        fclose(fp);
        free(img);
        return NULL;
    }

    // Allouer la mémoire pour les données de l'image
    img->data = (unsigned char *)malloc(img->width * img->height * ((img->format[1] == '6') ? 3 : 1) * sizeof(unsigned char));

    // Lire les données de l'image
    for (i = 0; i < img->width * img->height * ((img->format[1] == '6') ? 3 : 1); i++) {
        if (fread(&img->data[i], 1, 1, fp) != 1) {
            fprintf(stderr, "Erreur : fichier d'image corrompu\n");
            fclose(fp);
            free(img->data);
            free(img);
            return NULL;
        }
    }

    fclose(fp);
    return img;
}


void display_image(image_t *img) {
    printf("hello");
    printf("%s", img->format);
    printf("\n%d %d", img->width, img->height);
    if (img->format[1] != '1') {
        printf("\n%d", img->maxpixel);
    }
    printf("\n");

    for (int y = 0; y < img->height; y++) {
        for (int x = 0; x < img->width; x++) {
            if (img->format[1] == '1') {
                printf("%d ", img->data[y * img->width + x]);
            } else if (img->format[1] == '2') {
                printf("%3d ", img->data[y * img->width + x]);
            } else {
                printf("%3d %3d %3d ", img->data[(y * img->width + x) * 3], img->data[(y * img->width + x) * 3 + 1], img->data[(y * img->width + x) * 3 + 2]);
            }
        }
        printf("\n");
    }
}

int save_image(const char *filename, image_t *img) {
    FILE *fp;
    int i, j, val;
    char c;

    // Ouvrir le fichier en écriture
    fp = fopen(filename, "w");
    if (!fp) {
        fprintf(stderr, "Erreur : impossible d'ouvrir le fichier %s\n", filename);
        return 0;
    }

    // Écrire l'en-tête de l'image
    fprintf(fp, "%s\n", img->format);
    fprintf(fp, "%d %d\n", img->width, img->height);
    fprintf(fp, "%d\n", img->maxpixel);

    // Écrire les données de l'image
    for (i = 0; i < img->width * img->height * ((img->format[1] == '6') ? 3 : 1); i++) {
        fwrite(&img->data[i], 1, 1, fp);
    }

    fclose(fp);
    return 1;
}

image_t *convert_to_grayscale(image_t *color_img) {
    image_t *gray_img;
    int i, j, index;

    // Allouer la mémoire pour l'image en niveaux de gris
    gray_img = (image_t *)malloc(sizeof(image_t));
    strcpy(gray_img->format, "P5");
    gray_img->width = color_img->width;
    gray_img->height = color_img->height;
    gray_img->maxpixel = color_img->maxpixel;
    gray_img->data = (unsigned char *)malloc(color_img->width * color_img->height);

    // Convertir l'image en niveaux de gris
    for (i = 0; i < color_img->height; i++) {
        for (j = 0; j < color_img->width; j++) {
            index = (i * color_img->width + j) * 3;
            gray_img->data[i * color_img->width + j] = (unsigned char)(
                (color_img->data[index] + color_img->data[index + 1] + color_img->data[index + 2]) / 3);
        }
    }

    return gray_img;
}

int *calculate_histogram(image_t *img) {
    int *histogram = (int *)calloc(img->maxpixel + 1, sizeof(int));
    int i, j;

    for (i = 0; i < img->height; i++) {
        for (j = 0; j < img->width; j++) {
            int index = (i * img->width + j) * (strcmp(img->format, "P5") == 0 ? 1 : 3);
            if (strcmp(img->format, "P5") == 0) { // Image en niveaux de gris
                histogram[img->data[index]]++;
            } else { // Image couleur
                histogram[img->data[index + 0]]++;
                histogram[img->data[index + 1]]++;
                histogram[img->data[index + 2]]++;
            }
        }
    }

    return histogram;
}

void save_histogram_image(int *histogram, int max_val, char *filename) {
    int width = max_val + 1;
    int height = max_val + 1;
    int max_count = 0;

    // Trouver le maximum de l'histogramme
    for (int i = 0; i <= max_val; i++) {
        if (histogram[i] > max_count) {
            max_count = histogram[i];
        }
    }

    // Créer l'image de l'histogramme
    image_t *img = (image_t *)malloc(sizeof(image_t));
    img->width = width;
    img->height = height;
    img->maxpixel = 255;
    strcpy(img->format, "P6");
    img->data = (unsigned char *)calloc(width * height * 3, sizeof(unsigned char));

    // Remplir l'image avec un fond noir
    memset(img->data, 0, width * height * 3);

    // Dessiner l'histogramme sur l'image
    for (int i = 0; i < width; i++) {
        for (int j = height - 1 - (histogram[i] * (height - 1) / max_count); j < height; j++) {
            int index = (j * width + i) * 3;
            img->data[index + 0] = 255;
            img->data[index + 1] = 255;
            img->data[index + 2] = 255;
        }
    }

    // Enregistrer l'image
    FILE *fp = fopen(filename, "wb");
    fprintf(fp, "%s\n%d %d\n%d\n", img->format, img->width, img->height, img->maxpixel);
    fwrite(img->data, sizeof(unsigned char), width * height * 3, fp);
    fclose(fp);

    free(img->data);
    free(img);
}

int compare_pixels(const void *a, const void *b) {
    return *(unsigned char *)a - *(unsigned char *)b;
}

void median_filter(image_t *src, image_t *dst, int filter_size) {
    // Allocation mémoire pour l'image de destination
    dst->data = (unsigned char *)calloc(src->height * src->width * (strcmp(src->format, "P5") == 0 ? 1 : 3), sizeof(unsigned char));
    dst->width = src->width;
    dst->height = src->height;
    dst->maxpixel = src->maxpixel;
    strcpy(dst->format, src->format);

    // Parcours de l'image source pixel par pixel
    for (int i = 0; i < src->height; i++) {
        for (int j = 0; j < src->width; j++) {
            // Calcul de l'index du pixel courant
            int index = (i * src->width + j) * (strcmp(src->format, "P5") == 0 ? 1 : 3);

            // Extraction des valeurs des pixels dans la fenêtre du filtre médian
            unsigned char temp[filter_size * filter_size];
            int k = 0;
            for (int m = -filter_size / 2; m <= filter_size / 2; m++) {
                for (int n = -filter_size / 2; n <= filter_size / 2; n++) {
                    int x = i + m;
                    int y = j + n;
                    if (x >= 0 && x < src->height && y >= 0 && y < src->width) {
                        int index_temp = (x * src->width + y) * (strcmp(src->format, "P5") == 0 ? 1 : 3);
                        if (strcmp(src->format, "P5") == 0) { // Image en niveaux de gris
                            temp[k++] = src->data[index_temp];
                        } else { // Image couleur
                            temp[k++] = src->data[index_temp + 0];
                            temp[k++] = src->data[index_temp + 1];
                            temp[k++] = src->data[index_temp + 2];
                        }
                    } else {
                        // Valeur par défaut pour les pixels hors de l'image
                        temp[k++] = 0;
                    }
                }
            }

            // Tri du tableau temporaire et récupération de la valeur médiane
            qsort(temp, filter_size * filter_size, sizeof(unsigned char), compare_pixels);
            int mid = (filter_size * filter_size) / 2;

            // Stockage de la valeur médiane dans l'image de destination
            if (strcmp(dst->format, "P5") == 0) { // Image en niveaux de gris
                dst->data[index] = temp[mid];
            } else { // Image couleur
                dst->data[index + 0] = temp[mid * 3 + 0];
                dst->data[index + 1] = temp[mid * 3 + 1];
                dst->data[index + 2] = temp[mid * 3 + 2];
            }
        }
    }
}