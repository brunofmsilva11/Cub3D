/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmota-si <bmota-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 11:47:06 by bmota-si          #+#    #+#             */
/*   Updated: 2024/04/10 16:38:43 by bmota-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "libft/libft.h"
# include "minilibx-linux/mlx.h"
# include "minilibx-linux/mlx_int.h"
# include <stdio.h>
# include <stdlib.h>
# include <X11/X.h>
# include <fcntl.h>
# include <unistd.h>
# include <math.h>
# include <signal.h>
# define HEIGHT 1080
# define WIDTH 1920
# define WALL 0xffffff
# define FLOOR 0x000000
# define GRID 0x838589
# define PLAYER 0xfffb00
# define SIZE 50
# define TEX_WIDTH 64
# define TEX_HEIGHT 64

typedef struct s_image
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
	int		h;
	int		w;
}	t_image;

typedef struct s_map
{
	char	**map;
	char	**map_dup;
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	int		flag_c;
	int		flag_f;
	char	player_pos;
	char	**f_color;
	char	**c_color;
	char	**color_aux;
	int		skip_count;
}	t_map;

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	char	*line;
	int		count_lines;
	int		line_length;
	t_map	*map_utils;
	t_image	*img;
	t_image	*aux;
	t_image	*n_img;
	t_image	*s_img;
	t_image	*w_img;
	t_image	*e_img;
	float	p_y;
	float	p_x;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	double	camera_x;
	double	raydir_x;
	double	raydir_y;
	double	side_dist_x;
	double	side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;
	double	perp_wall_dist;
	int		stepx;
	int		stepy;
	int		hit;
	int		side;
	int		line_height;
	int		draw_start;
	int		draw_end;
	int		mapx;
	int		mapy;
	int		wall_dir;
	int		x;
	int		y;
	int		fd;
	int		temp_fd;
	int		i;
	int		a;
	int		b;
	int		key_press_up;
	int		key_press_down;
	int		key_press_left;
	int		key_press_right;
	int		key_press_r_right;
	int		key_press_r_left;
	int		tab_count;
	double	wall_x;
	int		tex_x;
	int		tex_y;
	double	text_step;
	double	text_pos;
}	t_data;

/**************************************************************************************************************/


/* - - - - - -[INIT] - - - - - -*/

//init.c
void	ft_init_stack(t_data *d);
void	ft_init_stack1(t_data *d);
void	ft_init_stack2(t_data *d);
void	ft_init_stack3(t_data *d);
void	ft_init_stack4(t_data *d);

//init2.c
void	init_struct_imgs(t_data *d);
int     check_access(t_data *d);


/**************************************************************************************************************/


/* - - - - - -[MAP_FILE] - - - - - -*/

//check_file.c
void	args_in_file(t_data *d, char *file_name);
void	ft_check_map_file(t_data *d, char *file_name);

//direc_color.c
int		valid_info(t_data *d, char *line);
int		valid_info1(t_data *d, char *line);
int		valid_info2(t_data *d, char *line);
void	path_image(t_data *d, char *line, int flag);

//rgb_check.c
void	put_rgb(t_data *d, char *line, int flag);
int		ft_check_next_comma(char *line);
int		ft_verify_digits(char *str, int position);
void	put_fc_rgb(t_data *d, int flag, char *line);
int		check_for_spaces(char *str);


/**************************************************************************************************************/
/* - - - - - -[error.c] - - - - - -*/
void	finish_error(char *str, int i);
void	file_name_error(t_data *d);
void	error_handling(char *line, t_data *d, char *str);

/* - - - - - -[file.c] - - - - - -*/
/* void	args_in_file(t_data *d, char *file_name);
int		valid_info(t_data *d, char *line);
int		valid_info1(t_data *d, char *line);
int	    valid_info2(t_data *d, char *line); */
void	error_in_elem(t_data *d, char *line);
void	error_dup_elem(t_data *d, char *line);

/* - - - - - -[rgb_check.c] - - - - - -*/
void	put_rgb(t_data *d, char *line, int flag);
int		ft_check_next_comma(char *line);
int		ft_verify_digits(char *str, int position);
void	put_fc_rgb(t_data *d, int flag, char *line);
int		check_for_spaces(char *str);

/* - - - - - -[utils.c] - - - - - -*/
int		string_comp(char *s1, char *s2);
int		ft_count(char *str, char c);

/* - - - - - -[xpm_files.c] - - - - - -*/
void	get_imgs_xpm(t_data *d);
void	get_imgs_addr(t_data *d);

/* - - - - - -[main.c] - - - - - -*/
int		main(int ac, char **av);

#endif