#include <stdio.h>
#include <stdlib.h>
#include <time.h>
///Algorytm sortujacy WYBOR
/// Zawiera tablice gdzie zapisuje wynik sortowania, zmienna temp do zamiany wartosci w tablicy oraz tabb deklarujacy ilosc liczb do sortowania
void sort_wyb( int* tablica,  int* temp,  int* tabb)
{
    int ilosc = tabb;
    for ( int i = 1; i < ilosc; i++)
    {
        
        for ( int j = i+1; j <= ilosc; j++)
        {
            int tmin = i;
            if (tablica[j] < tablica[tmin]) {
                tmin = j;
            }
            temp = tablica[i];	
            tablica[i] = tablica[tmin];
            tablica[tmin] = temp;
            
            
        }
        
    }
    FILE* plik;
    errno_t err = fopen_s(&plik, "./pliki/w³asne.liczby/Sort_Wyb_Tablica.txt", "w");
  
    for (int i = 1; i <= ilosc; i++) {
       
        fprintf_s(plik, "%d ", tablica[i]);
       // printf("%d, ", tablica[i]);
    }
   
    fclose(plik);
}

///Funkcja losuje tablice wlasnych liczb(10) wczesniej sluzyla do generowania tablic do pomiarow

void los(int* tablica,  int* tabb) {
    int ran = 0;
    srand(time(0));
    FILE* plik;
    errno_t err = fopen_s(&plik, "./pliki/w³asne.liczby/Tablica.txt", "w");
    for ( int i = 1; i <= tabb; i++)
    {
        ran = (rand() % (10000 - (-10000) + 1)) + (-10000);
        tablica[i] = ran;
        fprintf_s(plik, "%d ", ran);
    }
    fclose(plik);
}

///Funkcja zapisuje tablice wlasnych liczb(10) gdy jej nie ma
void zapis_wyb( int* tablica, int* temp,  int* tabb ) {
    int ilosc = tabb;
    FILE* plik;
    errno_t err = fopen_s(&plik, "./Pliki/w³asne.liczby/Tablica.txt", "r");
    if (plik == NULL) {
        los(tablica, 10);
        return;
    }
    for ( int i = 1; i <= ilosc; i++)
    {
        fscanf_s(plik, "%d", &tablica[i]);
       // printf("%d, ", tablica[i]);
    }

    fclose(plik);

}
///W tym miejscu liczony jest czas sortowania wybor i zapisywany do tablicy w miejscu 0 do pozniejszego wyswietlenia

void czas_wyb( int* tablica,  int* temp,  int* tabb) {
    int czas = clock();
    int czas2 = clock();
    int wynik;
    czas = clock();
    sort_wyb(tablica, temp, tabb);
    czas2 = clock();
    tablica[0] = czas2 - czas;
    return 0;

}