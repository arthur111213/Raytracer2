/*
** what_to_do.c for rt2 in /home/benjamin/Dropbox/raytracer2/parse/
**
** Made by Benjamin
** Login   <benjamin.solca@epitech.eu>
**
** Started on  Mon Apr 17 13:01:12 2017 Benjamin
** Last update Sat May 20 16:43:44 2017 Julien Delane
*/

#include <stdlib.h>
#include "parse.h"
#include "bs.h"

static void	is_parse_opt(t_parse *parse, char *str)
{
  if (!(my_strncmp(str, "##MATERIAUX", 11)))
    parse->opt = 1;
  if (!(my_strncmp(str, "##LIGHT", 7)))
    parse->opt = 2;
  if (!(my_strncmp(str, "##OBJETS", 8)))
    parse->opt = 3;
}

static int	create_new_object(char **tab, t_parse *parse, t_scene *scene)
{
  if (cnt_line_tab(tab) > 1)
    {
      if (parse->opt == 1)
	return (create_mat(tab[1], &scene->mat));
      if (parse->opt == 2)
	return (create_light(tab[1], &scene->light));
      if (parse->opt == 3)
	return (create_obj(tab[1], &scene->obj));
    }
  else
    {
      my_put_error("Please choose a name. (ex: > NAME)");
      return (-1);
    }
  return (0);
}

int		parse_what_to_do(char **tab, t_parse *parse, t_scene *scene)
{
  int		ret;
  static char	*name = "\0";

  ret = 0;
  if (my_strlen(tab[0]) > 1 && !(my_strncmp(tab[0], "##", 2)))
    is_parse_opt(parse, tab[0]);
  else if (tab[0][0] ==  '>')
    {
      if (name[0] != '\0')
	free(name);
      if (cnt_line_tab(tab) > 1)
	name = my_strdup(tab[1]);
      ret = create_new_object(tab, parse, scene);
    }
  else if (name[0] != '\0')
    {
      if (parse->opt == 1)
      	return (set_mat(tab, name, scene->mat));
      if (parse->opt == 2)
      	return (set_light(tab, name, scene->light));
      if (parse->opt == 3)
      	return (set_obj(tab, name, scene->obj));
    }
  return (ret);
}
