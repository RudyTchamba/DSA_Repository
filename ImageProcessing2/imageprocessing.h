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
image_t *convert_to_grayscale(image_t *color_img);
int *calculate_histogram(image_t *img);
void save_histogram_image(int *histogram, int max_val, char *filename);
/*void compute_color_histogram(image_t *img, int histogram[256][3]);
image_t *visualize_color_histogram(int histogram[256][3], int width, int height);*/
int compare_pixels(const void *a, const void *b);
void median_filter(image_t *src, image_t *dst, int filter_size);

#endif // IMAGEPROCESSING_H_INCLUDED