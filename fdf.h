/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selbert <selbert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 13:37:48 by selbert           #+#    #+#             */
/*   Updated: 2021/09/26 14:26:59 by selbert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "./libft/libft.h"
# include "./minilibx_macos/mlx.h"
# include <stdio.h>
# include <fcntl.h>
# include "./gnl/get_next_line.h"
# include "./printf/ft_printf.h"

typedef struct s_fdf
{
	int		width;
	int		height;
	int		**z_matrix;
	int		zoom;
	int		color;
	void	*mlx_ptr;
	void	*win_ptr;
	int		move_x;
	int		move_y;
	float	agle;
}	t_fdf;

typedef struct t_cord
{
	float	x;
	float	y;
	float	x1;
	float	y1;
}	t_cord;

void	read_file(t_fdf *data, char *filename);
void	draw_map(t_fdf *data);
#endif
