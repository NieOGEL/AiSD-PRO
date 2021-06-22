#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#include <allegro5/allegro5.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_primitives.h>
///Funkcja wczytujaca dane pomiarowe z piku Wyniki_kop.txt
///Gdy brak pliku ustawia wartosc tablicy[24] = 123456 
void p_kop(int* wyniki_kop) {

    FILE* plik;
    errno_t err = fopen_s(&plik, "./pliki/wyniki/Wyniki_kop.txt", "r");
    if (plik == NULL) {
        for (int i = 0; i <= 23; i++) {
            wyniki_kop[i] = -1;
        }
        wyniki_kop[24] = 123456;
        return 0;
    }
    for (int i = 0; i <= 21; i++)
    {
        fscanf_s(plik, "%d", &wyniki_kop[i]);
    }
    fclose(plik);
    return *wyniki_kop;
}
///Funkcja liczy srednia oraz wyswietla czasy sortowan
///Gdy wartosc tablicy[24] = 123456 wyswietlony zostaje blad
void tekst_kop(int* wyniki_kop, ALLEGRO_FONT* font36, ALLEGRO_FONT* font22, ALLEGRO_FONT* font16) {
    /*Średnia*/
    float Iks = (wyniki_kop[1] + wyniki_kop[2] + wyniki_kop[3]) / 3;
    float IIks = (wyniki_kop[8] + wyniki_kop[9] + wyniki_kop[10]) / 3;
    float IIIks = (wyniki_kop[15] + wyniki_kop[16] + wyniki_kop[17]) / 3;

    float Iksl = (wyniki_kop[4] + wyniki_kop[5] + wyniki_kop[6]) / 3;
    float IIksl = (wyniki_kop[11] + wyniki_kop[12] + wyniki_kop[13]) / 3;
    float IIIksl = (wyniki_kop[18] + wyniki_kop[19] + wyniki_kop[20]) / 3;
    /*===*/
    if (wyniki_kop[24] == 123456) {
        al_draw_text(font16, al_map_rgb(237, 7, 210), 10, 10, 0, "B[Xd: Brak Pliku z danymi w katalogu ''/wyniki/Wyniki kop.txt''");
        al_draw_text(font16, al_map_rgb(237, 7, 210), 10, 50, 0, "Sprawd^ Pliki lub Zainstaluj Program Ponownie!");
    }
    else {
        al_draw_text(font36, al_map_rgb(237, 7, 210), 10, 10, 0, "Sortowanie przez Kopcowanie");

        al_draw_textf(font22, al_map_rgb(139, 122, 245), 10, 70, 0, "Komputer Stacjonarny:");
        al_draw_textf(font16, al_map_rgb(7, 237, 38), 10, 100, 0, "Dla %d elementVw: %dms, %dms, %dms", wyniki_kop[0], wyniki_kop[1], wyniki_kop[2], wyniki_kop[3]);
        al_draw_textf(font16, al_map_rgb(7, 237, 38), 450, 100, 0, "=rednia: %.0fms", Iks);
        al_draw_textf(font16, al_map_rgb(7, 237, 38), 10, 120, 0, "Dla %d elementVw: %dms, %dms, %dms", wyniki_kop[7], wyniki_kop[8], wyniki_kop[9], wyniki_kop[10]);
        al_draw_textf(font16, al_map_rgb(7, 237, 38), 450, 120, 0, "=rednia: %.0fms", IIks);
        al_draw_textf(font16, al_map_rgb(7, 237, 38), 10, 140, 0, "Dla %d elementVw: %dms, %dms, %dms", wyniki_kop[14], wyniki_kop[15], wyniki_kop[16], wyniki_kop[17]);
        al_draw_textf(font16, al_map_rgb(7, 237, 38), 450, 140, 0, "=rednia: %.0fms", IIIks);

        al_draw_textf(font22, al_map_rgb(139, 122, 245), 10, 170, 0, "Laptop:");
        al_draw_textf(font16, al_map_rgb(7, 237, 38), 10, 200, 0, "Dla %d elementVw: %dms, %dms, %dms", wyniki_kop[0], wyniki_kop[4], wyniki_kop[5], wyniki_kop[6]);
        al_draw_textf(font16, al_map_rgb(7, 237, 38), 450, 200, 0, "=rednia: %.0fms", Iksl);
        al_draw_textf(font16, al_map_rgb(7, 237, 38), 10, 220, 0, "Dla %d elementVw: %dms, %dms, %dms", wyniki_kop[7], wyniki_kop[11], wyniki_kop[12], wyniki_kop[13]);
        al_draw_textf(font16, al_map_rgb(7, 237, 38), 450, 220, 0, "=rednia: %.0fms", IIksl);
        al_draw_textf(font16, al_map_rgb(7, 237, 38), 10, 240, 0, "Dla %d elementVw: %dms, %dms, %dms", wyniki_kop[14], wyniki_kop[18], wyniki_kop[19], wyniki_kop[20]);
        al_draw_textf(font16, al_map_rgb(7, 237, 38), 450, 240, 0, "=rednia: %.0fms", IIIksl);
        al_draw_text(font36, al_map_rgb(205, 5, 255), 10, 550, 0, "PowrVt: ESC");
    }
}