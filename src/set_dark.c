/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_dark.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 18:29:04 by vicgarci          #+#    #+#             */
/*   Updated: 2023/03/07 15:01:36 by vicgarci         ###   ########.fr       */
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
			ft_pixel_put(fdf->img, j, i, 0);
			i++;
		}
		i = 0;
		j++;
	}
}
