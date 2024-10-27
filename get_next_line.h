//HEADER

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H "get_next_line.h"

# include <stdlib.h>
# include <unistd.h>

//main function here
char  *get_next_line(int fd);
//from utils, secondary functions;
size_t  len(char buf[BUFFER_SIZE +1], size_t i);
size_t  len_str(char *str);
#endif
