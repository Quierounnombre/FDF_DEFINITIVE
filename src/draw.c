/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 13:49:10 by vicgarci          #+#    #+#             */
/*   Updated: 2023/03/07 15:02:45 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

static t_vector2D	draw_dot(t_FdF_info *fdf, int i, int j)
{
	t_vector2D	v;
	t_vector3D	v3;
	t_map		*map;

	map = fdf->map;
	v3 = load_vector3d(i, j, map->map[j][i].pixel);
	v = get_iso_perspective(v3, fdf);
	if (v.x >= 0 && v.x < WIDTH && v.y >= 0 && v.y < HEIGHT)
		ft_pixel_put(fdf->img, v.x, v.y, map->map[j][i].color);
	return (v);
}

static void	draw_dots(t_FdF_info *fdf)
{
	int			i;
	int			j;
	t_map		*map;
	t_vector2D	v;

	i = 0;
	j = 0;
	map = fdf->map;
	while (j < map->map_size_y - 1)
	{
		while (i < map->map_size_x)
		{
			v = draw_dot(fdf, i, j);
			draw_lines(fdf, i, j, v);
			i++;
		}
		j++;
		i = 0;
	}
}

void	draw(t_FdF_info *fdf)
{
	set_dark(fdf);
	draw_dots(fdf);
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img->img, 0, 0);
	ft_printf("\n--------TERMINE DE DIBUJAR--------\n\n");
}
