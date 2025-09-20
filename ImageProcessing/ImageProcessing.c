#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ImageProcessing.h"

image_t *load_image(const char *filename) {
    FILE *fp;
    image_t *img;
    int i;
    char buffer[100];

    // Allouer la mémoire pour l'image
    img = (image_t *)malloc(sizeof(image_t));
    if (!img) {
        fprintf(stderr, "Erreur : impossible d'allouer la mémoire pour l'image\n");
        return NULL;
    }

    // Ouvrir le fichier
    fp = fopen(filename, "rb");
    if (!fp) {
        fprintf(stderr, "Erreur : impossible d'ouvrir le fichier %s\n", filename);
        free(img);
        return NULL;
    }

    // Lire l'en-tête
    if (fgets(buffer, sizeof(buffer), fp) == NULL) {
        fprintf(stderr, "Erreur : impossible de lire le format d'image\n");
        fclose(fp);
        free(img);
        return NULL;
    }
    sscanf(buffer, "%2s", img->format);

    if (img->format[0] != 'P' || (img->format[1] != '5' && img->format[1] != '6')) {
        fprintf(stderr, "Erreur : format d'image non reconnu\n");
        fclose(fp);
        free(img);
        return NULL;
    }

    // Ignorer les commentaires
    do {
        if (fgets(buffer, sizeof(buffer), fp) == NULL) {
            fprintf(stderr, "Erreur : fichier corrompu\n");
            fclose(fp);
            free(img);
            return NULL;
        }
    } while (buffer[0] == '#');

    // Lire les dimensions de l'image et la valeur maximale des pixels
    if (sscanf(buffer, "%d %d", &img->width, &img->height) != 2) {
        if (fscanf(fp, "%d %d %d", &img->width, &img->height, &img->maxpixel) != 3) {
            fprintf(stderr, "Erreur : impossible de lire les dimensions de l'image ou la valeur maximale des pixels\n");
            fclose(fp);
            free(img);
            return NULL;
        }
    } else {
        if (fscanf(fp, "%d", &img->maxpixel) != 1) {
            fprintf(stderr, "Erreur : impossible de lire la valeur maximale des pixels\n");
            fclose(fp);
            free(img);
            return NULL;
        }
    }

    // Consommer le caractère de nouvelle ligne après maxpixel
    fgetc(fp);

    // Allouer la mémoire pour les données de l'image
    size_t data_size = img->width * img->height * (img->format[1] == '6' ? 3 : 1);
    img->data = (unsigned char *)malloc(data_size);
    if (!img->data) {
        fprintf(stderr, "Erreur : impossible d'allouer la mémoire pour les données de l'image\n");
        fclose(fp);
        free(img);
        return NULL;
    }

    // Lire les données de l'image
    if (fread(img->data, 1, data_size, fp) != data_size) {
        fprintf(stderr, "Erreur : fichier d'image corrompu ou incomplet\n");
        fclose(fp);
        free(img->data);
        free(img);
        return NULL;
    }

    fclose(fp);
    return img;
}

void display_image(image_t *img) {
    if (!img) {
        printf("Erreur : Image non valide\n");
        return;
    }

    printf("hello world");

    // Affichage de l'en-tête
    printf("%s\n", img->format);
    printf("%d %d\n", img->width, img->height);
    printf("%d\n", img->maxpixel);

    printf("\n");

    // Affichage des données de l'image
    for (int y = 0; y < img->height; y++) {
        for (int x = 0; x < img->width; x++) {
            if (img->format[1] == '5') {  // Format PGM (P5)
                printf("%3d ", img->data[y * img->width + x]);
            } else if (img->format[1] == '6') {  // Format PPM (P6)
                int index = (y * img->width + x) * 3;
                printf("%3d %3d %3d ", 
                       img->data[index], 
                       img->data[index + 1], 
                       img->data[index + 2]);
            }
        }
        printf("\n");
    }
}

int save_image(const char *filename, image_t *img) {
    if (!img || !img->data) {
        fprintf(stderr, "Erreur : image invalide\n");
        return 0;
    }

    FILE *fp = fopen(filename, "wb");
    if (!fp) {
        fprintf(stderr, "Erreur : impossible d'ouvrir le fichier %s\n", filename);
        return 0;
    }

    // Écrire l'en-tête de l'image
    fprintf(fp, "%s\n%d %d\n%d\n", img->format, img->width, img->height, img->maxpixel);

    // Calculer la taille des données
    size_t data_size = img->width * img->height * (img->format[1] == '6' ? 3 : 1);

    // Écrire les données de l'image en une seule opération
    if (fwrite(img->data, 1, data_size, fp) != data_size) {
        fprintf(stderr, "Erreur : échec de l'écriture des données de l'image\n");
        fclose(fp);
        return 0;
    }

    fclose(fp);
    return 1;
}

image_t *convert_to_grayscale(image_t *color_img) {
    if (!color_img || !color_img->data || color_img->format[1] != '6') {
        fprintf(stderr, "Erreur : image d'entrée invalide ou non PPM\n");
        return NULL;
    }

    int i, j, index;

    // Allouer la mémoire pour l'image en niveaux de gris
    image_t *gray_img = (image_t *)malloc(sizeof(image_t));
    if (!gray_img) {
        fprintf(stderr, "Erreur : allocation mémoire échouée pour gray_img\n");
        return NULL;
    }
    
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

image_t *increase_brightness(image_t *img, int brightness_increase) {
    if (!img || !img->data) {
        fprintf(stderr, "Erreur : image d'entrée invalide\n");
        return NULL;
    }

    image_t *bright_img = (image_t *)malloc(sizeof(image_t));
    if (!bright_img) {
        fprintf(stderr, "Erreur : allocation mémoire échouée pour bright_img\n");
        return NULL;
    }

    // Copie des métadonnées
    strncpy(bright_img->format, img->format, sizeof(bright_img->format));
    bright_img->width = img->width;
    bright_img->height = img->height;
    bright_img->maxpixel = img->maxpixel;

    int is_color = (img->format[1] == '6');
    size_t pixel_count = img->width * img->height;
    size_t data_size = pixel_count * (is_color ? 3 : 1);

    bright_img->data = (unsigned char *)malloc(data_size);
    if (!bright_img->data) {
        fprintf(stderr, "Erreur : allocation mémoire échouée pour bright_img->data\n");
        free(bright_img);
        return NULL;
    }

    for (size_t i = 0; i < data_size; i++) {
        int new_value = img->data[i] + brightness_increase;
        // Assurer que la valeur reste dans la plage [0, maxpixel]
        bright_img->data[i] = (unsigned char)
            (new_value < 0 ? 0 : (new_value > bright_img->maxpixel ? bright_img->maxpixel : new_value));
    }

    return bright_img;
}

image_t *increase_contrast(image_t *img, float contrast_factor) {
    if (!img || !img->data) {
        fprintf(stderr, "Erreur : image d'entrée invalide\n");
        return NULL;
    }

    image_t *contrast_img = (image_t *)malloc(sizeof(image_t));
    if (!contrast_img) {
        fprintf(stderr, "Erreur : allocation mémoire échouée pour contrast_img\n");
        return NULL;
    }

    // Copie des métadonnées
    strncpy(contrast_img->format, img->format, sizeof(contrast_img->format));
    contrast_img->width = img->width;
    contrast_img->height = img->height;
    contrast_img->maxpixel = img->maxpixel;

    int is_color = (img->format[1] == '6');
    size_t pixel_count = img->width * img->height;
    size_t data_size = pixel_count * (is_color ? 3 : 1);

    contrast_img->data = (unsigned char *)malloc(data_size);
    if (!contrast_img->data) {
        fprintf(stderr, "Erreur : allocation mémoire échouée pour contrast_img->data\n");
        free(contrast_img);
        return NULL;
    }

    // Calcul de la valeur moyenne
    float avg = 0;
    for (size_t i = 0; i < data_size; i++) {
        avg += img->data[i];
    }
    avg /= data_size;

    // Appliquer l'augmentation de contraste
    for (size_t i = 0; i < data_size; i++) {
        float pixel = img->data[i];
        float new_value = avg + (pixel - avg) * contrast_factor;
        
        // Limiter les valeurs entre 0 et maxpixel
        if (new_value < 0) new_value = 0;
        if (new_value > img->maxpixel) new_value = img->maxpixel;
        
        contrast_img->data[i] = (unsigned char)new_value;
    }

    return contrast_img;
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