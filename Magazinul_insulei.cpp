#include <iostream>
#include "Magazinul_insulei.h"
#include <cmath>
#include <windows.h>
using namespace std;

Magazinul_insulei::Magazinul_insulei()
{

}

void Magazinul_insulei::Setare_valori_initiale(int p, int s, int g, int silver, int v)
{
    if(p==1)
        pistol=true;
    if(s==1)
        shotgun=true;

    G=g;
    S=silver;
    nr_vieti=v;
}

int Magazinul_insulei::Get_Nr_Vieti()
{
    return nr_vieti;
}

Magazinul_insulei::Afisarea_Magazinului()
{
    system("cls");
    int i,j;
    for(i=0; i<=6; i++)
    {
        for(j=0; j<=40; j++)
            cout<<magazin[i][j];
        cout<<endl;
    }

    cout<<endl;
    cout<<"Iteme de vanzare: "<<endl;
    cout<<endl;
    cout<<"Pistol -                 Shotgun =                     1 viata in plus (valabila doar in nivelul 1 si 2)"<<endl;
    cout<<"cod: 1                   cod: 2                        cod: 3"<<endl;
    cout<<"pret: 50G 50S            pret: 69G 69S                 pret: 30G 30S"<<endl;
    cout<<endl;
    cout<<endl;
}



Magazinul_insulei::Inventarul_Meu()
{
    cout<<"INVENTARUL DVS:"<<endl;

    if(pistol==true)
        cout<<"Pistol standard: 1 pct damage inamicilor/glont."<<endl;

    if(shotgun==true)
        cout<<"Shotgunul: 2 pct damage inamicilor/glont."<<endl;

    if(nr_vieti==1)
        cout<<"1 viata"<<endl;
    else
        cout<<nr_vieti<<" vieti."<<endl;

    cout<<"Sold curent: "<<G<<"G "<<S<<"S."<<endl;
    cout<<endl;
}



bool Magazinul_insulei::E_Valida_Comanda()
{
    cout<<"1-cumpara iteme, 2-vinde itemele tale, 9-paraseste magazinul."<<endl;
    cin>>alegere;

    if(alegere==1 || alegere==2)
    {
        cout<<"Introduceti codul produsului:"<<endl;
        cin>>cod;

        if(cod==1)
        {
            if(alegere==1 &&(pistol==true || shotgun==true) )
            {
                cout<<"Nu puteti avea decat o arma pe rand !"<<endl;
                return false;
            }

            if(alegere==2 && pistol==false)
            {
                cout<<"Nu aveti pistolul in inventar."<<endl;
                return false;
            }

            cantitG=50;
            cantitS=50;
        }


        if(cod==2)
        {

            if(alegere==1 &&(pistol==true || shotgun==true) )
            {
                cout<<"Nu puteti avea decat o arma pe rand !"<<endl;
                return false;
            }

            if(alegere==2 && shotgun==false)
            {
                cout<<"Nu aveti shotgunul in inventar."<<endl;
                return false;
            }

            cantitG=69;
            cantitS=69;

        }


        if(cod==3)
        {
            if(alegere==2 && nr_vieti==1 )
            {
                cout<<"Nu puteti vinde singura viata pe care o aveti !"<<endl;
                return false;
            }

            cantitG=30;
            cantitS=30;
        }


        if(alegere==1 && ((G*100+S)<(cantitG*100+cantitS)))
        {
            cout<<"Fonduri insuficiente !"<<endl;
            return false;
        }



        return true;


    }
    else
        return false;

}


Magazinul_insulei::Efectuare_Tranzactie()
{

    if(alegere==1)
    {
        G=G-cantitG;
        nr_arginti=(G*100+S)-cantitS;
        G=nr_arginti/100;
        S=nr_arginti%100;

        if(cod==1)
        {
            pistol=true;
            cout<<"Achizitionare pistolul: Completa."<<endl;
        }

        if(cod==2)
        {
            shotgun=true;
            cout<<"Achizitionare shotgun-ului: Completa."<<endl;
        }

        if(cod==3)
        {
            nr_vieti++;
            cout<<"Achizitionare viata in plus: Completa."<<endl;
        }

    }


    else
    {

        if(cod==1)
        {
            G=G+cantitG;

            if(S+cantitS>=100)
            {
                G=G+(S+cantitS)/100;
                S=(S+cantitS)%100;

            }
            else
                S=S+cantitS;

            pistol=false;
            cout<<"Vanzare pistol: Completa."<<endl;
        }



        if(cod==2)
        {
            G=G+cantitG;

            if(S+cantitS>=100)
            {
                G=G+(S+cantitS)/100;
                S=(S+cantitS)%100;

            }
            else
                S=S+cantitS;

            shotgun=false;
            cout<<"Vanzare shotgun: Completa."<<endl;
        }



        if(cod==3)
        {
            G=G+cantitG;

            if(S+cantitS>=100)
            {
                G=G+(S+cantitS)/100;
                S=(S+cantitS)%100;

            }
            else
                S=S+cantitS;

            nr_vieti--;
            cout<<"Vanzare 1 viata: Completa."<<endl;
        }


    }

}


Magazinul_insulei::Sold_final()
{
    cout<<"Sold final: "<<G<<"G "<<S<<"S."<<endl;
}


bool Magazinul_insulei::Ramai_In_Magazin()
{
        cout<<"1-ramaneti in magazin, 2-iesiti."<<endl;
        cin>>alegere;
        if(alegere==1)
            return true;

            return false;
}
