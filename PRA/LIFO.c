#include <stdio.h>
main()
{
	int pagereq[100],clock=0,npr,i,nfr,k=0,miss=0,j,small,z,pos;
	printf("Enter No of page Requests : ");
	scanf("%d",&npr);
	printf("Enter Page Requests : ");
	for (i=0;i<npr;i++)
		scanf("%d",&pagereq[i]);
	printf("Enter No of Frames ");
	scanf("%d",&nfr);
	int frame[nfr],poss[nfr];
	for (i=0;i<nfr;i++)
	{
		frame[i]=-1;
		poss[i]=-1;
	}
	for (i=0;i<npr;i++)
	{
		k=0;
		for (j=0;j<nfr;j++)
		{
			if (pagereq[i]==frame[j])
			{
				k++;
				miss--;
				clock++;
				poss[j]=clock;
			}
		}
		miss++;
		clock++;
		if (miss<=nfr && k==0)
		{
			frame[miss-1]=pagereq[i];
			poss[miss-1]=clock;
		}
		else if(k==0)
		{
			small = poss[0];
			for (z=1;z<nfr;z++)
			{
				if (small > poss[z])
				{
					small = poss[z];
				}
			}
			for (z=0;z<nfr;z++)
			{
				if (poss[z]==small)
					pos = z;
			}
			frame[pos]=pagereq[i];
			poss[pos]=clock;	
		}
		printf("\n\t-------------------------------------\n"); 
        for(j=0;j<nfr;j++)
        {
        	printf("\t");       
            printf("(%d)\t",frame[j]);
        }
        if (k==0)
        	printf(" --> MISS");
        else
        	printf(" --> HIT");
	}
	printf("\n\t-------------------------------------\n");
	printf("No of page Faults is %d ",miss);
}
