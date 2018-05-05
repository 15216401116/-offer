#include<iostream>
using namespace std;
struct node
{
    int data;
    node* next;
    node(int n)
    {
        data = n;
        next = NULL;
    }

};

class linkedList
{
public:
    linkedList()
    {
        head= new node(0);
    }

    ~linkedList()
    {
        
    }

    void addNode(int data)
    {
        node* newNode = new node(data);
        node* nextNode = head->next;
        newNode->next = head->next;
        head->next = newNode;
        head->data= head->data + 1;
    }

    bool removeNode(int data)
    {
        node* current = head->next;
        node* previousNode = head;
        while(current != NULL)
        {
            if (data == current->data)
            {
                previousNode->next = current->next;
                delete current;
                head->data = head->data-1;
                return true;
            }
            else
            {
                previousNode = current;
                current = current->next;
            }
        }
        return false;

    }

    int getLength()
    {
        return head->data;
    }

    void printList()
    {
        node* current = head->next;
        while(current != NULL)
        {
            cout<<current->data<<" ";
            current = current->next;
        }
    }
    void printReverse()
    {
        if(head->next!=NULL)
            printR(head->next);
        else
          cout<<"empty list"<<endl;
    }
    void printR(node* current)
    {
        if( current->next != NULL)
        {
            printR(current->next);
        }
        cout<<current->data<<" ";
    }
    
private:
    node* head;

};

int main()
{
    linkedList ll;
    ll.addNode(1);
    ll.addNode(2);
    ll.addNode(3);
    ll.addNode(4);
    ll.addNode(5);
    ll.addNode(6);
    ll.addNode(7);
    ll.addNode(8);
    ll.addNode(9);
    ll.addNode(10);
    ll.addNode(11);
    ll.addNode(12);
    ll.addNode(13);
    ll.removeNode(7);
    cout<<ll.getLength()<<endl;
    ll.printList();
    cout<<endl;
    ll.printReverse();
}
