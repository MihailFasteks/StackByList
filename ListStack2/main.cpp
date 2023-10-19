#include <iostream>
#include <string>
using namespace std;

template<class T>
struct Elem
{
    T data;
    Elem<T>* next, * prev;
};
template<class T>
class List
{
    Elem<T>* Head, * Tail;
    int Count;
    int MaxSize=20;
public:
    List();
    List(const List&);
    ~List();
    void DelAll();
    void Del();
    void AddTail(T n);
    void Print();
};
template<class T>
List<T>::List()
{
    Head = Tail = NULL;
    Count = 0;
}
template<class T>
List<T>::List(const List<T>& L)
{
    Head = Tail = NULL;
    Count = 0;
    Elem<T>* temp = L.Head;
    while (temp != 0)
    {
        AddTail(temp->data);
        temp = temp->next;
    }
}
template<class T>
List<T>::~List()
{
    DelAll();
}

template<class T>
void List<T>::AddTail(T n)
{
    if (Count<MaxSize)
    {
        Elem<T>* temp = new Elem<T>;
        temp->next = 0;
        temp->data = n;
        temp->prev = Tail;
        if (Tail != 0)
            Tail->next = temp;
        if (Count == 0)
            Head = Tail = temp;
        else
            Tail = temp;

        Count++;
    }
    else
    {
        cout<<"Stack overfloat!"<<endl;
    }
    
}
template<class T>
void List<T>::Del()
{
   if (Count>=0)
   {
       Elem<T>* temp=Tail;
       Tail=temp->prev;
       delete temp;
       Count--;
   }
 
}
template<class T>
void List<T>::DelAll()
{
    
    while (Count != 0)
        Del();
}

template<class T>
void List<T>::Print()
{
    int tempCount=Count;
    Elem<T>* temp = Head;
    while (tempCount > 0)
    {
        
            cout << temp->data << ", ";
            temp = temp->next;
        tempCount--;
    }

}


int main()
{
    List <string> q;
    q.AddTail("Alex");
    q.AddTail("Tom");
    q.AddTail("Crus");
    cout<<endl;
    q.Print();
    cout<<endl;
    q.Del();
    q.Print();
    cout<<endl;
    return 0;
}
