
/* Considerăm următoarea problemă: ni se dă o suprafată circulară
cu un număr n de pini (tărusi) pe margini (numerotati de la 1 la n), împreună cu o listă de
perechi de pini ce trebuie conectati cu fire metalice. Problema cere să determinati în timp
O(n) dacă pentru o configuratie ca mai sus, pinii pereche pot fi conectati, fără ca perechile
să se intersecteze. La intrare se vor citi:
• n - numărul de pini
• pereche[n], un vector de n componente, unde pereche[i] == pereche[j], 1 <= i < j <=
n dacă pinii i s, i j trebuie conectat, i */

#include <iostream>
#include <fstream>
using namespace std;
struct Node
{
    int valoare;

    Node *next;
}*Top;
void push(int valoare)
{
    Node *curent;
    curent=new Node();
    curent->valoare=valoare;
    curent->next=Top;
    Top=curent;
}
void pop()
{
    Node *temp;
    temp=Top;
    Top=Top->next;
    delete temp;

}
int main() {
    Top=nullptr;
    ifstream f("date.txt");
    int n, *pereche,nr=0,suma=0,elemente,ok=1;
    f>>n;
    pereche=new int[n/2];
    for (int i=0;i<n;i++)
    {
        f>>pereche[i];
        suma+=pereche[i];
        push(pereche[i]);
        if (pereche[i]<nr)
        {
            elemente=0;
            while (Top!=nullptr)
            {
                pop();
                elemente++;
            }
            if ((nr-pereche[i]+1)*2!=elemente)
            {
                ok=0;
                break;
            }

        }
        else
            nr=pereche[i];

    }
    if (ok==1)
        cout<<"Valid";
    else
        cout<<"Invalid";


    return 0;
}
