/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 16:39:05 by vicgarci          #+#    #+#             */
/*   Updated: 2023/03/06 19:26:02 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

void	free_struct(t_FdF_info *fdf)
{
	if (fdf->map->map)
	{
		free_map(fdf->map);
		free(fdf->map);
	}
	free(fdf->cam->ang);
	free(fdf->cam->dir_vec);
	free(fdf->cam->perps);
	free(fdf->cam);
	if (!fdf->mlx)
	{
		if (fdf->img)
			mlx_destroy_image(fdf->mlx, fdf->img);
		if (fdf->win)
			mlx_destroy_window(fdf->mlx, fdf->win);
		free(fdf->mlx);
	}
	free(fdf);
}
