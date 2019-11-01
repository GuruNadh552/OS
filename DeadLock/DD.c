#include <stdio.h>
int x,y;
void safe(int a[x][y],int m[x][y],int av[x])
{
	int d,e,stat[x],req[x],z=0,g,p,yy;
	//Status_Of_Each_Processor
	for (d=0;d<x;d++)
		stat[d]=0;
	for (d=0;d<x;d++)
	{
		for (e=0;e<x;e++)
		{
			if (stat[e]==0)
			{
				p=0;
				for ( g =0; g < y; g++)
				{
					if (m[e][g]>av[g])
					{
						p = 1;
						break;
					}
				}
				if (p == 0)
				{
				    req[z++] = e;
				    for (yy = 0; yy < y; yy++)
				        av[yy]=av[yy] + a[e][yy];
				    stat[e] = 1;
                }
			}
		}
	}
	int gg = 0;
    for (d = 0 ; d < x ; d++)
	if (stat[d]==1)
		gg++;
    if (gg == x)
    {

    printf("\nSaFe SeQuEnCe : \n");
    for (d = 0; d < x; d++)
        printf(" P%d \t", req[d]);
    }
    else
    	printf("DeadLock");

}
void main()
{
	int nop,nor,i,j,k;
        printf("\nEnter No Of Process :  ");
	scanf("%d",&nop);
	printf("\nEnter No Of Resources : ");
        scanf("%d",&nor);
	int alloc[nop][nor],max[nop][nor],avail[nop];
	int alloc1[nop][nor],max1[nop][nor],avail1[nop];
        //Allocation Matrix
	for (i=0;i<nop;i++)
	{
		printf("\n Enter P%d Allocation : \n",i);
		for (j=0;j<nor;j++)
		{
			scanf("%d",&alloc[i][j]);
			alloc1[i][j] = alloc[i][j];
		}
	}
	//Required Matrix
	for (i=0;i<nop;i++)
	{
		printf("\n Enter P%d Request  : \n",i);
		for (j=0;j<nor;j++)
		{
			scanf("%d",&max[i][j]);
			max1[i][j] = max[i][j];
		}
	}
	//available Resources
	printf("Enter Available Resources : ");
	for (i=0;i<nor;i++)
	{
		scanf("%d",&avail[i]);
		avail1[i] = avail[i];
	}
	x = nop;
	y = nor;
	safe(alloc,max,avail);
	//For Granting Request
	printf("Enter Process : ");
	scanf("%d",&k);
	int arr[nor],count=0,nee[nor],f=0,count1=0;
	printf("Enter Requests For P%d",k);
	for (i=0;i<nor;i++)
		scanf("%d",&arr[i]);
	for (j=0;j<nor;j++)
		nee[j] = max1[k][j] - alloc1[k][j];
	for (i=0;i<nor;i++)
	{
		if (nee[i]>=arr[i])
			count++;
	}
	if (count == nor)
	{
		for (i=0;i<nor;i++)
			if (avail1[i]>=arr[i])
				count1++;
		if (count1==nor)
		{
			for (i=0;i<nor;i++)
			{
				alloc1[k][i] = alloc1[k][i] + arr[i];
				avail1[i] = avail1[i] - arr[i];
			}
			safe(alloc1,max1,avail1);
		}
		else
			printf("Allocation Resources Are Less Than Request");
	}
	else	printf("Invalid Request");
}

