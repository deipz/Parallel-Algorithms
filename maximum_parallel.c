#include<stdio.h>
#include<stdlib.h>
#define TRUE 1
#define FALSE 0
void main()
{
	int n,*A,*m,i,j,max;
	printf("enter the limit:\n");
	scanf("%d",&n);
	A=(int*)malloc(n*sizeof(int));
	m=(int*)malloc(n*sizeof(int));
	for(i=0;i<n;i++)
	{
		scanf("%d",&A[i]);
	}
	#pragma omp parallel
	{
		#pragma omp for
		for(i-0;i<n;i++)
		{
			m[i]=TRUE;
		}
		#pragma omp for
		for(i=0;i<n;i++)
		{
			#pragma omp for
			for(j=0;j<n;j++)
			{
				if(A[i]<A[j])
					m[i]=FALSE;
					else m[i]=TRUE;
			}
		}
		#pragma omp for
		for(i=0;i<n;i++)
		{
			if(m[i]==TRUE)
				max=A[i];
		}
		printf("maximum is : %d",max);
	}
}