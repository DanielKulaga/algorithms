#include <iostream>
#include <stdlib.h>

using namespace std;

void losowa_tablica(int tab[] )
{
	for (int i = 0; i < 100; i++)
	{
		tab[i] = rand() % tab[i];
	}
	
}
void rosnaca_tablica(int tab[])
{
	for (int i = 0; i < 100; i++)
	{
		tab[i] = i;
	}
}
void malejaca_tablica(int tab[])
{
	for (int i = 0; i < 100; i++)
	{
		if (i == 0)
		{
			tab[i] = 99;
		}
		else {
			tab[i] = tab[i - 1] - 1;
		}
	}
}
	
	void sortowanie_babelkowe(int tab[], int n)
	{
		for (int i = 0; i < n; i++)
			for (int j = 1; j < n - i; j++) //pętla wewnętrzna
				if (tab[j - 1] > tab[j])
					//zamiana miejscami
					swap(tab[j - 1], tab[j]);
	}
	void selection_sort(int tab[], int n) //n - ilość elementów do posortowania
	{
		int mn_index; //zmienna pomocnicza przechowująca indeks komórki 
				//z minimalną wartością
		for (int i = 0; i < n - 1; i++)
		{
			mn_index = i;
			for (int j = i + 1; j < n; j++) //pętla wyszukuje najmniejszy element w podzbiorze nieposortowanym
				if (tab[j] < tab[mn_index])
					mn_index = j;

			//zamiana elementu najmniejszego w podzbiorze z pierwszą pozycją nieposortowaną
			swap(tab[i], tab[mn_index]);
		}
	}
	void sortowanie_przez_wstawianie(int n, int* tab)
	{
		int pom, j;
		for (int i = 1; i < n; i++)
		{
			//wstawienie elementu w odpowiednie miejsce
			pom = tab[i]; //ten element będzie wstawiony w odpowiednie miejsce
			j = i - 1;

			//przesuwanie elementów większych od pom
			while (j >= 0 && tab[j] > pom)
			{
				tab[j + 1] = tab[j]; //przesuwanie elementów
				--j;
			}
			tab[j + 1] = pom; //wstawienie pom w odpowiednie miejsce
		}
	}
	void quick_sort(int *tab, int lewy, int prawy)
{
	if(prawy <= lewy) return;
	
	int i = lewy - 1, j = prawy + 1, 
	pivot = tab[(lewy+prawy)/2]; //wybieramy punkt odniesienia
	
	while(1)
	{
		//szukam elementu wiekszego lub rownego piwot stojacego
		//po prawej stronie wartosci pivot
		while(pivot>tab[++i]);
		
		//szukam elementu mniejszego lub rownego pivot stojacego
		//po lewej stronie wartosci pivot
		while(pivot<tab[--j]);
		
		//jesli liczniki sie nie minely to zamień elementy ze soba
		//stojace po niewlasciwej stronie elementu pivot
		if( i <= j)
			//funkcja swap zamienia wartosciami tab[i] z tab[j]
			swap(tab[i],tab[j]);
		else
			break;
	}

	if(j > lewy)
	quick_sort(tab, lewy, j);
	if(i < prawy)
	quick_sort(tab, i, prawy);
}

int main()
{
	int tab[100];
	losowa_tablica(tab);
	for (int i = 0; i < 100; i++)
	{
		cout << tab[i] << endl;
	}
	quick_sort(tab, tab[0], tab[99]);

	
    
}
