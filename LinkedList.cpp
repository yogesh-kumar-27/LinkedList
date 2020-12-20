#include <iostream>
#include <stdlib.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};
class List:public Node
{
 
    Node *first,*last;
public:
    List()
    {
        first=NULL;
        last=NULL;
    }
    void create();
   void search();
   void insert();
   void display();
   void Delete();
   void reverse();
   void sort();

};

//creating node
void List::create()
{
    Node *temp;
    temp=new Node;
    cout<<"\nEnter an Element:";
    cin>>temp->data;
    temp->next=NULL;
    if(first==NULL)
    {
        first=temp;
        last=first;
    }
 
    else
    {
        last->next=temp;
        last=temp;
    }
}

//insert 
void List::insert()
{
    Node *prev,*cur;
    prev=NULL;
    cur=first;
    int count=1,pos,ch,n;
    Node *temp=new Node;
    cout<<"\nEnter an Element:";
    cin>>n;
    temp->data=n;
    temp->next=NULL;
    cout<<"\nINSERT AS\n1:FIRSTNODE\n2:LASTNODE\n3:IN BETWEEN FIRST&LAST NODES";
    cout<<"\nEnter Your Choice:";
    cin>>ch;
    switch(ch)
    {
    case 1:
        temp->next=first;
        first=temp;
        break;
    case 2:
        last->next=temp;
        last=temp;
        break;
    case 3:
        cout<<"\nEnter the Position to Insert:";
        cin>>pos;
        while(count!=pos)
        {
            prev=cur;
            cur=cur->next;
            count++;
        }
        if(count==pos)
        {
            prev->next=temp;
            temp->next=cur;
        }
        else
            cout<<"\nNot Able to Insert";
        break;
 
    }
}

//searching
void List::search()
{
  if(first == NULL)
  {
    cout<<"\nList is Empty: ";
    return;
  }
        cout<<"Enter number to be search:: ";
        int value;
        cin>>value;
        int flag;
        Node *temp = first;
        flag = 0;
        while(temp != NULL)
        {
            if(temp->data == value)
            {
              flag = 1;
              break;
            }
              temp = temp ->next;
        }
        if(flag == 1)
        {
          cout<<"value found:";
        }
        else
        {
          cout<<"value not found:";
        }
}


void List::Delete()
{
    Node *prev=NULL,*cur=first;
    int count=1,pos,ch;
    cout<<"\nDELETE\n1:FIRSTNODE\n2:LASTNODE\n3:IN BETWEEN FIRST&LAST NODES";
    cout<<"\nEnter Your Choice:";
    cin>>ch;
    switch(ch)
    {
    case 1:
        if(first!=NULL)
        {
            cout<<"\nDeleted Element is "<<first->data;
            first=first->next;
        }
        else
            cout<<"\nNot Able to Delete";
        break;
    case 2:
        while(cur!=last)
        {
            prev=cur;
            cur=cur->next;
        }
        if(cur==last)
        {
            cout<<"\nDeleted Element is: "<<cur->data;
            prev->next=NULL;
            last=prev;
        }
        else
            cout<<"\nNot Able to Delete";
        break;
    case 3:
        cout<<"\nEnter the Position of Deletion:";
        cin>>pos;
        while(count!=pos)
        {
            prev=cur;
            cur=cur->next;
            count++;
        }
        if(count==pos)
        {
            cout<<"\nDeleted Element is: "<<cur->data;
            prev->next=cur->next;
        }
        else
            cout<<"\nNot Able to Delete";
        break;
    }
}

//sort
void List::sort()
{
  Node *temphead =first;
  Node * tempnode = NULL;
  int temp;
      if(first == NULL)
    {
       return;
    }
      else
      {
            while(temphead != NULL)
            {
             tempnode=temphead->next;
              while(tempnode != NULL)
            {
              if(temphead->data > tempnode->data)
              {
                  temp=temphead->data;
                  temphead->data=tempnode->data;
                  tempnode->data=temp;
              }
              tempnode=tempnode->next;
           }
           temphead=temphead->next; 
       }
    }  

}
//reverse
void List::reverse()
{
  Node *current=first,*previous=NULL;
  if(current == NULL)
  {
    cout<<"list is Empty";
  }
  else
  {
    while(current != NULL)
  {
      next=current->next;
      current->next=previous;

      previous=current;
      current=next;
  }
  first=previous;
  return;
  }
 
}

 
//display the linked list
 void List::display()
 {
   Node *temp = first;
   if(first == NULL)
   {
     cout<<"\nList is Empty:";
     return;
   }
   else 
   {
       while(temp != NULL)
       {
          cout<<temp->data;
          cout<<" -- ";
          temp = temp->next; 
       }
   }

 }



int main()
{
    List l;
    int ch;
    while(1)
    {
        cout<<"\n**** MENU ****";
        cout<<"\n1:CREATE\n2:search\n3:display\n4:Inset\n5:Delet\n6:Sort\n7:Reverse\n8:Exit";
        cout<<"\nEnter Your Choice:";
        cin>>ch;
        switch(ch)
        {
        case 1:
            l.create();
            break;

        case 2:
            l.search();
            break;
        case 3:

            l.display();
            break;

            case 4:
            l.insert();
            break;

            case 5:
            l.Delete();
            break;

            case 6:
            l.sort();

        case 7:
            l.reverse();
            break;
            
             case 8:
        exit(0);
        }
       

    }
    return 0;
}
