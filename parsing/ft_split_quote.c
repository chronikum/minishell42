#include "../includes/ft_minishell.h"


/*
	Returns the word count
*/
//static int	ft_wordcount(char *s, char c)
//{
//	int i;
//	int saw_quote;
//	int words;
//
	//words = 0;
	//saw_quote = 0;
	//i = 0;
	//while (s[i])
	//{
	//	if (s[i] == '"' && c)
	//	{
	//		saw_quote = 1;
	//		i++;
	//		while (s[i] != '"' && s[i])
	//			i++;
	//		saw_quote = 0;
	//		words++;
	//	}
	//	if ((s[i] == c || i == 0))
	//	{
	//		i++;
	//		while (s[i] != c && s[i])
	//			i++;
	//		words++;
	//	}
	//}
//
//	return (words);
//}

static int	word_counter(char const *s, char c)
{
	int	i;
	int	words;
	int saw_quote;

	saw_quote = 0;
	i = 0;
	while (s[i] == c && s[i] != '\0')
		i++;
	//*pword_start = i;
	words = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '"')
		{
			i++;
			while (s[i] != '"' && s[i])
				i++;
			saw_quote = 1;
			words++;
		}
		if (s[i] != c)
		{
			while (s[i] != c)
			{
				i++;
				if (s[i] == '\0')
					return (words);
			}
			words++;
		}
		i++;
	}
	return (words);
}

char	**ft_split_quote(char *s, char c)
{
	if (s && c)
	{
		printf("COUNT: %d\n", word_counter(s, c));
	}
	return (NULL);
}
