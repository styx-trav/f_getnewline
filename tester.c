//HEADER

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

void	print(char *s)
{
	unsigned int	i;

	i = 0;
	if (s == NULL)
		return ;
	while (s[i] != '\0')
	{
		if (write(1, &s[i], 1) == -1)
			return ;
		i++;
	}
	return ;
}

void	print_c(char c)
{
	write(1, &c, 1);
	return ;
}

int main(void)
{
  int i = 1;
  //int fd = 1;
  //int fd = -1;
  //int fd = open("test_notes", O_RDONLY);
  //int fd = open("notes", O_RDONLY);
  char *str = get_next_line(fd);
  while (str != NULL && i < 15)
  {
    print("line ");
    print_c(i + '0');
    print(": ~");
    if (str == NULL)
      print("(null)");
    print(str);
    print("~");
    free(str);
    i++;
    print("\n");
    str = get_next_line(fd);
  }
  //close(fd);
  free(str);
}
