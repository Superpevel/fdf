#ifndef FDF_H
# define FDF_H
#include "libft/libft.h"
#include "minilibx_macos/mlx.h"
#include <stdio.h>
#include <fcntl.h>
#include "GNL_get_next_line/get_next_line.h"
#include "printf/ft_printf.h"
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
void read_file(fdf *data,char *filename);
void draw(float x,float y,float x1,float y1,fdf *data);
void draw_map(fdf *data);

#endif