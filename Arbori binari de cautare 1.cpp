/*Sa se implementeze o procedura pentru inserarea unui nod intr-un
arbore binar de cautare echilibrat AVL. Sa se creeze folosind aceasta metoda un arbore binar
de cautare echilibrat AVL din valorile existente intr-un fisier arbore.in. Sa se afiseze nodurile
din arbore in pre-ordine pe ecran*/

#include <iostream>
#include <fstream>
using namespace std;
struct Tree
{
    int valoare;
    Tree *stanga;
    Tree *dreapta;
    int inaltime;
};
Tree *initializare(int valoare)
{
    Tree* curent=new Tree();
    curent->valoare=valoare;
    curent->dreapta=nullptr;
    curent->stanga=nullptr;
    curent->inaltime=1;
    return curent;
}
int get_inaltime(Tree *curent)
{
    if (curent==nullptr)
        return 0;
    return curent->inaltime;
}
int arbore_ok(Tree *curent)
{
    if (curent==nullptr)
        return 0;
    return get_inaltime(curent->stanga)-get_inaltime(curent->dreapta);
}
Tree *rotire_dreapta(Tree* curent)
{
    Tree *stanga=curent->stanga;
    Tree *stanga_dreapta=stanga->dreapta;
    stanga->dreapta=curent;
    curent->stanga=stanga_dreapta;

    curent->inaltime=1 + max(get_inaltime(curent->stanga), get_inaltime(curent->dreapta));
    stanga->inaltime=1 + max(get_inaltime(stanga->stanga), get_inaltime(stanga->dreapta));
    return stanga;
}
Tree *rotire_stanga( Tree *curent)
{
    Tree *dreapta=curent->dreapta;
    Tree *dreapta_stanga=dreapta->stanga;
    dreapta->stanga=curent;
    curent->dreapta=dreapta_stanga;
    curent->inaltime=1 + max(get_inaltime(curent->stanga), get_inaltime(curent->dreapta));
    dreapta->inaltime=1 + max(get_inaltime(dreapta->stanga), get_inaltime(dreapta->dreapta));
    return dreapta;
}

Tree* adaugare(Tree *curent, int valoare)
{

    if (curent==nullptr)
    {
        curent=initializare(valoare);
        return curent;
    }
    if (valoare<curent->valoare)
        curent->stanga=adaugare(curent->stanga,valoare);
    else if (valoare>curent->valoare)
        curent->dreapta=adaugare(curent->dreapta,valoare);
    else
        return curent;
    curent->inaltime=1 + max(get_inaltime(curent->stanga), get_inaltime(curent->dreapta));
    if (arbore_ok(curent)>1 && valoare<curent->stanga->valoare)
        return rotire_dreapta(curent);
    if (arbore_ok(curent)>1 && valoare>curent->stanga->valoare)
    {
        curent->stanga=rotire_stanga(curent->stanga);
        return rotire_dreapta(curent);
    }
    if (arbore_ok(curent)<-1 && valoare>curent->dreapta->valoare)
        return rotire_stanga(curent);
    if (arbore_ok(curent)<-1 && valoare<curent->dreapta->valoare)
    {

        curent->dreapta=rotire_dreapta(curent->dreapta);
        return rotire_stanga(curent);
    }
    return curent;

}
void RSD(Tree *root)
{
    if (root!=nullptr)
    {
        cout<<root->valoare<<" cu inaltime "<<root->inaltime<<endl;
        RSD(root->stanga);
        RSD(root->dreapta);

    }
}
int main() {
    Tree *root;
    root= new Tree();
    int x;
    ifstream f("date.txt");
    f>>x;
    root->stanga=nullptr;
    root->dreapta=nullptr;
    root->valoare=x;
    root->inaltime=1;
    while(f>>x)
        root=adaugare(root,x);
    cout<<"Parcurgerea arborelui in pre-ordine: ";
    cout<<endl;
    RSD(root);



    return 0;
}
