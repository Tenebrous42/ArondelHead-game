#include <iostream>
#include <fstream>
#include "Nivel_1.h"
#include "Nivel_2.h"
#include "Nivel_3.h"
#include "Nivel_4.h"
#include "Magazinul_insulei.h"
#include <Windows.h>
#include <math.h>
#include <cmath>
#include <stdlib.h>
#include <ctime>
#define VK_W 0x57
#define VK_A 0x41
#define VK_S 0x53
#define VK_D 0x44
#define VK_ENTER 0x0D
#define VK_ESCAPE 0x1B
#define VK_Q 0x51
using namespace std;
fstream Contul_principal("Contul_principal.txt");

char harta_princip[43][169]
{
    "########################################################################################################################################################################",
    "#                                                                                                                                                                      #",
    "#            ZZZ                      ZZZZZZ          ZZZZZ                                   ZZZZZZ                   ZZZZZZZZ             ZZZZZZ                     #",
    "#          ZZZZZZZZ         ZZZZZZZZZZZZZZZ     ZZZZZZZZZZZZZ                           ZZZZZZZZZZZZZZZ       ZZZZZZZZZZZZZZZZZZ        ZZZZZZZZZZZZZZZZZ              #",
    "#     ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ                           ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ         #",
    "#    ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ                               ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ        #",
    "#     ZZZZZZZ   ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ                                   ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ            #",
    "#      ZZZZZZ 1 ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ                                     ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ 4 ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ          #",
    "#     ZZZZZZZ Z ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ                         ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ   ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ              #",
    "#        ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ                                      ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ      #",
    "#      ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ                          ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ      #",
    "#    ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ                     ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ            #",
    "#    ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ                       ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ             #",
    "#      ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ                            ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ        #",
    "#    ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ                                     ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ       #",
    "#  ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ                            ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ   #",
    "#      ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ                                ZZZZZZZZ  ZZZZ   ZZZ     ZZZZZZ         Z           ZZZZZZZZZZZ               #",
    "#     ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ                               ZZZZZ                                 Z             ZZZZZZZ                 #",
    "#          ZZZZZZZZ  ZZZZ      Z       ZZZZZ   ZZZZZZZZZZZZZ                                                                     P                                     #",
    "#            ZZZZ              Z                  ZZZZZ                                      ZZZZ                                Z                          Z          #",
    "#                              P                                                         ZZZZZZZZZZZZ                            Z                       ZZZZZ         #",
    "#                              Z                                                 ZZZZZZZZZZZZZZZZZZZZZZZZZZ      ZZZZ       ZZZZZZZZZZ       ZZZZZ     ZZZZZZZZZZZZ    #",
    "#               ZZZZZZZZ       Z    ZZZZZZZZZ   ZZZZZZZ                                ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ          #",
    "#            ZZZZZZZZZZ    ZZZZZZZZZZZZZZZZZZZZZZZZ                                  ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ        #",
    "#      ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ                                    ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ               #",
    "#        ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ        ZZZZZZZZ                         ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ      #",
    "#    ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ                  ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ      #",
    "#           ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ                           ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ     ZZZZZZZZZZZZ      #",
    "#        ZZZZZZZZZZZZZZZZZZZZZZZZZZ  M  ZZZZZZZZZZZZZZZZZZZZZZZ                 ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ    #",
    "#     ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ     ZZZZZZZZZZZZZZZZZZZZZZZZZZZZ                ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ          #",
    "#             ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZPZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ     ZZZZZZZZZZZZZZZZZZ   #",
    "#      ZZZZZZZZZZZZZZZZZZ 2 ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ          ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ             #",
    "#  ZZZZZZZZZZZZZZZZZZZZZZ   ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ        ZZ       ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ       #",
    "#       ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ        ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ  #",
    "#   ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ      ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ  3 ZZZZZZZZZZ            #",
    "#        ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ                    ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ    ZZZZZZZZZZZZZZZZZZZZ  #",
    "#      ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ                       ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ        #",
    "#  ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ              ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ                   #",
    "#         ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ                             ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ        #",
    "#    ZZZZZZZ        ZZZZZZZZ   ZZZ         ZZZZ    ZZZZZZ                                         ZZZZZZZZ      ZZZZZZZZZZZZ         ZZ        ZZZZZZ     ZZZ          #",
    "#                                                                                                                                                                      #",
    "########################################################################################################################################################################",
};

bool gameOver=false, Arondel_Traieste=true, pistol=false, shotgun=false;
int numar_vieti=1, monede_aur=0, monede_argint=0;
int stare_nivel_1, stare_nivel_2, stare_nivel_3, stare_nivel_4;
int x=6,y=7,fin=1;

void Salvari();

void Afisare()
{
    int i;
    system("cls");
    for(i=0; i<43; i++)
        cout<<harta_princip[i]<<endl;
}

void Afisarea_initializare(int K)
{
    int i,j;
    system("cls");

    if(K==1)
    {
        for(i=1; i<=3; i++)
        {
            cout<<"Loading: \nInitializing level 1";
            for(j=1; j<=3; j++)
            {
                Sleep(300);
                cout<<". ";
            }

            Sleep(300);
            system("cls");

        }
    }


    if(K==2)
    {
        for(i=1; i<=3; i++)
        {
            cout<<"Loading: \nInitializing level 2";
            for(j=1; j<=3; j++)
            {
                Sleep(300);
                cout<<". ";
            }

            Sleep(300);
            system("cls");

        }
    }



    if(K==3)
    {
        for(i=1; i<=3; i++)
        {
            cout<<"Loading: \nInitializing level 3";
            for(j=1; j<=3; j++)
            {
                Sleep(300);
                cout<<". ";
            }

            Sleep(300);
            system("cls");

        }
    }


    if(K==4)
    {
        for(i=1; i<=3; i++)
        {
            cout<<"Loading: \nInitializing level 4";
            for(j=1; j<=3; j++)
            {
                Sleep(300);
                cout<<". ";
            }

            Sleep(300);
            system("cls");

        }
    }


    if(K==5)
    {
        for(i=1; i<=3; i++)
        {
            cout<<"Loading: \nInitializing store";
            for(j=1; j<=3; j++)
            {
                Sleep(300);
                cout<<". ";
            }

            Sleep(300);
            system("cls");

        }
    }
}


void Miscari()
{

    if(GetAsyncKeyState(VK_UP))
    {

        if(harta_princip[x-1][y]=='Z')
        {
            harta_princip[x][y]='Z';
            x--;
            harta_princip[x][y]='@';
            Afisare();
        }

        Sleep(30);

    }


    if(GetAsyncKeyState(VK_DOWN))
    {

        if(harta_princip[x+1][y]=='Z')
        {
            harta_princip[x][y]='Z';
            x++;
            harta_princip[x][y]='@';
            Afisare();
        }

        Sleep(30);

    }


    if(GetAsyncKeyState(VK_LEFT))
    {

        if(harta_princip[x][y-1]=='Z')
        {
            harta_princip[x][y]='Z';
            y--;
            harta_princip[x][y]='@';
            Afisare();
        }

        Sleep(30);

    }


    if(GetAsyncKeyState(VK_RIGHT))
    {

        if(harta_princip[x][y+1]=='Z')
        {
            harta_princip[x][y]='Z';
            y++;
            harta_princip[x][y]='@';
            Afisare();
        }

        Sleep(30);

    }
}


void Initializare_nivelul_1()
{
    Afisarea_initializare(1);

    Nivel_1 obj1;
    obj1.Set_Nr_Vieti(numar_vieti);
    obj1.Poz_Cheie();

    while(obj1.Game_Over()==false)
    {
        obj1.Afisare();
        system("pause>nul");
        obj1.Miscari();
        obj1.Gravitatie();

        if(obj1.Get_Nr_Vieti()==0)
        {
            cout<<"Ai murit :("<<endl;
            break;
        }

        if(GetAsyncKeyState(VK_ESCAPE))
        {
            cout<<"Never give up again !"<<endl;
            break;
        }

    }

    if(obj1.Get_Nr_Chei()==5)
    {
        stare_nivel_1=1;
        harta_princip[20][31]='Z';
        system("cls");
        cout<<"Ati terminat nivelul, felicitari !"<<endl;
    }

    cout<<endl;
    system("pause");
}




void Initializare_nivelul_2()
{
    Afisarea_initializare(2);

    Nivel_2 IAA;

    IAA.Set_Nr_Vieti(numar_vieti);
    if(pistol==true)
        IAA.Set_Damage(1);
    if(shotgun==true)
        IAA.Set_Damage(2);

    IAA.harta[IAA.x][IAA.y]='@';
    IAA.Afisare();

    while(IAA.gameOver==false && IAA.Inamic_Traieste)
    {
        system("pause>nul");
        IAA.Mutarea_Inamicului();
        if(GetAsyncKeyState(VK_Q))
            break;

    }


    if(IAA.Arondel_Traieste==false)
    {
        cout<<"Allahu Akbar ! *Explozie*."<<endl;
        cout<<"Ai murit !";
        system("pause>nul");

    }

    if(IAA.Inamic_Traieste==false)
    {
        stare_nivel_2=1;
        harta_princip[30][73]='Z';
        cout<<"Ai omorat inamicul. The bomb has been defused."<<endl;
        cout<<"Ai castigat !"<<endl;
        system("pause>nul");

    }
}




void Initializare_nivelul_3()
{
    Afisarea_initializare(3);

    Nivel_3 M;

    cout<<"Gaseste cele "<<M.nrb<<" bombe: "<<endl;
    cout<<endl;

    M.Afisare_harta_b();

    do
    {
        cout<<endl;
        cout<<"Alegeti pozitia pe care faceti click: ";
        cin>>M.pl>>M.pc;
        cout<<endl;

        if(M.a[M.pl][M.pc]=='B')
        {
            M.Afisare_harta_a();
            break;
        }

        else
        {
            if(M.nu_exista_bombe()==1)
                M.Marchez_vecinii();
            else
                M.b[M.pl][M.pc]=M.numar_mine(M.pl,M.pc);

            M.Afisare_harta_b();

            cout<<endl;

        }

        if(GetAsyncKeyState(VK_Q))
        {
            cout<<"Never give up again !";
            break;
        }

    }
    while(M.Nr_bombelor_gasite()!=M.nrb);


    if(M.Nr_bombelor_gasite()==M.nrb)
    {
        cout<<endl;
        cout<<"Felicitari, ati castigat !!!"<<endl;
        stare_nivel_3=1;
        harta_princip[18][129]='Z';
    }
}



void Initializare_nivelul_4()
{
    Afisarea_initializare(4);

    Nivel_4 Vm;
    Vm.Combinatii();

    do
    {
        cout<<endl;
        Vm.Afisare();

        cout<<endl;

        cout<<"Introduceti pozitia pe care doriti sa o completati cu X (indicele liniei spatiu indicele coloanei):"<<endl;
        cin>>Vm.pl>>Vm.pc;
        cout<<endl;


        while(Vm.pl<1||Vm.pl>3||Vm.pc<1||Vm.pc>3)
        {
            cout<<"Date invalide, puneti valori intre 1 si 3 atat pt linie cat si pt coloana:"<<endl;
            cin>>Vm.pl>>Vm.pc;
            cout<<endl;
        }



        if(Vm.a[Vm.pl][Vm.pc]=='#')
        {
            Vm.a[Vm.pl][Vm.pc]='X';
            Vm.c[Vm.l]=Vm.pl*10+Vm.pc;
            Vm.l++;

        }



        if(Vm.pas==1)
        {

            if(Vm.pl==2&&Vm.pc==2)
            {
                Vm.a[1][3]='O';
                Vm.pas++;
                Vm.caz1++;
            }
            else
            {
                Vm.a[2][2]='O';
                Vm.pas++;
                Vm.caz2++;
            }

        }

        if(Vm.pas==2 && Vm.c[2]!=0)
        {

            Vm.primulX=Vm.c[1];
            Vm.AlDoileaX=Vm.c[2];

            Vm.pozitie= Vm.b[Vm.primulX][Vm.AlDoileaX];
            Vm.a[Vm.pozitie/10][Vm.pozitie%10]='O';

            Vm.pas++;

        }



        if(Vm.pas==3&&Vm.c[3]!=0)
        {
            if(Vm.caz1==1)
            {

                Vm.blocare=0;

                if(Vm.Caut_pt_O()!=0&&Vm.blocare==0)
                {
                    Vm.pozitieO=Vm.Caut_pt_O();
                    Vm.a[Vm.pozitieO/10][Vm.pozitieO%10]='O';
                    Vm.blocare++;
                }



                if(Vm.Blocare_X_1()!=0&&Vm.blocare==0)
                {
                    Vm.pozitieO=Vm.Blocare_X_1();
                    Vm.a[Vm.pozitieO/10][Vm.pozitieO%10]='O';
                    Vm.blocare++;
                }


                if(Vm.Liber_pt_O()!=0&&Vm.blocare==0)
                {
                    Vm.pozitieO=Vm.Liber_pt_O();
                    Vm.a[Vm.pozitieO/10][Vm.pozitieO%10]='O';
                    Vm.blocare++;
                }


                Vm.Pune_random_O();


            }

            if(Vm.caz2==1)
            {


                Vm.blocare=0;

                if(Vm.Caut_pt_O()!=0 && Vm.blocare==0)
                {
                    Vm.pozitieO=Vm.Caut_pt_O();
                    Vm.a[Vm.pozitieO/10][Vm.pozitieO%10]='O';
                    Vm.blocare++;
                }



                if(Vm.Blocare_X_2()!=0&&Vm.blocare==0)
                {
                    Vm.pozitieO=Vm.Blocare_X_2();
                    Vm.a[Vm.pozitieO/10][Vm.pozitieO%10]='O';
                    Vm.blocare++;
                }



                if(Vm.Liber_pt_O()!=0&&Vm.blocare==0)
                {
                    Vm.pozitieO=Vm.Liber_pt_O();
                    Vm.a[Vm.pozitieO/10][Vm.pozitieO%10]='O';
                    Vm.blocare++;
                }

                Vm.Pune_random_O();


            }


        }

        if(GetAsyncKeyState(VK_Q))
        {
            cout<<"Never give up again !";
            break;
        }

    }
    while(Vm.castigsauegalit()==0);

    Vm.Afisare();

    cout<<endl;


    if(Vm.castigsauegalit()==1)
    {
        cout<<"Ati castigat!";
        stare_nivel_4=1;
    }


    if(Vm.castigsauegalit()==2)
    {
        cout<<"Ati pierdut!";
        system("pause>nul");
    }

    if(Vm.castigsauegalit()==3)
    {
        cout<<"Este egalitate!";
        system("pause>nul");
    }
}



void Initializare_magazin()
{
    Afisarea_initializare(5);

    Magazinul_insulei OM;
    OM.Setare_valori_initiale(pistol,shotgun, monede_aur, monede_argint, numar_vieti);

    while(1==1)
    {
        OM.Afisarea_Magazinului();
        OM.Inventarul_Meu();

        if(OM.E_Valida_Comanda())
            OM.Efectuare_Tranzactie();

        OM.Sold_final();
        if(OM.Ramai_In_Magazin()==false)
            break;
    }

    numar_vieti=OM.Get_Nr_Vieti();

    if(OM.pistol==true)
        pistol=true;
    else
        pistol=false;


    if(OM.shotgun==true)
        shotgun=true;
    else
        shotgun=false;

    monede_aur=OM.G;
    monede_argint=OM.S;
}

void Salvari()
{
    ofstream Contul_principal("Contul_principal.txt");
    Contul_principal<<stare_nivel_1<<' '<<stare_nivel_2<<' '<<stare_nivel_3<<' '<<stare_nivel_4<<' '<<x<<' '<<y<<endl;

    Contul_principal<<numar_vieti<<endl;

    if(pistol==true)
        Contul_principal<<1<<endl;
    else
        Contul_principal<<0<<endl;

    if(shotgun==true)
        Contul_principal<<1<<endl;
    else
        Contul_principal<<0<<endl;

    Contul_principal<<monede_aur<<endl;
    Contul_principal<<monede_argint<<endl;
}


int main()
{
AICI:
    system("cls");

    int alege;
    cout<<"Welcome to ArondelHead !\n"<<endl;
    cout<<"Press 1 to start a new game."<<endl;
    cout<<"Press 2 to resume your game."<<endl;
    cout<<"Press 3 to exit."<<endl;
    cout<<endl;
    cout<<"Joaca in fullscreen ;) "<<endl;
    cin>>alege;


    if(alege==1 || alege==2)
    {

        if(alege==1)
        {
            system("cls");
            cout<<"Arondel a naufragiat pe o insula si trebuie sa ajunga la cea mai indepartata insula de el pentru a gasi"<<endl;
            cout<<"ajutorul necesar intoarcerii in civilizatie. Controleaza-l pe Arondel cu sagetile, castiga nivelurile 1,"<<endl;
            cout<<"2, 3 si 4 pentru a avea acces la insula destinatie. Apasa pe ESCAPE pentru a-ti vedea optiunile.\n"<<endl;
            cout<<"Press any key to continue."<<endl;
            system("pause>nul");
            system("cls");

            stare_nivel_1=0;
            stare_nivel_2=0;
            stare_nivel_3=0;
            stare_nivel_4=0;
            x=6;
            y=7;
            numar_vieti=1;
            pistol=false;
            shotgun=false;
            monede_aur=100;
            monede_argint=50;

            Contul_principal<<stare_nivel_1<<' '<<stare_nivel_2<<' '<<stare_nivel_3<<' '<<stare_nivel_4<<' '<<x<<' '<<y<<endl;
            Contul_principal<<numar_vieti<<endl;
            Contul_principal<<pistol<<endl;
            Contul_principal<<shotgun<<endl;
            Contul_principal<<monede_aur<<endl;
            Contul_principal<<monede_argint<<endl;

            harta_princip[20][31]='P';
            harta_princip[30][73]='P';
            harta_princip[18][129]='P';


        }

        else
        {
            Contul_principal>>stare_nivel_1>>stare_nivel_2>>stare_nivel_3>>stare_nivel_4>>x>>y;
            Contul_principal>>numar_vieti;
            Contul_principal>>pistol;
            Contul_principal>>shotgun;
            Contul_principal>>monede_aur;
            Contul_principal>>monede_argint;

            if(stare_nivel_1==1)
                harta_princip[20][31]='Z';

            if(stare_nivel_2==1)
                harta_princip[30][73]='Z';

            if(stare_nivel_3==1)
                harta_princip[18][129]='Z';

        }


        harta_princip[x][y]='@';
        Afisare();

        while(gameOver==false)
        {
            Miscari();

            if( (harta_princip[x-1][y-1]=='1'||harta_princip[x-1][y]=='1'||harta_princip[x-1][y+1]=='1'||harta_princip[x][y-1]=='1'
                    ||harta_princip[x][y+1]=='1'||harta_princip[x+1][y-1]=='1'||harta_princip[x+1][y]=='1'||harta_princip[x+1][y+1]=='1')
                    && GetAsyncKeyState(VK_ENTER)  )
            {
                system("pause>nul");
                if(GetAsyncKeyState(VK_ENTER))
                    Initializare_nivelul_1();

            }
                  Salvari();


            if( (harta_princip[x-1][y-1]=='2'||harta_princip[x-1][y]=='2'||harta_princip[x-1][y+1]=='2'||harta_princip[x][y-1]=='2'
                    ||harta_princip[x][y+1]=='2'||harta_princip[x+1][y-1]=='2'||harta_princip[x+1][y]=='2'||harta_princip[x+1][y+1]=='2')
                    && GetAsyncKeyState(VK_ENTER) )
            {
                system("pause>nul");
                if(GetAsyncKeyState(VK_ENTER))
                    Initializare_nivelul_2();
            }

                  Salvari();


            if( (harta_princip[x-1][y-1]=='3'||harta_princip[x-1][y]=='3'||harta_princip[x-1][y+1]=='3'||harta_princip[x][y-1]=='3'
                    ||harta_princip[x][y+1]=='3'||harta_princip[x+1][y-1]=='3'||harta_princip[x+1][y]=='3'||harta_princip[x+1][y+1]=='3')
                    && GetAsyncKeyState(VK_ENTER) )
            {
                system("pause>nul");
                if(GetAsyncKeyState(VK_ENTER))
                    Initializare_nivelul_3();
            }

                  Salvari();

            if( (harta_princip[x-1][y-1]=='4'||harta_princip[x-1][y]=='4'||harta_princip[x-1][y+1]=='4'||harta_princip[x][y-1]=='4'
                    ||harta_princip[x][y+1]=='4'||harta_princip[x+1][y-1]=='4'||harta_princip[x+1][y]=='4'||harta_princip[x+1][y+1]=='4')
                    && GetAsyncKeyState(VK_ENTER) )
            {
                system("pause>nul");
                if(GetAsyncKeyState(VK_ENTER))
                    Initializare_nivelul_4();
            }


                  Salvari();

            if( (harta_princip[x-1][y-1]=='M'||harta_princip[x-1][y]=='M'||harta_princip[x-1][y+1]=='M'||harta_princip[x][y-1]=='M'
                    ||harta_princip[x][y+1]=='M'||harta_princip[x+1][y-1]=='M'||harta_princip[x+1][y]=='M'||harta_princip[x+1][y+1]=='M')
                    && GetAsyncKeyState(VK_ENTER)  )
            {
                system("pause>nul");
                if(GetAsyncKeyState(VK_ENTER))
                    Initializare_magazin();

            }

            Salvari();

            if(GetAsyncKeyState(VK_ESCAPE))
            {
                int alegere;
                system("cls");
                cout<<"Press 1 to return to the game."<<endl;
                cout<<"Press 2 to go to the main menu."<<endl;
                cin>>alegere;

                if(alegere==2)
                {
                    harta_princip[x][y]='Z';
                    goto AICI;
                }

            }
                  Salvari();


            if(stare_nivel_1==1 && stare_nivel_2==1 && stare_nivel_3==1 && stare_nivel_4==1 && fin==1)
            {
                system("cls");
                system("pause>nul");
                cout<<"Arondel a gasit o baza militara care l-a dus cu elicopterul in civilizatie. Acolo si-a intalnit nevasta si le-a povestit"<<endl;
                cout<<"nepotilor peste ani de experientele sale in solitaritate. Si a trait fericit pana la adanci batraneti."<<endl;
                cout<<endl;
                cout<<"Apasa pe Escape pentru a iesi din joc :) "<<endl;
                system("pause>nul");
                if(GetAsyncKeyState(VK_ESCAPE))
                {
                    cout<<"THE END !"<<endl;
                    break;
                }

                fin=0;
            }


        }




    }

    if(alege==3)
        return 0;


    return 0;
}
///DE FACUT (IN ORDINEA PRIORITATILOR):

///CODEZ CLEAN
///POVESTE
///ALEG LIMBA ENGLEZA PENTRU TOT JOCUL
///REARANJEZ ORDINEA NIVELELOR
/*
Pot folosi for loop pentru liniisi coloane , ca sa fie mai putin cod

for(){


}

if(a[3][1]=='X'&&a[3][2]=='X')
    {
        if(a[3][3]=='#')
        {
            return 33;
        }

    }
*/

