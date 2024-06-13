/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pajimene <pajimene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 13:48:37 by pajimene          #+#    #+#             */
/*   Updated: 2024/06/13 19:12:22 by pajimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_count_word(char const *s, char c)
{
	int	i;
	int	word;

	i = 0;
	word = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
			word++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (word);
}

static int	ft_wordlen(char const *s, char c, int i)
{
	int	count;

	count = 0;
	while (s[i] && s[i] != c)
	{
		count++;
		i++;
	}
	return (count);
}

static void	ft_free_tab(char **tab, int *k)
{
	int	i;

	i = 0;
	if (!tab[*k])
	{
		while (tab[i])
			free(tab[i++]);
		free(tab);
	}
	(*k)++;
	return ;
}

static char	*ft_print_word(char const *s, char c, int i)
{
	char	*word;
	int		j;

	word = malloc(sizeof(char) * (1 + ft_wordlen(s, c, i)));
	if (!word)
		return (NULL);
	j = 0;
	while (j < ft_wordlen(s, c, i))
	{
		word[j] = s[i + j];
		j++;
	}
	word[j] = '\0';
	return (word);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	int		i;
	int		k;

	if (!s)
		return (NULL);
	tab = malloc(sizeof(char *) * (1 + ft_count_word(s, c)));
	if (!tab)
		return (NULL);
	i = 0;
	k = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
		{
			tab[k] = ft_print_word(s, c, i);
			ft_free_tab(tab, &k);
		}
		while (s[i] && s[i] != c)
			i++;
	}
	tab[k] = 0;
	return (tab);
}
