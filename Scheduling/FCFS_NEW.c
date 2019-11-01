#include<stdio.h>

int main()
{
    int n,bt[20],pid[20],wt[20],tat[20],ct[20],avwt=0,avtat=0,i,j,z,v,tl;
    float at[20],t;
    printf("Enter No Of Process :");
    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
         printf("\nEnter Process Arrival Time\n");
         printf("P[%d]:",i+1);
         scanf("%f",&at[i]);
         printf("\nEnter Process Burst Time\n");
         printf("P[%d]:",i+1);
         scanf("%d",&bt[i]);
         pid[i]=i+1;
    }

    // Sortig Process By Arrival Time
    for (i=0;i<n;i++)
    {
        for (j=i+1;j<n;j++)
        {
            if  (at[i]>at[j])
            {
                t = at[i];
                at[i]=at[j];
                at[j]=t;

                z = bt[i];
                bt[i]=bt[j];
                bt[j]=z;

                v = pid[i];
                pid[i] = pid[j];
                pid[j]= v;
            }
        }
    }
    //For Calculating Completion TIME
    for(i=0;i<n;i++)
    {
            if (i==0)
                ct[i]=bt[i]+at[i];
            else
            {
                if (ct[i-1]<at[i])
                {
                    tl = at[i]-ct[i-1];
                    ct[i]=ct[i-1]+bt[i]+tl;
                }
                else
                    ct[i]=ct[i-1]+bt[i];
            }
    }

    printf("\n+----------------------------------------------------------------------------------------------------+\n");
    printf("|  PId \t| Arrival Time \t | Burst Time \t |  Completion Time\t | Waiting Time\t | TurnAround Time\t |\n");
    printf("+----------------------------------------------------------------------------------------------------+\n");

    //calculating turnaround time
    for(i=0;i<n;i++)
    {
        tat[i]=ct[i]-at[i];
        wt[i]=tat[i]-bt[i];
        avwt+=wt[i];
        avtat+=tat[i];
        printf("|  P%d\t|     %.2f  \t |       %d\t |          %d\t         |      %d\t |      %d\t     |\n",pid[i],at[i],bt[i],ct[i],wt[i],tat[i]);
        printf("+----------------------------------------------------------------------------------------------------+\n");
    }

    avwt=avwt/n;
    avtat=avtat/n;
    printf("\n\nAverage Waiting Time:%d",avwt);
    printf("\nAverage Turnaround Time:%d",avtat);

    return 0;
}
