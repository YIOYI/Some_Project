#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#pragma comment(lib,"winmm.lib")
#include "badapple.h"

void HideCursor()
{
	CONSOLE_CURSOR_INFO cursor;    
	cursor.bVisible = FALSE;    
	cursor.dwSize = sizeof(cursor);    
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);    
	SetConsoleCursorInfo(handle, &cursor);
}

int main (void)
{
	int isPlay = 9;
	Viewport buffer[2] = {0};
	int front_index, back_index;
	FILE * fp;
	
	system("mode con cols=150 lines=57");
	HideCursor();
	front_index = 0;
	back_index = 1;
	fp = fopen("badapple.txt", "r");
	while (!feof(fp))
	{
		CleanBuffer(&buffer[back_index]);
		WriteStringToBuffer(&buffer[back_index], fp);
		VierportToSreen(&buffer[back_index], &buffer[front_index]);
		Delay();
		if (isPlay == 1)
		{
			PlaySound("badapple.wav", NULL, SND_FILENAME | SND_ASYNC);
			isPlay = 0;
		}
		{
			int temp = back_index;
			back_index = front_index;
			front_index = temp;
		}
		isPlay --;
	}
	system("cls");
	fclose(fp);
	
	return 0;
}
