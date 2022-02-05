#include <stdio.h>
#include <ctype.h>

void menu (void);
float get_float (void);
void add (void);
void sub (void);
void mul (void);
void div (void);

int main (void)
{
	char ch;
	
	menu();
	while ((ch = getchar()) != 'q')
	{
		while (isspace(ch))
			ch = getchar();
		while (getchar() != '\n')
			continue;
		ch = tolower(ch);
		
		switch (ch)
		{
		case 'a': add(); break;
		case 's': sub(); break;
		case 'm': mul(); break;
		case 'd': div(); break;
		default: printf("Sorry, I understand only"
					" a, s, m, d or q.\n"); break;
		}
		
		menu();
	}
	printf("Bye.\n");
	
	return 0;
}

void menu (void)
{
	
	printf("Enter the operation of your choice:\n"
			"a. add           s. subtract\n"
			"m. multiply      d. divide\n"
			"q. quit\n");
	
}

float get_float (void)
{
	float num;
	char ch;
	
	while (scanf("%f", &num) != 1)
	{
		while ((ch = getchar()) != '\n')
			putchar(ch);
		printf(" is not an number.\n");
		printf("Please enter a number, such as 2.5, -1.78E8, or 3: ");
	}
	while (getchar() != '\n')
		continue;
	
	return num;
}

void add (void)
{
	float fir, sec;
	
	printf("Enter first number: ");
	fir = get_float();
	printf("Enter second number: ");
	sec = get_float();
	printf("%g + %g = %g\n", fir, sec, fir+sec);
	
}

void sub (void)
{
	float fir, sec;
	
	printf("Enter first number: ");
	fir = get_float();
	printf("Enter second number: ");
	sec = get_float();
	printf("%g - %g = %g\n", fir, sec, fir-sec);
	
}

void mul (void)
{
	float fir, sec;
	
	printf("Enter first number: ");
	fir = get_float();
	printf("Enter second number: ");
	sec = get_float();
	printf("%g * %g = %g\n", fir, sec, fir*sec);
	
}

void div (void)
{
	float fir, sec;
	
	printf("Enter first number: ");
	fir = get_float();
	printf("Enter second number: ");
	sec = get_float();
	while (sec == 0)
	{
		printf("Enter a number other than 0: ");
		sec = get_float();
	}
	printf("%g / %g = %g\n", fir, sec, fir/sec);
	
}
