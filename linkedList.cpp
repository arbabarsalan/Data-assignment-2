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

    void insertAtHead()
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
            nN->next = head;
            head = nN;
        }
    }

    void insertAtEnd()
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

    void deleteFromHead(){
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

    void deleteFromEnd(){
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
            while(temp->next!=tail){
                temp=temp->next;
            }
            delete tail;
            tail=temp;
            temp=NULL;
            tail->next=NULL;
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
    while (choise != 5)
    {   cout<<"********************< Singly LinkedList >*************************************"<<endl;
        cout << " Enter Choise " << endl;
        cout << " (1) insert at Head " << endl;
        cout << " (2) insert at End " << endl;
        cout << " (3) Delete from Head " << endl;
        cout << " (4) Delete From End " << endl;
        cout << " (5) Exit " << endl;
        cout<<" (6) Display "<<endl; 

        cin >> choise;

        switch (choise)
        {
        case 1:
            int x;
            cout << "Enter no of nodes you want to add " << endl;
            cin >> x;
            for (int i = 0; i < x; i++)
            {
                aa.insertAtHead();
            }

            break;
        case 2:
            cout << "Enter no of nodes you want to add " << endl;
            cin >> x;
            for (int i = 0; i < x; i++)
            {
                aa.insertAtEnd();
            }
            break;
        case 3:
            cout << "Enter no of nodes you want to delete " << endl;
            cin >> x;
            for (int i = 0; i < x; i++)
            {
                aa.deleteFromHead();
            }

            break;
        case 4:
            cout << "Enter no of nodes you want to delete " << endl;
            cin >> x;
            for (int i = 0; i < x; i++)
            {
                aa.deleteFromEnd();
            }
            break;
        case 5:

            cout << " Exiting.... ";
            break;
        case 6:
        aa.display();
        break;

        default:
            cout << "invalid input! ";
            break;
        }
    }

    return 0;
}