/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lib.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloimusa <aloimusa@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 15:09:05 by aloimusa          #+#    #+#             */
/*   Updated: 2025/02/02 22:59:11 by aloimusa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIB_H
# define FT_LIB_H
# define ERROR = "Dict Error\n"
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <fcntl.h>

enum e_names {ones, teens, tenz, hundreds, npwthousands};

char	*ft_buffer(char *str);
char	*ones_str(char num);
char	*teens_str(char num);
char	*tenz_str(char num);
char	*hun_str(char num);
char	*pow_str(char num);
void	call_num(char num, int name);
void	call_ternary(char *array);
int		str_len(char *str);
char	*ft_strchr(char *str, char c);
int		ft_strcmp(char *s1, char *s2);
char	*ft_strtok(char *str, char delim);
void	ft_strtok_reset(void);
char	*read_file(const char *filename);
void	ft_putstr(char *str);
char	*search(char *dict, char *number_str);
void	printword(char *number_str);
char	*ft_strdup(char *src);
int		length(char *str);
int		something_wrong(char *arg);
void	ft_dupcpy(char *src, char *dest);
int		av_c(char *str);
int		av_toolong(char *str);
int		zero_maker(char *arg);
void	activate(void);

#endif
