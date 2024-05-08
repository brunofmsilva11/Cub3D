/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmota-si <bmota-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 11:47:06 by bmota-si          #+#    #+#             */
/*   Updated: 2024/05/08 18:02:16 by bmota-si         ###   ########.fr       */
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
# include <sys/stat.h>
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
	int		error;
}	t_data;

/**************************************************************************************************************/


/* - - - - - -[ERROR] - - - - - -*/

//error.c
void			finish_error(char *str, int i);
void			file_name_error(t_data *d);
void			error_rgb(char *line, t_data *d, char *str);
void			error_in_elem(t_data *d, char *line);

//error2.c
void			error_dup_elem(t_data *d, char *line);
void			no_tab_error_handle(t_data *d);


/**************************************************************************************************************/


/* - - - - - -[INIT] - - - - - -*/

//init.c
void			ft_init_stack(t_data *d);
void			ft_init_stack1(t_data *d);
void			ft_init_stack2(t_data *d);
void			ft_init_stack3(t_data *d);
void			ft_init_stack4(t_data *d);

//init2.c
void			init_struct_imgs(t_data *d);
int     		check_access(t_data *d);


/**************************************************************************************************************/


/* - - - - - -[MAP_FILE] - - - - - -*/

//check_file.c
void			six_args(t_data *d, char *file_name);
void			check_null_file(t_data *d, char *file_name);
void			ft_check_map_file(t_data *d, char *file_name);

//check_file2.c
void			map_to_file(t_data *d, char *file_name);
void			search_for_map_elem(t_data *d);
void			map_to_file2(t_data *d);
void			map_to_matrix(t_data *d);
void			ft_fill_map_index(t_data *d);

//check_file3.c
void			put_first_last(t_data *d);
//static 			void	process_tabs_and_spaces(char *str, char *line, t_data *d);
//static 			void	fill_remaining_with_hash(char *line, t_data *d);
char			*fill_matrix_line(t_data *d, char *str);
void			fill_rest(t_data *d);

//check_textures.c
void			ft_check_textures(t_data *d);
void			ft_check_textures2(t_data *d);

//direc_color.c
int				check_direc(t_data *d, char *line);
int				check_direc2(t_data *d, char *line);
int				check_color(t_data *d, char *line);
void			path_image(t_data *d, char *line, int flag);

//rgb_check.c
void			put_rgb(t_data *d, char *line, int flag);
int				ft_check_next_comma(char *line);
int				ft_verify_digits(char *str, int position);
void			put_fc_rgb(t_data *d, int flag, char *line);
int				check_for_spaces(char *str);

//rgb_check2.c
char			*remove_tabs(char *str);


/**************************************************************************************************************/


/*- - - - - - [START] - - - - - -*/
//start.c
void			get_texture_val(t_data *d);
void			ray_values(t_data *d);
void			get_hit(t_data *d);
void			check_side(t_data *d);
void			ray_calc(t_data *d);
void			draw_raycast(t_data *d);
void			ft_start(t_data *d);

//direction.c
void			direction(t_data *d);
void			direction2(t_data *d);

//draw.c
void			ft_draw(t_data *d, int i);
void			get_wall_x(t_data *d);
int				ft_get_pixel(t_data *d, int x, int y);

//move.c
int				game_loop(t_data *d);
int				ft_movs(t_data *d);
void			move_vertical(t_data *d, int dir_flag);
void			move_horizontal(t_data *d, int dir_flag);
void			rotate_player(t_data *d, int dir_flag);


/**************************************************************************************************************/


/*- - - - - - [TEST_MAP_VALIDATION] - - - - - -*/

//test.c
void			map_validation_test(t_data *d, char *file_name);
void			put_player_pos(t_data *d, int y, int x);


/**************************************************************************************************************/


/*- - - - - - [WINDOW] - - - - - -*/

//win_color.c
void    		put_color_on_window(t_data *d);
void    		put_color_on_window2(t_data *d, int f_color, int c_color);

//win_utils.c
void			my_mlx_pixel_put(t_data *data, int x, int y, int color);

/**************************************************************************************************************/

/* - - - - - -[exit_command.c] - - - - - -*/
int    			ft_exit_x(t_data *d);
int				release_key(int keysym, t_data *d);
int				handle_input(int keysym, t_data *d);

/* - - - - - -[free.c] - - - - - -*/
void			ft_free_data(t_data *d);
void			ft_free_data2(t_data *d);
void			ft_free_data3(t_data *d);
void			ft_no_leak(t_data *d, char *line);
void			ft_no_leak2(t_data *d, char *line);
int				ft_no_leak3(t_data *d, char *line);
void			free_imgs(t_data *d);
/* - - - - - -[rgb_check.c] - - - - - -*/
void			put_rgb(t_data *d, char *line, int flag);
int				ft_check_next_comma(char *line);
int				ft_verify_digits(char *str, int position);
void			put_fc_rgb(t_data *d, int flag, char *line);
int				check_for_spaces(char *str);

/* - - - - - -[utils.c] - - - - - -*/
int				string_comp(char *s1, char *s2);
int				ft_count(char *str, char c);
int				ft_search(char *str, char c);
int				ft_search_space(char *str);
int				ft_count_lines(t_data *d);

/* - - - - - -[xpm_files.c] - - - - - -*/
void			get_imgs_xpm(t_data *d);
void			get_imgs_addr(t_data *d);

/* - - - - - -[main.c] - - - - - -*/
void			ft_start(t_data *d);
int				main(int ac, char **av);

#endif