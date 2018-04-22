// implementation with mutex
#include<iostream>
#include<pthread.h>
using namespace std;
pthread_mutex_t mutex;
class Singletion
{
public:
    static Singletion* getInstance()
    {
        if (_instance == NULL)
        {
            pthread_mutex_lock(&mutex);
            if (_instance == NULL)
            {
                _instance = new Singletion();
            }
            pthread_mutex_unlock(&mutex);
        }
        return _instance;
    }
private:
    Singletion()
    {
        cout<<"Constructor"<<endl;
    }
    Singletion(const Singletion&)
    {
        cout<<"Copy Constructor"<<endl;
    }
    Singletion& operator = (const Singletion&)
    {
        cout<<"operator = "<<endl;
    }
    ~Singletion()
    {
        cout<<"Destructor"<<endl;
    }
    static Singletion* _instance;
};

Singletion* Singletion::_instance = NULL;

int main()
{
    Singletion* instance = Singletion::getInstance();
    Singletion* a_instance = Singletion::getInstance();
}
