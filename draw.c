#include "fdf.h"
#include <math.h>
int max(int a,int b)
{
    if(b>a){
        if(b<0)
            return(-b);
        return(b);
    }
    if(a>0)
        return(a);
    return(-a);
}

void isometric(float *x,float *y,int z,fdf *data)
{
	*x = (*x - *y) * cos(data->agle);
	*y = (*x + *y) * sin(data->agle) - z;
}

void draw(float x,float y,float x1,float y1,fdf *data)
{
    float x_step;
    float y_step;
    int max1;
    int z;
    int z1;

    z = data->z_matrix[(int)y][(int)x];
    z1 = data->z_matrix[(int)y1][(int)x1];
    isometric(&x,&y,z,data);
    isometric(&x1,&y1,z1,data);   
    if(z || z1)
    {
        data->color = 0xe80c0c;
    }
    else
        data->color = 0xffffff;
    x*=data->zoom;
    x1*=data->zoom;
    y*=data->zoom;
    y1*=data->zoom;

    x+=data->move_x;
    y+=data->move_y;
    y1+=data->move_y;
    x1+=data->move_x;
    x_step = x1 - x;
    y_step = y1 - y;


    max1 = max(x_step,y_step);
    x_step /= max1;
    y_step /= max1;
    int i = 0;
    while (((int)(x-x1)) || ((int)(y-y1)))
    {
        mlx_pixel_put(data->mlx_ptr,data->win_ptr,x,y,data->color);
        x += x_step;
        y += y_step;
    
    }
    
}

void draw_map(fdf *data)
{
    int x;
    int y;

    y = 0;
    while (y< data->height)
    {
        x = 0;
        while(x < data->width)
        {
            if(x < data->width-1)
                draw(x,y,x+1,y,data);
            if(y<data->height-1)
                draw(x,y,x,y+1,data);
            x++;
        }
        y++;
    }
    

}