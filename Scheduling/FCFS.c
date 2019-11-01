#include <stdio.h>
void main()
{
    int n,i,j,z,p,v;
    float t,tat=0,tati,wti,mm;
    printf("Enter the NO Of  process : " );
    scanf("%d",&n);
    int bt[n],ct[n],pid[n];
    float at[n];
    printf("Enter Arrival Time & Burst Time :");
    for (i=0;i<n;i++)
    {
        scanf("%f , %d",&at[i],&bt[i]);
        pid[i]=i+1;
    }
    printf("\n---------------------------------------\n");
    printf("|  PId \t| Arrival Time \t | Burst Time |\n");
    printf("---------------------------------------\n");
    for (i=0;i<n;i++)
    {
        printf("|  P%d\t|     %.2f\t |   %d\t      |\n",pid[i],at[i],bt[i]);
        printf("---------------------------------------\n");
    }
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
    p=(int)at[0];
    printf("\n \t Gantt Chart \t");
    printf("\n--------------------------------------------\n");
    for (i=0;i<n;i++)
    {
        printf("|  P%d   |",pid[i]);
    }
    printf("\n--------------------------------------------\n");
    for (i=0;i<n+1;i++)
    {
        //printf("%d\t",p);
        p=p+bt[i];
       // ct[i]=p;
        mm = 0;
        if (at[i]>mm && i<n-1)
        {
          mm = at[i] - p;
        }
        p=p+mm;
        ct[i] = p;
    }
    float wt=0;
    printf("\n--------------------------------------------\n");
    printf("|  PId \t| Waiting Time \t | TurnAround Time |\n");
    printf("--------------------------------------------\n");
    for (i=0;i<n;i++)
    {
        tati = ct[i] - at[i];
        tat += tati;
        wti = tati-bt[i];
        wt = wt+wti;
        printf("|  P%d\t|     %.2f\t |   %.2f\t   |\n",pid[i],wti,tati);
    }
    printf("--------------------------------------------\n");
    printf("\n Average Turn Around Time is %.2f",(tat/n));
    printf("\n Average Waiting Time is %.2f",(wt)/n);
}
