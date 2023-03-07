/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_dark.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 18:29:04 by vicgarci          #+#    #+#             */
/*   Updated: 2023/03/07 11:28:13 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

void	set_dark(t_FdF_info *fdf)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (j != HEIGHT)
	{
		while (i != WIDTH)
		{
			mlx_pixel_put(fdf->mlx, fdf->win, i, j, 0xFF000000);
			i++;
		}
		i = 0;
		j++;
	}
}
