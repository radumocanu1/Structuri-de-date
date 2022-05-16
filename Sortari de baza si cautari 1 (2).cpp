//Scrieti o metodă de sortare a unui s, ir de string-uri astfel încât toate anagramele să fie una
//lângă cealaltă.


#include <iostream>
#include <string.h>
#include<fstream>
using namespace std;
int anagrame (char c[], char d[])
{
    char a[50],b[50];
    strcpy(a,c);
    strcpy(b,d);
    if (strlen(a) != strlen(b))
        return 0;
    else
    {

        int i,j;
        for (i = 0; i < strlen(a);i++)
                for (j = i + 1; j < strlen(a); j++)
                        if (a[i] > a[j]){
                                char aux = a[i];
                                a[i] = a[j];
                                a[j] = aux;
                        }
        for (i = 0; i < strlen(b); i++)
                for (j = i + 1; j < strlen(b); j++)
                        if (b[i] > b[j]){
                                char aux = b[i];
                                b[i] = b[j];
                                b[j] = aux;
                        }

        if (strcmp(a,b) == 0)
                return 1;
        else
                return 0;
}
}

int main()
{
        char a[100][100],cuv_curent[100],aux[100];
        int i,n,poz=2;
        cin>>n;
        for (i=1;i<=n;i++)
            cin>>a[i];
        strcpy(cuv_curent,a[1]);
        while(poz<=n)
        {
            for (i=poz;i<=n;i++)
                if(anagrame(cuv_curent,a[i])==1)
                {
                    swap(a[i],a[poz]);
                    poz++;

                }
            strcpy(cuv_curent,a[poz]);



        }
        for(i=1;i<=n;i++)
            cout<<a[i]<<" ";

return 0;
}
