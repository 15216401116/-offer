#include<iostream>
using namespace std;
int func(int n1,int n2,int n3)
{
    int min=n1;
    if(n2<min)
      min=n2;
    if(n3<min)
      min=n3;
    return min;
}
int main()
{
   int num[11];
   num[1]=1;
   num[2]=2;
   num[3]=1;
   num[4]=2;
   num[5]=1;
   for(int i=6;i<=11;i++)
   {
       num[i]=func(num[i-1],num[i-3],num[i-5])+1;
   }
   cout<<"11 need at least: "<<num[11]<<" coins"<<endl;
}
