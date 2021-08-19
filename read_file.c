#include "fdf.h"

int get_height(char *filename)
{
    char *line;
    int fd;
    int height;
    fd = open(filename,O_RDONLY,0);
    height = 0;
    while (get_next_line(fd,&line))
    {
        height++;
        free(line);
    }
    free(line);
    close(fd);
    return(height);
}
void fill_matrix(fdf *data,char *filename)
{
    int fd;
    fd = open(filename,O_RDONLY,0);
    char *line;
    char **s;
    int i = 0;
    int j = 0;
    while (get_next_line(fd,&line))
    {
        j = 0;
        s = ft_split(line,' ');
        while (s[j])
        {
            data->z_matrix[i][j] = ft_atoi(s[j]);
            j++;
        }
        j = j-1;
        while(j)
        {
            free(s[j]);
            j--;
        }
        free(s[j]);
        free(s);
        free(line);
        i++;
    }
    free(line);
    close(fd);
    data->z_matrix[i] = NULL;

}
int get_width(char *filename)
{
    char *line;
    int fd;
    int width;
    char **s;
    fd = open(filename,O_RDONLY,0);
    get_next_line(fd,&line);
    width = 0;
    s = ft_split(line,' ');
    free(line);
    close(fd);
    int j = 0;
    while (s[j])
    {
        free(s[j]);
        j++;
    }
    free(s);
    return(j);    
}
void read_file(fdf *data,char *filename)
{
    char *line;
    int i;
    data->height = get_height(filename);
    data->width = get_width(filename);

    data->z_matrix = (int**)malloc(sizeof(int*) * (data->height +1));
    i = 0;
    while (i <= data->height)
        data->z_matrix[i++] = (int*)malloc(sizeof(int) * (data->width +1));

    fill_matrix(data,filename);
}