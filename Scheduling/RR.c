#include <stdio.h>
void swap(int *a, int *b)
{
   int t;

   t  = *b;
   *b = *a;
   *a = t;
}
void main()
{
    int n,i,j,tbt=0,tq,p=0,avwt=0,avtat=0;

    printf("Enter No of Process : ");
    scanf("%d",&n);

    int at[n],bt[n],pid[n],cbt[n],ct[n],oid[n],oex[n],tat[n],wt[n];

    // Taking Inputs From User
    for(i=0;i<n;i++)
    {
        printf("Enter Arrival Time  Of P[%d] :",i+1);
        scanf("%d",&at[i]);
        printf("Enter Burst Time  Of P[%d] :",i+1);
        scanf("%d",&bt[i]);
        tbt+= bt[i];
        pid[i] = i+1;
        oex[i]=0;
    }

    // sorting the process by Arrival Time

    for (i=0;i<n;i++)
    {
        for (j=i+1;j<n;j++)
        {
            if (at[i]>at[j])
            {
                swap(&at[i],&at[j]);
                swap(&bt[i],&bt[j]);
                swap(&pid[i],&pid[j]);
            }
        }
    }
    // Taking Order Id For each Process
        for (i=0;i<n;i++)
            oid[i]=i;
    // Copying burst time into another Array
    for(i=0;i<n;i++)
        cbt[i]=bt[i];

    // Taking Time Quantum From User
    printf("Enter Time Quantum : ");
    scanf("%d",&tq);
    int k,min;
    k = oid[n-1]+1;
    int pidd;
    //Main Round Robin Code Starts
    for (i=0;i<k;i++)
    {
        for (j=0;j<n;j++)
        {
            if (oid[j]==i)
                pidd = j;
        }
        if (p<at[pidd])
            p = p+(at[pidd]- p);
        if (cbt[pidd]>=tq)
        {
            cbt[pidd] = cbt[pidd] - tq;
            p = p+tq;
        }
        else if(cbt[pidd]<tq)
        {
            p = p+cbt[pidd];
            cbt[pidd] = 0;
        }
        if (cbt[pidd]==0)
        {
            ct[pidd] = p;
            oex[pidd]=1;
            oid[pidd]=1000;
        }
        else
        {
            min = 999;
            for (j=0;j<n;j++)
            {
                if (at[j]>p && oid[j]<min && oex[j]==0)
                    min = oid[j];
            }
            if (min!=999)
            {
            for (j=0;j<n;j++)
            {
                if (oid[j]>=min && oex[j]==0)
                    oid[j]++;
            }
            oid[pidd] = min;
            k++;
            }
        else if (min == 999)
        {
            oid[pidd] = k;
            k++;
        }
        }
    }
    printf("\n-------------------------------------------------------------------------------------------------------------------\n");
    printf("|  PId \t| Arrival Time \t |  Burst Time \t        |   Completion Time\t |     Waiting Time\t | TurnAround Time |\n");
    printf("--------------------------------------------------------------------------------------------------------------------\n");
    //calculating turnaround time and Waiting time
    for(i=0;i<n;i++)
    {
        tat[i]=ct[i]-at[i];
        wt[i]=tat[i]-bt[i];
        avwt+=wt[i];
        avtat+=tat[i];
        printf("|  P%d\t|        %d\t |           %d\t        |      %d\t         |           %d  \t |      %d   \t   |\n",pid[i],at[i],bt[i],ct[i],wt[i],tat[i]);
        printf("--------------------------------------------------------------------------------------------------------------------\n");
    }

    printf("\n\nAverage Waiting Time:%.2f",(float)avwt/n);
    printf("\nAverage Turnaround Time:%.2f",(float)avtat/n);

}
