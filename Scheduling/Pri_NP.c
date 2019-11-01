#include <stdio.h>
void swap(int *a , int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
void main()
{
    int n,i,j,spos;
    float small,tati,wti;
    printf("Enter the NO Of  process : " );
    scanf("%d",&n);
    int bt[n],ct[n],pid[n],pri[n],wt[n],tat[n],tl,avwt=0,avtat=0,at[n];
    for (i=0;i<n;i++)
    {
        printf("Enter Arrival Time :");
        scanf("%d",&at[i]);
        printf("Enter Burst Time : ");
        scanf("%d",&bt[i]);
        printf("Enter Priority :");
        scanf("%d",&pri[i]);
        pid[i]=i+1;
    }

    // Sorting the process by using Arrival time
    for (i=0;i<n;i++)
    {
        for (j=i+1;j<n;j++)
        {
            if (at[i]>at[j])
            {
                swap(&at[i],&at[j]);
                swap(&bt[i],&bt[j]);
                swap(&pri[i],&pri[j]);
                swap(&pid[i],&pid[j]);
            }
            if (at[i]==at[j])
            {
                if(pri[i]>pri[j])
                {
                    swap(&at[i],&at[j]);
                    swap(&bt[i],&bt[j]);
                    swap(&pri[i],&pri[j]);
                    swap(&pid[i],&pid[j]);
                }
                if (pri[i]==pri[j])
                {
                    if (pid[i]>pid[j])
                    {
                        swap(&at[i],&at[j]);
                        swap(&bt[i],&bt[j]);
                        swap(&pri[i],&pri[j]);
                        swap(&pid[i],&pid[j]);
                    }
                }
            }
        }
    }
    ct[0] = at[0]+bt[0];
    // Sorting the process by priority

    int count,zz,kk;
    for(i=0;i<n;i++)
    {
            count = 0;
            if (i==0)
                ct[i]=bt[i]+at[i];
            else
            {
                for (j=i;j<n;j++)
                {
                    if (at[j]<=ct[i-1])
                        count ++;
                }
                for (zz=i;zz<=count;zz++)
                {
                    for (kk = zz+1;kk<=count;kk++)
                    {
                        if (pri[zz]>pri[kk])
                        {
                            swap(&at[zz],&at[kk]);
                            swap(&bt[zz],&bt[kk]);
                            swap(&pid[zz],&pid[kk]);
                            swap(&pri[zz],&pri[kk]);
                        }
                    }
                }
                if (ct[i-1]<at[i])
                {
                    tl = at[i]-ct[i-1];
                    ct[i]=ct[i-1]+bt[i]+tl;
                }
                else
                    ct[i]=ct[i-1]+bt[i];
            }
    }
printf("\n------------------------------------------------------------------------------------------------------------------------------------\n");
    printf("|  PId \t| Arrival Time \t | Burst Time \t |      Priority \t |  Completion Time\t |     Waiting Time\t | TurnAround Time |\n");
    printf("------------------------------------------------------------------------------------------------------------------------------------\n");
    //calculating turnaround time and Waiting time
    for(i=0;i<n;i++)
    {
        tat[i]=ct[i]-at[i];
        wt[i]=tat[i]-bt[i];
        avwt+=wt[i];
        avtat+=tat[i];
        printf("|  P%d\t|     %.2d \t |       %d\t |           %d\t         |         %d\t         |           %d  \t |      %d   \t   |\n",pid[i],at[i],bt[i],pri[i],ct[i],wt[i],tat[i]);
        printf("------------------------------------------------------------------------------------------------------------------------------------\n");
    }

    printf("\n\nAverage Waiting Time:%.2f",(float)avwt/n);
    printf("\nAverage Turnaround Time:%.2f",(float)avtat/n);

    return 0;
}
