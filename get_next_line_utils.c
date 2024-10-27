//HEADER

#include "get_next_line.h"

size_t  len(char buf[BUFFER_SIZE +1], size_t i)
{
  size_t  j;

  j = 0;
  while (buf[i + j] != '\0' && buf[i + j] != '\n')
    j++;
  if (buf[i + j] == '\n')
    j++;
  return (j);
}

size_t  len_str(char *str)
{
  size_t  i;

  i = 0;
  while (str != NULL && str[i] != '\0')
    i++;
  return (i);
}

