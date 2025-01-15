#ifndef NIVEL_2_H
#define NIVEL_2_H


class Nivel_2
{
private:
    int nr_vieti=0;
    int damageul_armei=0;
public:

    bool gameOver=false, Arondel_Traieste=true,Inamic_Traieste=true;
    int x=10,y=10,viata_inamic=50,xi,yi;

    int Set_Nr_Vieti(int);
    int Set_Damage(int);
    Get_Nr_Vieti();
    Nivel_2();
    Dificultate();
    Afisare();
    Miscari();
    Trage_Arondel();
    Mutarea_Inamicului();

    char harta[30][30]
    {
        "#############################",
        "#                           #",
        "#                           #",
        "#                           #",
        "#                           #",
        "#                           #",
        "#                           #",
        "#                           #",
        "#                           #",
        "#                           #",
        "#                           #",
        "#                           #",
        "#                           #",
        "#                           #",
        "#                           #",
        "#                           #",
        "#                           #",
        "#                           #",
        "#                           #",
        "#                           #",
        "#                           #",
        "#                           #",
        "#                           #",
        "#                           #",
        "#                           #",
        "#                           #",
        "#                           #",
        "#                           #",
        "#                           #",
        "#############################",
    };

};

#endif // NIVEL_2_H
