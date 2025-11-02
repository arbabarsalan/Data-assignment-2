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

    void push(int val)
    {

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

    void pop()
    {
        if (isEmpty())
        {
            cout << " LinkedList is empty!!!" << endl;
            return;
        }
        else if (head == tail)
        {
            delete head;
            head = tail = NULL;
        }
        else
        {
            node *temp = head;
            while (temp->next != tail)
            {
                temp = temp->next;
            }
            delete tail;
            tail = temp;
            temp = NULL;
            tail->next = NULL;
        }
    }

    void display()
    {
        if (isEmpty())
        {
            cout << " LinkedList is empty!!!" << endl;
            return;
        }
        node *temp = head;
        while (temp)
        {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << endl;
    }

    int top()
    {
        return tail->data;
    }

    void isValidParenthisis()
    {    
        bool istrue=true;
         int arr[6] = {'(', '{', '[', ']', '}', ')'};
          int size=6;

        for (int i = 0; i < size; i++)
        {
            if ((arr[i] == '(') || (arr[i] == '[') || (arr[i] == '{'))
            {
                push(arr[i]);
            }
            else
            {
                if (isEmpty())
                {
                      istrue= false;
                }
            

            if ((top() == '(' && arr[i] == ')') ||
                (top() == '{' && arr[i] == '}') ||
                (top() == '[' && arr[i] == ']'))
            {
                pop();
            }
            else
            {
                istrue= false;
            }
        }
    }
        if (isEmpty()){
            istrue= true;
        }
        else{
              istrue= false;
        }


         if (  istrue)
    {
        cout << " valid " << endl;
    }
    else
    {
        cout << "invalid " << endl;
    }


    }

    void nextGreater(){
       
        int arr[5]={9,4,7,3,2};
        int size=5;
        int ans[size]{0,0,0,0,0};
        
        for(int i=size-1;i>=0;i--){

            while( !isEmpty() && top()<=arr[i]){
                pop();
            }

            if(isEmpty()){
                ans[i]=-1;
            }
            else{
                ans[i]=top();
            }
            push(arr[i]);
        }

        for(int i=0;i<size;i++){
            cout<<ans[i]<<" ";
        }
    }
};

int main()
{
    LinkedList aa;

    // int choise = 0;

    // while (choise != 4)
    // {
    //     cout << "*************************< Stack >********************************" << endl;
    //     cout << " Enter Choise " << endl;
    //     cout << " (1) Push " << endl;
    //     cout << " (2) POP" << endl;
    //     cout << " (3) Display " << endl;
    //     cout << " (4) Exit " << endl;
    //     cin>>choise;

    //     switch (choise)
    //     {
    //     case 1:
    //     cout<<"enetr value";
    //     int val;
    //     cin>>val;
    //         aa.push( val);

    //         break;

    //     case 2:

    //         aa.pop();

    //         break;
    //     case 3:
    //         aa.display();
    //         break;
    //     case 4:

    //         cout << " Exiting.... ";
    //         break;

    //     default:
    //         cout << "invalid input! "<<endl;
    //         break;
    //     }
    // }

    

  //  aa.isValidParenthisis();

    aa.nextGreater();

    return 0;
}