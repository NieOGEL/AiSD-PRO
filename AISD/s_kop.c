#include <stdio.h>
#include <stdlib.h>
#include <time.h>
///Algorytm sortujacy KOPCOWANIE 
/// Zawiera tablice 2 gdzie zapisuje wynik sortowania, zmienna temp do zamiany wartosci w tablicy oraz tabb deklarujacy ilosc liczb do sortowania
void sort_kop( int* tablica2,  int* temp,  int* tabb) {
    int ilosc = tabb;
    int i = 0, j = 0, b = 0, c = 0, tmp = 0, temps=0;
    for (i = 2; i <= ilosc; i++)
    {
        j = i;
        b = j / 2;
        tmp = tablica2[i];
        while ((b > 0) && (tablica2[b] < tmp))
        {
            tablica2[j] = tablica2[b];
            j = b; 
            b = j / 2;
        }
        tablica2[j] = tmp;
    }
    for (i = ilosc; i > 1; i--)
    {
        temps = tablica2[i];
        tablica2[i] = tablica2[1];
        tablica2[1] = temps;
        j = 1; 
        b = 2;
        while (b < i)
        {
            if ((b + 1 < i) && (tablica2[b + 1] > tablica2[b])) {
                c = b + 1;
            }
            else {
                c = b;
            }
            if (tablica2[c] <= tablica2[j]) {
                break;
            }
            temps = tablica2[c];
            tablica2[c] = tablica2[j];
            tablica2[j] = temps;
            j = c; b = j + j;
        }
    }
    FILE* plik;
    errno_t err = fopen_s(&plik, "./pliki/w³asne.liczby/Sort_Kop_Tablica.txt", "w");
    for (int i = 1; i <= ilosc; i++) {

        fprintf_s(plik, "%d ", tablica2[i]);
      //  printf("%d, ", tablica2[i]);
    }

    fclose(plik);
}
///Algorytm sortujacy KOPCOWANIE 
/// Zawiera tablice 2 gdzie znajduje sie wynik sortowania, tabb deklarujacy ilosc liczb do sortowania oraz tablice3 ktora zachowuje stan tablicy przed sortowaniem

void zapis_kop( int* tablica2,  int* temp,  int* tabb, int* tablica3 ) {
    int ilosc = tabb;
    FILE* plik;
    errno_t err = fopen_s(&plik, "./pliki/w³asne.liczby/Tablica.txt", "r");
    for ( int i = 1; i <= ilosc; i++)
    {
        fscanf_s(plik, "%d", &tablica2[i]);
    }

    fclose(plik);
    for (int i = 1; i <= ilosc; i++) {
        tablica3[i] = tablica2[i];
       // printf("%d, ", tablica3[i]);
    }
}
///W tym miejscu liczony jest czas sortowania kopcowanie i zapisywany do tablicy2 w miejscu 0 do pozniejszego wyswietlenia

void czas_kop( int* tablica2,  int* temp,  int* tabb) {
    int czas = clock();
    int czas2 = clock();
    czas = clock();
    sort_kop(tablica2, temp, tabb);
    czas2 = clock();
    tablica2[0] = czas2 - czas;
    return 0;
}