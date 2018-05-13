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
void selectSort(int* input, int length)
{
    for(int i=length-1; i>=0 ; i--)
    {
        int max = input[0];
        int maxindex = 0;
        for(int j =1;j<=i;j++)
        {
           if(input[j]>max)
           {
                max = input[j];
                maxindex = j;
           }
        }
        int tmp = input[i];
        input[i] = max;
        input[maxindex] = tmp;
    }
}
void insertSort(int* input, int length)
{
    for(int i = 1; i<length; i++)
    {
        int tmp = input[i];
        int j = i-1;
        for(;j>=0;j--)
        {
            if(tmp<input[j])
            {
                input[j+1]=input[j];
            }
            else
            {
                break;
            }
        }
        input[j+1]=tmp;
    }
}
void shellSort(int* input, int length)
{
    //to do
    cout<<"todo"<<endl;
}
void mergeSort(int* input, int length, int* result)
{
    if(length==1)
        return;
    int leftLength = length/2;
    int rightLength = length - length/2;
    int* left = input;
    int* right= input + leftLength;
    mergeSort(left, leftLength,result);
    mergeSort(right,rightLength,result);
    int rightIndex = 0;
    int i = 0;
    int leftIndex = 0;
    while((leftIndex<leftLength)&&(rightIndex<rightLength))
    {
        if (left[leftIndex]<=right[rightIndex])
        {
            result[i] = left[leftIndex];
            leftIndex++;
            i++;
        }
        else
        {
            result[i]=right[rightIndex];
            rightIndex++;
            i++;
        }

    }
    while(leftIndex<leftLength)
    {
        result[i] = left[leftIndex];
        leftIndex++;
        i++;
    }
    while(rightIndex<rightLength)
    {
        result[i]= right[rightIndex];
        rightIndex++;
        i++;
    }
    for(int i = 0;i < length;i++)
    {
        input[i] = result[i]; 
    }
    
}
void quickSort(int* input, int l, int r)
{
   int metrix = input[l];
   int i=l;
   int j=r;
   if(i>j)
   {
        return;
   }
   while(i<j)
   {
        while((i<j)&&(input[j]>metrix))
        {
            j--;
        }
        if(i<j)
        {
            input[i++] = input[j];
        }
        while((i<j)&&(input[i]<metrix))
        {
            i++;
        }
        if(i<j)
        {
            input[j--]=input[i];
        }

   }
   input[i]= metrix;
   quickSort(input,l,i-1);
   quickSort(input,i+1,r);


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
    int result[10];
    printInput(input,10);
    //bubbleSort(input, 10);
    //selectSort(input,10);
    //insertSort(input,10);
    //mergeSort(input,10,result);
    quickSort(input,0,9);
    printInput(input,10);

}
