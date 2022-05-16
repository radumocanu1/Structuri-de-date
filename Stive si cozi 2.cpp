/* Se consideră un string s reprezentând o expresie validă formată din numere si ’+’, ’-’, ’(’, ’)’, ’ ’. Implementati un calculator pentru evaluarea expresiei s, i returnat, i
rezultatul. Atentie! ’+’ nu este folosit ca
operatie unară (i.e., +1 s, i +(2 + 3) sunt invalide). ’-’ poate fi folosit ca operatie unară (i.e.,
−1 s, i −(2 + 3) sunt valide). */


#include <iostream>
#include <cstring>
using namespace std;
int rezultat=0;
struct Node
{
    string operatie;
    int valoare=0;
    Node *next;
}*rear, *front;
Node* paranteza(Node *it)
{

    int rez=0;
    while (it->operatie[0]!=')')
    {
        if (it->valoare!=0)
            rez+=it->valoare;
        else
        {
            if (it->operatie[0]=='-')
            {
                if (it->next->valoare!=0)
                {
                    rez = rez - it->next->valoare;
                    it = it->next;
                }
                else
                {

                    it=paranteza(it->next->next);
                    rez=rez-it->valoare;
                }

            }
            else if (it->operatie[0]=='+')
            {
                if (it->next->valoare != 0)
                {
                    rez = rez + it->next->valoare;
                    it = it->next;
                }
                else
                {

                    it = paranteza(it->next->next);
                    rez = rez + it->valoare;
                }
            }
            }
        it=it->next;
    }

    it->valoare=rez;
    return it;
}
void calculeaza(Node *front)
{
    Node *it;
    it=front;
    while(it!=nullptr)
    {

        if (it->valoare!=0)
            rezultat+=it->valoare;
        else
        {
            if (it->operatie[0]=='-')
            {
                if (it->next->valoare!=0)
                {

                    rezultat=rezultat-it->next->valoare;
                    it=it->next;
                }
                else
                {

                    it=paranteza(it->next->next);
                    rezultat=rezultat-it->valoare;


                }

            }
            if (it->operatie[0]=='+')
            {
                if (it->next->valoare!=0)
                {
                    rezultat=rezultat+it->next->valoare;
                    it=it->next;
                }
                else
                {

                    it=paranteza(it->next->next);
                    rezultat=rezultat+it->valoare;


                }


            }

        }
        it=it->next;
    }
    cout<<endl<<rezultat;
}
void insert (char operatie)
{

    Node *curent=new Node();
    curent->operatie=operatie;
    curent->next=nullptr;
    if (rear==nullptr)
        front=curent;
    else
        rear->next=curent;
    rear=curent;

}
void insert( unsigned int valoare)
{
    Node *curent=new Node();
    curent->valoare=valoare;
    curent->next=nullptr;
    if (rear==nullptr)
        front=curent;
    else
        rear->next=curent;
    rear=curent;
}
void afisare(Node *front)
{
    Node *it;
    it=front;
    while(it!=nullptr)
    {
        if (it->valoare==0)
            cout<<it->operatie;
        else
            cout<<it->valoare;
        cout<<" ";
        it=it->next;
    }

}
void stergere_coada(Node *front)
{
    Node *it;
    it=front;
    while(it!=nullptr)
    {
        Node *temp=it;
        it=it->next;
        delete temp;
    }
}
int main()
{
    string s;
    std::getline(cin, s);
    unsigned int numar=0;
    for (int i=0;i<s.length();i++)
    {
        if (s[i]!=' ')
        {
            if (s[i]=='+' || s[i]=='-'  || s[i]==')' || s[i]=='(')
                insert(s[i]);
            else if (isdigit(s[i+1])!=true)
            {

                int aux=s[i]-'0';
                numar=numar*10+aux;
                insert(numar);
                numar=0;

            }
            else
            {
                int aux=s[i]-'0';
                numar=numar*10+aux;


            }
        }

    }

    afisare(front);
    calculeaza(front);
    stergere_coada(front);
    return 0;
}