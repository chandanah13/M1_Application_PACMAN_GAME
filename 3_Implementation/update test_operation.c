#include "unity.h"
#include "operation.h"

void test_display_board(void);
void test_input(void);
void test_winner(void);

/* Required by the unity test framework */
void setUp(){}
/* Required by the unity test framework */
void tearDown(){}


int main()
{
/* Initiate the Unity Test Framework */
  UNITY_BEGIN();

/* Run Test functions */
  RUN_TEST(test_display_board);
  RUN_TEST( test_input );
  RUN_TEST( test_winner);

  /* Close the Unity Test Framework */
  return UNITY_END();
}


void test_display_board(void)
{
	int i = 0; 
	int j = 0; 

	for (i = 0; i < 3; i++) 
	{
		printf(" \n ");
		for (j = 0; j < 3; j++) 
		{
			printf(" %c ", board[i][j]); 
		}
	}
	printf(" \n "); 
	return 0;
}




void test_input(void) 
{
	int row_or_column = 0; 
	char* string_to_print[7]; 
	if (number == 0) 
	{
		*string_to_print = "row";
	} else if (number == 1) 
	{
		*string_to_print = "column";
	} else {
		printf("\n This is not supposed to hapen. \n"); 
	}
	int valid = 0; 
	while (valid == 0)
	{
		printf("\n Choose a %s> ", *string_to_print); 
		scanf("%d", &row_or_column);  
		if (1 <= row_or_column && row_or_column <= 3)
		{
			printf("\n You have chosen %s #%d. \n", *string_to_print, row_or_column);
			valid = 1;

		} else {
			printf("\n %s = %d \n", *string_to_print, row_or_column); 
			printf("\n Invalid %s chosen, please try again. \n (The %s number must be either 1, 2, or 3.) \n", *string_to_print, *string_to_print);

		}
	}
	return row_or_column;
}




void test_winner(void) 
{
	int winner_number = 0;
	int blank = 0;
	int i = 0; 
	int j = 0; 
	if (((board[0][0] == 'X') && (board[0][1] == 'X') && (board[0][2] == 'X')) || // first row
		((board[0][0] == 'X') && (board[1][0] == 'X') && (board[2][0] == 'X')) || // first column
		((board[0][0] == 'X') && (board[1][1] == 'X') && (board[2][2] == 'X')) || // diagonal 1
		((board[1][0] == 'X') && (board[1][1] == 'X') && (board[1][2] == 'X')) || // second row
		((board[2][0] == 'X') && (board[2][1] == 'X') && (board[2][2] == 'X')) || // third row
		((board[0][1] == 'X') && (board[1][1] == 'X') && (board[2][1] == 'X')) || // second column
		((board[0][2] == 'X') && (board[1][2] == 'X') && (board[2][2] == 'X')) || // third column
		((board[0][2] == 'X') && (board[1][1] == 'X') && (board[2][0] == 'X')) // diagonal 2
		)
	{
		winner_number = 1;
	} else if (((board[0][0] == 'O') && (board[0][1] == 'O') && (board[0][2] == 'O')) || // first row
			   ((board[0][0] == 'O') && (board[1][0] == 'O') && (board[2][0] == 'O')) || // first column
			   ((board[0][0] == 'O') && (board[1][1] == 'O') && (board[2][2] == 'O')) || // diagonal 1
			   ((board[1][0] == 'O') && (board[1][1] == 'O') && (board[1][2] == 'O')) || // second row
			   ((board[2][0] == 'O') && (board[2][1] == 'O') && (board[2][2] == 'O')) || // third row
			   ((board[0][1] == 'O') && (board[1][1] == 'O') && (board[2][1] == 'O')) || // second column
			   ((board[0][2] == 'O') && (board[1][2] == 'O') && (board[2][2] == 'O')) || // third column
			   ((board[0][2] == 'O') && (board[1][1] == 'O') && (board[2][0] == 'O')) // diagonal 2
			   )
	{
		winner_number = 2;
	} else {
		for (i = 0; i < 3; i++) 
		{
			for (j = 0; j < 3; j++) 
			{
				if (board[i][j] == '_') {
					blank = 1; 
				}
			}
		}
		if (blank == 0) { 
			winner_number = 3;
		}
	}

	return winner_number;
}



