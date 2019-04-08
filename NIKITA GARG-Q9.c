#include<stdio.h>
#include<conio.h>
#define max 30
void main()
{
  int i,j,n,t,p[max],bt[max],wt[max],tat[max];
  //p = process id
  //bt = burst time
  //wt = waiting time
  //tat = turn around time
  float awt=0, atat=0;
  //awt = average waiting time
  //atat = average turn around time
  int c=0;
  
	//burst time taken from user and stored in file
	printf("Enter the number of processes : ");
    scanf("%d",&n); 
	printf("Enter process ID for each process : ");
  	for(i=0;i<n;i++)
  	{
    	scanf("%d",&p[i]);
  	} 
  	FILE *fp;
	fp=fopen("CPU_BURST.txt","w");
	if(fp==NULL)
	printf("\n File not found");
	again:
	printf("\nEnter burst time : ");
	for(i=0;i<n;i++)
	{
    	scanf("%d",&bt[i]);
  	}
  	for(i=0;i<n;i++)
  	{
  		if(bt[i]<=0)
  		goto again;
  	}
  	
	for(i=0;i<n;i++)
	fprintf(fp,"\t %d",bt[i]);
	fclose(fp);
	
	fp=fopen("CPU_BURST.txt","r");
	fscanf(fp,"%d",&c);
	printf("\nBurst time from file : ");
	while(!feof(fp))
	{
		printf("\t %d",c);
		fscanf(fp,"\t %d",&c);
		
	}
	printf("\t %d\n",c);
	fclose(fp);
	
  
  printf("\nProcess ID \t Burst time \n");
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
   
