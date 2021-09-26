#ifndef FDF_H
# define FDF_H
#include "./libft/libft.h"
#include "./minilibx_macos/mlx.h"
#include <stdio.h>
#include <fcntl.h>
#include "./gnl/get_next_line.h"
#include "./printf/ft_printf.h"
typedef struct
{
    int width;
    int height;
    int **z_matrix;
    int zoom;
    int color;
    void *mlx_ptr;
    void *win_ptr;
    int move_x;
    int move_y;
    float agle;
} fdf;

typedef struct
{
    float x;
    float y;
    float x1;
    float y1;
} cord;

void read_file(fdf *data,char *filename);
void draw_map(fdf *data);
#endif
