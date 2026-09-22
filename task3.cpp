#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node *next;
   Node(int value)
   {
    data=value;
    next=NULL;
   } 
};
class List{
    Node* first;
    Node* last;
    public:
    List()
    {
        first=last=NULL;
    } 
    void insertAtHead(int val)
{
    Node* newNode=new Node(val);
    if(first==NULL)
    {
        first=last=newNode;
        return;
    }
    else
    {
        newNode->next=first;
        first=newNode;
    }
}
void insertAtThird(int val)
{
    if (first == NULL || first->next == NULL)
    {
        cout << "At least two nodes are required.\n";
        return;
    }
    Node* temp = first->next; 
    Node* newNode = new Node(val);

    newNode->next = temp->next;
    temp->next = newNode;
}
void displayList()
{
    Node* temp=first;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}
void deleteLast()
{
    if (first == NULL)
    {
        return;
    }
    if (first == last)
    {
        delete first;
        first = last = NULL;
        return;
    }
    Node* temp = first;
    while (temp->next != last)
    {
        temp = temp->next;
    }
    delete last;
    last = temp;
    last->next = NULL;
}
int countNodes()
{
    int count = 0;
    Node* temp = first;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}
void reverseList()
{
    Node* previous = NULL;
    Node* current = first;
    Node* nextNode = NULL;
    last = first; 
    while (current != NULL)
    {
        nextNode = current->next;
        current->next = previous; 
        previous = current; 
        current = nextNode;
    }
    first = previous;
}
int search(int val)
{
    Node* temp = first;
    int position = 1;
    while (temp != NULL)
    {
        if (temp->data == val)
        {
            return position;
        }
        temp = temp->next;
        position++;
    }
    return -1;
}
};

int main()
{
    List ll;
    int option;
    do{
        cout<<"---------------Menu--------------------\n";
        cout<<"1:Insert at Head position.\n";
        cout<<"2:Insert at Third position.\n";
        cout<<"3:Display the results.\n";
        cout<<"4:Delete last position.\n";
        cout<<"5:Count all the number of nodes.\n";
        cout<<"6:Reverse the linked list.\n";
        cout<<"7:Search for an index.\n";
        cout<<"0:Exit the program.\n";

        cout<<"Enter the option of operation you want to perform.If you want to exit the program, Enter 0.\n";

        cin>>option;

        if(option==1)
        {
            int val;
            cout<<"Enter the value: ";
            cin>>val;
            ll.insertAtHead(val);
        }
        else if(option==2)
        {
            int val;
            cout<<"Enter the value: ";
            cin>>val;
            ll.insertAtThird(val);
        }
        else if(option==3)
        {
            ll.displayList();
            cout<<endl;
        }
        else if(option==4)
        {
            ll.deleteLast();
        }
        else if(option==5)
        {
            cout<<"Total nodes: "<<ll.countNodes()<<endl;
        }
        else if(option==6)
        {
            ll.reverseList();
        }
        else if(option==7)
        {
            int val;
            cout<<"Enter the value to search: ";
            cin>>val;

            int position=ll.search(val);

            if(position==-1)
            {
                cout<<"Value not found.\n";
            }
            else
            {
                cout<<"Value found at position: "<<position<<endl;
            }
        }
        else if( option==0)
        {
            cout<<"Exiting the program.\n";
        }
        else
        {
            cout<<"Invalid option.\n";
        }

    }while(option!=0);
}