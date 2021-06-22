#include <allegro5/allegro5.h>
#include <allegro5/allegro_image.h>

void gif_kop(int zeg2, ALLEGRO_BITMAP* longkop)
{
    al_draw_bitmap_region(longkop, 0, (zeg2 * 2880) / 11, 500, 262, 150, 270, NULL);
}

void gif_wyb(int zeg2, ALLEGRO_BITMAP *longwyb) {
    
    al_draw_bitmap_region(longwyb, 0, (zeg2 * 2597) / 13, 500, 199, 150, 300, NULL);

}