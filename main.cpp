// fajerwerki

#include <stdio.h>
//#include <math.h>
#include "allegro5/allegro.h"
//#include <allegro5/allegro_primitives.h>
//#include "allegro5/allegro_image.h"
#include "allegroStart.h"
#include "rysuj.h"

void *__gxx_personality_v0;

void point(unsigned char *pt, int xx, int yy,int r, int g, int b);

allegroStart mA(800,600);
ALLEGRO_DISPLAY *okno = mA.openWindow();
ALLEGRO_BITMAP  *bitmapa = mA.openBitmap(800,600);
ALLEGRO_BITMAP  *bitmapa_tlo = mA.openBitmap(800,600);
ALLEGRO_KEYBOARD_STATE klawisz;
ALLEGRO_LOCKED_REGION *lr;
unsigned char *ptr;


int main(int argc, char **argv)
{
 //   rysuj p(300.0, 500.0, 0.0, 0.8, 150.0, 100);     // p = particle(x,y,dx,dy,stop)
 //   rysuj p1(400.0, 550.0, 0.0, 0.3, 140.0, 100);     // p = particle(x,y,dx,dy,stop)
    int ile_p  = 500;   // ile fajerwerkow
    rysuj pp[500];
    float tx, ty, tdx, tdy, tstop, ttx = 0, ttdx=20;
    int tdelay;
    for (int k=1; k<ile_p; k++)
    {
       tx=(rand() % 600 )+100;
       ttx=ttx+ttdx;
       tx=100+ttx;
       if (ttx>600 || ttx<0) ttdx=ttdx*-1;
       ty=(rand() % 50 )+550;
       tdx=(rand() % 30)/10;
       tdx=tdx-0.5;
//        tdx=0;
       tdy=(rand() % 7 );
       tdy=(tdy/100)+0.1;
       tstop=(rand() % 120 )+60;
       tdelay = (rand() % 3000)+1;
        tdelay=k*10;
        pp[k].init(tx, ty, tdx, tdy, tstop, 100, tdelay);
//        pp[2].init(300.0, 550.0, 0.0, 0.6, 120.0, 100);
//        pp[3].init(400.0, 550.0, 0.0, 0.1, 110.0, 100);
//        pp[4].init(500.0, 550.0, 0.0, 0.3, 150.0, 100);
//        pp[5].init(600.0, 550.0, 0.0, 0.2, 90.0, 100);
    }

    int xx,yy;
    int kolor;
    int r,g,b;
	bitmapa_tlo = al_load_bitmap("tlo1.bmp");

    while( !al_key_down( & klawisz, ALLEGRO_KEY_ESCAPE ) )    {

        lr = al_lock_bitmap(bitmapa, ALLEGRO_PIXEL_FORMAT_ABGR_8888, ALLEGRO_LOCK_WRITEONLY);
        ptr = (unsigned char *)lr->data;

        al_clear_to_color(al_map_rgba( 0, 0,0,0));
   //     al_draw_bitmap(bitmapa_tlo,0,0,0);

    for (int k=1; k<ile_p; k++)
    {
        if (pp[k].fire == false)    {
            pp[k].particle_high(xx,yy,r,g,b);
            point(ptr,xx+1,yy,r,g,b);
            point(ptr,xx-1,yy,r,g,b);
            point(ptr,xx,yy-1,r,g,b);
            point(ptr,xx,yy+1,r,g,b);

        } else {
            for (int j=1; j<pp[k].ile; j++)
                {
                    pp[k].particle_fire(j,xx,yy,r,g,b);
if (pp[k].tryb == 1) point(ptr,xx+1,yy,r,g,b);
if (pp[k].tryb == 2) {
                point(ptr,xx+1,yy,r,g,b);
              //      point(ptr,xx-1,yy,r,g,b);
                    point(ptr,xx,yy+1,r,g,b);
              //      point(ptr,xx,yy-1,r,g,b);
}

if (pp[k].tryb == 3) {
                point(ptr,xx+1,yy,r,g,b);
                    point(ptr,xx-1,yy,r,g,b);
                    point(ptr,xx,yy+1,r,g,b);
                    point(ptr,xx,yy-1,r,g,b);
}

                }
            }
    }


        al_draw_bitmap(bitmapa,0,0,0);
        al_unlock_bitmap(bitmapa);

        al_flip_display();
        al_get_keyboard_state( & klawisz );
        al_rest(0.004);
	}

	return 0;
}



void point(unsigned char *pt, int xx, int yy,int r, int g, int b)
{
    if (xx<mA.screenW && yy<mA.screenH && xx>0 && yy>0) {
        int pixel;
        pixel = xx+yy*mA.screenW;
        pt[pixel*4] = r;
        pt[pixel*4+1] = g;
        pt[pixel*4+2] = b;
        pt[pixel*4+3] = 250;
    }
}


