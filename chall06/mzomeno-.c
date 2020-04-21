static int get_line_length(char *board)
{
  int line_length;

  line_length = 0;
  while (*board != '\n' && *board != '\0')
    {
      if (*board != '.' && *board != 'K' &&
	  *board != 'P' && *board != 'R' &&
	  *board != 'B' && *board != 'Q')
	return (0);
      line_length++;
      board++;
    }
  return (line_length);
}

static int check_board(char *board, int line_length)
{
  int line_number;

  if (line_length == 0 || line_length > 9)
    return (0);
  line_number = 1;
  while (*board != '\0')
    {
      if (line_length != get_line_length(board + (line_length * (line_number + 1))))
	return (1);
      line_number++;
      board++;
    }
  if (line_number != line_length)
    return (0);
  return (line_number);
}

static int check_king(char *board)
{
  int iterator;
  int king_position;

  king_position = -1;
  iterator = 0;
  while (board[iterator] != '\0')
    {
      if (board[iterator] == 'K')
	{
	  if (king_position == -1)
	    king_position = iterator;
	  else
	    return (-1);
	}
      iterator++;
    }
  return (king_position);
  /*
   * Note that the function will return -1 if there is no king,
   * as the king_position variable’s initial value remains untouched
   */
}

static int pawn_capture(int line_length, int position, int king_position)
{
  if (king_position == (position - line_length - 2) ||
      king_position == (position - line_length + 2) ||
      king_position == (position + line_length - 2) ||
      king_position == (position + line_length + 2))
    return (1);
  else
    return (0);
}

static int bishop_capture(int line_length, int line_number, int position, int king_position)
{
  int n;

  n = 1;
  while (n < (line_number - (position - line_length)))
    {
      if (king_position == (position + n * (line_length + 1) + n) ||
	  king_position == (position + n * (line_length + 1) - n))
	return (1);
      n++;
    }
  n = 1;
  while (n < (position / line_length))
    {
      if (king_position == (position - n * (line_length + 1) + n) ||
	  king_position == (position - n * (line_length + 1) - n))
	return (1);
      n++;
    }
  return (0);
}

static int rook_capture(int line_length, int line_number,
			int position, int king_position)
{
  int n;

  n = 1;
  while (n < (line_number - (position - line_length)))
    {
      if (king_position == (position + n * (line_length + 1)) ||
	  king_position == (position + n * (line_length + 1)))
	return (1);
      n++;
    }
  n = 1;
  while (n < (position / line_length))
    {
      if (king_position == (position - n * (line_length + 1)) ||
	  king_position == (position - n * (line_length + 1)))
	return (1);
      n++;
    }
  return (0);
}

int ft_check_mate(char *board)
{
  int line_length;
  int line_number;
  int king_position;
  int position;
  /*
   * Check if board is correct
   */
  /**
   ** No input
   **/
  if (board == 0)
    return (1);
  /**
   ** - Even square
   ** - Not larger than 9x9
   ** - No invalid pieces
   ** - One \n at the end of each line
   **/
  line_length = get_line_length(board);
  line_number = check_board(board, line_length);
  if (line_number == 0)
    return (1);
  /**
   ** - One king
   ** - Record king position
   **/
  king_position = check_king(board);
  if (king_position == -1)
    return (1);
  /*
   * Check mate
   */
  position = 0;
  while (board[position] != '\0')
    {
      if (board[position] == 'P' &&
	  pawn_capture(line_length, position, king_position) == 1)
	return (0);
      if (board[position] == 'B' &&
	  bishop_capture(line_length, line_number, position, king_position) == 1)
	return (0);
      if (board[position] == 'R' &&
	  rook_capture(line_length, line_number, position, king_position) == 1)
	return (0);
      if (board[position] == 'Q' &&
	  (bishop_capture(line_length, line_number, position, king_position) == 1 ||
	   rook_capture(line_length, line_number, position, king_position) == 1))
	return (0);
      position++;
    }
  return (1);
}
