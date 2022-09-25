#include<bits/stdc++.h>
using namespace std;

//class to create doubly linked list node
class Node
{
    public:

    string name;
    int age;
    Node* aft;
    Node* bef;

    Node(string name, int age)
    {
        this->name = name;
        this->age = age;
        aft = NULL;
        bef = NULL;
    }
};

//function to create a node
Node* create(string *name, int *age, int members)
{
    Node* curr=NULL;
    Node* bef_ = NULL;
    Node* aft_ = NULL;
    Node* head = NULL;
    for(int i=0;i<members;i++)
    {
        
        curr = new Node(name[i],age[i]);
        if(head==NULL)   //checks if linked list is currently empty
        {
            head = curr;
        }
        curr->bef = bef_;
        if(bef_!=NULL)
        {
            bef_->aft = curr;
        }
        bef_ = curr;
    }

    return head;
}

//function to add name and age to linked list head node 
void add(Node* head, int age, string name)
{
    Node* nh = new Node(name, age);
    nh->aft = head;
    head->bef = nh;
    head = nh;
}

//function to print contents of linked list node
void print(Node* head)
{
    while(head!=NULL)
    {
        cout<<head->name<<" "<<head->age<<endl;
        head = head->aft;
    }
}


//main function which takes user input
int main()
{
    int n;
    cout<<"Number of members in family: ";
    cin>>n;

    int *age = new int[n];
    string *name = new string[n];

    cout<<"Enter family member relation and ages"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>name[i]>>age[i];
    }
    Node* head = create(name, age, n);
    cout<<"\n";
    cout<<"Relation Age "<<"\n";
    print(head);
return 0;
}
