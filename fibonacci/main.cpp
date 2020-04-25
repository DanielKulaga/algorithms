#include <iostream>
#include <stdio.h>
#include <math.h>

using namespace std;

int fibonacci_ite(int n)
{
    int a =  0, b = 1 , m = 0;
    if(n==0) return 0;
    n=n-1;
    for(int i =0; i < n; i++)
    {
        b += a; //do zmiennej b idzie wyraz nastepny a+b
        a = b-a;//pod zmienna a wartosc zmiennej b z poprzedniego
        cout << "Teraz licze:" << m << "ktorego wartosc to:" << b << endl;
        m++;

    }
    return b;


}

int fibonacci(int n)
{
    for(unsigned int i=1; i<=n; ++i){
        cout << fibonacci(i) << endl;
    }
    cout << fibonacci(n);



    /*if(n<3)
		return 1;
    else
    return (((1/sqrt(5))*pow(((1+sqrt(5))/2),n))-((1/sqrt(5))*pow(((1-sqrt(5))/2),n)));
    */

}

int main()
{
    double wynik;
    int n; // numer wyrazu ciagu fibonacciego

    int w; //zmienna do wyboru rodzaju algorytmu
    cout << "Ile chesz wypisac wyrazow ciagu Fibonacciego?" << endl;
    cin >> n;
    cout << "Chcesz zebym zrobil to iteracyjnie(wpisz1) czy rekurencyjnie(wpisz 2)?" << endl;
    cin >> w;
    switch(w)
    {
        case(1):
            wynik = fibonacci_ite(n);
            cout << wynik << endl;
         break;
        case(2):
            if(n == 0) return 0;
            if(n == 1) return 1;
            else return fibonacci(n-1)+fibonacci(n-2);


            //wynik = fibonacci_rek(n);
            //cout << wynik << endl;
         break;
        default:
        cout << "Podales zla wartosc,musisz wpisac 1 lub 2" << endl;
         break;
    }



}
