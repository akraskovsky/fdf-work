/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fprovolo <fprovolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 10:40:42 by fprovolo          #+#    #+#             */
/*   Updated: 2019/11/27 11:07:28 by fprovolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include "libft/libft.h"

typedef struct		s_pix
{
	int				x;
	int				y;
	int				z;
	int				color;
	struct s_pix	*next;
}					t_pix;

typedef struct		s_map
{
	int				size_x;
	int				size_y;
	int				max_z;
	int				min_z;
	int				bg_color;
	t_pix			*pix;
	t_pix			*last_pix;
}					t_map;

t_map				*read_map(int fd);
t_map				*init_map(void);
int					parse_point(char *line, t_map *map, int x, int y);
int					parse_line(char *line, t_map *map);
void				clean_map(t_map *map);
void				clean_points(char **points);
void				print_map(t_map *map);

#endif