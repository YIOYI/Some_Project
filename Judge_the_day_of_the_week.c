#include <stdio.h>
int GetDays (int year,int month,int day); //计算输入日期到2018.01.01有多少天 
int IsLeapYear (int year); //判断闰年 
int GetMonthDays (int year,int month); //判断当年前几个月有多少天 
int GetYearDays (int year); //判断当年到2018有多少天或2018到前一年多少天 
void Printf (int year,int month,int day); //输出星期几 
int main(void)
{
	int year,month,day;
	
	scanf("%d %d %d",&year,&month,&day);
	Printf (year,month,day);
	
	getchar();
	getchar();
	
	return 0;
} 

int GetDays (int year,int month,int day) //计算输入日期到2018.01.01有多少天 
{
	int i;
	
	if (year>=2018)
		i = GetMonthDays (year,month) + GetYearDays (year) + day -1;
	else if (year<2018)
	    i = GetYearDays (year) - GetMonthDays (year,month) - day;

    return i;
}

int IsLeapYear (int year) //判断闰年 
{
	int i;
	
	if( (year%4==0 && year%100!=0) || year%400==0 )
	    i = 1;
    else
        i = 0;
        
    return i;
}

int GetMonthDays (int year,int month) //判断当年前几个月有多少天 
{
	int i,j;
	int months[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	
	months[1] += IsLeapYear (year); //闰年二月加一天 
	for(j=0,i=0;j<month-1;j++)
	    i += months[j];
	    
	return i;
}

int GetYearDays (int year) //判断当年到2018有多少天或2018到前一年多少天 
{
	int i,j;
	int day = 365;
	
	i = 0;
	if(year>=2018)
	{
		for (j=2018;j<year;j++)
		    i = i + day + IsLeapYear (j); //闰年加一天 
	}
	else
	{
		for (j=2017;j>=year;j--)
		    i = i + day + IsLeapYear (j);
	}
	
	return i; 
}

void Printf (int year,int month,int day) //输出星期几 
{
	int i;
	
	i = GetDays (year,month,day) % 7;
	if (year>=2018) 
	{
		switch(i)
	    {
		case 0:printf("Monday\n"); break;
        case 1:printf("Tuesday\n"); break;
        case 2:printf("Wednesday\n"); break;
        case 3:printf("Thursday\n"); break;
        case 4:printf("Friday\n"); break;
        case 5:printf("Saturday\n"); break;
        case 6:printf("Sunday\n"); break;
	    }
	}
	else if (year<2018)
	{
		switch(i)
	    {
		case 6:printf("Monday\n"); break;
        case 5:printf("Tuesday\n"); break;
        case 4:printf("Wednesday\n"); break;
        case 3:printf("Thursday\n"); break;
        case 2:printf("Friday\n"); break;
        case 1:printf("Saturday\n"); break;
        case 0:printf("Sunday\n"); break;
        }
	}
}
