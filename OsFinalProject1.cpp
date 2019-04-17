#include<conio.h>
#include<stdio.h>
int main()
{
 int a;    
 int b;      
 int i,j,k,cnt,cntt,pro;
 int avail[10],p[10],sequence[10],count=0;
 int need[10][10],alloc[10][10],max[10][10];

 printf("\n Number of processes :");
 scanf("%d",&a);
 printf("\n Available resources  : ");
 scanf("%d",&b);
 printf("\nResources insatnces :\n");
 for(i=0;i<b;i++)
 {  printf("R%d ",i+1);
  scanf("%d",&avail[i]);
  }
 printf("\n Allocation Matrix  \n");
 for(i=0;i<a;i++)
 {
 printf("p%d\t",i+1);          p[i]=0;
 for(j=0;j<b;j++)
 {
  scanf("%d",&alloc[i][j]);
 }
}
  printf("\n Maximum Matrix  \n");

 for(i=0;i<a;i++)
 {
 printf("p%d\t",i+1);
 for(j=0;j<b;j++)
 {
  scanf("%d",&max[i][j]);
 }
 }

 for(i=0;i<a;i++)
 {
 printf("\np%d\t",i+1) ;
 for(j=0;j<b;j++)
 {
  need[i][j]=max[i][j]-alloc[i][j];
  printf("\t%d",need[i][j]);
  }
 }
 k=0;     cntt=0;
do
{
printf("\n\n Pro\t\tAllocation\t\tMaximum\n");
for(i=0;i<a;i++)
{
printf("P[%d]\t\t",i+1);
for(j=0;j<b;j++)
{
printf("%d\t\t",alloc[i][j]);
printf("%d\n",max[i][j]);
}
}
pro=-1;
for(i=0;i<a;i++)
{
if(p[i]==0)
{
pro=i;
for(j=0;j<b;j++)
{
if(avail[j]<need[i][j])
{
pro=-1;
break;
}
}
}
if(pro!=-1)
break;
}
if(pro!=-1)
{
printf("P[%d] Runs Successfully",pro+1);
sequence[i]=pro+1;
count++;
for(j=0;j<b;j++)
{
avail[j]=avail[j]+alloc[pro][j];
alloc[pro][j]=0;
max[pro][j]=0;
p[j]=1;
}
}
}
while(count!=a&&pro!=-1);
if(count==a)
{
printf("\n System is in Safe State");
}
else
printf("\n System is in Deadlock");

}


