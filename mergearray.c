#include <stdio.h>
int main ()
{
int a[50],b[50],c[20],n,m,i,j,k,temp;

printf("Enter the array limit");
scanf("%d",&n);
printf("Enter the Elements");
for(i=0;i<n;i++){
scanf("%d",&a[i]);
}
// selection sort 

for(i=0;i<n-1;i++){
for(j=i+1;j<n;j++){
if(a[i]>a[j])
{
temp=a[i];
a[i]=a[j];
a[j]=temp;
}
}
}
printf("The sorted array is...\n");
for(i=0;i<n;i++){
printf("%d \t",a[i]);
} 
printf("Enter the array limit for second array");
scanf("%d",&m);
printf("Enter the Elements of second array");
for(i=0;i<m;i++){
scanf("%d",&b[i]);
}
// selection sort 
for(i=0;i<m-1;i++){
for (j=i+1;j<m;j++){
if(b[i]>b[j])
{
temp=b[i];
b[i]=b[j];
b[j]=temp;
}
}
}
printf("\n The sorted array is...\n");
for (i=0;i<m;i++){
printf("%d \t",b[i]);
}
k=0;
i=0;
j=0;
// merging and sorting both array 
while(i<n&&j<m)
{
if(a[i]<=b[j])
{
c[k++]=a[i++];
}
else{
c[k++]=b[j++];
}
}
while(i<n)
{
c[k++]=a[i++];
}
while(j<m)
{
c[k++]=b[j++];
}
printf("Merged sorted array \n");
for(i=0;i<n+m;i++)
{
printf("%d\t",c[i]);
}
return 0;
}  

