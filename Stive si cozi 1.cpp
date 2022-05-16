/*O coadă cu priorităti este o coadă în care
elementele au, pe lângă cheie şi o prioritate. Vom presupune că cea mai înaltă prioritate este
1, urmată de 2 etc. Ordinea liniară este dată de regulile:
• elementele cu aceeaşi prioritate sunt extrase (şi procesate) în ordinea intrării;
• toate elementele cu prioritate i se află înaintea celor cu prioritate i+1 (şi deci vor fi
extrase înaintea lor).
Implementati operatiile de inserare si de stergere pentru acest tip de structură.*/

#include <iostream>

using namespace std;

struct Node
{
    int data;
    int prioritate;
    Node *next;
};
Node *Rear;
Node *Front;
void adaugare (int valoare,int prioritate)
{
    Node *curent;
    curent=new Node();
    curent->data=valoare;
    curent->prioritate=prioritate;
    curent->next=nullptr;
    if (Rear==nullptr)
    {
        Front=curent;
        Rear=curent;
    }

    else
        {

            Node *it;
            Node *p_node;
            int nr=0;
            p_node=nullptr;;
            it=Front;
            while (curent->prioritate>=it->prioritate && it->next!=nullptr)
            {
                nr=1;
                p_node=it;
                it=it->next;
            }




                if (it->next==nullptr && curent->prioritate>it->prioritate)
            {
                Rear->next=curent;
                Rear=curent;

            }
            else if (nr==0)
            {
                curent->next=Front;
                Front=curent;
            }
            else
            {
                p_node->next=curent;
                curent->next=it;
            }
        }

}
void stergere ()
{
    if (Front==nullptr)
        cout<<endl<<"Coada nu contine niciun element";
    else
    {
        Node *temp;
        temp=Front;
        Front=Front->next;
        delete temp;
        if (Front==nullptr)
            Rear=nullptr;

    }
}
void afisare (Node *Front)
{
    Node *it;
    it=Front;
    while (it!=nullptr)
    {
        cout<<it->data<<" cu prioritate " <<it->prioritate<<endl;
        it=it->next;
    }
}
int main()
{

    Rear=nullptr;
    Front=nullptr;
    adaugare(6,2);
    adaugare(5,1);
    adaugare(7,5);
    adaugare(12,0);
    adaugare(8,4);
    adaugare(9,4);
    adaugare(10,0);
    adaugare(11,0);
    afisare(Front);
    stergere();
    stergere();
    cout<<endl;
    afisare(Front);



    return 0;
}
