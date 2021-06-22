#pragma once
#include <allegro5/allegro5.h>
#include <allegro5/allegro_image.h>
/// Wyswietlamy obrazek przedstawiajacy prace algorytmu kopcowania
/// zeg2 jest wartoscia zliczana co 400 tikow zeg1 tzn. co 400 zeg1 dodajemy 1 do zeg2 co pozwala uzyskac animacje obrazu
void gif_kop(int zeg2, ALLEGRO_BITMAP* longkop);

/// Wyswietlamy obrazek przedstawiajacy prace algorytmu wyboru
/// zeg2 jest wartoscia zliczana co 400 tikow zeg1 tzn. co 400 zeg1 dodajemy 1 do zeg2 co pozwala uzyskac animacje obrazu
void gif_wyb(int zeg2, ALLEGRO_BITMAP* longwyb);