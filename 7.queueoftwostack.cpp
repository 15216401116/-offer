#include<iostream>
#include<stack>
using namespace std;

class CQueue
{
public:
    CQueue(void)
    {}
    ~CQueue(void)
    {}
    void appendTail(int node)
    {
        stack1.push(node);
    }
    int deleteHead()
    {
        if(!stack2.empty())
        {
            int node = stack2.top();
            stack2.pop();
            return node;
        }
        else if(!stack1.empty())
        {
            while(!stack1.empty())
            {
                int node = stack1.top();
                stack1.pop();
                stack2.push(node);
            }
            int node = stack2.top();
            stack2.pop();
            return node;
        }
        else
        {
            return -1;
        }

    }
private:
    stack<int> stack1;
    stack<int> stack2;

};
int main()
{

    CQueue queue;
    queue.appendTail(1);
    queue.appendTail(2);
    queue.appendTail(3);
    int i =0;
    while(i<3)
    {
        int r1 = queue.deleteHead();
        cout<<r1<<" ";
        i++;
    }
    queue.appendTail(4);
    queue.appendTail(5);
    queue.appendTail(6);
    queue.appendTail(7);
    queue.appendTail(8);
    queue.appendTail(9);
    while(i<20)
    {
        int r1 = queue.deleteHead();
        cout<<r1<<" ";
        i++;
    }
}
