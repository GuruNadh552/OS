#include <stdio.h>
void swap(int *a, int *b)
{
   int t;

   t  = *b;
   *b = *a;
   *a = t;
}
main()
{
    int n,i,tbt=0,j,p=0,l;

    printf("Enter No of process  : ");
    scanf("%d",&n);

    int avwt=0,avtat=0,tat[n],wt[n];
    int pid[n],bt[n],cbt[n],sb,sbp,m,ct[n],at[n];

    for (i=0;i<n;i++)
    {
        printf("Enter P%d Arrival time :",i+1);
        scanf("%d",&at[i]);
        printf("Enter P%d Burst Time :",i+1);
        scanf("%d",&bt[i]);
        tbt = tbt + bt[i];
        pid[i]=i+1;

        ct[i]=0;
    }
    l = at[n-1];
    // Sortig Process By Arrival Time
    for (i=0;i<n;i++)
    {
        for (j=i+1;j<n;j++)
        {
            if  (at[i]>at[j])
            {

                    swap(&at[i],&at[j]);
                    swap(&bt[i],&bt[j]);
                    swap(&pid[i],&pid[j]);
            }
            if (at[i]==at[j])
            {
                if (bt[i]>bt[j])
                {
                    swap(&at[i],&at[j]);
                    swap(&bt[i],&bt[j]);
                    swap(&pid[i],&pid[j]);
                }
            }
        }
    }

    // Copying Burst time into another Array

    for (i=0;i<n;i++)
        cbt[i]=bt[i];
    // Primitive SJF code starts
    for (i=0;i<n-1;i++)
    {
        if (i==0)
        {
            if (cbt[i]>= at[i+1])
            {
              cbt[i] = cbt[i]-at[i+1];
              ct[i] = at[i+1];
            }
            else
            {
                ct[i] = cbt[i];
                cbt[i] = 0;
            }
        }
        else
        {
            m = at[i+1]-at[i];
            sb = cbt[0];
            sbp = 0;
            for (j=0;j<=i;j++)
            {
               if (cbt[j]!=0)
               {
                if (sb>cbt[j])
                   {
                       sb = cbt[j];
                       sbp = j;
                   }
               }
            }
            if (cbt[sbp]>=m)
            {
                cbt[sbp] = cbt[sbp]-m;
                ct[sbp] = at[i+1];
            }
            else
            {
                ct[i] = at[i]+cbt[i];
                cbt[i] = 0;
            }
        }
    }
    // SJF NON PRimitive for non process
    // For sorting the Process By Burst Time
    for (i=0;i<n;i++)
    {
        for (j=i+1;j<n;j++)
        {
                if (cbt[i]>cbt[j])
                {
                        swap(&at[i],&at[j]);
                        swap(&cbt[i],&cbt[j]);
                        swap(&pid[i],&pid[j]);
                        swap(&ct[i],&ct[j]);
                        swap(&bt[i],&bt[j]);
                }
        }
    }
    //Calculating Completion Time
    for(i=0;i<n;i++)
    {
        if (cbt[i]!=0)
        {
            p=p+1;
            if (p==1)
                ct[i]=cbt[i]+l;
            else
                ct[i]=ct[i-1]+cbt[i];
        }
    }

    printf("\n------------------------------------------------------------------------------------------------------\n");
    printf("|  PId \t| Arrival Time \t | Burst Time \t |  Completion Time\t | Waiting Time\t | TurnAround Time\t |\n");
    printf("------------------------------------------------------------------------------------------------------\n");
    //calculating turnaround time and Waiting time
    for(i=0;i<n;i++)
    {
        tat[i]=ct[i]-at[i];
        wt[i]=tat[i]-bt[i];
        avwt+=wt[i];
        avtat+=tat[i];
        printf("|  P%d\t|     %d  \t |       %d\t |          %d\t         |      %d\t |      %d\t     |\n",pid[i],at[i],bt[i],ct[i],wt[i],tat[i]);
        printf("------------------------------------------------------------------------------------------------------\n");
    }

    printf("\n\nAverage Waiting Time:%.2f",(float)avwt/n);
    printf("\nAverage Turnaround Time:%.2f",(float)avtat/n);
}
