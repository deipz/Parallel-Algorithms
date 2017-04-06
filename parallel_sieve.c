#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define TRUE 1
#define FALSE 0
#define MAX 1000000
int Num[MAX+1],start=1,limit;
void sieve()
{
	int temp,i;
	#pragma omp critical
			{temp=start+=2;}
		if(temp<=sqrt(limit))
		{
		if(Num[temp])
		{
			
			for (i=temp;i*temp<=limit;i+=2)
				Num[i*temp] = FALSE;
				
			}
}
}
int main(int argc,char **argv)
{
	int i,num_primes=0;
	limit=atoi(argv[1]);
	//Num=(int*)malloc((limit+1)*sizeof(int));
	Num[0]=Num[1]=FALSE;
	Num[2]=TRUE;
	for(i=3;i<=limit;i++)
		{
			if(i%2==0)
				Num[i]=FALSE;
				else
					Num[i]=TRUE;
		}
		omp_set_num_threads(500);
		
	#pragma omp parallel
	{
		sieve();
	//		printf("%d\n",omp_get_num_threads());
	}
		
		
	
	for(i=2;i<=limit;i++)
	{
		if(Num[i]==TRUE)
			num_primes++;
	}
	printf("NUMBER OF PRIMES %d",num_primes);
	return 0;
}