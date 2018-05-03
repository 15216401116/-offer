#include<iostream>
using namespace std;
bool replaceBlank(char * string, int length)
{
    int originalLength = 0;
    int newLength = 0;
    int i = 0;
    while(string[i]!='\0')
    {
        originalLength ++;
        newLength++;
        if (string[i] == ' ')
            newLength+=2;
        i++;
    }
    int oldindex = originalLength;
    int newindex = newLength;
    if(newindex+1>length)
        return false;
    while(oldindex>=0)
    {
        if(string[oldindex]!=' ')
        {
            string[newindex] = string[oldindex];
            newindex--;
            oldindex--;
        }
        else
        {
            string[newindex--] = '0';
            string[newindex--] = '2';
            string[newindex--] = '%';
            oldindex--;
        }
    }
    return true;
}

int main()
{
    const int length = 100;
    char string[length] = "Hello world, I love you.";
    if(replaceBlank(string,length)== true)
        cout<<string<<endl;
    else
       cout<<"not enough space"<<endl;
}
