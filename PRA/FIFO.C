#include<stdio.h>
main()
   {
      int a[10],miss=0,i,j,k,n,m;
      printf("\n\tEnter No. of Pages:\n");
      printf("\t");
      scanf("%d",&n);
      printf("\n\tEnter Page Requests :\n");
      for(i=0;i<n;i++)
      {
       printf("\t");
       scanf("%d",&a[i]);
       }
     printf("\n\tEnter no. of frames:\n");
     {
      printf("\t");
     scanf("%d",&m);
     }
     int count1[m];
     for(i=0;i<m;i++)
       count1[i]=-1;
     for(i=0;i<n;i++)
      {
            k=0;
            for(j=0;j<m;j++)
             {
                if(a[i]==count1[j])
                  {
                     k++;
                     miss--;
                  }
             }
             miss++;
             if(miss<=m && k==0)
                {
                   count1[i]=a[i];
                }
             else if(k==0)
                  {
                      count1[(miss-1)%m]=a[i];
                  }
      }
      printf("\n\n\tTotal Page Faults %d",miss);
}
