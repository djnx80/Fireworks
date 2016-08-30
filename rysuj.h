#ifndef _RYSUJ_H_
#define _RYSUJ_H_
class rysuj
{
private:
    float dx,dy;
    float start_fire;
    float pos[100][4];      // pos[nr][x,y,kat_L, power]
    int rgb[100][3];        // tablica powinna byc rowna "ile" z public
    int delay;

public:
    bool fire;
    int ile;
    int tryb; // =1 -1 piksel. =2 -2 piksele. itp
    rysuj();
    rysuj(float, float, float, float, float, int);
    void init(float, float, float, float, float, int, int);
    ~rysuj();
    void particle_high(int &, int &, int &, int &, int &);
    void particle_fire(int, int &, int &, int &, int &, int &);

};
#endif
