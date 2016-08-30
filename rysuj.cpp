//#include <stdio.h>
//#include <iostream>
#include <cstdlib>
#include <math.h>
//#include <allegro5/allegro_primitives.h>
//#include "allegro5/allegro.h"
//#include "allegro5/allegro_image.h"
#include "rysuj.h"

using namespace std;

rysuj::rysuj()
{

}

rysuj::rysuj(float xx, float yy, float dxx, float dyy, float start_f, int ilee)
{
    /*
    int r1,g1,b1;
    fire=false;
    dx=dxx;
    dy=dyy;
    start_fire=start_f;
    ile=ilee;

    pos[1][0]=xx;
    pos[1][1]=yy;

    for (int i=1; i<ile; i++)
    {
        r1=(rand() % 255 );
        g1=(rand() % 255 );
        b1=(rand() % 255 );
        rgb[i][0]=r1;
        rgb[i][1]=g1;
        rgb[i][2]=b1;
        pos[i][2]=(rand() % 360);
        pos[i][3]=1.0+(rand() % 10)/7;
    }
    */
}

void rysuj::init(float xx, float yy, float dxx, float dyy, float start_f, int ilee, int delayy)
{
    int r1,g1,b1;
    fire=false;
    dx=dxx;
    dy=dyy;
    start_fire=start_f;
    ile=ilee;
    delay=delayy;

    pos[1][0]=xx;
    pos[1][1]=yy;
    tryb =(rand() % 3)+1;
 //   tryb = 2;



    for (int i=1; i<ile; i++)
    {
        r1=(rand() % 255 );
        g1=(rand() % 255 );
        b1=(rand() % 255 );
        rgb[i][0]=r1;
        rgb[i][1]=g1;
        rgb[i][2]=b1;
        pos[i][2]=(rand() % 360);
        pos[i][3]=1.0+(rand() % 10)/7;
    }
}

rysuj::~rysuj() { }

void rysuj::particle_fire(int nr, int &xx, int &yy, int &r, int &g, int &b)
{
    float xt,yt;
    float alfa,power;

    xt=pos[nr][0];
    yt=pos[nr][1];
    alfa=pos[nr][2];
    power=pos[nr][3];

    xt=xt+((sin(alfa*3.14/180))/power);
    yt=yt+((cos(alfa*3.14/180))/power);
    pos[nr][0]=xt;
    pos[nr][1]=yt;


    xx=xt;
    yy=yt;
    rgb[nr][0]--;
    rgb[nr][1]--;
    rgb[nr][2]--;
    if (rgb[nr][0]<0) rgb[nr][0]=0;
    if (rgb[nr][1]<0) rgb[nr][1]=0;
    if (rgb[nr][2]<0) rgb[nr][2]=0;

    r=rgb[nr][0];
    g=rgb[nr][1];
    b=rgb[nr][2];
}

void rysuj::particle_high(int &xx, int &yy, int &r, int &g, int &b)
{

if (delay >= 0)
{
    delay--;
    xx=0;
    yy=0;
    r=0; g=0; b=0;
}
if (delay < 0)
{
    pos[1][0]=pos[1][0]+dx;
    pos[1][1]=pos[1][1]-dy;

    if (pos[1][1]<start_fire) {
        for (int i=2; i<ile; i++)
        {
            pos[i][0]=pos[1][0];
            pos[i][1]=pos[1][1];
        }
       fire=true;
    }
    else {
        dy=dy+(dy/30);
        xx=(int)pos[1][0]; //x;
        yy=(int)pos[1][1]; //y;
        r=rgb[1][0];
        g=rgb[1][1];
        b=rgb[1][2];
    }
}

}

