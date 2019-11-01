#include<stdio.h>
#include <stdlib.h>

//All case Woring

int main()
{
    int n=0,m=0,i=0,j=0,k=0,time=10000,currenttime=0,pid=-1,timespace=0;
    int quantum,min;

    struct process{
        int arrival;
        int burst;
        int wait;
        int complete;
        int execute;
        int turn;
        int cpu;
        int ord;
    };

    printf("Enter no.of process:");
    scanf("%d",&n);

    struct process arr[n];
    for(i=0;i<n;i++)
    {
        printf("Process %d\n",i);
        printf("Enter Arrival time:");
        scanf("%d",&arr[i].arrival);
        printf("Enter burst time:");
        scanf("%d",&arr[i].burst);
        arr[i].wait=0;
        arr[i].complete=0;
        arr[i].execute=0;
        arr[i].turn=-1;
        arr[i].cpu=0;
        arr[i].ord=-1;
    }

    printf("Enter your Time Quantum:");
    scanf("%d",&quantum);

    for(i=0;i<n;i++)
    {
        time=999;
        pid=-1;
        for(j=0;j<n;j++)
        {
            if(arr[j].arrival<time && arr[j].ord==-1)
            {
                time=arr[j].arrival;
                pid=j;
            }
        }
        arr[pid].ord=k;
        k++;
    }
    for(j=0;j<n;j++)
        {
            printf("%d\t|%d\t|%d\n",j,arr[j].burst,arr[j].ord);
        }

    for(i=0;i<k;i++)
    {

        printf("\n");
        for(j=0;j<n;j++)
        {
            if(arr[j].ord == i)
            {
                pid=j;
            }
        }
        if(currenttime<arr[pid].arrival)
        {
            currenttime=currenttime+(arr[j].arrival-currenttime);
        }

        if(arr[pid].burst>=quantum)
        {
            arr[pid].burst=arr[pid].burst-quantum;
            arr[pid].cpu=arr[pid].cpu+quantum;
            currenttime=currenttime+quantum;
        }
        else if (arr[pid].burst<quantum)
        {
            currenttime=currenttime+arr[pid].burst;
            arr[pid].cpu=arr[pid].cpu+arr[pid].burst;
            arr[pid].burst=0;
        }

        if(arr[pid].burst==0)
        {
            arr[pid].complete=currenttime;
            arr[pid].turn=arr[pid].complete-arr[pid].arrival;
            arr[pid].wait=arr[pid].turn-arr[pid].cpu;
            arr[pid].execute=1;
            arr[pid].ord=10000;
        }
        else
        {
            min=999;
            for(j=0;j<n;j++)
            {
                if(arr[j].arrival>currenttime && arr[j].ord<min && arr[j].execute==0)
                {
                    min=arr[j].ord;
                }
            }
            printf("max ord %d\n",min);

            if(min!=999)
            {
                for(j=0;j<n;j++)
                {
                    if(arr[j].ord>=min && arr[j].execute==0)
                    {
                        arr[j].ord++;
                    }
                }
                arr[pid].ord=min;
                k++;
            }
            else if(min==999)
            {
                arr[pid].ord=k;
                k++;
            }
        }
        for(j=0;j<n;j++)
        {
            printf("%d\t|%d\t|%d\n",j,arr[j].burst,arr[j].ord);
        }
    }
    printf("------------------------------------------------------\n");
    printf("|process|Arrival|Burst  |Waiting|Complete|turn Around\n");
    printf("------------------------------------------------------\n");
    for(i=0;i<n;i++)
    {
        printf("| %d\t|%d   \t|%d\t|%d\t|%d   \t |%d\t|\n",i,arr[i].arrival,arr[i].cpu,arr[i].wait,arr[i].complete,arr[i].turn);
        printf("------------------------------------------------------\n");
    }


}
