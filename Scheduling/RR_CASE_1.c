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
    int n,i,j,tbt=0,tq,x,p;

    printf("Enter No of Process : ");
    scanf("%d",&n);

    int at[n],bt[n],pid[n],cbt[n],ct[n],tat[n],wt[n],avwt=0,avtat=0;
    // Taking Inputs From User
    for(i=0;i<n;i++)
    {
        printf("Enter Arrival Time  Of P[%d] :",i+1);
        scanf("%d",&at[i]);
        printf("Enter Burst Time  Of P[%d] :",i+1);
        scanf("%d",&bt[i]);
        tbt+= bt[i];
        pid[i] = i+1;
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

    // Copying burst time into another Array
    for(i=0;i<n;i++)
        cbt[i]=bt[i];

    // Taking Time Quantum From User
    printf("Enter Time Quantum : ");
    scanf("%d",&tq);

   x=0;
   i=0;
   while(tbt!=0)
   {
       if (cbt[i]!=0)
       {
           if (x==0)
           {
              if (cbt[i]>=tq)
              {
                  cbt[i] -= tq;
                  ct[i] = tq;
                  tbt -= tq;
              }
              else
              {
                  ct[i] = cbt[i];
                  tbt -= cbt[i];
                  cbt[i] = 0;
              }
              p=ct[i];
              x++;
           }
           else
           {
             if (cbt[i]>=tq)
              {
                  cbt[i] -= tq;
                  ct[i] = tq + p;
                  tbt -= tq;
              }
              else
              {
                  ct[i] = cbt[i] + p;
                  tbt -= cbt[i];
                  cbt[i] = 0;
              }
              p=ct[i];
           }
           i++;
       }
        if (i==n)
                i=0;
   }
    printf("%d %d %d",ct[1],ct[2],ct[3]);

}
