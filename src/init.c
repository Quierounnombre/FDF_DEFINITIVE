/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 16:05:24 by vicgarci          #+#    #+#             */
/*   Updated: 2023/03/06 19:19:55 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

static t_bool	ft_mlx_start(t_FdF_info **fdf)
{
	(*fdf)->mlx = mlx_init(WIDTH, HEIGHT, NAME, false);
	if ((*fdf)->mlx)
	{
		(*fdf)->img = mlx_new_image((*fdf)->mlx, WIDTH, HEIGHT);
		if ((*fdf)->img)
		{
			if (!(mlx_put_image_to_window((*fdf)->mlx, (*fdf)->win,
						(*fdf)->img, 0, 0) > 0))
				return (true);
			free ((*fdf)->img);
		}
		free((*fdf)->mlx);
	}
	return (false);
}

t_bool	init(int argc, char **argv, t_FdF_info **fdf)
{
	int	fd;

	if (parse(argc, argv))
	{
		fd = open(argv[1], O_RDONLY);
		if (fd >= 0)
		{
			*fdf = init_struct();
			if (fdf && store_file(fd, (*fdf)->map))
			{
				close(fd);
				fd = 0;
				(*fdf)->cam->dim = set_dimensions((*fdf)->map);
				if (ft_mlx_start(fdf))
					return (true);
			}
			free_struct(*fdf);
			if (fd)
				close (fd);
			return (false);
		}
		else
			ft_printf("No he podido abrir el archivo, %s %d\n\n", argv[1], fd);
	}
	return (false);
}
