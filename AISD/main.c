#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#include <allegro5/allegro5.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <stdbool.h> 
#include <windows.h>
#include "p_wyb.h"
#include "p_kop.h"
#include "p_por.h"
#include "gif.h"
#include "s_wyb.h"
#include "s_kop.h"

///W funkci main wczytujemy obrazy, muzyke oraz uruchamiamy allego5 z tym miejscu sa elementy odpowiedzialne za menu, wyciszenie muzyki, wyswietlenie odpowiedniego okna po wyborze wszytko znajduje sie w petli while ktorej wymaga allegro5 aby poprawie wyswietlac ekran dlatego nie sa w osobnych funkcjach


int main() {
    setlocale(LC_CTYPE, "Polish");
 
    HWND hWnd = GetConsoleWindow();
    ShowWindow(hWnd, SW_HIDE);

   // los(tablica, tabb);
    int tablica3[11];
    int tablica2[11];
    int tabb = 10;
    int tablica[11];
    int temp = 0;

    int czasy_sort[2];

    int wyniki_wyb[25];
    p_wyb(wyniki_wyb);

    int wyniki_kop[25];
    p_kop(wyniki_kop);

    bool exit = false;

    int strzalka = 0;
    bool menu = true;
    bool losowanie = false;
    int zeg1 = 0;
    float zeg2 = 0;

    bool test = false;
    int wynik[10];


    al_init();
    al_init_image_addon();
    al_install_keyboard();
    al_init_primitives_addon();
    al_init_font_addon();
    al_init_ttf_addon();
    al_install_audio();
    al_init_acodec_addon();
    al_reserve_samples(1);

    ALLEGRO_DISPLAY* display = NULL;
    ALLEGRO_SAMPLE* audio = NULL;
    ALLEGRO_SAMPLE_INSTANCE* muzyka = NULL;

    bool volume = true;
    audio = al_load_sample("./pliki/Patrol_of_stroll.mp3");
    muzyka = al_create_sample_instance(audio);
    al_attach_sample_instance_to_mixer(muzyka, al_get_default_mixer());
    al_set_sample_instance_playmode(muzyka, ALLEGRO_PLAYMODE_LOOP);
    al_set_sample_instance_gain(muzyka, 0.1);
    al_play_sample_instance(muzyka);

    int szer = 800, wys = 600;
    al_set_new_display_flags(ALLEGRO_WINDOWED | ALLEGRO_RESIZABLE); //skalowanie zawart. okna
    display = al_create_display(szer, wys);

    if (!display)
    {
        printf("Nie udalo sie utworzyc okna!");
        return 0;
    }

    ALLEGRO_FONT* font36 = al_load_font("./pliki/arial_e.ttf", 36, 0);
    ALLEGRO_FONT* font22 = al_load_font("./pliki/arial_e.ttf", 22, 0);
    ALLEGRO_FONT* font16 = al_load_font("./pliki/arial_e.ttf", 16, 0);

    ALLEGRO_BITMAP* ikonka = al_load_bitmap("./pliki/aisd.bmp");
    if (!ikonka) {
        printf("Nie udalo sie wczytac obrazka 'aisd.bmp'.");
        return 0;
    }

    ALLEGRO_BITMAP* longwyb = al_load_bitmap("./pliki/wybor/longwyb.png");
    if (!longwyb) {
        printf("Nie udalo sie wczytac obrazka 'longwyb.png'.");
        return 0;
    }


    ALLEGRO_BITMAP* longkop = al_load_bitmap("./pliki/kopcowanie/longkop.png");
    if (!longkop) {
        printf("Nie udalo sie wczytac obrazka 'longkop.png'.");
        return 0;
    }
    ALLEGRO_EVENT ev;
    ALLEGRO_EVENT_QUEUE* event_queue = al_create_event_queue();
    al_register_event_source(event_queue, al_get_keyboard_event_source());
    al_register_event_source(event_queue, al_get_display_event_source(display));
    al_set_display_icon(display, ikonka);
    ALLEGRO_KEYBOARD_STATE key_state;

    while (!exit)
    {
        al_get_keyboard_state(&key_state);

        al_get_next_event(event_queue, &ev);
        //al_wait_for_event(event_queue, &ev);
        al_clear_to_color(al_map_rgb(66, 66, 66));

        if (ev.type == ALLEGRO_EVENT_KEY_DOWN) {
            switch (ev.keyboard.keycode)
            {
            case ALLEGRO_KEY_F1:
                if (volume) {
                    al_stop_sample_instance(muzyka);
                    volume = false;
                }
                else {
                    al_play_sample_instance(muzyka);;
                    volume = true;
                }
                break;
            case ALLEGRO_KEY_ESCAPE:
                menu = true;
                zeg1 = 0;
                zeg2 = 0;
                losowanie = false;
                break;
            case ALLEGRO_KEY_ENTER:
                menu = false;
                break;
            }

        }
        if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
            exit = true;
        }


        if (!menu && strzalka == 0) {
            //POLE SORT WYBÓR
            al_set_window_title(display, "AiSD_PRO - Sortowanie przez Prosty Wybor");
            tekst_wyb(wyniki_wyb, font36, font22, font16);

            //ZEGAR GIF
            if (zeg1 >= 400) {  //Co 10 ticków +1 do a
                zeg1 = 0;
                zeg2++;
                if (zeg2 == 13) { //iloœæ klatek gif
                    zeg2 = 0;  //powrót do 1 klatki
                }
            }
            else {
                zeg1++;
            }
            //==== 
            gif_wyb(zeg2, longwyb);

        }


        if (!menu && strzalka == 1) {
            //POLE SORT KOPCOWANIE
            al_set_window_title(display, "AiSD_PRO - Sortowanie przez Kopcowanie");
            tekst_kop(wyniki_kop, font36, font22, font16);

            //ZEGAR GIF
            if (zeg1 >= 500) {  //Co 10 ticków +1 do a
                zeg1 = 0;
                zeg2++;
                if (zeg2 == 11) { //iloœæ klatek gif
                    zeg2 = 0;  //powrót do 1 klatki
                }
            }
            else {
                zeg1++;
            }
            //====
            gif_kop(zeg2, longkop);
        }

        if (!menu && strzalka == 2) {
            //POLE PORÓWNAWCZE
            al_set_window_title(display, "AiSD_PRO - Prosty Wybor vs Kopcowanie");
            
            tekst_por(wyniki_kop, wyniki_wyb, font36, font22, font16);
            if (losowanie) {
                
                al_draw_text(font22, al_map_rgb(252, 186, 3), 10, 350, 0, "Twoja Tablica :");
                al_draw_textf(font16, al_map_rgb(5, 238, 255), 10, 375, 0, "  %d, %d, %d, %d, %d, %d, %d, %d, %d, %d",tablica3[1], tablica3[2], tablica3[3], tablica3[4], tablica3[5], tablica3[6], tablica3[7], tablica3[8], tablica3[9], tablica3[10] );
                al_draw_textf(font22, al_map_rgb(252, 186, 3), 10, 400, 0, "Posortowana Tablica (Prosty wybVr) Czas: %dms:", tablica[0]);
                al_draw_textf(font16, al_map_rgb(5, 238, 255), 10, 425, 0, "  %d, %d, %d, %d, %d, %d, %d, %d, %d, %d", tablica[1], tablica[2], tablica[3], tablica[4], tablica[5], tablica[6], tablica[7], tablica[8], tablica[9], tablica[10]);
                al_draw_textf(font22, al_map_rgb(252, 186, 3), 10, 450, 0, "Posortowana Tablica (Kopcowanie) Czas: %dms:", tablica2[0]);
                al_draw_textf(font16, al_map_rgb(5, 238, 255), 10, 475, 0, "  %d, %d, %d, %d, %d, %d, %d, %d, %d, %d", tablica2[1], tablica2[2], tablica2[3], tablica2[4], tablica2[5], tablica2[6], tablica2[7], tablica2[8], tablica2[9], tablica2[10]);
                al_draw_text(font22, al_map_rgb(252, 3, 169), 10, 500, 0, "NaciYnij Spacj` aby zresetowa@");

            }
            else {
                al_draw_text(font22, al_map_rgb(252, 186, 3), 10, 350, 0, "Cyfry mo_na zmieni@ w katalogu programu ''/w[asne.liczby/Tablica.txt''");
                al_draw_text(font22, al_map_rgb(255, 0, 0), 10, 375, 0, "(Limit 10 cyfr!!)");
                al_draw_text(font22, al_map_rgb(252, 3, 169), 10, 410, 0, "NaciYnij Spacj` aby posortowa@ w[asnX tablic`");
            }

            if (ev.type == ALLEGRO_EVENT_KEY_DOWN) {
                if (ev.keyboard.keycode == ALLEGRO_KEY_SPACE) {

                    if (!losowanie) {
                        zapis_wyb(tablica, temp, tabb);
                        zapis_kop(tablica2, temp, tabb, tablica3);
                        czas_wyb(tablica, temp, tabb);
                        czas_kop(tablica2, temp, tabb);
                        losowanie = true;
                    }
                    else {
                        losowanie = false;
                    }
                   
                }
            }
        }


        if (menu) {
            //POLE MENU
            al_set_window_title(display, "AiSD_PRO - Menu");

            al_draw_text(font36, al_map_rgb(205, 5, 255), 10, 550, 0, "Zatwierd^: ENTER");
            if (volume) {
                al_draw_textf(font16, al_map_rgb(38, 201, 32), 10, 5, 0, "Wy[Xcz d^wi`k: F1");
            }
            else {
                al_draw_textf(font16, al_map_rgb(201, 32, 57), 10, 5, 0, "W[Xcz d^wi`k: F1");
            }

            if (ev.type == ALLEGRO_EVENT_KEY_DOWN) {
                switch (ev.keyboard.keycode)
                {
                case ALLEGRO_KEY_UP:
                    if (strzalka == 0) {
                        strzalka = 2;
                    }
                    else {
                        strzalka -= 1;
                    }
                    break;
                case ALLEGRO_KEY_DOWN:
                    if (strzalka == 2) {
                        strzalka = 0;
                    }
                    else {
                        strzalka += 1;
                    }
                    break;
                }
            }


            //WYBÓR ZAK£ADKI + ZMIANA KOLORU TEKSTU
            switch (strzalka)
            {
            case 0:
                al_draw_text(font36, al_map_rgb(0, 230, 54), 50, 200, 0, "  >");

                al_draw_text(font36, al_map_rgb(0, 230, 54), 100, 200, 0, "Sortowanie przez prosty wybVr");
                al_draw_text(font36, al_map_rgb(205, 5, 255), 100, 250, 0, "Sortowanie przez kopcowanie");
                al_draw_text(font36, al_map_rgb(205, 5, 255), 100, 300, 0, "PorVwnanie Sortowa~");

                break;
            case 1:
                al_draw_text(font36, al_map_rgb(0, 230, 54), 50, 250, 0, "  >");
                al_draw_text(font36, al_map_rgb(205, 5, 255), 100, 200, 0, "Sortowanie przez prosty wybVr");
                al_draw_text(font36, al_map_rgb(0, 230, 54), 100, 250, 0, "Sortowanie przez kopcowanie");
                al_draw_text(font36, al_map_rgb(205, 5, 255), 100, 300, 0, "PorVwnanie Sortowa~");
                break;
            case 2:
                al_draw_text(font36, al_map_rgb(0, 230, 54), 50, 300, 0, "  >");
                al_draw_text(font36, al_map_rgb(205, 5, 255), 100, 200, 0, "Sortowanie przez prosty wybVr");
                al_draw_text(font36, al_map_rgb(205, 5, 255), 100, 250, 0, "Sortowanie przez kopcowanie");
                al_draw_text(font36, al_map_rgb(0, 230, 54), 100, 300, 0, "PorVwnanie Sortowa~");
                break;
            }
            //=========

        }
        //al_rest(0.1);
        al_flip_display();
    }
    al_destroy_display(display);
    al_destroy_font(font36);
    al_destroy_font(font22);
    al_destroy_font(font16);
    al_destroy_bitmap(longwyb);
    al_destroy_bitmap(longkop);
    al_destroy_bitmap(ikonka);
    al_destroy_sample(audio);
    al_destroy_sample_instance(muzyka);
}
