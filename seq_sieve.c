#include <stdio.h>
#include <stdlib.h>
#include <math.h> 
#define TRUE 1
#define FALSE 0
int main(int argc,char **argv)
{
	int *Num,limit,i,j,prime=0;
	limit=atoi(argv[1]);
	Num=(int*)malloc(limit*sizeof(int));
	Num[0]=Num[1]=FALSE;
	for(i=2;i<limit;i++)
	{
		Num[i]=TRUE;
	}
	for(i=2;i<=sqrt(limit);i++)
	{
		if(Num[i]==TRUE)
		{
			for(j=2;j*i<=limit;j++)
			{
				Num[j*i]=FALSE;
			}
		}	
	}
	for(i=0;i<limit;i++)
	{
		if(Num[i])
			prime++;
	}
	printf("%d",prime);
return 0;
}