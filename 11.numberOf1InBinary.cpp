#include<iostream>
using namespace std;
int numberOf1InBinary(int value)
{
    int count = 0;
    while(value)
    {
        value = (value-1)&value;
        count++;
    }
    return count;
}
int main()
{
    int value;
    cout<<"input value:";
    cin>>value;
    int n=numberOf1InBinary(value);
    cout<<"number of 1 in "<<value<<": "<<n<<endl;
}
