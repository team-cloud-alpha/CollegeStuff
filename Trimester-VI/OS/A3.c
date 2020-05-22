#include<stdio.h>
#include<math.h>
#include<limits.h>
typedef struct
{
  int arrival_time;
  int burst_time;
  int waiting_time;
  int turnaround_time;
}Process;

void swap(Process *xp, Process *yp)
{
    Process temp = *xp;
    *xp = *yp;
    *yp = temp;
}
void ascending(Process a[20],int n)
{
  for (int i = 0; i < n-1; i++)
     for (int j = 0; j < n-i-1; j++)
         if (a[j].arrival_time > a[j+1].arrival_time)
            swap(&a[j], &a[j+1]);
}
void fcfs()
{
  Process p[10];
  int n;
  printf("Enter number of processes:");
  scanf("%d",&n);

  for(int i=0;i<n;i++)
  {
    printf("Arrival time of p[%d]:",i);
    scanf("%d",&p[i].arrival_time);
    printf("Burst time of p[%d]:",i);
    scanf("%d",&p[i].burst_time);
  }
  ascending(p,n);

  p[0].waiting_time=0;int delay=0;
  //printf("Waiting time for p[%d]:%d\n",i,p[i].waiting_time);
  //p[0].turnaround_time=p[0].burst_time+p[0].waiting_time;

  for(int i=1;i<n;i++)
  {

    p[i].waiting_time=0;

    for(int j=0;j<i;j++)
    {
      p[i].waiting_time+=p[j].burst_time;
    }
    p[i-1].turnaround_time=p[i-1].burst_time+p[i-1].waiting_time;

    if(p[i].arrival_time<=p[i-1].turnaround_time+p[i-1].arrival_time)
      p[i].waiting_time-=p[i].arrival_time-p[0].arrival_time-delay;
    else
      {p[i].waiting_time=0;delay++;}
  }
  p[n-1].turnaround_time=p[n-1].burst_time+p[n-1].waiting_time;

  printf("\nProcess\tArrival Time\tBurst Time\tWaiting Time\tTurn-Around Time\n");
  printf("--------------------------------------------------------------------\n");

  double sum_wt=0,sum_tt=0;
  for(int i=0;i<n;i++)//display tabular loop
  {

    printf("\nP[%d]\t%d\t\t%d\t\t%d\t\t%d",i,p[i].arrival_time,p[i].burst_time,p[i].waiting_time,p[i].turnaround_time);
    sum_wt+=p[i].waiting_time;
    sum_tt+=p[i].turnaround_time;
  }
  float avg_wt=sum_wt/n;
  float avg_tt=sum_tt/n;

  printf("\n-------------------------------------------------------------\n");
  printf("Average Waiting Time=%f\n",avg_wt);
  printf("Average TurnAround Time=%f\n",avg_tt);

  for(int i=0;i<n;i++)
  {
    if(i>0 && p[i-1].turnaround_time+p[i-1].arrival_time<=p[i].arrival_time)
    {
      printf("----idle----");
    }

    printf("|---P[%d]----",i);
    for(int j=0;j<i;j++)
      printf("-");
    printf("|");
  }
  printf("|\n");
  int sum=p[0].arrival_time;
  for(int i=0;i<=n;i++)
  {
    if(i>0 && i<n && p[i-1].turnaround_time+p[i-1].arrival_time<=p[i].arrival_time)
    {
      printf("%d             ",sum);
      sum=p[i].arrival_time;
    }

    printf("%d             ",sum);
    //for(int j=0;j<i;j++)
      //printf(" ");
    sum+=p[i].burst_time;
  }
  printf("\n");
}
void sjf()
{
  Process p[10];
  int n;
  printf("Enter number of processes:");
  scanf("%d",&n);

  for(int i=0;i<n;i++)
  {
    printf("Arrival time of p[%d]:",i);
    scanf("%d",&p[i].arrival_time);
    printf("Burst time of p[%d]:",i);
    scanf("%d",&p[i].burst_time);
  }

//same as FCFS till here

  //printf("Waiting time for p[%d]:%d\n",i,p[i].waiting_time);

int remaining_time[n];

  for(int i=0;i<n;i++)
    remaining_time[i]=p[i].burst_time;

  int complete = 0, t = 0, minm = INT_MAX;
      int shortest = 0, finish_time;
      int check = 0;

      while (complete != n)
      {
          for (int j = 0; j < n; j++) {
              if ((p[j].arrival_time <= t) && (remaining_time[j] < minm) && remaining_time[j] > 0) {
                  minm = remaining_time[j];
                  shortest = j;
                  check = 1;
                  //
              }
          }



          if (check == 0) {
              t++;
              printf("--idle--\t");
              continue;
          }
          else
            printf("P[%d]\t",shortest);

          remaining_time[shortest]--;
          minm = remaining_time[shortest];
          if (minm == 0)
              minm = INT_MAX;

          if (remaining_time[shortest] == 0)
          {
              complete++;
              check = 0;
              finish_time = t + 1;
              p[shortest].waiting_time = finish_time - p[shortest].burst_time - p[shortest].arrival_time;

              if (p[shortest].waiting_time < 0)
                  p[shortest].waiting_time = 0;

          }
          t++;
        }

  printf("\nProcess\tArrival Time\tBurst Time\tWaiting Time\tTurn-Around Time\n");
  printf("--------------------------------------------------------------------\n");

  float sum_wt=0,sum_tt=0;
  for(int i=0;i<n;i++)//display tabular loop
  {
    p[i].turnaround_time=p[i].burst_time+p[i].waiting_time;
    printf("\nP[%d]\t%d\t\t%d\t\t%d\t\t%d",i,p[i].arrival_time,p[i].burst_time,p[i].waiting_time,p[i].turnaround_time);
    sum_wt+=p[i].waiting_time;
    sum_tt+=p[i].turnaround_time;
  }
  float avg_wt=sum_wt/n;
  float avg_tt=sum_tt/n;

  printf("\n-------------------------------------------------------------\n");
  printf("Average Waiting Time=%f\n",avg_wt);
  printf("Average TurnAround Time=%f\n",avg_tt);


  printf("\n");
}

int main()
{
  printf("1. First Come First Serve\t2.Shortest Job First\n");
  int c;
  scanf("%d",&c);

  switch(c)
  {
    case 1: {fcfs();
            break;}

    case 2: {sjf();
            break;}
  }

  return 0;
}

/*
asianintel@DESKTOP-I3513S7:/mnt/c/Users/gauta/OneDrive/Desktop/MITWPU/Trimester-VI/OS$ ./a.out
1. First Come First Serve       2.Shortest Job First
1
Enter number of processes:5
Arrival time of p[0]:0
Burst time of p[0]:3
Arrival time of p[1]:1
Burst time of p[1]:1
Arrival time of p[2]:2
Burst time of p[2]:2
Arrival time of p[3]:7
Burst time of p[3]:4
Arrival time of p[4]:8
Burst time of p[4]:2

Process Arrival Time    Burst Time      Waiting Time    Turn-Around Time
--------------------------------------------------------------------

P[0]    0               3               0               3
P[1]    1               1               2               3
P[2]    2               2               2               4
P[3]    7               4               0               4
P[4]    8               2               3               5
-------------------------------------------------------------
Average Waiting Time=1.400000
Average TurnAround Time=3.800000
|---P[0]----||---P[1]-----||---P[2]------|----idle----|---P[3]-------||---P[4]--------||
0             3             4             6             7             11             13
asianintel@DESKTOP-I3513S7:/mnt/c/Users/gauta/OneDrive/Desktop/MITWPU/Trimester-VI/OS$ ./a.out
1. First Come First Serve       2.Shortest Job First
2
Enter number of processes:5
Arrival time of p[0]:0
Burst time of p[0]:3
Arrival time of p[1]:1
Burst time of p[1]:1
Arrival time of p[2]:2
Burst time of p[2]:2
Arrival time of p[3]:7
Burst time of p[3]:4
Arrival time of p[4]:8
Burst time of p[4]:2
P[0]    P[1]    P[0]    P[0]    P[2]    P[2]    --idle--        P[3]    P[4]    P[4]    P[3]    P[3]    P[3]
Process Arrival Time    Burst Time      Waiting Time    Turn-Around Time
--------------------------------------------------------------------

P[0]    0               3               1               4
P[1]    1               1               0               1
P[2]    2               2               2               4
P[3]    7               4               2               6
P[4]    8               2               0               2
-------------------------------------------------------------
Average Waiting Time=1.000000
Average TurnAround Time=3.400000
*/