#include <stdio.h>
main()
{
	int n,i,m,k,hit=0,c=0,large,z,pos,j,miss=0,x,y,g;
	printf("Enter the Number of Page Requests ");
	scanf("%d",&n);
	int req[n];
	printf("Enter Page Requests : \n");
	for (i=0;i<n;i++)
		scanf("%d",&req[i]);
	printf("Enter the No of Frames :");
        scanf("%d",&m);
	int fram[m];
	int pri[m];
	for (i=0;i<m;i++)
    {
        fram[i]=-1;
        pri[i]=-1;
    }
    for (i=0;i<n;i++)
    {
        k=0;
        for (j=0;j<m;j++)
        {
            if (fram[j]==req[i])
            {
                k++;
                hit++;
            }
        }
        if (miss<m && k==0)
        {
            fram[miss]=req[i];
            miss++;
        }
        else if (k==0)
        {
           for (x=0;x<m;x++)
           {
               g=0;
               for (y=i;y<n;y++)
               {
                   if (fram[x]==req[y])
                   {
                       pri[x]=y;
                       g++;
                       break;
                   }
               }
               if (g!=1)
                pri[x]=n;

           }
           large = pri[0];
           for (z=0;z<m;z++)
           {
               if (large<pri[z])
                    large=pri[z];
           }
           for (z=0;z<m;z++)
           {
               if (pri[z]==large)
                pos=z;
           }
           fram[pos]=req[i];
           miss++;

        }
        printf("\n\t-------------------------------------\n");
        for(j=0;j<m;j++)
        {
        	printf("\t");
            printf("(%d)\t",fram[j]);
        }
        if (k==0)
        	printf(" --> MISS");
        else
        	printf(" --> HIT");
    }
    printf("\n\t-------------------------------------\n");
	printf("No of page Faults is %d ",miss);
}
