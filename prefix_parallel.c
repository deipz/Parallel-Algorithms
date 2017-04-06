#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int n,A[1001];
int POW(int a,int b)
{
	int value;
	value=(int)pow(a,b);
	return value;
}
void main()
{
	int i,j,tid;
	printf("enter the limit:\n");
	scanf("%d",&n);
	//A=(int*)malloc(n*sizeof(int));
	for(i=0;i<n;i++)
	{
		scanf("%d",&A[i]);
	}
	omp_set_num_threads(n-1);
	#pragma omp parallel
	{
		
			#pragma omp for
			for(j=0;j <= (int)ceil( log(n) / log(2) ) - 1 ;j++)
			{
				
				tid = omp_get_thread_num()+1;
				//printf("%d ",tid);
				if(tid-POW(2,j)>=0)
					A[tid]=A[tid]+A[tid-POW(2,j)];
					//#pragma omp barrier
				
			}
			
	}
	for(i=0;i<n;i++)
		printf("%d ",A[i]);
}