#include<iostream>
#include<iomanip>
using namespace std;
void oneCirclePrint(int** metric, int row, int col, int start)
{
    //topleft->topright
    int curX=start;
    int curY=start;
    while(curY<col-start)
    {
        cout<<metric[curX][curY]<<" ";
        curY++;
    }
    //topright->bottomright
    curX++;
    curY--;
    while(curX<row-start)
    {
        cout<<metric[curX][curY]<<" ";
        curX++;
    }
    //bottomright->bottomleft
    curY--;
    curX--;
    while(curY>=start)
    {
        cout<<metric[curX][curY]<<" ";
        curY--;
    }
    //bottomleft->topleft
    curX--;
    curY++;
    while(curX>start)
    {
        cout<<metric[curX][curY]<<" ";
        curX--;
    }

    
}

void clockwisePrintMetric(int** metric,int row, int col)
{
    cout<<"original metric:"<<endl;
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            cout<<setw(3)<<metric[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"clockwisePrintMetric:"<<endl;
    if ((metric==NULL)||(row <=0)||(col<=0))
    {
        return;
    }
    int start=0;
    while((start*2<row)&&(start*2<col))
    {
        oneCirclePrint(metric,row,col,start);
        start++;

    }
    cout<<endl;
}
int main()
{
    int metric[4][4]={{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
    int** m = new int*[4];
    for(int i=0;i<4;i++)
    {
        m[i]=new int[4];
    }
    m[0][0]=1;
    m[0][1]=2;
    m[0][2]=3;
    m[0][3]=4;
    m[1][0]=5;
    m[1][1]=6;
    m[1][2]=7;
    m[1][3]=8;
    m[2][0]=9;
    m[2][1]=10;
    m[2][2]=11;
    m[2][3]=12;
    m[3][0]=13;
    m[3][1]=14;
    m[3][2]=15;
    m[3][3]=16;
    clockwisePrintMetric(m, 4, 4);
}
