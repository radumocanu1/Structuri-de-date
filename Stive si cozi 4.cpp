/*Un depou feroviar constă dintr-o linie ferată de intrare, 3 linii auxiliare de depozitare si o linie de iesire. Fiecare linie operează pe un sistem de coadă (FIFO).
În plus, vagoanele se pot deplasa doar dinspre linia de intrare spre linia de iesire.
Să se scrie un program care, dat un sir de vagoane pe linia de intrare (numerotate de la 1 la
n si aranjate în orice ordine), descrie o strategie de a obtine pe linia de iesire sirul de vagoane
n; n - 1;... ; 2; 1, folosind liniile de depozitare. În caz că nu există o astfel de strategie, se va
afisa acest lucru.. */

#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
struct Node
{
    int valoare;
    Node *next;
};
Node *Rear_1=nullptr;
Node *Front_1;
Node *Rear_2=nullptr;
Node *Front_2;
Node *Rear_3=nullptr;
Node *Front_3;
void push_1 (int valoare)
{
    Node *curent;
    curent=new Node();
    curent->valoare=valoare;
    curent->next=nullptr;
    if (Rear_1==nullptr)
        Front_1=curent;
    else
        Rear_1->next=curent;
    Rear_1=curent;
}
void pop_1 ()
{
    Node *temp;
    temp=Front_1;
    cout<<Front_1->valoare<<" ";
    Front_1=Front_1->next;
    delete temp;
    if (Front_1==nullptr)
        Rear_1=nullptr;
}
void push_2 (int valoare)
{
    Node *curent;
    curent=new Node();
    curent->valoare=valoare;
    curent->next=nullptr;
    if (Rear_2==nullptr)
        Front_2=curent;
    else
        Rear_2->next=curent;
    Rear_2=curent;
}
void pop_2 ()
{
    Node *temp;
    temp=Front_2;
    cout<<Front_2->valoare<<" ";
    Front_2=Front_2->next;
    delete temp;
    if (Front_2==nullptr)
        Rear_2=nullptr;
}
void push_3 (int valoare)
{
    Node *curent;
    curent=new Node();
    curent->valoare=valoare;
    curent->next=nullptr;
    if (Rear_3==nullptr)
        Front_3=curent;
    else
        Rear_3->next=curent;
    Rear_3=curent;
}
void pop_3 ()
{
    Node *temp;
    temp=Front_3;
    cout<<Front_3->valoare<<" ";
    Front_3=Front_3->next;
    delete temp;
    if (Front_3==nullptr)
        Rear_3=nullptr;
}
void afisare_coada( Node *Front)
{
    Node *it;
    it=Front;
    cout<<endl;
    while (it!=nullptr)
    {
        cout<<it->valoare<<" ";
        it=it->next;
    }


}
bool cmp (int a, int b)
{
    return (a<b);
}
int main() {
    int ultimul_1=0,ultimul_2=0,ultimul_3=0, ok=1;
    ifstream f ("date.txt");
    int x;
    while (f>>x)
    {
        if (x>ultimul_1)
        {
            push_1(x);
            ultimul_1=x;
        }
        else if (x>ultimul_2)
        {
            push_2(x);
            ultimul_2=x;
        }
        else if (x>ultimul_3)
        {
            push_3(x);
            ultimul_3=x;
        }
        else
        {
            ok=0;
            break;
        }
    }
    if (ok==0)
    {
        cout<<"Trenurile nu pot fi aranjate convenabil";
    }


    else

    //afisarea ordinii de iesire a trenurilor este redundanta (fiind o singura ordine acceptata), insa e o alta verificare ca programul functioneaza

    {
        cout<<"Trenurile pot fi aranjate convenabil, iar ordinea lor este: "<<endl;
        while (Front_1!=nullptr && Front_2!=nullptr && Front_3!=nullptr)
        {
            if (min({Front_1->valoare,Front_2->valoare,Front_3->valoare},cmp)==Front_1->valoare)
                pop_1();
            else if (min({Front_1->valoare,Front_2->valoare,Front_3->valoare},cmp)==Front_2->valoare)
                pop_2();
            else
                pop_3();
        }
        if (Front_1==nullptr)
        {
            Front_1=Front_3;
            Rear_1=Rear_3;
        }
        else if (Front_2==nullptr)
        {
            Front_2=Front_3;
            Rear_2=Rear_3;
        }

        while (Front_1!=nullptr && Front_2!=nullptr)
            if (min(Front_1->valoare, Front_2->valoare)==Front_1->valoare)
                pop_1();
            else
                pop_2();
        if (Front_1!=nullptr)
            while(Front_1!=nullptr)
                pop_1();
        else
            while(Front_2!=nullptr)
                pop_2();


    }
    f.close();
    return 0;
}
