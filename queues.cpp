#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;
    node(int val) : next(NULL), data(val) {}
};

class LinkedList
{
public:
    node *head;
    node *tail;

    LinkedList() : head(NULL), tail(NULL) {}

    bool isEmpty()
    {
        return head == NULL;
    }


    void Enqueue()
    {
        int val;
        cout << "Enter Data " << endl;
        cin >> val;
        node *nN = new node(val);

        if (isEmpty())
        {
            head = tail = nN;
        }
        else
        {
            tail->next = nN;
            tail = nN;
        }
    }

    void Dequeue(){
        if(isEmpty()){
            cout<<" LinkedList is empty!!!"<<endl;
            return;
        }
        else if(head==tail){
            delete head;
            head=tail=NULL;
        }
        else{
            node* temp =head;
            head=head->next;
            delete temp;
            temp=NULL;
        }
    }



    void display()
    {
        if(isEmpty()){
            cout<<" LinkedList is empty!!!"<<endl;
            return;
        }
        node *temp = head;
        while (temp)
        {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout<<endl;
    }
};

int main()
{
   LinkedList aa;

    int choise = 0;

    while (choise != 4)
    {
        cout << "************************< Queue >*********************************" << endl;
        cout << " Enter Choise " << endl;
        cout << " (1) Enqueue " << endl;
        cout << " (2) Dequeue " << endl;
        cout << " (3) Display " << endl;
        cout << " (4) Exit " << endl;
        cin>>choise;

        switch (choise)
        {
        case 1:
            aa.Enqueue();

            break;

        case 2:

            aa.Dequeue();

            break;
        case 3:
            aa.display();
            break;
        case 4:

            cout << " Exiting.... ";
            break;

        default:
            cout << "invalid input! "<<endl;
            break;
        }
    }
    return 0;
}