//HEADER

#include "get_next_line.h"

size_t  new_i(char buf[BUFFER_SIZE +1], size_t i)
{
  if (buf == NULL)
    return (0);
  while (buf[i] != '\0' && buf[i] != '\n')
    i++;
  if (buf[i] == '\n')
    i++;
  if (i == BUFFER_SIZE)
    return (0);
  return (i);
}

char  *join(char *str, char *s, char buf[BUFFER_SIZE +1], size_t i)
{
  size_t  j;
  size_t  k;

  j = 0;
  k = 0;
  while (s && s[j])
  {
    str[j] = s[j];
    j++;
  }
  while (buf[i + k] != '\0' && buf[i + k] != '\n')
  {
    str[j + k] = buf[i + k];
    k++;
  }
  str[j + k] = buf[i + k];
  if (str[j + k] == '\n')
    str[j + k + 1] = '\0';
  return (str);
}

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

size_t add_to_str(char **s, char buf[BUFFER_SIZE +1], size_t i)
{
  char  *str;

  str = malloc((len_str(*s) + len(buf, i) + 1) * sizeof(char));
  if (str)
    str = join(str, *s, buf, i);
  if (*s != NULL)
    free(*s);
  *s = str;
  if (str == NULL || i + len(buf, i) != BUFFER_SIZE
        || (len_str(str) > 0 && str[len_str(str) - 1] ==  '\n'))
    return (1);
  return (0);
}

char  *get_next_line(int fd)
{
  static size_t i;
  static char buf[BUFFER_SIZE +1];
  char  *str;
  ssize_t done;

  str = NULL;
  if (i && i != 0)
  {
    done = add_to_str(&str, buf, i);
    i = new_i(buf, i);
    if (done)
      return (str);
  }
  done = 0;
  while (done < BUFFER_SIZE +1)
    buf[done++] = '\0';
  done = read(fd, buf, BUFFER_SIZE);
  while (done > 0)
  {
    write(1, "here\n", 6);
    done = add_to_str(&str, buf, 0);
    i = new_i(buf, 0);
    if (done)
      return (str);
    done = 0;
    while (done < BUFFER_SIZE +1)
      buf[done++] = '\0';
    done = read(fd, buf, BUFFER_SIZE);
    if (done == 0)
      i = 0;
  }
  return (str);
}
