//HEADER

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int main(void)
{
  int i = 1;
  char a;
  int fd = open("notes", O_RDONLY);
  char *str = get_next_line(fd);
  while (i < 14)
  {
    //printf("line %d: %s", i, str);
    a = i + 48;
    write(1, &a, 1);
    write(1, "\n", 1);
    free(str);
    i++;
    str = get_next_line(fd);
  }
  free(str);
}
