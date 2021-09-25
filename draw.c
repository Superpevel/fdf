/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selbert <selbert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 14:19:25 by selbert           #+#    #+#             */
/*   Updated: 2021/09/25 17:43:26 by selbert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

int	max(int a, int b)
{
	if (b > a)
	{
		if (b < 0)
			return (-b);
		return (b);
	}
	if (a > 0)
		return (a);
	return (-a);
}

cord	isometric(cord dta, int z, int z1, fdf *data)
{
	dta.x = (dta.x - dta.y) * cos(data->agle);
	dta.y = (dta.x + dta.y) * sin(data->agle) - z;
	dta.x1 = (dta.x1 - dta.y1) * cos(data->agle);
	dta.y1 = (dta.x1 + dta.y1) * sin(data->agle) - z1;
	return (dta);
}

void	draw1(cord dta, fdf *data)
{
	int		max1;
	float	x_step;
	float	y_step;

	dta.x *= data->zoom;
	dta.x1 *= data->zoom;
	dta.y *= data->zoom;
	dta.y1 *= data->zoom;
	dta.x += data->move_x;
	dta.y += data->move_y;
	dta.y1 += data->move_y;
	dta.x1 += data->move_x;
	x_step = dta.x1 - dta.x;
	y_step = dta.y1 - dta.y;
	max1 = max(x_step, y_step);
	x_step /= max1;
	y_step /= max1;
	while (((int)(dta.x - dta.x1)) || ((int)(dta.y - dta.y1)))
	{
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, dta.x, dta.y, data->color);
		dta.x += x_step;
		dta.y += y_step;
	}
}

void	draw(cord dta, fdf *data)
{
	int		z;
	int		z1;

	z = data->z_matrix[(int)dta.y][(int)dta.x];
	z1 = data->z_matrix[(int)dta.y1][(int)dta.x1];
	dta = isometric(dta, z, z1, data);
	if (z || z1)
	{
		data->color = 0xe80c0c;
	}
	else
		data->color = 0xffffff;
	draw1(dta, data);
}

void	draw_map(fdf *data)
{
	cord	dta;

	dta.y = 0;
	while (dta.y < data->height)
	{
		dta.x = 0;
		while (dta.x < data->width)
		{
			if (dta.x < data->width - 1)
			{
				dta.y1 = dta.y;
				dta.x1 = dta.x + 1;
				draw(dta, data);
			}
			if (dta.y < data->height - 1)
			{
				dta.x1 = dta.x;
				dta.y1 = dta.y + 1;
				draw(dta, data);
			}
			dta.x = dta.x + 1 ;
		}
		dta.y++;
	}
}
