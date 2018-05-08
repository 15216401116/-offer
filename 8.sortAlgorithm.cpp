#include<iostream>
using namespace std;
void bubbleSort(int* input, int length)
{
    int index =length - 1;
    bool mark = true;
    while(mark)
    {
        mark = false;
        for(int i =0;i<index;i++)
        {
            if(input[i]>input[i+1])
            {
                int tmp = input[i];
                input[i]=input[i+1];
                input[i+1]=tmp;
                mark = true;
            }
        }
        index--;
    }
}
void printInput(int* input, int length)
{
    for(int i=0;i<length;i++)
    {
        cout<<input[i]<<" ";
    }
    cout<<endl;
}
int main()
{
    int input[10] = {9,8,7,3,4,5,6,2,1,10};
    bubbleSort(input, 10);
    printInput(input,10);

}
