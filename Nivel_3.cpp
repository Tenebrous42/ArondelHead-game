#include <iostream>
#include "Nivel_3.h"
#include <Windows.h>
#include <ctime>

using namespace std;

Nivel_3::Nivel_3()
{
   for(i=1; i<=n; i++)
        for(j=1; j<=m; j++)
            a[i][j]='O';


    time_t t;
    time(&t);
    srand(t);

   // nrb=2+rand()%9;
    nrb=4;
    if((i<1 || i>5)||(i<1 ||j>5))
    {
        i=1+rand()%(n-1);
        j=1+rand()%(m-1);
    }

    for(k=1; k<=nrb; k++)
    {
        while(a[i][j]=='B')
        {
            i=1+rand()%n;
            j=1+rand()%m;
        }


        a[i][j]='B';
    }

    for(i=1; i<=n; i++)
        for(j=1; j<=m; j++)
            b[i][j]=9;

}

Nivel_3::numar_mine(int,int)
{
    int k=0;

    if(a[pl-1][pc-1]=='B')
        k++;
    if(a[pl-1][pc]=='B')
        k++;
    if(a[pl-1][pc+1]=='B')
        k++;
    if(a[pl][pc-1]=='B')
        k++;
    if(a[pl][pc+1]=='B')
        k++;
    if(a[pl+1][pc-1]=='B')
        k++;
    if(a[pl+1][pc]=='B')
        k++;
    if(a[pl+1][pc+1]=='B')
        k++;

    return k;
}

Nivel_3::nu_exista_bombe()
{
    if(a[pl-1][pc-1]!='B'&&a[pl-1][pc]!='B'&&a[pl-1][pc+1]!='B'&&a[pl][pc-1]!='B'&&a[pl][pc+1]!='B'&&a[pl+1][pc-1]!='B'&&a[pl+1][pc]!='B'&&a[pl+1][pc+1]!='B')
        return 1;
    else
        return 0;

}

Nivel_3::Afisare_harta_b()
{
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=m; j++)
            cout << b[i][j]<<" ";
        cout << endl;
    }
}

Nivel_3::Afisare_harta_a()
{
    cout<<"Ati pierdut !";
    cout<<endl;

    for(i=1; i<=n; i++)
    {
        for(j=1; j<=m; j++)
            cout << a[i][j]<<" ";
        cout << endl;
    }
}

Nivel_3::Nr_bombelor_gasite()
{

    int bombe_gasite=0;
    for(i=1; i<=n; i++)
        for(j=1; j<=m; j++)
            if(b[i][j]==9)
                bombe_gasite++;

    return bombe_gasite;
}

Nivel_3::Marchez_vecinii()
{
    b[pl-1][pc-1]=numar_mine(pl-1,pc-1);
    b[pl-1][pc]=numar_mine(pl-1,pc);
    b[pl-1][pc+1]=numar_mine(pl-1,pc+1);
    b[pl][pc-1]=numar_mine(pl,pc-1);
    b[pl][pc+1]=numar_mine(pl,pc+1);
    b[pl+1][pc-1]=numar_mine(pl+1,pc-1);
    b[pl+1][pc]=numar_mine(pl+1,pc);
    b[pl+1][pc+1]=numar_mine(pl+1,pc+1);
    b[pl][pc]=numar_mine(pl,pc);
}
