#ifndef NIVEL_3_H
#define NIVEL_3_H


class Nivel_3
{

public:
    int n=5,m=5,i=0,j=0,pl,pc,k,nrb;
    char a[100][100];
    int b[100][100];

    Nivel_3();
    numar_mine(int,int);
    nu_exista_bombe();
    Afisare_harta_a();
    Afisare_harta_b();
    Nr_bombelor_gasite();
    Marchez_vecinii();

};

#endif // NIVEL_3_H
