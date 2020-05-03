#include<stdio.h>
#include<pthread.h>
#include<unistd.h>

void* addition(void *arg)
{
	int *x=(int*)arg;
	x[0] = x[0] + x[1];
}

int main()
{
    int A[2], B[2];
	printf("Enter 1st number: ");
    scanf("%d", &A[0]);
    printf("Enter 2nd number: ");
    scanf("%d", &A[1]);
    printf("Enter 3rd number: ");
    scanf("%d", &B[0]);
    printf("Enter 4th number: ");
    scanf("%d", &B[1]);

    pthread_t tid,tid1;
    pthread_create(&tid, NULL, addition, &A);
    pthread_join(tid, NULL);

    pthread_create(&tid1, NULL, addition, &B);
    pthread_join(tid1, NULL);

    printf("Outcome: %d\n", A[0] + B[0]);

	return 0;
}