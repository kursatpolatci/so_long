/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_creat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpolatci <kpolatci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 13:43:39 by kpolatci          #+#    #+#             */
/*   Updated: 2023/09/29 14:35:48 by kpolatci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_check_map_name(int argc, char **argv)
{
	int	index;
	int	len_without_ber;

	index = ft_strlen(argv[1]) - 1;
	len_without_ber = 0;
	if (argc != 2)
		ft_print_error("Invalid argument count.");
	if (argv[1][index] != 'r' || argv[1][index - 1] != 'e'
		|| argv[1][index - 2] != 'b' || argv[1][index - 3] != '.'
		|| index < 4)
		ft_print_error("Invalid map file");
	index -= 4;
	if (argv[1][index] == '/')
		ft_print_error("Invalid map file");
}

int	ft_count_lines(int fd)
{
	int		count;
	char	*temp;

	count = 0;
	while (1)
	{
		temp = get_next_line(fd);
		if (!temp)
		{
			free(temp);
			break ;
		}
		free(temp);
		count++;
	}
	return (count);
}

void	ft_copy_map(t_map *map)
{
	int		index;

	index = 0;
	map->line_clone = (char **)malloc(sizeof(char *) * (map->map_y + 1));
	map->line_clone[map->map_y] = 0;
	while (index < map->map_y)
	{
		map->line_clone[index] = (char *)malloc(map->map_x + 1);
		map->line_clone[index][map->map_x] = 0;
		ft_memset(map->line_clone[index], '0', map->map_x);
		index++;
	}
	map->line_clone[index] = 0;
}

t_map	*ft_create_map(int argc, char **argv)
{
	t_map	*creat_map;
	int		fd;
	int		index;
	char	*str;
	char	**lines;

	ft_check_map_name(argc, argv);
	fd = open(argv[1], O_RDWR);
	index = ft_count_lines(fd);
	lines = (char **)malloc(sizeof(char *) * index + 1);
	lines[index] = 0;
	close(fd);
	fd = open(argv[1], O_RDWR);
	creat_map = (t_map *)malloc(sizeof(t_map));
	ft_assignment(creat_map);
	index = 0;
	str = get_next_line(fd);
	while (str)
	{
		lines[index++] = str;
		str = get_next_line(fd);
	}
	creat_map->line = lines;
	creat_map->map_name = argv[1];
	return (creat_map);
}
