#ifndef NIVEL_4_H
#define NIVEL_4_H

#define P1_11 0
#define P2_11 0
#define P1_22 1
#define P2_22 1

class Nivel_4
{
public:

    char a[3][3];
    int c[5]={0,0,0,0,0};
    int b[34][34]={ { 0 } };
    ///b[P1_11][P2_22] = 33;

    int i,j,XorO=1,pl,pc,alegere,pas=1,caz1=0,caz2=0,blocare,l=1,primulX=0,AlDoileaX=0,pozitie,pozitieO,nivel;

    Nivel_4();
    int castigsauegalit();
    int Caut_pt_O();
    int Liber_pt_O();
    int Strategie();
    int Blocare_X_1();
    int Blocare_X_2();
    Combinatii();
    Afisare();
    Pune_random_O();


};

#endif // NIVEL_4_H
