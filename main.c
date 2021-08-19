#include "fdf.h"
int deal_key(int key,fdf *data)
{
    if (key == 126)
        data->move_y -=10;
    if (key == 125)
        data->move_y +=10;
    if (key == 124)
        data->move_x +=10;
    if (key == 123)
        data->move_x -=10;
    if(key ==24)
        data->zoom +=1;
    if(key == 27)
        data->zoom -=1;

    mlx_clear_window(data->mlx_ptr,data->win_ptr);
    draw_map(data);
    return(0);
}

int main(int argc,char **argv)
{
    fdf *data;
    data = (fdf*)malloc(sizeof(fdf));
    int fd;
    read_file(data,argv[1]);
    int i;
    int j;
    data->move_x = 150;
    data->move_y = 150;
    data->agle =0.8;
    data->mlx_ptr = mlx_init();
    data->win_ptr = mlx_new_window(data->mlx_ptr,1000,1000,"FDF");
    data->zoom = 20;
    draw_map(data);
    mlx_key_hook(data->win_ptr,deal_key,data);
    mlx_loop(data->mlx_ptr);
}