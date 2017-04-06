#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int d,i,n,*A,temp;
int POW(int a,int b)
{
	int value;
	value=(int)pow(a,b);
	return value;
}
void main()
{

	printf("Enter No of Elements:\n");
	scanf("%d",&n);
	A=(int*)malloc(n*sizeof(int));
	for(i=0;i<n;i++)
	{
		scanf("%d",&A[i]);
	}
	omp_set_num_threads(100);

	for(d=0; d <= ceil((log(n)/log(2))) - 1; d++)
	{
		#pragma omp parallel for
		for(i=0; i <= n - 1 ; i = i + POW(2,d+1))
		{
			A[POW(2,d+1)+i-1] = A[POW(2,d)+i-1] + A[POW(2,d+1)+i-1];
            #pragma omp barrier
		}
	}

	A[n-1]=0;
	for(d=ceil((log(n)/log(2)))-1; d >= 0; d--)
    {
		#pragma omp parallel for
		for(i = 0; i <= n-1; i = i + POW(2,d + 1))
		{
			temp=A[i+POW(2,d)-1];
			A[i+POW(2,d)-1]=A[i+POW(2,d+1)-1];
			A[i+POW(2,d+1)-1]+=temp;
			#pragma omp barrier
		}
	}
	for(i=0;i<n;i++)
		printf("%d ",A[i]);
}
