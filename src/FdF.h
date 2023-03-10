/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FdF.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 14:30:33 by vicgarci          #+#    #+#             */
/*   Updated: 2023/03/07 17:09:59 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft_def/libftprintf.h"
# include <mlx.h>
# include "FdF_ang_defines.h"
# include "Key_defines.h"

# ifndef WIDTH
#  define WIDTH 1000
# endif

# ifndef HEIGHT
#  define HEIGHT 1000
# endif

# ifndef NAME
#  define NAME "FDF"
# endif

# define MAX_ARGS 2

typedef struct s_pixel
{
	int			pixel;
	uint32_t	color;
}			t_pixel;

typedef struct s_map
{
	t_pixel	**map;
	int		map_size_x;
	int		map_size_y;
}			t_map;

typedef struct s_angle
{
	float	alpha;
	float	beta;
	float	gamma;
}				t_angle;

typedef struct s_dir_vectors
{
	t_vector2D	v_alpha;
	t_vector2D	v_beta;
	t_vector2D	v_gamma;
}					t_dir_vectors;

typedef struct s_perspective
{
	t_angle	isometrica;
	t_angle	dimetrica;
	t_angle	trimetrica;
	t_angle	caballera;
	t_angle	militar;
	int		current;
}				t_perspective;

typedef struct s_cam
{
	t_angle			*ang;
	t_vector3D		dim;
	t_dir_vectors	*dir_vec;
	t_vector2D		pos;
	t_perspective	*perps;
}				t_cam;

typedef struct s_img
{
	void	*img;
	char	*adres;
	int		bits_per_pixel;
	int		line;
	int		endian;
}				t_img;

typedef struct s_FdF_info
{
	void		*mlx;
	t_img		*img;
	void		*win;
	t_map		*map;
	t_cam		*cam;
}			t_FdF_info;

/*----STORE----*/

t_bool			store_file(int fd, t_map *map);
t_bool			store_line(char *s, t_map *map, int line);
t_FdF_info		*init_struct(void);
void			free_map(t_map *map);
void			free_struct(t_FdF_info *fdf);

/*----INIT && PARSE----*/

t_bool			parse(int argc, char **argv);
int				calc_len(char *s);
t_bool			init(int argc, char **argv, t_FdF_info **fdf_info);
void			ft_hooks(t_FdF_info *fdf);

/*----CLOSE----*/

int				close_fdf(t_FdF_info *fdf);

/*----DRAW----*/

void			draw(t_FdF_info	*fdf);
void			draw_lines(t_FdF_info *fdf, int i, int j, t_vector2D v);
t_vector2D		get_iso_perspective(t_vector3D v3, t_FdF_info *fdf);
void			set_dark(t_FdF_info *fdf);
void			ft_pixel_put(t_img	*img, int x, int y, int color);

/*-----CAM-----*/

t_vector3D		set_dimensions(t_map *map);
void			load_angles(t_angle *ang, t_dir_vectors *v);
void			select_perspective(t_FdF_info *fdf);

/*-----HOOKS-----*/

void			a_hook(t_FdF_info *fdf);
void			d_hook(t_FdF_info *fdf);
void			w_hook(t_FdF_info *fdf);
void			s_hook(t_FdF_info *fdf);
void			z_hook(t_FdF_info *fdf);
void			x_hook(t_FdF_info *fdf);
void			y_hook(t_FdF_info *fdf);
void			h_hook(t_FdF_info *fdf);
void			u_hook(t_FdF_info *fdf);
void			j_hook(t_FdF_info *fdf);
void			i_hook(t_FdF_info *fdf);
void			k_hook(t_FdF_info *fdf);
void			left_hook(t_FdF_info *fdf);
void			right_hook(t_FdF_info *fdf);
void			space_hook(t_FdF_info *fdf);
int				scroll_hook(int button, int xdelta,
					int ydelta, t_FdF_info *param);

#endif