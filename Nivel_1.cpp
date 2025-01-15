#include <iostream>
#include "Nivel_1.h"
#include <Windows.h>
#include <stdlib.h>
#include <ctime>

using namespace std;

Nivel_1::Nivel_1()
{
    //ctor
}

void Nivel_1::Set_Nr_Vieti(int a)
{
    nrv=a;
}

Nivel_1::Get_Nr_Vieti()
{
    return nrv;
}

int Nivel_1::Get_Nr_Chei()
{
    return nrchei;
}

bool Nivel_1::Game_Over()
{
    if(continua==1)
        return 0;
    else
        return 1;
}

Nivel_1::Afisare()
{

    int i;
    system("cls");
    for(i=0; i<20; i++)
        cout<<harta[i]<<endl;

    cout<<"Colectati cheile ( C ), pentru a descuia poarta ( P se va deschide si va fi D)."<<endl;
    cout<<"Folositi sagetile pentru a-l controla pe Arondel."<<endl;
    cout<<"Daca tii apasat pe CTRL, el se va prinde de zidurile de langa el si se va putea urca pe ele"<<endl;
    cout<<endl;
    cout<<"Aveti "<<nrchei<<" chei din 5."<<endl;
    cout<<"Mai aveti "<<nrv<<" vieti."<<endl;
    cout<<endl;
    cout<<"Apasati ESC pentru a iesi din joc"<<endl;
    cout<<endl;

}

Nivel_1::Poz_Cheie()
{
    int cheie_x,cheie_y;
    time_t t;
    time(&t);
    srand(t);
    while(cheie_x<1 || cheie_x>20 || cheie_y<1 ||cheie_y>30 || harta[cheie_x][cheie_y]!=' '
            || harta[cheie_x][cheie_y-1]!='Z' || harta[cheie_x][cheie_y+1]!='Z')
    {

        cheie_x=1+rand()%19;
        cheie_y=1+rand()%29;
    }

    harta[cheie_x][cheie_y]='C';
}

Nivel_1::Miscari ()
{

    while(GetAsyncKeyState(VK_CONTROL))
    {

        system("pause>nul");

        if(GetAsyncKeyState(VK_UP) )
        {
            Afisare();

            if(harta[x-1][y]=='D')
            {
                harta[x][y]=' ';
                x--;
                harta[x][y]='@';
                //  Afisare();
                continua=false;
            }


            if(harta[x-1][y]=='C')
            {
                harta[x][y]=' ';
                x--;
                harta[x][y]='@';

                nrchei++;
                if(nrchei<5)
                    Poz_Cheie();
                else if(nrchei==5)
                    harta[1][28]='D';
            }


            if(harta[x-1][y]==' ')
            {
                harta[x][y]=' ';
                x--;
                harta[x][y]='@';

            }
        }




        if(GetAsyncKeyState(VK_DOWN))
        {

            Afisare();

            if(harta[x+1][y]=='D')
            {
                harta[x][y]=' ';
                x++;
                harta[x][y]='@';
                //    Afisare();
                continua=false;
            }

            if(harta[x+1][y]=='C')
            {
                harta[x][y]=' ';
                x++;
                harta[x][y]='@';

                nrchei++;
                if(nrchei<5)
                    Poz_Cheie();
                else if(nrchei==5)
                    harta[1][28]='D';

            }

            if(harta[x+1][y]==' ' )
            {
                harta[x][y]=' ';
                x++;
                harta[x][y]='@';
            }

        }



    }
///Sfarsitul While-ului Control-ului/////

    if( GetAsyncKeyState(VK_UP) )
    {

        if(harta[x-1][y]=='D')
        {
            harta[x][y]=' ';
            x--;
            harta[x][y]='@';

            continua=false;
        }


        if(harta[x-1][y]=='C' )
        {
            harta[x][y]=' ';
            x--;
            harta[x][y]='@';
            ok=1;

            nrchei++;
            if(nrchei<5)
                Poz_Cheie();
            else if(nrchei==5)
                harta[1][28]='D';
        }

        if(harta[x-1][y]==' ' )
        {
            harta[x][y]=' ';
            x--;
            harta[x][y]='@';

        }

        Afisare();
        Sleep(90);
    }




    if(GetAsyncKeyState(VK_LEFT))
    {

        ok=0;
        if(harta[x][y-1]=='D')
        {
            harta[x][y]=' ';
            y--;
            harta[x][y]='@';
            Afisare();
            continua=false;
        }

        if(harta[x][y-1]=='C' && ok==0)
        {
            harta[x][y]=' ';
            y--;
            harta[x][y]='@';
            Afisare();
            ok=1;

            nrchei++;
            if(nrchei<5)
                Poz_Cheie();
            else if(nrchei==5)
                harta[1][28]='D';
        }

        if(harta[x][y-1]==' ' && ok==0)
        {
            harta[x][y]=' ';
            y--;
            harta[x][y]='@';
        }
        Afisare();
    }





    if(GetAsyncKeyState(VK_RIGHT))
    {
        ok=0;
        if(harta[x][y+1]=='D')
        {
            harta[x][y]=' ';
            y++;
            harta[x][y]='@';

            continua=false;
        }

        if(harta[x][y+1]=='C' && ok==0)
        {
            harta[x][y]=' ';
            y++;
            harta[x][y]='@';
            ok=1;

            nrchei++;
            if(nrchei<5)
                Poz_Cheie();
            else if(nrchei==5)
                harta[1][28]='D';
        }

        if(harta[x][y+1]==' '&& ok==0)
        {
            harta[x][y]=' ';
            y++;
            harta[x][y]='@';

        }
        Afisare();
    }


}

Nivel_1::Gravitatie()
{
    while(  (harta[x+1][y]==' ' || harta[x+1][y]=='C' || harta[x+1][y]=='D' || harta[x+1][y]=='L')   )
    {

        Sleep(80);

        if( GetAsyncKeyState(VK_CONTROL) && (harta[x][y-1]=='Z' || harta[x][y+1]=='Z') )
            break;

        if(harta[x+1][y]=='C' )
        {
            harta[x][y]=' ';
            x++;
            harta[x][y]='@';

            nrchei++;
            if(nrchei<5)
                Poz_Cheie();
            else if(nrchei==5)
                harta[1][28]='D';

        }

        if(harta[x+1][y]=='D')
        {
            harta[x][y]=' ';
            x++;
            harta[x][y]='@';
            continua=false;
        }

        if(harta[x+1][y]=='L')
        {
            harta[x][y]=' ';
            x=1;
            y=1;
            harta[x][y]='@';
            nrv--;

        }

        if(harta[x+1][y]=' ')
        {
            harta[x][y]=' ';
            x++;
            harta[x][y]='@';
        }

        Afisare();
    }

}

