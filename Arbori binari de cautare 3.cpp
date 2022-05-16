
/*Să se ordoneze descrescător un şir de cuvinte date de la tastatură,
        folosind un arbore binar de căutare*/


#include <iostream>
using namespace std;
struct Tree
{
    string valoare;
    Tree *stanga;
    Tree *dreapta;
};
void adaugare(string val, Tree *root)
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
void descrescator(Tree *root)
{
    if (root!=nullptr)
    {
        descrescator(root->dreapta);
        cout<<root->valoare<<" ";
        descrescator(root->stanga);




    }
}
int main() {
    Tree *root;
    root= new Tree();
    int n;
    string a;
    cout<<"Numarul de cuvinte= ";
    cin>>n;
    cout<<"Cuvintele( separate prin enter)= ";
    for (int i=0;i<n;i++)
    {
        cin>>a;
        adaugare(a,root);
    }


    cout<<"Parcurgerea arborelui in pre-ordine: ";
    RSD(root);
    cout<<endl<<"Ordinea descrescatoare a cuvintelor:";
    descrescator(root);

    return 0;
}
