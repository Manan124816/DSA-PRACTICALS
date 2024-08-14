#include<iostream>
using namespace std;

struct Node{
int data;

Node *next;

}*start = nullptr;

void createLL()
{
int data;
cout<<"Enter the data to be get enterd into LL(for existing the LL press -1)"<<endl;
cin>>data;

while(data != -1)
{
    Node *newnode,*ptr;

    newnode = new Node;
    newnode ->data = data;
    newnode ->next = nullptr;

    if(start == nullptr) //it will check if list is empty or not.
    {
        start = newnode;
    }
    else // if the list is not empty then it will make the entered node at last of the list
    {
       ptr = start; //we will provide the address of start to the ptr pointer.
       while(ptr ->next != nullptr) // it will run until it find the lastnode of LL.
       {
           ptr = ptr->next;
       }
       ptr ->next = newnode;
    }
    cout<<"Enter the data to be get enterd into LL(for existing the LL press -1)"<<endl;
    cin>>data;

}

}
void display()
{
    if(start == nullptr)
    {
        cout<<"The Linked List is empty"<<endl;
    }
    else
    {
        Node *ptr;
        ptr = start;
        while(ptr != nullptr)
        {
            cout<<ptr->data<<"-->";
            ptr = ptr->next;
        }
        cout<<endl;
    }
}

void enterff()
{
    int data;
    cout<<"Enter the data to be get enterd into LL(for existing the LL press -1)"<<endl;
    cin>>data;


    Node* newnode = new Node;
    newnode->data = data;
    newnode->next = start;
    start = newnode;
}
 void enterfl(){
    int data;
    Node *newnode = new Node;
    Node *ptr;
    cout<<"\n Enter a data here:::";
    cin>>data;
    newnode->data = data;
    newnode->next = nullptr;
    if(start == nullptr){
            start = newnode;
    }
    else{
        ptr = start;
        while(ptr->next  != nullptr){
                ptr = ptr->next;
        }
        ptr->next = newnode;
    }
}

void deleteff()
{


  if(start == nullptr)
    {
        cout<<"The Linked List is empty"<<endl;
    }
    else
    {
         Node *ptr = start;
         start = start->next;
         delete ptr;
    }

}
void deletefl()
{
     if(start == nullptr)
    {
        cout<<"The Linked List is empty"<<endl;
    }
    else
    {
         Node *ptr ,*prev;
         if(start->next == nullptr)
         {
             ptr = start;
             start = nullptr;
             delete ptr;
         }
         else
         {
            ptr = start;
            while(ptr->next != nullptr)
            {
                prev = ptr;
                ptr = ptr->next;
            }
            prev->next = nullptr;
            delete ptr;

         }
    }
}
void printinreverse(Node *node)
{
   if(node == nullptr)
   {
       return;
   }
   printinreverse(node->next);
    cout << node->data << "->";

}
void insertAtNth(Node *start,int data,int position)
{
    if(position == 1)
    {
        enterff();
    }
    else
    {
        Node *ptr = start;
        for(int i=0;i<position-1;i++)
        {
            ptr = ptr->next;
        }

        Node *temp = new Node;
        temp->data = data;
        temp->next = ptr->next;
        ptr->next = temp;
    }
}
int main(){
    int n;
    cout<<":::::::::::::MENU:::::::::::::::"<<endl;
    cout<<"\n Choose from the following: \n 1) CREATE LINKED LIST \n 2) PRINT LINKED LIST \n 3) INSERT FROM FRONT \n 4) INSERT FROM LAST \n 5) DELETE FROM FRONT \n 6) DELETE FROM LAST \n 7)PRINT IN REVERSE \n 8) SORT \n 9) INSERT AT NTH POSITION \n 10)REVERSE LL \n 11) EXIT(-1): ";
    cin>>n;

    while(n!=-1){
        switch(n){
        case 1:
            createLL();
            break;
        case 2:
           display();
            break;
        case 3:
            enterff();
            break;
        case 4:
            enterfl();
            break;
        case 5:
            deleteff();
            break;
        case 6:
            deletefl();
            break;
        case 7:
            printinreverse(start);
            break;
        case 8:
            //sortll();
            break;
        case 9:
            cout << endl<< "Enter the Position (nth) : ";
            int position,data;
            cin >> position;
            cout << "Enter the value : ";
            cin >> data;
            insertAtNth(start, data, position);
            break;
        case 10:
           // reverseLinkedList(start);
            break;
        }
        cout<<":::::::::::::MENU:::::::::::::::"<<endl;
        cout<<"\n Choose from the following:\n 1) CREATE LINKED LIST \n 2) PRINT LINKED LIST \n 3) INSERT FROM FRONT \n 4) INSERT FROM LAST \n 5) DELETE FROM FRONT \n 6) DELETE FROM LAST \n 7)PRINT IN REVERSE \n 8) SORT \n 9) INSERT AT NTH POSITION \n 10)REVERSE LL \n 11) EXIT(-1): ";
        cin>>n;
}

}
