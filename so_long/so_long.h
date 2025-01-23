/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elopin <elopin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 22:12:56 by elopin            #+#    #+#             */
/*   Updated: 2025/01/22 22:06:22 by elopin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "gnl/get_next_line.h"
# include "mlx/mlx.h"
# include "printf/ft_printf.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <time.h>

int		ft_strlen(char *str);
char	**ft_split(char const *s, char c);
char	**gest_map(char *ber);
void	*ft_calloc(size_t ec, size_t es);
int		valid_map(char **map);
int		pjoueur(char **map, int *a, int *b, char p);
int		swap_case(char *a, char *b, int i);
int		swap_map(char ***tmap, int i, void *win, void *mlx);
void	put_img(void *mlx, void *win, char **map);
void	*ft_choose_img(int x, int y, char **map, void *mlx);
int		c_count(char **map, char f);
void	add_enemie(char ***map);
int		gety(char **map);
int		getx(char **map);
void	acces_sorti(char **map, int y, int x, int *c);
void	ft_reset_map(char **map);
void	moov_enemie(char ***tmap, void *mlx, void *win);
int		moov_enemie2(void *param);
int		check_0(char **map);
char	*my_ft_itoa(int n);
int		ft_strstr(const char *b, const char *li);
void	ft_free_map(char ***tmap);
void	mlx_des(void *win, void *mlx);
void	*sous_choose_img(int y, int x, void *mlx);
void	help_me(int e, char **map);
char	*help_mev2(int fd);
int		help_mev3(char **map, int i);
void	*sous_img(int y, int x, void *mlx, char **map);

#endif
