#ifndef IMAGEPROCESSING_H_INCLUDED
#define IMAGEPROCESSING_H_INCLUDED

typedef struct {
    char format[3];    // Format de l'image (P1, P2, P3)
    int width;         // Largeur de l'image
    int height;        // Hauteur de l'image
    int maxpixel;        // Valeur maximale des pixels
    unsigned char *data; // Données de l'image
} image_t;

image_t *load_image(const char *filename);
void display_image(image_t *img);
int save_image(const char *filename, image_t *img);
image_t *increase_brightness(image_t *img, int brightness_increase);
image_t *increase_contrast(image_t *img, float contrast_factor);
int *calculate_histogram(image_t *img);
void save_histogram_image(int *histogram, int max_val, char *filename);
int compare_pixels(const void *a, const void *b);
void median_filter(image_t *src, image_t *dst, int filter_size);
#endif // IMAGEPROCESSING_H_INCLUDED