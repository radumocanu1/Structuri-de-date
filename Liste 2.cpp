/*Să se implementeze un program care realizează s,tergerea unui nod
din interiorul unei liste simplu înlănt,uite, oferindu-se acces numai la nodul respectiv.
*/
#include <iostream>
#include <fstream>
using namespace std;
struct Node
{
    int valoare;
    Node *next;
} ;
Node *citire_lista()
{
    ifstream f("date.in");
    Node *head, *p_node,*curent;
    int x;
    f>>x;
    head=new Node();
    head->valoare=x;
    head->next=nullptr;
    p_node=head;
    while(f>>x)
    {
        curent=new Node();
        curent->valoare=x;
        p_node->next=curent;
        curent->next=nullptr;
        p_node=curent;



    }
    return head;
}
void afisare_lista (Node *x)
{
    while(x!=nullptr)
    {
        cout<<x->valoare<<" ";
        x=x->next;
    }
}
void stergere_nod (Node *x)
{
    if (x->next!=nullptr)
    {
        Node *temp;
        x->valoare=x->next->valoare;
        temp=x->next;
        x->next=x->next->next;
        delete temp;
    }
    else
    {
       x=nullptr;
    }

}
int main()
{

    Node *head;
    head=citire_lista();
    afisare_lista(head);
    cout<<endl<<"Ce element doriti sa stergeti?";
    int x;
    cin>>x;
    Node *it;
    it=head;
    while(it->valoare!=x)
        it=it->next;
    stergere_nod(it);
    afisare_lista(head);



    return 0;

}
