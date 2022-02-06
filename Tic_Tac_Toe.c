#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>
#define SIZE 3

void Menu (void);
char GetChar (void);
int GetInt (void);
void Board (int (*chess)[SIZE]);
void Initialization (int (*chess)[SIZE]);
int Win (int (*chess)[SIZE]);
int StartGame (int (*chess)[SIZE], char * ro);
int ContinueGame (int (*chess)[SIZE], int ct, char * ro);

int main (void)
{
	char choice;
	int isContinue = 0;
	int chess[SIZE][SIZE];
	int ct1;
	char ro[2];
	
	printf("Let's play a game of tic-tac-toe!\n");
	Menu();
	while ((choice = getchar()) != 'q')
	{
		int isbreak = 0, isdefault = 0;
		
		while (isspace(choice))
			choice = getchar();
		while (getchar() != '\n')
			continue;
		choice = tolower(choice);
		
		switch (choice) 
		{
		case 's':
			{
				ct1 = StartGame(chess,ro);
				isContinue = 1;
				if (ct1 == 0)
					isContinue = 0;
				break;
			}
		case 'c':
			{
				if (!isContinue)
				{
					printf("Sorry, you need to start the game in advance\n");
					break;
				}
				else
				{
					ct1 = ContinueGame(chess,ct1,ro);
					if (ct1 == 0)
						isContinue = 0;
					break;
				}
			}
		case 'q':
			{
				isbreak = 1;
				break;
			}
		default:
			{
				isdefault = 1; 
				break;
			}
		}
		if (isbreak)
			break;
		if (isdefault)
		{
			printf("Sorry, I understand only"
				" s, c or q.\n");
			printf("Try to enter the operation again: ");
			continue;
		}
		
		Menu();
	}
	printf("Bye!\n");
	
	return 0;
}

void Menu ()
{
	
	printf("**************************************\n");
	printf("Enter the operation of your choice:\n");
	printf("s) Start the game\n");
	printf("c) Continue the game\n");
	printf("q) Quit the game\n");
	printf("**************************************\n");
	
}

char GetChar (void)
{
	char ch;
	
	ch = getchar();
	while (isspace(ch))
		ch = getchar();
	while (getchar() != '\n')
		continue;
	ch = toupper(ch);
	while (ch != 'X' && ch != 'O')
	{
		printf("Sorry, I understand only"
			" X or O.\n");
		printf("Try to enter the role again: ");
		ch = getchar();
		while (isspace(ch))
			ch = getchar();
		while (getchar() != '\n')
			continue;
		ch = toupper(ch);
	}
	
	return ch;
}

int GetInt (void)
{
	int num;
	char ch;
	
	while (scanf("%d", &num) != 1)
	{
		if ((ch = getchar()) == 'q')
		{
			num = -1;
			break;
		}
		putchar(ch);
		while ((ch = getchar()) != '\n')
			putchar(ch);
		printf(" is not an number.\n");
		printf("Please enter a number, such as 1, 2 or 3: ");
	}
	while ((num > 3 || num < 1) && num != -1)
	{
		printf("Please enter a number between 1 and 3: ");
		while (scanf("%d", &num) != 1)
		{
			if ((ch = getchar()) == 'q')
			{
				num = -1;
				break;
			}
			putchar(ch);
			while ((ch = getchar()) != '\n')
				putchar(ch);
			printf(" is not an number.\n");
			printf("Please enter a number, such as 1, 2 or 3: ");
		}
	}
	while (getchar() != '\n')
		continue;
	
	return num;
}

void Initialization (int (*chess)[SIZE])
{
	
	for (int i = 0; i < SIZE; i ++)
		for (int j = 0; j < SIZE; j ++)
			chess[i][j] = -1;
	
}

void Board (int (*chess)[SIZE])
{
	
	printf("     1     2     3   \n\n"); 
	printf("  |*****|*****|*****|\n");
	for (int i = 0; i < SIZE; i ++)
	{
		printf("  |     |     |     |\n");
		printf("%d |", i+1);
		for (int j = 0; j < SIZE; j ++)
		{
			if (chess[i][j] == -1)
				printf("     |");
			else if (chess[i][j] == 0)
				printf("  O  |");
			else 
				printf("  X  |");
		}
		printf("\n");
		printf("  |     |     |     |\n");
		printf("  |*****|*****|*****|\n");
	}
	printf("\n");
	
}

int Win (int (*chess)[SIZE])
{
	int isWin = -1;
	int x_ct = 0, o_ct = 0, a_ct = 0;
	
	for (int i = 0; i < SIZE; i ++)
	{
		x_ct = o_ct = 0;
		for (int j = 0; j < SIZE; j ++)
		{
			if (chess[i][j] == 0)
			{
				o_ct ++;
			}
			else if (chess[i][j] == 1)
			{
				x_ct ++;
			}
		}
		if (x_ct == SIZE)
		{
			isWin = 1;
			break;
		}
		else if (o_ct == SIZE)
		{
			isWin = 0;
			break;
		}
	}
	if (isWin == -1)
	{
		for (int j = 0; j < SIZE; j ++)
		{
			x_ct = o_ct = 0;
			for (int i = 0; i < SIZE; i ++)
			{
				if (chess[i][j] == 0)
				{
					o_ct ++;
				}
				else if (chess[i][j] == 1)
				{
					x_ct ++;
				}
			}
			if (x_ct == SIZE)
			{
				isWin = 1;
				break;
			}
			else if (o_ct == SIZE)
			{
				isWin = 0;
				break;
			}
		}
	}
	if (isWin == -1)
	{
		x_ct = o_ct = 0;
		for (int i = 0; i < SIZE; i ++)
		{
			if (chess[i][SIZE-i-1] == 0)
			{
				o_ct ++;
			}
			else if (chess[i][SIZE-i-1] == 1)
			{
				x_ct ++;
			}
		}
		if (x_ct == SIZE)
		{
			isWin = 1;
		}
		else if (o_ct == SIZE)
		{
			isWin = 0;
		}
	}
	if (isWin == -1)
	{
		x_ct = o_ct = 0;
		for (int i = 0; i < SIZE; i ++)
		{
			if (chess[i][i] == 0)
			{
				o_ct ++;
			}
			else if (chess[i][i] == 1)
			{
				x_ct ++;
			}
		}
		if (x_ct == SIZE)
		{
			isWin = 1;
		}
		else if (o_ct == SIZE)
		{
			isWin = 0;
		}
	}
	if (isWin == -1)
	{
		for (int i = 0; i < SIZE; i ++)
			for (int j = 0; j < SIZE; j ++)
				if (chess[i][j] == -1)
					a_ct ++;
		if (a_ct == 0)
			isWin = 2;
	}
	
	return isWin;
}

int StartGame (int (*chess)[SIZE], char * ro)
{
	int r_num,c_num;
	char f_ro, s_ro;
	int ct = 0, isWin = -1;
	
	Initialization(chess);
	Board(chess);
	
	printf("Enter the first role to play the game( X or O): ");
	f_ro = GetChar();
	s_ro = f_ro=='X'?'O':'X';
	ro[0] = f_ro;
	ro[1] = s_ro;
	do
	{
		ct ++;
		printf("Now it's %c's turn\n", ct%2==1?f_ro:s_ro);
		printf("Enter row number: ");
		r_num = GetInt();
		if (r_num == -1)
			break;
		printf("Enter column number: ");
		c_num = GetInt();
		if (c_num == -1)
			break;
		
		if (chess[r_num-1][c_num-1] != -1)
		{
			printf("There are already chess in this area\n");
			printf("Please enter again\n");
			ct --;
			continue;
		}
		if (ct%2)
		{
			if (f_ro == 'X')
				chess[r_num-1][c_num-1] = 1;
			else
				chess[r_num-1][c_num-1] = 0;
		}
		else
		{
			if (s_ro == 'X')
				chess[r_num-1][c_num-1] = 1;
			else
				chess[r_num-1][c_num-1] = 0;
		}
		Board(chess);
		isWin = Win(chess);
	} while(isWin == -1);
	if (isWin != -1)
	{
		if (isWin == 1)
			printf("X win !\n");
		else if (isWin == 0)
			printf("O win !\n");
		else
			printf("No one win !\n");
		Initialization(chess);
		ct = 0;
	}
	
	return ct;
}

int ContinueGame (int (*chess)[SIZE], int ct, char * ro)
{
	int r_num,c_num;
	char f_ro, s_ro;
	int isWin = -1;
	
	Board(chess);
	
	f_ro = ro[0];
	s_ro = ro[1];
	ct --;
	do
	{
		ct ++;
		printf("Now it's %c's turn\n", ct%2==1?f_ro:s_ro);
		printf("Enter row number: ");
		r_num = GetInt();
		if (r_num == -1)
			break;
		printf("Enter column number: ");
		c_num = GetInt();
		if (c_num == -1)
			break;
		
		if (chess[r_num-1][c_num-1] != -1)
		{
			printf("There are already chess in this area\n");
			printf("Please enter again\n");
			ct --;
			continue;
		}
		if (ct%2)
		{
			if (f_ro == 'X')
				chess[r_num-1][c_num-1] = 1;
			else
				chess[r_num-1][c_num-1] = 0;
		}
		else
		{
			if (s_ro == 'X')
				chess[r_num-1][c_num-1] = 1;
			else
				chess[r_num-1][c_num-1] = 0;
		}
		Board(chess);
		isWin = Win(chess);
	} while(isWin == -1);
	if (isWin != -1)
	{
		if (isWin == 1)
			printf("X win !\n");
		else if (isWin == 0)
			printf("O win !\n");
		else
			printf("No one win !\n");
		Initialization(chess);
		ct = 0;
	}
	
	return ct;
}
