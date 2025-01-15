#ifndef NIVEL_1_H
#define NIVEL_1_H


class Nivel_1
{
private:

    bool continua=true;
    int k=0,i,x=2,y=1,ok=0,nrv=1,nrchei=0;

public:

    Nivel_1();
    Afisare();
    Poz_Cheie();
    Miscari();
    Gravitatie();
    void Set_Nr_Vieti(int);
    int Get_Nr_Vieti();
    int Get_Nr_Chei();
    bool Game_Over();


    char harta[20][30]
    {
        "#############################",
        "#     Z                     P",
        "#     Z ZZZZZZZ Z ZZZZZ Z ZZ#",
        "#ZZZ  Z         Z       Z   #",
        "#  Z  Z     ZZZZZ       Z   #",
        "#  Z        Z           Z   #",
        "#  ZZZ ZZZZZZ       ZZZZZ Z #",
        "#    Z                    Z #",
        "#    Z                  ZZZ #",
        "#    Z ZZZ ZZZZZ        Z   #",
        "#    Z         Z        Z   #",
        "#    ZZZZ ZZZZ Z        Z   #",
        "#              ZZZZZ ZZZZ   #",
        "# ZZZ ZZZZZZZZZZ     Z      #",
        "#     Z              Z      #",
        "#     Z             ZZ      #",
        "#  ZZ Z                     #",
        "#                           #",
        "#LLLLLLLLLLLLLLLLLLLLLLLLLLL#",

    };


};

#endif // NIVEL_1_H
