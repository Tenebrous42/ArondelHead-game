#ifndef MAGAZINUL_INSULEI_H
#define MAGAZINUL_INSULEI_H


class Magazinul_insulei
{
private:
    int nr_vieti=1;

public:

    int G, S, cantitG, cantitS, alegere, cod, nr_arginti;
    bool pistol=false, shotgun=false;

    Magazinul_insulei();

    void Setare_valori_initiale(int, int, int, int, int);
    int Get_Nr_Vieti();

    Afisarea_Magazinului();
    Inventarul_Meu();
    Efectuare_Tranzactie();
    bool E_Valida_Comanda();
    Sold_final();
    bool Ramai_In_Magazin();

    char magazin[7][41]
    {
        "########################################",
        "#                                      #",
        "# MAGAZINUL GENIAL RANDOM DE PE INSULA #",
        "#  (are mai multa logica cu cat te     #",
        "#         gandesti mai putin)          #",
        "#                                      #",
        "########################################",

    };


};

#endif // MAGAZINUL_INSULEI_H
