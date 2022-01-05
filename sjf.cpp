#include<stdio.h>
#include<conio.h>
int main()
{
      int n,temp,tt=0,min,d,i,j;

      float atat=0,awt=0,stat=0,swt=0;

      printf("Enter no of process: ");
      scanf("%d",&n);
      int a[10],b[10],e[10],tat[10],wt[10];
      for(i=0;i<n;i++)
      {
    printf("Enter arrival time P[%d]: ",i+1);       //input arrival time
    scanf("%d",&a[i]);
      }
      for(i=0;i<n;i++)
      {
    printf("Enter burst time P[%d]: ",i+1);      //input burst time
    scanf("%d",&b[i]);
      }
      for(i=0;i<n;i++)
      {
for(j=i+1;j<n;j++)
  {
if(b[i]>b[j]) // bubble sort(compare 2 elements)
{
       temp=a[i];
      a[i]=a[j];
      a[j]=temp;
      temp=b[i];
      b[i]=b[j];
      b[j]=temp;
                }
          }
      }
      min=a[0];  
      for(i=0;i<n;i++)
      {
            if(min>a[i])  //if min is greater than a[i] change min to a[i]
            {
                  min=a[i]; 
                  d=i; // index of min at is d
            }
      }
      tt=min;  //tt=timer in gantt
      e[d]=tt+b[d];  //end time in gantt
      tt=e[d];     //time collapsed until now
      for(i=0;i<n;i++)
      {
            if(a[i]!=min)    //calculate end time other  processes than (min)
            {
                  e[i]=b[i]+tt;
                  tt=e[i];
            }
      }
      for(i=0;i<n;i++)
      {
            tat[i]=e[i]-a[i];  //tat=ct-at
            stat=stat+tat[i];
            wt[i]=tat[i]-b[i];  //wt=tat-bt
            swt=swt+wt[i];
      }
     atat=stat/n;
      awt=swt/n;
      printf("Process  Arrival-time(s)  Burst-time(s)  Waiting-time(s)  Turnaround-time(s)\n");
    for(i=0;i<n;i++)
    {
    printf("P%d\t\t%d\t\t%d\t\t%d\t\t%d\n",i+1,a[i],b[i],wt[i],tat[i]);
    }
    printf("awt=%f\n atat=%f",awt,atat);  //average waiting time and turn around time
    getch();

}
