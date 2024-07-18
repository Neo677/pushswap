// header

#include "push_swap.h"

// pour affichage des arguments dans la command line

static int	count_word(char *str, char sp)
{
	int		i;
	bool	word;

	i = 0;
	while (*str)
	{
		word = false;
		while (*str == sp && *str)
			str++;
		while (*str != sp && *str)
		{
			if (!word)
			{
				i++;
				word = true;
			}
			str++;
		}
	}
	return (i);
}

// implmentation de argv dans la memoire

char	**ft_split(char *str, char sp)
{
	int	i;
	int	**vc;
	int	count;

	count = count_word(str, sp);
	if (!count)
		exit(1);
	vc = malloc(sizeof(char *) * (size_t)(count + 2));
	// add 2 dans la memoire pour le '\0' et le NULL la fin
	if (vc == NULL)
		return (free(vc), NULL);
	while (count-- >= 0)
	{
		if (i == 0)
		{
			vc[i] = malloc(sizeof(char));
			if (vc[i] == NULL)
				return (free(vc), NULL);
			vc[i++][0] = '\0';
			continue ;
		}
		vc[i++] = get_next_word(str, sp);
	}
	vc[i] = NULL;
	return (vc);
}

static char	*get_next_word(char *str, char sp)
{
	static int cursor_cmd = 0;
	char *next;
	int len;
	int i;

	while (str[cursor_cmd] == sp)
		cursor_cmd++;
	len = 0;
	i = 0;
	while ((str[cursor_cmd + len] != sp) && str[cursor_cmd + len])
		len++;
	next = malloc((size_t)len * sizeof(char) + 1);
	if (NULL == next)
		return (free(next), NULL);
	while ((str[cursor_cmd] != sp) && str[cursor_cmd])
		next[i++] = str[cursor_cmd++];
	next[i] = '\0';
	return (next);
}