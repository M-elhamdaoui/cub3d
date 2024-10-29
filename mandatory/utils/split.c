/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houbet <houbet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 20:57:38 by hmrabet           #+#    #+#             */
/*   Updated: 2024/08/26 14:51:10 by houbet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	word_count(char *s, char c)
{
	int	i;
	int	count;

	if (!s || !s[0])
		return (0);
	i = -1;
	count = 0;
	while (s[++i])
		if ((s[i] != c && s[i + 1] == c)
			|| (s[i] != c && s[i + 1] == '\0'))
			count++;
	return (count);
}

static int	words_len(char *s, char c, int i)
{
	int	l;

	l = 0;
	while (s && s[i] && s[i] == c)
		i++;
	while (s && s[i] && s[i++] != c)
		l++;
	return (l);
}

static char	**fill_arr(int w[], char *s, char **arr, t_cub3d *cub)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = 0;
	while (k < w[1])
	{
		j = 0;
		arr[k] = (char *)ft_malloc(cub, &cub->collector,
				sizeof(char) * (words_len(s, w[0], i) + 1));
		if (!arr[k])
			return (NULL);
		while (s && s[i] && s[i] == w[0])
			i++;
		while (s && s[i] && s[i] != w[0])
			arr[k][j++] = s[i++];
		arr[k][j] = '\0';
		k++;
	}
	arr[k] = 0;
	return (arr);
}

char	**ft_split(char *s, char c, t_cub3d *cub)
{
	char	**arr;
	int		words[2];

	words[0] = c;
	if (!s || !s[0])
		return (NULL);
	words[1] = word_count(s, words[0]);
	arr = (char **)ft_malloc(cub, &cub->collector,
			sizeof(char *) * (words[1] + 1));
	if (!arr)
		return (NULL);
	arr = fill_arr(words, s, arr, cub);
	return (arr);
}
