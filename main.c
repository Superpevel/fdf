/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selbert <selbert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 14:23:37 by selbert           #+#    #+#             */
/*   Updated: 2021/09/26 14:30:46 by selbert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	deal_key(int key, t_fdf *data)
{
	if (key == 126)
		data->move_y -= 10;
	if (key == 125)
		data->move_y += 10;
	if (key == 124)
		data->move_x += 10;
	if (key == 123)
		data->move_x -= 10;
	if (key == 24)
		data->zoom += 1;
	if (key == 27)
		data->zoom -= 1;
	if (key == 53)
	{
		free(data);
		exit(1);
	}
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	draw_map(data);
	return (0);
}

void	start_program(t_fdf *data, char **argv)
{
	int	fd;

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		ft_printf("cant open file");
	}
	else
	{
		read_file(data, argv[1]);
		data->move_x = 150;
		data->move_y = 150;
		data->agle = 0.8;
		data->mlx_ptr = mlx_init();
		data->win_ptr = mlx_new_window(data->mlx_ptr, 1000, 1000, "fdf");
		data->zoom = 20;
		draw_map(data);
		mlx_key_hook(data->win_ptr, deal_key, data);
		mlx_loop(data->mlx_ptr);
	}
}

int	main(int argc, char **argv)
{
	t_fdf	*data;
	char	*check;

	if (argc > 2 || argc < 2)
	{
		ft_printf("Invalid arguments");
		return (0);
	}
	data = (t_fdf *)malloc(sizeof(t_fdf));
	if (ft_strnstr(argv[1], ".fdf",
			ft_strlen(argv[1])) && ft_strlen(argv[1]) > 4)
	{
		check = ft_substr(argv[1], ft_strlen(argv[1]) - 4, 4);
		if (ft_strnstr(check, ".fdf", 4))
		{
			free(check);
			start_program(data, argv);
		}
		else
			ft_printf("Not valid file");
	}
	else
		ft_printf("Not valid file");
	return (0);
}
