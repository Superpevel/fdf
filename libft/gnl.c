#include "libft.h"
#include <fcntl.h>
int get_next_line(int fd, char **line)
{
    char c;
    char buf[1+1];
    int was_read;
    char *p_n;
    int flag;
    char *remain;
    char *tmp;

    flag =1;

    *line = "\0";
    while(flag && (was_read =  read(fd,buf,1)))
    {
        buf[was_read] = '\0';
        if((p_n = strchr(buf,'\n')))
        {
            *p_n = '\0';
            flag = 0;
        }
        tmp = *line;
        *line = ft_strjoin(*line,buf);
        free(tmp);
    }
    return(0);
}
