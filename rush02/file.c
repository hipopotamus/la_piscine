#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <fcntl.h>

typedef struct s_key_value
{
	char *key;
	char *value;
	int len;
} t_Key_Value;

int check_space(char c)
{
	if (c == '\t' || c == '\t' || c == '\v')
		return (1);
	if (c == '\r' || c == '\n' || c == ' ')
		return (1);
	return (0);
}

void ft_strncpy(char* dest, char*src, int n)
{
	int i;

	i = 0;
	while (src[i] != '\0' && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}

int len_kv(char *str, int signal)
{
	int i;

	i = 0;
	if (signal == 1)
	{
		while (check_space(str[i]) == 0 && str[i] != ':')
			i++;
	}
	if (signal == 0)
	{
		while (str[i] != '\n' && str[i] != '\0')
		i++;
	}
	return (i);
}

int len_entry(char *str)
{
	int i;
	int cnt;

	i = 0;
	cnt = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			cnt++;
		i++;
	}
	return (cnt);
}

void get_struct(char *str, int i, t_Key_Value *t[], int j)
{
	int l_key;
	int l_value;
	
	l_key = len_kv(&str[i], 1);
	if (l_key == 0)
	{
		t[j]->key = malloc(sizeof(char) * 5);
		ft_strncpy(t[j]->key, "null", 4);
		t[j]->value = malloc(sizeof(char) * 5);
		ft_strncpy(t[j]->value, "null", 4);
		return ;
	}
	t[j]->key = malloc(sizeof(char) * l_key + 1);
	ft_strncpy(t[j]->key, &str[i], l_key);
	t[j]->len = l_key;
	i += l_key;
	while (check_space(str[i]) == 1 || str[i] == ':')
		i++;
	l_value = len_kv(&str[i], 0);
	t[j]->value = malloc(sizeof(char) * l_value + 1);	
	ft_strncpy(t[j]->value, &str[i], l_value);
}

int  get_file(char *buff, char* name)
{
	int file;
	int readn;

	file = open(name, O_RDONLY);
	if (file < 0)
	{
		write(1, "error", 5);
		return (0);
	}
	
	readn = read(file, buff, 2000);
	buff[readn + 1] = '\0'; 
	return (readn);
}

t_Key_Value **make_get(int size)
{
	t_Key_Value **Dict;
	int i;

	Dict = malloc(sizeof(t_Key_Value*) * (size + 2));
	i = 0;
	while (i < size + 2)
	{
		Dict[i] = malloc(sizeof(t_Key_Value));
		i++;
	}
	return (Dict);
}

t_Key_Value **make_dict(char* name, char* buff)
{
	int len_e;
	int readn;
	t_Key_Value **Dict;

	readn = get_file(buff, name);
	len_e = len_entry(buff) + 1;
	Dict = make_get(len_e);

	int i = 0;
	int j = 0;
	while (i < readn)
	{
		get_struct(buff, i, Dict, j);
		i += (len_kv(&buff[i], 0) + 1);
		j++;
	}
	Dict[j]->key = malloc(sizeof(char) * 1);
	Dict[j]->key = "\0";
	return (Dict);
}

int main()
{
	char* name;
	char buff[2000];
	t_Key_Value **Dict;

	name = "numbers.dict.txt";
	Dict = make_dict(name, buff);
//make_dict는 파일이름을 받아서 구조체를 만들어줍니다.
//위의 형식으로 만들어서 쓰면 될것 같습니다.

//아래는 테스트 코드입니다.
	int i = 0;
	while((Dict[i]->key)[0] != '\0')
	{
		printf("%s: ", Dict[i]->key);
		printf("%s\n", Dict[i]->value);
		i++;
	}
}
