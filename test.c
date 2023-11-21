#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include "../libft/libft.h"

// int	main()
// {
// 	t_list	*first;
// 	t_list	*second;
	
// 	// int	fd;

// 	// fd = open("text.txt", O_RDONLY);
// 	first = ft_lstnew(malloc(sizeof(char) * 11));
// 	if (!first)
// 		return (0);
// 	read(0, (char *) first->content, 10);
// 	((char *) first->content)[10] = 0;
// 	second = ft_lstnew(malloc(sizeof(char) * 11));
// 	first->next = second;
// 	second->next = NULL;
// 	read(0, (char *) second->content, 10);
// 	((char *) second->content)[10] = 0;

// 	printf("%s", (char *) first->content);
// 	printf("%s", (char *) second->content);

// 	char *str;

// 	str = malloc(sizeof(char) * 5);
// 	ft_memcpy(str, first->content, 2);
// 	ft_memcpy(str + 2, second->content, 2);
// 	str[5] = 0;
// 	ft_lstclear(&first, free);
// 	printf("str = %s\n", str);
// }

#include <stdio.h>

void example_function() {
    static int static_variable = 0;
    printf("Static variable: %d\n", static_variable);
    static_variable++;
}

int main() {
    example_function(); // Sortie: Static variable: 0
    example_function(); // Sortie: Static variable: 1
    example_function(); // Sortie: Static variable: 2
    return 0;
}


// int	main()
// {
// 	static char	str[50];
// 	int	fd;
// 	fd = 0;
// 	fd = open("text.txt", O_RDONLY);
// 	read(3, str, 10);
// 	printf("premier printf %s\n", str);
// 	read(3, str, 10);
// 	printf("deuxieme printf %s\n", str);	
// }

// int	main()
// {	
// 	int	i;
// 	char	**str;
// 	str = malloc(sizeof(char *) * 10);
// 	if (!str)
// 		return (0);
// 	i = 0;
// 	while (i < 9)
// 		str[i++] = malloc(sizeof(char) * 50);
// 	str[9] = NULL;
// 	i = 8;
// 	while (i)
// 	{
// 		read(0, str[i], 50);
// 		i--;
// 	}
// 	i = 0;
// 	while (str[i])
// 	{
// 		printf("case %d = ", i);
// 		printf("%s\n", str[i++]);
// 	}
// 	i = 0;
// 	while (i < 10)
// 		free(str[i++]);
// 	free(str);
// }
