#include <iostream>

using namespace std;
const int n = 1000;


template <typename T>
class Container {
public:
	
	virtual T Count() const;
	virtual ~Container() {};
	virtual bool IsEmpty() const;
	virtual bool IsFull() const { return false; }
	virtual void MakeNull() = 0;

};

struct cell {
	char value;
	int priority;
};
int counter = 0;
template <typename T>
class PriorityQueue : public Container<T>{
public:
	virtual void Enqueue();
	virtual T FindMax();
	virtual T DequeueMax();

};
template <typename T>
class Heap
{
public:
	T nodes[1000];
	int num_of_elements = 0;
	void add(int a, char b);
	void show();
	
};

//Tablicowa
template <typename T>
class TabPQ : public PriorityQueue<T>
{
public:

	T tab[n];
	int num_of_tab = 0; //liczba elementowt ablicy
public:
	void Enqueue_t(int priority, char value);
	void show_tab();
	T FindMax_t();
	T DequeueMax_t();
	int getCounter();

};
template <typename T>
T TabPQ<T>::FindMax_t() {
	T max;
	max.priority = tab[0].priority;
	max.value = tab[0].value;

	for (int i = 0; i < num_of_tab; i++) {

		if (max.priority < tab[i].priority) {
			max.priority = tab[i].priority;
			max.value = tab[i].value;
		}
		counter++;
	}

	return max;
}
template <typename T>
void TabPQ<T>::Enqueue_t(int priority, char value) {
	tab[num_of_tab].priority = priority;
	tab[num_of_tab].value = value;
	num_of_tab++;
}


template <typename T>
T TabPQ<T>::DequeueMax_t() {
	T d_max;
	d_max.priority = tab[0].priority;
	d_max.value = tab[0].value;
	int i;
	int j = 0;
	for (i = 0; i < num_of_tab; i++)
	{
		if (d_max.priority < tab[i].priority)
		{
			d_max.priority = tab[i].priority;
			d_max.value = tab[i].value;
			j = i;
			counter++;
		}
		counter++;
	}

	int k = j + 1;
	for (j; j < num_of_tab; j++)
	{
		tab[j] = tab[k];
		k++;
	}

	num_of_tab--;

	return d_max;
}
template <typename T>
void TabPQ<T>::show_tab()
{
	for (int i = 0; i < num_of_tab; i++)
	{
		cout << "(" << tab[i].priority << ", " << tab[i].value << ")" << " ";
	}
}
//Implementacja kolejki priorytetowej za pomoca kopca binarnego
template <typename T >
class HeapPQ : public Heap<T>, public PriorityQueue<T>
{

public:
	void Enqueue(int priority, char value);
	T FindMax();
	T DequeueMax();
	void show();
	void downheap(int i);
	int getCounter();
};


template <typename T>
void HeapPQ<T>::downheap(int i)
{
	int a = (2 * i) + 1;
	int b = (2 * i) + 2;
	if (b < num_of_elements) {
		if (nodes[i].priority < nodes[b].priority) {
			cell t = nodes[i];
			nodes[i] = nodes[b];
			nodes[b] = t;
			downheap(b);
			counter++;
		}
		if (nodes[i].priority < nodes[a].priority) {
			cell p = nodes[i];
			nodes[i] = nodes[a];
			nodes[a] = p;
			downheap(a);
			counter++;
		}
		counter++;
	}
}
template <typename T>
void  HeapPQ<T>::Enqueue(int priority, char value) {
	T e;
	e.priority = priority;
	e.value = value;
	add(e.priority, e.value);
}
template <typename T>

T HeapPQ<T>::FindMax()
{
	return nodes[0];
}
template <typename T>
T HeapPQ<T>::DequeueMax()
{

	cell max;
	max = nodes[0];


	int k = num_of_elements - 1;
	nodes[0] = nodes[k];
	num_of_elements = num_of_elements - 1;
	downheap(0);

	return max;
}
template <typename T>
void Heap<T>::add(int a, char b)
{
	int i = num_of_elements++;
	int j = (i - 1) / 2;
	while (i > 0 && a > nodes[j].priority)
	{
		nodes[i] = nodes[j];
		i = j;
		j = (i - 1) / 2;
		counter++;
	}

	nodes[i].priority = a;
	nodes[i].value = b;
}
template< typename T>
void Heap<T>::show()
{
	for (int i = 0; i < num_of_elements; i++)
	{
		cout << "(" << nodes[i].priority << ',' << nodes[i].value << ')' << " ";
	}
}
template <typename T >

void HeapPQ<T>::show()
{
	for (int i = 0; i < num_of_elements; i++)
	{
		cout << "(" << nodes[i].priority << ", " << nodes[i].value << ")" << " ";
	}
}
template <typename T >

int HeapPQ<T>::getCounter()
{
	return counter;
}
template <typename T>
int TabPQ<T>::getCounter()
{
	return counter;
}




int main()
{
	//Przedstawiony przyklad z pliku pdf w celu zaprezentowania dzialania
	cout << "Implementacja kolejki priorytetowej za pomocą tablicy " << endl;

	TabPQ<cell> tab;
	tab.Enqueue_t(4, 'K');
	tab.Enqueue_t(1, 'A');
	tab.Enqueue_t(9, 'A');
	tab.Enqueue_t(3, 'O');
	tab.Enqueue_t(8, 'L');



	tab.show_tab();
	cout << endl;
	cout << "Findmax " << "(" << tab.FindMax_t().priority << "," << tab.FindMax_t().value << ")" << endl;

	cout << "Dequeue " << "(" << tab.DequeueMax_t().priority << "," << tab.FindMax_t().value << ")" << endl;
	tab.show_tab();

	cout << endl;

	tab.show_tab();
	cout << "Ilosc porownan : " << tab.getCounter() << endl;

	cout << endl;

	cout << "Implementacja kolejki priorytetowej za pomoca kopca binarnego" << endl;
	HeapPQ<cell> heappq;

	heappq.Enqueue(4, 'K');
	heappq.Enqueue(1, 'A');
	heappq.Enqueue(9, 'A');
	heappq.Enqueue(3, 'O');
	heappq.Enqueue(8, 'L');
	heappq.show();
	cout << endl;
	cout << "Findmax " << "(" << heappq.FindMax().priority << "," << heappq.FindMax().value << ")" << endl;

	cout << "DequeueMax " << "(" << heappq.DequeueMax().priority << "," << heappq.FindMax().value << ")" << endl;

	heappq.show();

	cout << endl;

	cout << "Dequeue " << "(" << heappq.DequeueMax().priority << "," << heappq.FindMax().value << ")" << endl;

	heappq.show();
	cout << "Ilosc porownan : " << heappq.getCounter() << endl;




	return 0;
}










/*
Kolejak priorytetotwa oprocz wartosci mamy przypisane priorytety. Bedizmey pobierac cell wg priorytetu.
Mozna to przechowywac jak otablciej akichs struktur,
char value;
int priority;
mozna jako dwuelemntowa komorka;
find max - zwraca cell o najwiekszym priorytecie ;
enqueue - metoda dodajaca elemnt do kolejki;
dequeue - zwraca i usuwa cell z kolejki;

*/