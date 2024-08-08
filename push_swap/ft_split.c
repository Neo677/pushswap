/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomtom <tomtom@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 13:31:11 by thobenel          #+#    #+#             */
/*   Updated: 2024/08/07 23:14:11 by tomtom           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stddef.h>

static int	count_segments(char *str, char delim)
{
	int		count;
	bool	in_word;

	count = 0;
	while (*str)
	{
		in_word = false;
		while (*str == delim && *str)
			str++;
		while (*str != delim && *str)
		{
			if (!in_word)
			{
				++count;
				in_word = true;
			}
			str++;
		}
		in_word = false;
	}
	return (count);
}

static char	*extract_next_segment(char *str, char delim)
{
	static int	cursor;
	char		*next_str;
	int			len;
	int			i;

	len = 0;
	i = 0;
	cursor = 0;
	while (str[cursor] == delim)
		cursor++;
	while ((str[cursor + len] != delim) && str[cursor + len])
		len++;
	next_str = malloc((size_t)len * sizeof(char) + 1);
	if (NULL == next_str)
		return (NULL);
	while ((str[cursor] != delim) && str[cursor])
		next_str[i++] = str[cursor++];
	next_str[i] = '\0';
	return (next_str);
}

char	**ft_split(char *str, char delim)
{
	int		words_number;
	char	**vector_strings;
	int		i;

	i = 0;
	words_number = count_segments(str, delim);
	if (words_number == 0)
		exit(1);
	vector_strings = (char **)malloc(sizeof(char *) * (size_t)(words_number
				+ 2));
	if (vector_strings == NULL)
		return (NULL);
	while (words_number-- >= 0)
	{
		vector_strings[i] = extract_next_segment(str, delim);
		if (vector_strings[i] == NULL)
			return (NULL);
		i++;
	}
	vector_strings[i] = NULL;
	return (vector_strings);
}
