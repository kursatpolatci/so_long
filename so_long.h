/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpolatci <kpolatci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 13:40:08 by kpolatci          #+#    #+#             */
/*   Updated: 2023/09/29 16:36:07 by kpolatci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./get_next_line/get_next_line.h"
# include "./ft_printf/ft_printf.h"
# include "./mlx/mlx.h"
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

typedef struct s_map
{
	char	*map_name;
	char	**line;
	char	**line_clone;
	int		map_x;
	int		map_y;
	int		player_x;
	int		player_y;
	int		exit_x;
	int		exit_y;
	int		collec_x;
	int		collec_y;
	int		p_count;
	int		c_count;
	int		e_count;
	int		collected_c_count;
}	t_map;

typedef struct s_picture
{
	void	*player;
	void	*coin;
	void	*wall;
	void	*ground;
	void	*exit;
	int		x;
	int		y;
}			t_picture;

typedef struct s_mlx
{
	void		*init;
	void		*window;
	int			x;
	int			y;
	int			pixel_x;
	int			pixel_y;
	t_map		*map;
	t_picture	*img;
}			t_mlx;

int		ft_move(t_map *map, int x, int y);
void	ft_calculate_coin(t_map *map);
void	ft_temporary_coin(t_map *map);
void	ft_collectible_coin(t_map *map);
int		ft_accessibility_exit(t_map	*map);

void	ft_check_map_name(int argc, char **argv);
int		ft_count_lines(int fd);
void	ft_copy_map(t_map *map);
t_map	*ft_create_map(int argc, char **argv);

void	ft_count_objects(t_map *map);
void	ft_check_object(t_map *map);

void	ft_map_width(t_map *map);
int		ft_full_wall_horizontal(char **str, int index);
int		ft_full_wall_vertical(char **str, int index);
int		ft_is_rectangle(char **map);
void	ft_check_rectangle(t_map *map);

void	ft_find_object_decision(t_map *map, char c, int *x, int	*y);
void	ft_find_object(t_map *map, char c, int *x, int	*y);
void	ft_assignment(t_map	*map);
t_map	*ft_check(int argc, char **argv);
void	ft_process(t_map **map, int argc, char **argv);

void	ft_img_init(t_picture *img, t_mlx *mlx);
void	ft_img_send(t_mlx *mlx, t_picture *img, char c);
void	ft_map_to_img(t_map *map, t_mlx *mlx, t_picture *img);
void	ft_shift(t_mlx *mlx, int x, int y);
int		ft_key_handler(int keycode, t_mlx *mlx);

void	ft_print_error(char *str);
void	ft_print_error_extended(char *str, t_map *map);
int		ft_strlen2(char **str);
int		ft_find_str(char *src, char *base, int *index);
void	ft_memset(void	*content, char c, int size);

void	ft_free_map_split(char ***str);
void	ft_free_map(t_map *map);
void	ft_check_fd_xpm(t_map *map);
void	ft_check_fd_ber(char **argv);
int		ft_close_game(t_mlx *mlx);

int		ft_isdigit(char c);
int		ft_isalpha(char c);
int		ft_is_another_obj(char **str);
void	ft_print_map(char **str);

#endif