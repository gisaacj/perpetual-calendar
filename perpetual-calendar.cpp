#include<stdio.h>
int monthd[13]={1,31,28,31,30,31,30,31,31,30,31,30,31};
int isleap(int year){
	if((year%4==0&&year%100!=0)||year%400==0)
		return 1;
	else
		return 0;
}
int days(int year,int month){
	int i,day=0;
	if(month>2){
		for(i=0;i<month;i++)
		day=day+monthd[i];
		day+=isleap(year);
	}	
	else{
		for(i=0;i<month;i++)
		day=day+monthd[i];
	}	
	while(year>1900){
		day+=(isleap(year-1)+365);
		year--;
	}
	return day;
}
int week(int day){
	int weekday;
	weekday=day%7;
	return weekday;
}
void printmonth(int year,int month){
	int n,i,j;
	int day=days(year,month);
	int weeks=week(day);
	printf("%d月\n",month);
	printf("日  一  二  三  四  五  六  \n");
			for(j=1;j<monthd[month]+1;j++){
				for(n=0;j==1&&n<weeks;n++)
				printf("    ");
				printf("%-4d",j);
				if((weeks+j)%7==0)
				printf("\n");
			}
		printf("\n");
}
int main(){
	int year,i;
	scanf("%d",&year);
	for(i=1;i<13;i++)
	printmonth(year,i);
	return 0;
}
