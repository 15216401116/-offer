#include<iostream>
using namespace std;
int findMin(int* input, int left, int right)
{//should remove all the duplicated value
    if (left==right)
        return left;
    int middleIndex = (left+right)/2;
    if ((input[middleIndex]>=input[left])&&(input[middleIndex]>=input[right]))
    {
        int newleft = middleIndex+1;
        int newright = right;
        return findMin(input, newleft, newright);
    }
    else if((input[middleIndex]<=input[left])&&(input[middleIndex]<=input[right]))
    {
        int newleft = left;
        int newright = middleIndex;
        return findMin(input, newleft, newright);
    }
}

int main()
{
    int input[15] = {7,8,9,10,11,12,13,14,15,1,2,3,4,5,6};
    int index = findMin(input,0,14);
    cout<<input[index];
}
