#include <stdio.h>

static int	word_counter(char const *s, char c)
{
	int	i;
	int	words;
	int saw_quote;

	saw_quote = 0;
	i = 0;
	while (s[i] == c && s[i])
		i++;
	words = 0;
	while (s[i])
	{
		if (s[i] == '.' && s[i])
		{
			i++;
			while (s[i] != '.' && s[i])
				i++;
			saw_quote = 1;
			words++;
		}
		i++;
		if (s[i] != c && s[i])
		{
			while (s[i] != c && s[i])
			{
				i++;
				if (!s[i])
					return (++words);
			}
			words++;
		}
		i++;
	}
	return (words);
}

int	main(int argc, char **argv)
{
	int word_count = word_counter(argv[1], ' ');
	printf("WC; %d", word_count);
}