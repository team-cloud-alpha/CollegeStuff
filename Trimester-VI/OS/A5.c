#include<stdio.h>
#include<pthread.h>
#include<unistd.h>

void* addition(void *arg)
{
	int *x=(int*)arg;
	int res = x[0] + x[1];
    printf("Addition: %d\n", res);
}

void* subtraction(void *arg)
{
	int *x=(int*)arg;
	int res = x[0] - x[1];
    printf("Subtraction: %d\n", res);
}

void* multiplication(void *arg)
{
	int *x=(int*)arg;
	int res = x[0] * x[1];
    printf("Multiplication: %d\n", res);
}

void* division(void *arg)
{
	int *x=(int*)arg;
	float res = (float)x[0] / x[1];
    printf("Division: %f\n", res);
}

int main()
{
    int A[2], B[2];
	printf("Enter 1st number: ");
    scanf("%d", &A[0]);
    printf("Enter 2nd number: ");
    scanf("%d", &A[1]);

    pthread_t t1, t2, t3, t4;
    pthread_create(&t1, NULL, addition, &A);
    pthread_create(&t2, NULL, subtraction, &A);
    pthread_create(&t3, NULL, multiplication, &A);
    pthread_create(&t4, NULL, division, &A);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    pthread_join(t3, NULL);
    pthread_join(t4, NULL);

	return 0;
}

/*
asianintel@DESKTOP-I3513S7:/mnt/c/Users/gauta/OneDrive/Desktop/MITWPU/Trimester-VI/OS$ gcc A5.c -pthread
asianintel@DESKTOP-I3513S7:/mnt/c/Users/gauta/OneDrive/Desktop/MITWPU/Trimester-VI/OS$ ./a.out
Enter 1st number: 12
Enter 2nd number: 4
Addition: 16
Subtraction: 8
Multiplication: 48
Division: 3.000000
*/