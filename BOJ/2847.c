#include <stdio.h>
int main()
{
 int n,i,sum=0;
 int a[100]={0};
 scanf("%d",&n);
 for(i=0;i<n;i++) scanf("%d",a+i);
 for(i=n-2;i>=0;i--)
 {
  if(a[i]>=a[i+1])
  {
   sum=sum+1+a[i]-a[i+1];
   a[i]=a[i+1]-1;
  }
 }
 printf("%d",sum);
 return 0;
}