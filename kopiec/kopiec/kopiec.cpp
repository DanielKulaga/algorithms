#include <iostream>

using namespace std;
const int n = 1000;
//Implementacja stosu 
/*
class Heap {
public:
	int nodes[n];
	int memory;

	void makeHeap(int n)
	{
		for (int i = 0; i <= n; i++)
		{
			nodes[i] = 0;
		}
	}
	void add(int cell)
	{
		for (int i = 0; i <= n; i++)
		{
			if (nodes[i] == 0)
			{
				nodes[i] = cell;
				break;
			}
		}

	}
	void downheap()
	{
		for (int i = 0; i <= n; i++)
		{
			if (nodes[i] < nodes[2 * i + 1])
			{
				int p = nodes[i];
				nodes[i] = nodes[2 * i + 1];
				nodes[2 * i + 1] = p;
			}
			else if (nodes[i] < nodes[2 * i + 2])
			{
				int p = nodes[i];
				nodes[i] = nodes[2 * i + 2];
				nodes[2 * i + 2] = p;
			}
			break;
		}

	}
	void show(int n)
	{
		for (int i = 0; i < n; i++)
		{
			cout << nodes[i] << endl;
		}

	}
}

*/

//Tworze jakas strukturę zeby kazdy cell mial swoj priortet

struct cell {
	char value;
	int priority;
};
int counter = 0;
class Heap
{
public:
	cell nodes[1000];
	int num_of_elements = 0;
	void add(int a, char b);
	void show();
	int getCounter();
};

//Tablicowa
class TabPriorityQueue
{
public:

	cell tab[n];
	int num_of_tab = 0; //liczba elementowt ablicy
public:
	void Enqueue_t(int priority, char value);
	void show_tab();
	cell FindMax_t();
	cell DequeueMax_t();
	int getCounter();

};
cell TabPriorityQueue::FindMax_t() {
	cell max;
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

void TabPriorityQueue::Enqueue_t(int priority, char value) {
	tab[num_of_tab].priority = priority;
	tab[num_of_tab].value = value;
	num_of_tab++;
}



cell TabPriorityQueue::DequeueMax_t() {
	cell d_max;
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
	for (j ; j < num_of_tab; j++)
	{
		tab[j] = tab[k];
		k++;
	}

	num_of_tab--;

	return d_max;
}

void TabPriorityQueue::show_tab()
{
	for (int i = 0; i < num_of_tab; i++)
	{
		cout << "(" << tab[i].priority << ", " << tab[i].value << ")" << " ";
	}
}
//Implementacja kolejki priorytetowej za pomoca kopca binarnego
class PriorityQueue : public Heap
{

public:
	void Enqueue(int priority, char value);
	cell FindMax();
	cell DequeueMax();
	void show();
	void downheap(int i);
};



void PriorityQueue::downheap(int i)
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
void PriorityQueue::Enqueue(int priority, char value) {
	cell e;
	e.priority = priority;
	e.value = value;
	add(e.priority, e.value);
}

cell PriorityQueue::FindMax()
{
	return nodes[0];
}

cell PriorityQueue::DequeueMax()
{
	
	cell max;
	max = nodes[0];


	int k = num_of_elements - 1;
	nodes[0] = nodes[k];
	num_of_elements = num_of_elements - 1;
	downheap(0);

	return max;
}

void Heap::add(int a, char b)
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

void Heap::show()
{
	for (int i = 0; i < num_of_elements; i++)
	{
		cout << "(" << nodes[i].priority << ',' << nodes[i].value << ')' << " ";
	}
}

void PriorityQueue::show()
{
	for (int i = 0; i < num_of_elements; i++)
	{
		cout << "(" << nodes[i].priority << ", " << nodes[i].value << ")" << " ";
	}
}
int Heap::getCounter()
{
	return counter;
}
int TabPriorityQueue::getCounter()
{
	return counter;
}




int main()
{
	//Przedstawiony przyklad z pliku pdf w celu zaprezentowania dzialania
	cout << "Implementacja kolejki priorytetowej za pomocą tablicy " << endl;

	TabPriorityQueue tab;
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
	PriorityQueue priorityQueue;

	priorityQueue.Enqueue(4, 'K');
	priorityQueue.Enqueue(1, 'A');
	priorityQueue.Enqueue(9, 'A');
	priorityQueue.Enqueue(3, 'O');
	priorityQueue.Enqueue(8, 'L');
	priorityQueue.show();
	cout << endl;
	cout << "Findmax " << "(" << priorityQueue.FindMax().priority << "," << priorityQueue.FindMax().value << ")" << endl;
	
	cout << "DequeueMax " << "(" << priorityQueue.DequeueMax().priority << "," << priorityQueue.FindMax().value << ")" << endl;

	priorityQueue.show();

	cout << endl;

	cout << "Dequeue " << "(" << priorityQueue.DequeueMax().priority << "," << priorityQueue.FindMax().value << ")" << endl;
	
	priorityQueue.show();
	cout << "Ilosc porownan : " << priorityQueue.getCounter() << endl;
	



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