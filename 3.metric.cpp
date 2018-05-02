#include<iostream>
using namespace std;
int metric[4][4] = {{1,2,8,9},{2,4,9,12},{4,7,10,13},{6,8,11,15}};
bool find(int input, int x, int y, int m, int n)
{
	if (metric[x][y] == input)
		return true;
	else if(input < metric[x][y] && y > 0)
		return find(input, x, y-1, m, n);
	else if (input > metric[x][y] && x < n)
		return find(input,x+1,y, m, n);
	else return false;
}
int main()
{
	bool output = find(8, 0, 3, 3, 3);
	cout <<output<<endl;
}
