#include<iostream>
using namespace std;
int stupidFind(int* input, int left, int right)
{
    min = input[left];
    minIndex = left;
    int index = left+1;
    while(index <= right)
    {
        if (input[index]<min)
        {
            min = input[index];
            minIndex = index;
        }
        index++;
    }
    return minIndex;
}
int findMin(int* input, int left, int right)
{
    if (input[left]<input[right])
    {
        return left;
    }
    if (left+1 == right)
        return right;
    int middleIndex = (left+right)/2;
    if(input[middleIndex]==input[left]==input[right])
    {
       return stupidFindMin(input, left, right);
    }
    else if (input[middleIndex]>=input[left])
    {
        int newleft = middleIndex+1;
        int newright = right;
        return findMin(input, newleft, newright);
    }
    else if(input[middleIndex]<=input[right])
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
