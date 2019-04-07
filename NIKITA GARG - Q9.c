#include<stdio.h>
#include<conio.h>
void main()
{
  int i,j,n,t,p[30],bt[30],wt[30],tat[30];
  //p = process id
  //bt = burst time
  //wt = waiting time
  //tat = turn around time
  float awt=0, atat=0;
  int c=0;
 
  printf("Enter the number of processes : ");
  scanf("%d",&n);
  printf("Enter process ID for each process : ");
  for(i=0;i<n;i++)
  {
    scanf("%d",&p[i]);
  }
  printf("Enter the burst time : ");
  for(i=0;i<n;i++)
  {
    scanf("%d",&bt[i]);
  }
  
  printf("Process ID \t Burst time \n");
  for(i=0;i<n;i++)
  {
  	printf("\t%d\t\t %d\n", p[i],bt[i]);
  }
  
  printf("\n **After applying Shortest Job First Algorithm ** \n\n");
  //applying bubble sort to burst time
  
  for(i=0;i<n;i++)
  {
    for(j=0;j<n-i-1;j++)
    {
      if(bt[j]>bt[j+1])
      {
        t = bt[j];
        bt[j] = bt[j+1];
        bt[j+1] = t;
        
        //arranging process number according to burst time
        
        t = p[j];
        p[j] = p[j+1];
        p[j+1] = t;
       }
     }
   }
   
   printf("Process ID \t Burst time \t Waiting time \t Turnaround Time \n");
   for(i=0;i<n;i++)
   {
     wt[i] = 0;
     tat[i] = 0;
     for(j=0;j<i;j++)
     {
       wt[i] = wt[i] + bt[j];
     }
     tat[i] = wt[i] + bt[i];
     awt = awt + wt[i];
     atat = atat + tat[i];
     printf("\t%d\t\t %d \t\t %d \t\t %d\n", p[i], bt[i], wt[i], tat[i]);
   }
   
   awt = awt/n;
   atat = atat/n;
   printf("Average waiting time : %.2f\n",awt);
   printf("Average turnaround time : %.2f",atat);
   
 }
   
