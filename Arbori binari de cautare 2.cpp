
/*Dat un arbore binar de cautare si doua noduri oarecare p si q, sa se
gaseasca cel mai apropiat stramos comun (LCA - Lowest Common Ancestor).*/S

#include <iostream>
#include <fstream>
using namespace std;
struct Node
{
    int valoare;
    Node *next;
};
struct Tree
{
    int valoare;
    Tree *stanga;
    Tree *dreapta;
};
int comun;
void adaugare(int val, Tree *root)
{
    Tree *it, *p_tree;
    it=root;
    int ok=1;
    while (it!=nullptr)
    {
        if (val<it->valoare)
        {
            p_tree=it;
            it=it->stanga;
            ok=-1;
        }
        else if (val>=it->valoare)
        {
            p_tree=it;
            it=it->dreapta;
            ok=1;
        }
    }
    it=new Tree();
    it->valoare=val;
    it->dreapta=nullptr;
    it->stanga=nullptr;
    if (ok==-1)
        p_tree->stanga=it;
    else
        p_tree->dreapta=it;



};
void RSD(Tree *root)
{
    if (root!=nullptr)
    {
        cout<<root->valoare<<" ";
        RSD(root->stanga);
        RSD(root->dreapta);

    }
}
int cautare (int p, int q, Tree* root)
{
    Tree *it1=root;
    Tree *it2=root;
    while (p>comun || q<comun)
    {
        if (it1->valoare==p || it2->valoare==q)
            break;
        if (comun>p)
        {
            it2=it2->stanga;
            it1=it1->stanga;
        }

        else
        {
            it2=it2->dreapta;
            it1=it1->dreapta;
        }


        comun=it1->valoare;

    }

    return comun;
}
int verificare_nod (Node *head, int x)
{
    while (head!=nullptr)
    {
        if (head->valoare==x)
            return 1;
        head=head->next;
    }
    return 0;

}
int main() {
    Tree *root;
    Node *head, *p_node, *it;
    head=new Node();
    root= new Tree();
    int x,p,q,aux;
    ifstream f ("date.txt");
    f>>root->valoare;
    root->dreapta=nullptr;
    root->stanga=nullptr;
    head->valoare=root->valoare;
    head->next=nullptr;
    p_node=head;

    while (f>>x)
    {
        adaugare(x,root);
        it=new Node();
        it->valoare=x;
        it->next=nullptr;
        p_node->next=it;
        p_node=it;
    }

    cout<<"Parcurgerea arborelui in pre-ordine: ";
    RSD(root);
    cout<<endl<<"Care sunt cele doua noduri? (introduse prin enter) ";
    cin>>p>>q;
    if (q<p)
    {
        aux=p;
        p=q;
        q=aux;
    }
    if (verificare_nod(head, p)==0 || verificare_nod (head, q)==0)
        cout<<"Cel putin unul dintre noduri nu exista in arbore";
    else
    {
        comun=root->valoare;
        cout<<endl<<"Stramosul comun este "<<cautare(p,q,root);
    }


    return 0;
}
