/*Se consideră două numere reprezentate într-o listă înlăntuită în care fiecare nod reprezintă o cifră. Cifrele sunt retinute în
ordine inversă astfel încât cifra unităttilor să fie stocată la începutul listei . Să se scrie un
program C/C++ care să calculeze suma acestor numere.*/

#include <iostream>
#include <fstream>
using namespace std;

struct Node
{
    unsigned int valoare;
    Node *next;
};
void afisare_lista(Node *x)
{
    cout<<endl;
    while(x!=nullptr)
    {
        cout<<x->valoare<<" ";
        x=x->next;
    }
}
long long int calculare_numar(Node *x)
{
    long long int numar=0;
    int p=1;
    while(x!=nullptr)
    {
        numar=numar+(x->valoare)*p;
        p*=10;
        x=x->next;
    }
    return numar;
}
int main()
{
    Node *head_x;
    Node *head_y;
    long long int x,y;
    int n;
    Node *p_node;
    unsigned int cifra;
//citire Lista1
    ifstream f("date.in");
    f>>n;
    head_x=new Node();
    f>>cifra;
    head_x->valoare=cifra;
    head_x->next=nullptr;
    p_node=head_x;
    for (int i=0;i<n-1;i++)
    {
        Node *curent;
        f>>cifra;
        curent=new Node();
        curent->valoare=cifra;
        curent->next=nullptr;
        p_node->next=curent;
        p_node=curent;
    }
//citire lista2
    f>>n;
    head_y=new Node();
    f>>cifra;
    head_y->valoare=cifra;
    head_y->next=nullptr;
    p_node=head_y;
    for (int i=0;i<n-1;i++)
    {
        Node *curent;
        f>>cifra;
        curent=new Node();
        curent->valoare=cifra;
        curent->next=nullptr;
        p_node->next=curent;
        p_node=curent;
    }
    x=calculare_numar(head_x);
    y=calculare_numar(head_y);
    cout<<endl<<x+y;
    return 0;
}
