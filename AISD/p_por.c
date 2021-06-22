#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#include <allegro5/allegro5.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_primitives.h>
///Okno Porownawcze w ktorym wyswietlamy srednie czasy sortowan KOPCOWANIA I WYBORU w ladnej tabelce

void tekst_por(int* wyniki_kop, int* wyniki_wyb, ALLEGRO_FONT* font36, ALLEGRO_FONT* font22, ALLEGRO_FONT* font16) {
    /*Œrednia*/
    float Iks = (wyniki_kop[1] + wyniki_kop[2] + wyniki_kop[3]) / 3;
    float IIks = (wyniki_kop[8] + wyniki_kop[9] + wyniki_kop[10]) / 3;
    float IIIks = (wyniki_kop[15] + wyniki_kop[16] + wyniki_kop[17]) / 3;

    float Iksl = (wyniki_kop[4] + wyniki_kop[5] + wyniki_kop[6]) / 3;
    float IIksl = (wyniki_kop[11] + wyniki_kop[12] + wyniki_kop[13]) / 3;
    float IIIksl = (wyniki_kop[18] + wyniki_kop[19] + wyniki_kop[20]) / 3;

    float Iksw = (wyniki_wyb[1] + wyniki_wyb[2] + wyniki_wyb[3]) / 3;
    float IIksw = (wyniki_wyb[8] + wyniki_wyb[9] + wyniki_wyb[10]) / 3;
    float IIIksw = (wyniki_wyb[15] + wyniki_wyb[16] + wyniki_wyb[17]) / 3;

    float Ikslw = (wyniki_wyb[4] + wyniki_wyb[5] + wyniki_wyb[6]) / 3;
    float IIkslw = (wyniki_wyb[11] + wyniki_wyb[12] + wyniki_wyb[13]) / 3;
    float IIIkslw = (wyniki_wyb[18] + wyniki_wyb[19] + wyniki_wyb[20]) / 3;

    /*===*/
    al_draw_text(font36, al_map_rgb(237, 7, 210), 10, 10, 0, "PorVwnanie Sortowa~");
    
    al_draw_textf(font22, al_map_rgb(139, 122, 245), 100, 70, 0, "Komputer Stacjonarny:");

    al_draw_text(font16, al_map_rgb(7, 237, 38), 100, 100, 0, "=rednia 1000 elementVw: ");
    al_draw_text(font16, al_map_rgb(7, 237, 38), 100, 120, 0, "=rednia 10000 elementVw: ");
    al_draw_text(font16, al_map_rgb(7, 237, 38), 100, 140, 0, "=rednia 100000 elementVw: ");

    al_draw_text(font22, al_map_rgb(237, 7, 210), 360, 70, 0, "Prosty WybVr:");
    al_draw_textf(font16, al_map_rgb(7, 237, 38), 400, 100, 0, "%.0fms", Iksw);
    al_draw_textf(font16, al_map_rgb(7, 237, 38), 400, 120, 0, "%.0fms", IIksw);
    al_draw_textf(font16, al_map_rgb(7, 237, 38), 400, 140, 0, "%.0fms", IIIksw);

    al_draw_text(font22, al_map_rgb(237, 7, 210), 560, 70, 0, "Kopcowanie:");
    al_draw_textf(font16, al_map_rgb(7, 237, 38), 600, 100, 0, "%.0fms", Iks);
    al_draw_textf(font16, al_map_rgb(7, 237, 38), 600, 120, 0, "%.0fms", IIks);
    al_draw_textf(font16, al_map_rgb(7, 237, 38), 600, 140, 0, "%.0fms", IIIks);

    al_draw_textf(font22, al_map_rgb(139, 122, 245), 100, 170, 0, "Laptop:");

    al_draw_text(font16, al_map_rgb(7, 237, 38), 100, 200, 0, "=rednia 1000 elementVw: ");
    al_draw_text(font16, al_map_rgb(7, 237, 38), 100, 220, 0, "=rednia 10000 elementVw: ");
    al_draw_text(font16, al_map_rgb(7, 237, 38), 100, 240, 0, "=rednia 100000 elementVw: ");

    al_draw_textf(font16, al_map_rgb(7, 237, 38), 400, 200, 0, "%.0fms", Ikslw);
    al_draw_textf(font16, al_map_rgb(7, 237, 38), 400, 220, 0, "%.0fms", IIkslw);
    al_draw_textf(font16, al_map_rgb(7, 237, 38), 400, 240, 0, "%.0fms", IIIkslw);

    al_draw_textf(font16, al_map_rgb(7, 237, 38), 600, 200, 0, "%.0fms", Iksl);
    al_draw_textf(font16, al_map_rgb(7, 237, 38), 600, 220, 0, "%.0fms", IIksl);
    al_draw_textf(font16, al_map_rgb(7, 237, 38), 600, 240, 0, "%.0fms", IIIksl);
    
    al_draw_text(font36, al_map_rgb(205, 5, 255), 10, 550, 0, "PowrVt: ESC");

    al_draw_rectangle(80, 60, 700, 280, al_map_rgb(252, 115, 3), 2);
    al_draw_line(345, 60, 345, 280, al_map_rgb(252, 115, 3), 2);
    al_draw_line(525, 60, 525, 280, al_map_rgb(252, 115, 3), 2);


    al_draw_text(font22, al_map_rgb(139, 122, 245), 10, 280, 0, "Po porVwnaniu wynikVw mo_emy stwierdzi@ _e Sortowanie przez Kopcowanie");
    al_draw_text(font22, al_map_rgb(139, 122, 245), 10, 305, 0, "jest szybsze ni_ Sortowanie przez Prosty WybVr");

  
}