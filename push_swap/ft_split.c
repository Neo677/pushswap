/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomtom <tomtom@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 13:31:11 by thobenel          #+#    #+#             */
/*   Updated: 2024/08/31 23:47:06 by tomtom           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stddef.h>
#include <stdio.h>

static int	count_seg(char *str, char delim)
{
	int		count;
	int		in_word;

	count = 0;
	in_word = 0;
	while (*str)
	{
		if (*str != delim && !in_word)
		{
			in_word = 1;
			count++;
		}
		else if (*str == delim && in_word)
			in_word = 0;
		str++;
	}
	printf("count seg = %d\n", count);
	return (count);
}

static char *new_seg(char **str, char delim)
{
    char *new_str;
    int len = 0;
	int i = 0;
    // Sauter les délimiteurs initiaux
    while (**str == delim)
        (*str)++;  // Avancer dans la chaîne principale

    // Calculer la longueur du segment suivant
    while ((*str)[len] != delim && (*str)[len])
        len++;

    printf("Extracting segment of length %d\n", len);  // Afficher la longueur

    // Allouer la mémoire pour le segment
    new_str = malloc((sizeof(char)) * (len + 1));
    if (!new_str)
        return (free(new_str), NULL);

    // Copier chaque caractère dans le nouveau segment
    while (i < len)
    {
        printf("Copying character: %c\n", **str);  // Afficher chaque caractère copié
        new_str[i] = *(*str)++;
		i++;
    }

    new_str[len] = '\0';  // Terminer la chaîne avec '\0'
    printf("Extracted segment: %s\n", new_str);  // Afficher le segment extrait
    return (new_str);
}


char	**ft_split(char *str, char delim)
{
	int		count;
	char	**ptr_str;
	int		i;

	i = 0;
	if (!str)
		return (NULL);
	count = count_seg(str, delim);
	ptr_str = malloc(sizeof(char *) * (count + 1));
	 printf("Allocated segment pointer: %p\n", ptr_str);

	if (!ptr_str)
		return (free(ptr_str), NULL);
	while (i < count)
	{
		ptr_str[i] = new_seg(&str, delim);
		if (!ptr_str[i])
		{
			while (i > 0)
				free(ptr_str[--i]);
			free(ptr_str);
		    printf("Freeing segment pointer: %p\n", ptr_str);
			return (NULL);	
		}
		i++;
	}
	ptr_str[i] = NULL;
	return (ptr_str);
}
