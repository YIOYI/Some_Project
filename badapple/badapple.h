#include <stdio.h>
#include <time.h>
#define COLUMNS 151
#define ROWS 	58

typedef struct {
	char m_buffer[ROWS*COLUMNS+1];
} Viewport;

extern void CleanBuffer (Viewport * buffer);
extern void WriteStringToBuffer (Viewport * buffer, FILE * fp);
extern void VierportToSreen (Viewport * back_buffer, Viewport * front_buffer);
extern void Delay (void);
