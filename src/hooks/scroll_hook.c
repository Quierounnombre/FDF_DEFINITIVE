/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scroll_hook.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 16:48:20 by vicgarci          #+#    #+#             */
/*   Updated: 2023/03/07 17:16:30 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../FdF.h"

static void	zoom_out(t_FdF_info *fdf)
{
	if ((int)fdf->cam->dim.x > 1 && (int)fdf->cam->dim.y > 1)
	{
		fdf->cam->dim.x -= 1;
		fdf->cam->dim.y -= 1;
	}
	draw(fdf);
}

static void	zoom_in(t_FdF_info *fdf)
{
	if ((int)fdf->cam->dim.x < (INT_MAX - 1)
		&& (int)fdf->cam->dim.y < (INT_MAX - 1))
	{
		fdf->cam->dim.x += 1;
		fdf->cam->dim.y += 1;
	}
	draw(fdf);
}

int	scroll_hook(int button, int xdelta, int ydelta, t_FdF_info *param)
{
	t_FdF_info	*fdf;

	fdf = param;
	if (xdelta && button == 4)
		zoom_in(fdf);
	else if (ydelta)
		zoom_out(fdf);
	ft_printf("Zoom actual (x, y)[%d, %d]\n", (int)fdf->cam->dim.x,
		(int)fdf->cam->dim.y);
	return (button);
}
