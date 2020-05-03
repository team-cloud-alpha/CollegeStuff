#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<stdlib.h>


int n;
int arr[20];
int main()
{
	int pid,status;
	printf("Enter the number of elements into be taken in the array\n");
	scanf("%d",&n);
	int arr[n];
	printf("Enter the elements\n");
	for(int i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	printf("The elements are:\n");
	for(int i=0;i<n;i++)
	{
		printf("%d\t",arr[i]);
	}

	printf("\n");
	pid=fork();
	if(pid==0)                                                
	{
		//child process
		printf("\nEntered Child process with id %d\n",getpid());
		int i,j,temp;
	
		for(i=0;i<n;i++)
		{
			for(j=0;j<n-i-1;j++)
			{
				if(arr[j]>arr[j+1])
				{
					temp=arr[j];
					arr[j]=arr[j+1];
					arr[j+1]=temp;
				}
			}
		}
		printf("\nElements sorted in ascending order: \n");
		for(i=0;i<n;i++)
		{
			printf("%d\t",arr[i]);
		}
		printf("\n");
		exit(100);
	}
	else if(pid>0)
	{
		//parent process

		wait(NULL);
		printf("\nEntered Parent process with id %d\n",getpid());
		int i,j,temp;
	
		for(i=0;i<n;i++)
		{
			for(j=0;j<n-i-1;j++)
			{
				if(arr[j]<arr[j+1])
				{
					temp=arr[j];
					arr[j]=arr[j+1];
					arr[j+1]=temp;
				}
			}
		}
		printf("\nElements sorted in descending order: \n");
		for(i=0;i<n;i++)
		{
			printf("%d\t",arr[i]);
		}
		printf("\n");
	}
	else
	{
		printf("Error in process creation\n");
	}
	return 0;

}