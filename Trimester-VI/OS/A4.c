#include<stdio.h>

int P = 5;
int R = 3;

void calculateNeed(int need[P][R], int maxm[P][R], int allot[P][R])
{
    int i,j;
    for (i = 0 ; i < P ; i++)
        for (j = 0 ; j < R ; j++)
            need[i][j] = maxm[i][j] - allot[i][j];
}

int isSafe(int processes[P], int avail[R], int maxm[P][R], int allot[P][R])
{
    int i,j,k,p;
    int need[P][R];
    calculateNeed(need, maxm, allot);

    printf("\n\nPROCESSES\t\t\t\tALLOCATION MATRIX\t\t\tMAXIMUM MATRIX\n");
    for(int i=0;i<P;i++)
    {

      printf("%d\t\t\t",processes[i]);

      printf("\t");
      for(int j=0;j<R;j++)
      {
        printf("%d\t",allot[i][j]);
      }
      printf("\t");
      for(int j=0;j<R;j++)
      {
        printf("%d\t\t",maxm[i][j]);
      }
      printf("\n");
    }
    printf("\nAVAILABLE:\n");
    for(int i=0;i<R;i++)
    {
      printf("%d\t",avail[i]);
    }
    printf("\n");

    int finish[P];
    for(int i=0;i<P;i++)
      finish[i]=0;

    int safeSeq[P];
    int work[R];
    for (i = 0; i < R ; i++)
        work[i] = avail[i];

    int count = 0;
    while (count < P)
    {
        int found = 0;
        for (p = 0; p < P; p++)
        {
            if (finish[p] == 0)
            {
                for (j = 0; j < R; j++)
                    if (need[p][j] > work[j])
                        break;

                if (j == R)
                {
                    for (k = 0 ; k < R ; k++)
                        work[k] += allot[p][k];

                    safeSeq[count++] = p;
                    finish[p] = 1;

                    found = 1;
                }
            }
        }

        if (found == 0)
        {
            printf("\n\n\nSystem is not in safe state\n");
            return 0;
        }
    }

    printf("\n\nNEED MATRIX:\n");

    for(int i=0;i<P;i++)
    {
      for(int j=0;j<R;j++)
      {
        printf("%d\t",need[i][j]);
      }
      printf("\n");
    }

    printf("\n\n\nSystem is in safe state. \nSafe sequence is: ");
    for (i = 0; i < P ; i++)
        printf("%d\t",processes[safeSeq[i]]) ;
    printf("\n");
    return 1; 
}

int main()
{
    printf("Enter number of processes:");
    scanf("%d",&P);

    int processes[P];

    for(int i=0;i<P;i++)
    {
      printf("Enter process id:");
      scanf("%d",&processes[i]);
    }

    printf("Enter number of resources:");
    scanf("%d",&R);

    int avail[R];
    for(int i=0;i<R;i++)
    {
      printf("Enter available amount of R%d:",i);
      scanf("%d",&avail[i]);
    }

    int maxm[P][R];

    for(int i=0;i<P;i++)
    {
      for(int j=0;j<R;j++)
      {
        printf("Enter maximum of R%d, for P%d:",j,processes[i]);
        scanf("%d",&maxm[i][j]);
      }
    }

    int allot[P][R];
    for(int i=0;i<P;i++)
    {
      for(int j=0;j<R;j++)
      {
        printf("Enter allocation of R%d, for P%d:",j,processes[i]);
        scanf("%d",&allot[i][j]);
      }
    }

    isSafe(processes, avail, maxm, allot);
    return 0;
}