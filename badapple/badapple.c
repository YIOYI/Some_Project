#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <string.h>
#include "badapple.h"

void CleanBuffer (Viewport * buffer)
{
	memset(buffer, 0, sizeof(*buffer));
}

void WriteStringToBuffer(Viewport * buffer, FILE * fp)
{
	char string[COLUMNS];
	int x, y, index;
	
	for (y = 0; y < ROWS; y ++)
	{
		for (x = 0; x < COLUMNS; x ++)
		{
			index = x + y * COLUMNS;
			buffer->m_buffer[index] = fgetc(fp);
		}
	}
	buffer->m_buffer[index+1] = '\0';
	fgets(string, COLUMNS, fp);
	fgets(string, COLUMNS, fp);
}

static void gotoxy(int x, int y) 
{
	COORD pos = {x,y};
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hOut, pos);
}

void VierportToSreen (Viewport * back_buffer, Viewport * front_buffer)
{
	for (int y = 0; y < ROWS; y ++)
	{
		for (int x = 0; x < COLUMNS; x ++)
		{
			int index = x + y * COLUMNS;
			char ch1 = back_buffer->m_buffer[index];
			char ch2 = front_buffer->m_buffer[index];
			if (ch1 != ch2)
			{
				gotoxy(x, y);
				printf("%c", ch1);
			}
		}
	}
}

void Delay (void)
{
	static clock_t endClock = 0;
	
	endClock += 125 * CLOCKS_PER_SEC / 1000;
	if (clock() > endClock)
		endClock = clock();
	else
		while (clock() < endClock)
			Sleep(1);
}
