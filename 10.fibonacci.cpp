#include<iostream>
#include <time.h>
#include <stdlib.h>
using namespace std;

int quick(int n)
{
    long long* fibonacci = new long long[n];
    fibonacci[0] = 0;
    fibonacci[1] = 1;
    if(n>1)
    {
        long long fi0 = 0;
        long long fi1 = 1;
        for(int i=2;i<=n;i++)
        {
            fibonacci[i] = fi0+fi1;
            fi0 = fi1;
            fi1 = fibonacci[i];
        }
    }
    return fibonacci[n];
}
int slow(int n)
{
    if(n==0)
        return 0;
    if(n==1)
        return 1;
    return slow(n-1)+slow(n-2);

}
int main()
{
    int n;
    cout<<"input n:"<<endl;
    cin>>n;
    cout<<endl;
    clock_t start = clock();
    int result0 = quick(n);
    clock_t end = clock();
    cout<<end-start<<" "<<result0<<endl;
    start = clock();
    int result1 = slow(n);
    end = clock();
    cout<<end-start<<" "<<result1<<endl;
}
