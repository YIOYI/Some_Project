#include <stdio.h>
int getDays (int,int); //�ж�ÿ�����ж����� 
int getdays (int year); //�ж�ÿ���ж����� 
int day_set (int year,int month,int day); //�жϳ���������˶����� 
int day_reset (int year,int month,int day); //�жϽ�����˶����� 
int getday (int year1,int year2); //�жϳ������굽�����м��ж����� 
int main(void)
{
	int year1,month1,day1;
	int year2,month2,day2;
	int day;
	
	scanf("%d %d %d",&year1,&month1,&day1);
	scanf("%d %d %d",&year2,&month2,&day2);
	if (year2>year1)
	    day = day_set (year1,month1,day1) + day_reset (year2,month2,day2) + getday (year1,year2);
    else if (year2 == year1)
        day = day_set (year1,month1,day1) + day_reset (year2,month2,day2) + getday (year1,year2) - getdays (year1);
	
	printf("%d",day);
	
	getchar(); 
	getchar(); 
	
	return 0;
}

int getDays(int x,int y) //�ж�ÿ�����ж����� 
{
    int z;
    
    if ( (x%4==0 && x%100!= 0) || x%400 == 0 )
    {
        if ( y==1 || y==3 || y==5 || y==7 || y==8 || y==10 || y==12 ) 
            z = 31;
        if ( y==4 || y==6 || y==9 || y==11 )
            z = 30;
        if ( y == 2)
            z = 29;
    }
    else
    {
        if ( y==1 || y==3 || y==5 || y==7 || y==8 || y==10 || y==12 ) 
            z = 31;
        if ( y==4 || y==6 || y==9 || y==11 )
            z = 30;
        if ( y == 2)
            z = 28;
    }
    
    return z;
}

int getdays(int year) //�ж�ÿ���ж����� 
{
	int z;
	
	if ( (year%4==0 && year%100!= 0) || year%400 == 0 )
	    z = 366;
	else
	    z = 365;
    
    return z;
}

int day_set (int year,int month,int day) //�жϳ���������˶����� 
{
	int i,j;
	
	j = 0;
	for(i=month;i<=12;i++)
	{
		j += getDays(year,i); //�жϰ��������Ǹ��»��˶����� 
	}
	j = j - day; //��ȥ�����Ǹ���û������� 
	
	return j;
}

int day_reset (int year,int month,int day) //�жϽ�����˶����� 
{
	int i,j;
	
	j = 0;
	for(i=month-1;i>=1;i--) //�жϽ����������»��˶����� 
	{
		j += getDays(year,i);
	}
	j = j + day; //��������»��˶����� 
	
	return j;
}

int getday (int year1,int year2) //�жϳ������굽�����м��ж����� 
{
	int i,j;
	
	j = 0;
	for(i=year1+1;i<=year2-1;i++)
	{
		j += getdays(i);
	}
	
	return j;
}
