#include "libft.h"

/*
	Checks if a character is in a set
	If no character is hit it will return -1

	First argument is the current indexated char
	and the second argument is the set which
	it is being checked against
*/
int	ft_single_inset(char c, char const *set)
{
	int	count;

	count = 0;
	while (set[count])
	{
		if (c == set[count])
			return (count);
		count++;
	}
	return (-1);
}

/*
	Checks if a character array is in a set
	Will return the index of the character which was being
	hit

	First argument is the string to being scanned.
	Second argument is the set to check against.
	IMPORTANT: If no character is hit it will return -1
*/
int	ft_inset(char *str, char const *set)
{
	int	count;

	count = 0;
	while (str[count])
	{
		if (ft_single_inset(str[count], set) != -1)
			return (ft_single_inset(str[count], set));
		count++;
	}
	return (-1);
}