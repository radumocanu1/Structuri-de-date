/*Să se optimizeze procedura de sortare rapidă, folosind următoarea tehnică: subşirurile de
dimensiune <= 11 elemente se sortează cu inserţia directă.*/

#include <iostream>

using namespace std;

void schimba(int* a, int* b)
{
    int t=*a;
    *a=*b;
    *b=t;
}
int partitie( int v[], int st, int dr)
{
    int pivot=v[dr];
    int j, i=st-1;
    for (j=st;j<=dr-1;j++)
        if (v[j]<pivot)
    {
        i++;
        schimba(&v[i], &v[j]);
    }
    schimba (&v[i+1], &v[dr]);
    return (i+1);
}
void insertie_directa (int v[], int st, int dr)
{
      for(int i=st;i<=dr;i++)
{
    int p=i;
    while(p > 0 && v[p] < v[p-1])
    {
        int aux = v[p];
        v[p] = v[p-1];
        v[p-1] = aux;
        p --;
    }
}




}
void quicksort(int v[], int st, int dr)
{
    if (st<dr)
        if (dr-st>11)
    {
        int a=partitie(v,st,dr);
        quicksort(v,st,a-1);
        quicksort(v,a+1,dr);
    }
    else
        insertie_directa(v,st+1,dr);


}
int main()
{
    int n, v[100];
    cout<<"Cate numere are array ul? ";
    cin>>n;
    cout<<"Dati cele "<<n<<" numere ";
    for(int i=0;i<=n-1;i++)
        cin>>v[i];
    quicksort(v,0,n-1);
    for(int i=0;i<=n-1;i++)
        cout<<v[i]<<" ";

    return 0;
}
