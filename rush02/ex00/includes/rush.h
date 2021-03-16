/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeyoon <jeyoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 10:15:56 by jeyoon            #+#    #+#             */
/*   Updated: 2021/03/14 22:53:17 by jeyoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH_H
# define RUSH_H

# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <fcntl.h>

typedef struct	s_key_value
{
	char		*key;
	char		*value;
	int			len;
}				t_key_value;

extern int		g_error;
extern char		g_section[3];

void			init_section(void);
void			cut_section(char *number, t_key_value **dict_arr);
void			fill_section(char *number, int len, int *i);
void			print_digit(int idx, char *number, t_key_value **dict_arr);
void			error_num(char *number);
void			read_first(char first, t_key_value **dict_arr);
void			read_second(char second, char third, t_key_value **dict_arr);
void			read_section(t_key_value **dict_arr);
void			get_free(t_key_value **dict);
void			get_struct_sub(t_key_value *t[], int j);
int				ft_strcmp(char *str1, char *str2);
void			ft_putstr(char *str);
int				find_key(char c, char *str);
int				ft_strlen(char *str);
int				print_error(void);
int				check_space(char c);
void			ft_strncpy(char *dest, char *src, int n);
int				len_kv(char *str, int signal);
int				len_entry(char *str);
void			get_struct(char *str, int i, t_key_value *t[], int j);
int				get_file(char *buff, char *name);
t_key_value		**make_get(int size);
t_key_value		**make_dict(char *name, char *buff, int i, int j);
int				print_digit2(char *number, t_key_value *dict_element,
		int temp, int len);
void			read_third(char third, t_key_value **dict_arr);
void			read_second2(char second, t_key_value **dict_arr);
int				check_zero(char *number);
void			print_zero(t_key_value **dict_arr);

#endif
