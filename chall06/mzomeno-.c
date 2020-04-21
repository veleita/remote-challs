int get_line_length(char *board)
{
  int line_length;

  line_length = 0;
  while (*board != '\n')
    {
      if (*board == '\0' ||
	  (*board != '.' && *board != 'K' &&
	   *board != 'B' && *board != 'Q'))
	return (0);
      line_length++;
      board++;
    }
  return (line_length);
}

int ft_check_mate(char *board)
{
  /*
   * Check if board is correct
   */
  /**
   ** One \n at the end of each line
   **/
  /**
   ** One king
   **/
  int line_length;
  int line_number;

  line_length = get_line_length(board);
  if (line_length == 0)
    return (0);
  line_number = 1;
  while (line_number < line_length)
    {
      if (line_length != get_line_length(board + (line_length * line_number)))
	return (0);
      
    }
  /*
   * Check mate
   */
}
