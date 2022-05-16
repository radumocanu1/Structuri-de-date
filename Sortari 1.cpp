/*Se dau două s, iruri ordonate crescător A s, i B s, i se consideră că A are destul spat, iu gol la
final încât să poată fi stocat s, i B. Scriet, i o metodă prin care să îl adăugat, i pe B în A astfel
încât vectorul să rămână tot ordonat. */


#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    int a[100], b[100], i, j,n,m,poz_a, poz_b,index;
    ifstream f ("date.in");
    f>>n;
    for(i=0;i<n;i++)
        f>>a[i];
    f>>m;
    for(i=0;i<m;i++)
        f>>b[i];
    poz_a=n-1;
    poz_b=m-1;
    index=m+n-1;
    while (poz_a!=-1 && poz_b!=-1 )
    {
        if (a[poz_a]>b[poz_b])
        {
            a[index]=a[poz_a];
            poz_a--;
        }
        else
        {
            a[index]=b[poz_b];
            poz_b--;
        }
        index--;
    }
    if (poz_a!=-1)
        while(poz_a!=-1)
    {
        a[index]=a[poz_a];
        index--;
        poz_a--;
    }
    else
         while(poz_b!=-1)
    {
        a[index]=b[poz_b];
        index--;
        poz_b--;
    }
    for (i=0;i<=m+n-1;i++)
        cout<<a[i]<<" ";
    return 0;
}
