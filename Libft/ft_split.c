/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohassani <ohassani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 14:51:20 by ohassani          #+#    #+#             */
/*   Updated: 2023/11/13 21:29:23 by ohassani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**free_arr(char **strings)
{
	int	i;

	i = 0;
	while (strings[i])
	{
		free(strings[i]);
		i++;
	}
	free(strings);
	return (0);
}

static size_t	cal(const char *s, char c)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			i++;
		else
		{
			count++;
			while (s[i] != '\0' && s[i] != c)
				i++;
		}
	}
	return (count);
}

static char	*word(char const *s, size_t begin, size_t last)
{
	char	*word1;
	size_t	i;

	word1 = (char *)malloc((last - begin + 1) * sizeof(char));
	if (!word1)
	{
		return (NULL);
	}
	i = 0;
	while (last > begin)
	{
		word1[i] = s[begin];
		i++;
		begin++;
	}
	word1[i] = '\0';
	return (word1);
}

static char	**loopsplit(const char *s, char c, size_t i, char **split)
{
	size_t	j;
	int		k;

	j = 0;
	k = -1;
	while (i <= ft_strlen(s))
	{
		if (s[i] != c && k < 0)
			k = i;
		else if ((s[i] == c || i == ft_strlen(s)) && k >= 0)
		{
			split[j] = word(s, k, i);
			if (!split[j])
			{
				free_arr(split);
				return (NULL);
			}
			j++;
			k = -1;
		}
		i++;
	}
	split[j] = NULL;
	return (split);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	size_t	j;

	split = (char **)malloc((cal(s, c) + 1) * sizeof(char *));
	j = 0;
	if (split == NULL)
		return (NULL);
	return (loopsplit(s, c, 0, split));
}
// int main()
// {
//     char **strings;
//     int i  = 0;
//     strings = ft_split("  oualid oualdui gfgf dgdfg", ' ');
//      while (strings[i]) {
//         printf("%s\n", strings[i]);
//         i++;
//     }
//         for (int i = 0; strings[i] != NULL; ++i)
// 		free(strings[i]);
// 	free(strings);
//     return (0);
// }

// int main ()
// {

// char **s = ft_split("hello!", ' ');
// printf("%s", *s);
// }