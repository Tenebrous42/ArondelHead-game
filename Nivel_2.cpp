#include <iostream>
#include "Nivel_2.h"
#include <Windows.h>
#include <math.h>
#include <cmath>
#include <stdlib.h>
#include <ctime>
#define VK_W 0x57
#define VK_A 0x41
#define VK_S 0x53
#define VK_D 0x44

using namespace std;

Nivel_2::Nivel_2()
{

    time_t t;
    time(&t);
    srand(t);
    while(xi<2 || yi>27 || xi>27 || yi<2)
    {
        xi=2+rand()%27;
        yi=2+rand()%27;
    }

    harta[xi][yi]='I';
}

int Nivel_2::Set_Nr_Vieti(int a)
{
    nr_vieti=a;
}

int Nivel_2::Set_Damage(int a)
{
    damageul_armei=a;
}

Nivel_2::Get_Nr_Vieti()
{
    return nr_vieti;
}

Nivel_2::Dificultate()
{
    Sleep(10);
}

Nivel_2::Afisare()
{
    int i;
    system("cls");
    for(i=0; i<30; i++)
        cout<<harta[i]<<endl;

    cout<<"Inamicul mai are "<<viata_inamic<<" puncte de viata."<<endl;
    cout<<"Aveti "<<nr_vieti<<" vieti."<<endl;
}


Nivel_2::Miscari()
{

    if(GetAsyncKeyState(VK_UP))
    {

        if(harta[x-1][y]==' ')
        {
            harta[x][y]=' ';
            x--;
            harta[x][y]='@';
            Afisare();
        }

        Sleep(20);

    }


    if(GetAsyncKeyState(VK_DOWN))
    {

        if(harta[x+1][y]==' ')
        {
            harta[x][y]=' ';
            x++;
            harta[x][y]='@';
            Afisare();
        }

        Sleep(20);

    }


    if(GetAsyncKeyState(VK_LEFT))
    {

        if(harta[x][y-1]==' ')
        {
            harta[x][y]=' ';
            y--;
            harta[x][y]='@';
            Afisare();
        }

        Sleep(20);

    }

    if(GetAsyncKeyState(VK_RIGHT))
    {

        if(harta[x][y+1]==' ')
        {
            harta[x][y]=' ';
            y++;
            harta[x][y]='@';
            Afisare();
        }

        Sleep(20);

    }


}


Nivel_2::Trage_Arondel()
{
    int xg,yg;

    if(GetAsyncKeyState(VK_W))
    {
        xg=x-1;
        yg=y;

        while(harta[xg-1][yg]!='#')
        {
            Miscari();

            if(harta[xg-1][yg]=='I')
            {
                harta[xg][yg]=' ';
                xg--;
                harta[xg][yg]=' ';
                harta[xg+1][yg]=' ';

                viata_inamic=viata_inamic-damageul_armei;

                if(viata_inamic==0)
                    Inamic_Traieste=false;

                Afisare();
                break;
            }

            harta[xg][yg]=' ';
            xg--;

            if(damageul_armei==1)
                harta[xg][yg]='|';

            if(damageul_armei==2)
                harta[xg][yg]='#';

            Afisare();
        }

        harta[xg][yg]=' ';
    }





    if(GetAsyncKeyState(VK_S))
    {
        xg=x+1;
        yg=y;

        while(harta[xg+1][yg]!='#')
        {
            Miscari();

            if(harta[xg+1][yg]=='I')
            {
                harta[xg][yg]=' ';
                xg++;
                harta[xg][yg]=' ';
                harta[xg-1][yg]=' ';

                viata_inamic=viata_inamic-damageul_armei;

                if(viata_inamic==0)
                    Inamic_Traieste=false;

                Afisare();
                break;
            }

            harta[xg][yg]=' ';
            xg++;

            if(damageul_armei==1)
                harta[xg][yg]='|';

            if(damageul_armei==2)
                harta[xg][yg]='#';

            Afisare();
        }
        harta[xg][yg]=' ';
    }




    if(GetAsyncKeyState(VK_A))
    {
        xg=x;
        yg=y-1;

        while(harta[xg][yg-1]!='#')
        {
            Miscari();

            if(harta[xg][yg-1]=='I')
            {
                harta[xg][yg]=' ';
                yg--;
                harta[xg][yg]=' ';
                harta[xg][yg+1]=' ';

                viata_inamic=viata_inamic-damageul_armei;

                if(viata_inamic==0)
                    Inamic_Traieste=false;

                Afisare();
                break;
            }

            harta[xg][yg]=' ';
            yg--;


            if(damageul_armei==1)
              harta[xg][yg]='-';

            if(damageul_armei==2)
                harta[xg][yg]='=';


            Afisare();
        }
        harta[xg][yg]=' ';
    }




    if(GetAsyncKeyState(VK_D))
    {
        xg=x;
        yg=y+1;

        while(harta[xg][yg+1]!='#')
        {
            Miscari();

            if(harta[xg][yg+1]=='I')
            {
                harta[xg][yg]=' ';
                yg++;
                harta[xg][yg]=' ';
                harta[xg][yg-1]=' ';

                viata_inamic=viata_inamic-damageul_armei;

                if(viata_inamic==0)
                    Inamic_Traieste=false;

                Afisare();
                break;
            }

            harta[xg][yg]=' ';
            yg++;

            if(damageul_armei==1)
              harta[xg][yg]='-';

            if(damageul_armei==2)
                harta[xg][yg]='=';


            Afisare();
        }
        harta[xg][yg]=' ';
    }


}


Nivel_2::Mutarea_Inamicului()
{

    while(Inamic_Traieste && Arondel_Traieste)
    {

        if(xi<x)
        {
            if(harta[xi+1][yi]=='@')
            {
                Arondel_Traieste=false;
                gameOver=true;

                harta[xi][yi]=' ';
                xi++;
                harta[xi][yi]=' ';

                Afisare();
                break;
            }

            harta[xi][yi]=' ';
            xi++;
            harta[xi][yi]='I';

            Miscari();
            Trage_Arondel();
            Afisare();
            Dificultate();

        }

        else if(xi>x)
        {

            if(harta[xi-1][yi]=='@')
            {
                Arondel_Traieste=false;
                gameOver=true;

                harta[xi][yi]=' ';
                xi--;
                harta[xi][yi]=' ';

                Afisare();
                break;
            }

            harta[xi][yi]=' ';
            xi--;
            harta[xi][yi]='I';

            Afisare();
            Miscari();
            Trage_Arondel();
            Dificultate();

        }







        if(yi<y)
        {

            if(harta[xi][yi+1]=='@')
            {
                Arondel_Traieste=false;
                gameOver=true;

                harta[xi][yi]=' ';
                yi++;
                harta[xi][yi]=' ';

                Afisare();
                break;
            }

            harta[xi][yi]=' ';
            yi++;
            harta[xi][yi]='I';


            Miscari();
            Trage_Arondel();
            Afisare();
            Dificultate();

        }

        else if(yi>y)
        {

            if(harta[xi][yi-1]=='@')
            {
                Arondel_Traieste=false;
                gameOver=true;

                harta[xi][yi]=' ';
                yi--;
                harta[xi][yi]=' ';

                Afisare();
                break;
            }

            harta[xi][yi]=' ';
            yi--;
            harta[xi][yi]='I';

            Miscari();
            Trage_Arondel();
            Afisare();
            Dificultate();
        }

    }



}
