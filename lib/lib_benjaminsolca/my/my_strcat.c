/*
** my_strcat.c for my_lib in /home/benjamin/Dropbox/func/
**
** Made by Benjamin
** Login   <benjamin.solca@epitech.eu>
**
** Started on  Sun Apr  2 20:37:42 2017 Benjamin
** Last update Mon Apr  3 22:13:36 2017 Benjamin
*/

#include <stdlib.h>
#include "bs.h"

char	*my_strcat(char *dest, char *src)
{
  int	i;
  int	j;
  char	*str;

  i = 0;
  j = 0;
  if (!(str = malloc(sizeof(char) * (my_strlen(dest) + my_strlen(src) + 1))))
    return (NULL);
  while (dest[i] != '\0')
    {
     str[i] = dest[i];
     i++;
    }
  while (src[j] != '\0')
    {
      str[i] = src[j];
      i++;
      j++;
    }
  str[i] = '\0';
  return (str);
}
