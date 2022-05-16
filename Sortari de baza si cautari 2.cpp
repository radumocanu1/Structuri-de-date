/*Un circ include în programul său un număr în care acrobat, ii stau unul deasupra celuilalt pe
umerii anteriorului. Din motive practice, fiecare persoană trebuie să fie mai scundă s, i mai
us,oară decât persoana de dedesubt. Fiind date greutăt, ile s, i înălt, imile persoanelor din circ,
să se scrie un algoritm pentru a calcula cea mai lungă secvent,ă posibilă dintr-un astfel de
turn uman.*/

#include <iostream>
#include <fstream>
using namespace std;

//citirea datelor de intrare se face din fisier, pe fiecare linie avand greutatea si inaltimea acrobatului curent

int main()
{
    int x, y, m[100][2],i=1,j,total,aux,nr_max=1,inaltime,greutate, nr_max2=1 ;
    ifstream f ("date.in");
    while (f>>x && f>>y)
    {
        m[i][1]=x;
        m[i][2]=y;
        i++;
    }
    total=i-1;

//sortez matricea in functie de inaltime

    for (i=1;i<total;i++)
        for(j=i+1;j<=total;j++)
        if (m[i][1]<m[j][1])
    {
        aux=m[i][1];
        m[i][1]=m[j][1];
        m[j][1]=aux;
        aux=m[i][2];
        m[i][2]=m[j][2];
        m[j][2]=aux;
    }
    inaltime=m[1][1];
    greutate=m[1][2];
    for (i=2;i<=total;i++)
        if (m[i][1]<=inaltime && m[i][2]<=greutate)
            {
                inaltime=m[i][1];
                greutate=m[i][2];
                nr_max++;
            }


//sortez matricea in functie de greutate

for (i=1;i<total;i++)
        for(j=i+1;j<=total;j++)
        if (m[i][2]<m[j][2])
    {
        aux=m[i][2];
        m[i][2]=m[j][2];
        m[j][2]=aux;
        aux=m[i][1];
        m[i][1]=m[j][1];
        m[j][1]=aux;
    }
    inaltime=m[1][1];
    greutate=m[1][2];
    for (i=2;i<=total;i++)
        if (m[i][1]<=inaltime && m[i][2]<=greutate)
            {
                inaltime=m[i][1];
                greutate=m[i][2];
                nr_max2++;
            }
    cout<<max(nr_max,nr_max2);

    return 0;
}
