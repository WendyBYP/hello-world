#include<stdio.h>
#include<stdlib.h>
int Day(int a,int b,int c)
{
	int i,j,k; 
    int r=0;//����1900��������������
    int m[]={31,28,31,30,31,30,31,31,30,31,30,31};//m��ÿ���µ�����
    if(a>=1601&&b>0&&b<13&&c>0&&c<32)
    {
		for(i=1601;i<=a;i++)//��������ĸ���
		{    
			if(i%400==0||i%100!=0&&i%4==0)
			r=r+1;
		}
		for(j=0;j<b-1;j++)//ͳ�Ƶ���1��1�յ����µ�����,ǰ(b-1)������ 
		{
			c+=m[j];
		}
		if(a%400==0||a%100!=0&&a%4==0&&b<3)//������������굫�������¾Ͳ������ȥ
			r--;
		return 365*(a-1601)+r+c;
	}
	else
		return -1;
}
int main(void)
{
	int month,day,year;
	printf("Enter date(mm/dd/yy):");
	scanf("%d/%d/%d",&month,&day,&year);
	printf("Dated this %d",day);
	switch(day)
	{
		case 1:case 21:case 31:
		printf("st");break;
		case 2:case 22:
		printf("nd");break;
		case 3:case 23:
		printf("rd");break;
		default:printf("th");break;
	}
	printf(" day of ");
	switch(month)
	{
		case 1:printf("January");break;
		case 2:printf("February");break;
		case 3:printf("March");break;
		case 4:printf("April");break;
		case 5:printf("May");break;
		case 6:printf("June");break;
		case 7:printf("July");break;
		case 8:printf("August");break;
		case 9:printf("September");break;
		case 10:printf("October");break;
		case 11:printf("November");break;
		case 12:printf("December");break;
	}
	printf(", %.2d ,",year);
	int days;
  	days=Day(year,month,day);
  	switch(days%7)  
  	{  
   	case 1: printf("Monday\n");  break;  
   	case 2: printf("Tuesday\n");  break;  
   	case 3: printf("Wednesday\n");  break;  
   	case 4: printf("Thursday\n");  break;  
   	case 5: printf("Friday\n");  break;  
   	case 6: printf("Saturday\n");  break;    
   	case 0: printf("Sunday\n");  break;  
    }
	return 0;
} 
