#include<bits/stdc++.h>
using namespace std;

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

void add(Node* head, int age, string name)
{
    Node* nh = new Node(name, age);
    nh->aft = head;
    head->bef = nh;
    head = nh;
}

void print(Node* head)
{
    while(head!=NULL)
    {
        cout<<head->name<<" "<<head->age<<endl;
        head = head->aft;
    }
}

Node* create(string *name, int *age, int members)
{
    Node* curr=NULL;
    Node* bef_ = NULL;
    Node* aft_ = NULL;
    Node* head = NULL;
    for(int i=0;i<members;i++)
    {
        
        curr = new Node(name[i],age[i]);
        if(head==NULL)
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

int main()
{
    int n;
    cout<<"Number of members in family: ";
    cin>>n;

    int *age = new int[n];
    string *name = new string[n];

    cout<<"Enter name of family member and ages"<<endl;
    for(int i=0;i<n;i++)
    {
        //cout<<"Enter details of member :";
        cin>>name[i]>>age[i];
    }
    Node* head = create(name, age, n);
    cout<<"Family member Details :"<<"\n";
    print(head);
return 0;
}