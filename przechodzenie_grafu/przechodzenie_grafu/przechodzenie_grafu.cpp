#include <iostream>
#include <vector>

using namespace std;

typedef int elementtype;
typedef int position;


const int max = 100;

class Vertex {
public:
	int value = -1;
	int getValue() { return value; }
};
//Tutaj skorzystalem z wykladu z pierwszego semestru
class Kolejka
{
protected:
	elementtype Queue[max];
	position First; 
	position Last; 
public:
	Kolejka() {
		First = 0;
		Last = max - 1;
	};
	int Add(int i);
	void Enqueue(elementtype x);
	void Dequeue();
	elementtype FirstElement();
	void Makenull();
	bool Empty();
};
void Kolejka::Enqueue(elementtype x)
{
	if (Add(Add(Last)) != First)
	{
		Last = Add(Last);
		Queue[Last] = x;
	}
}

void Kolejka::Dequeue()
{
	if (Empty() == 0)
	{
		First = Add(First);
	}
}

void Kolejka::Makenull()
{
	First = 0;
	Last = max - 1;
}

elementtype Kolejka::FirstElement()
{
	if (!Empty())
		return Queue[First];
	else return 100000000;
}

int Kolejka::Add(int i) {
	return ((i + 1) % max);
}

bool Kolejka::Empty()
{
	return (Add(Last) == First);
}


class Heap
{
protected:
	int heap[max];
	position Top;//szczyt stosu
public:
	Heap();
	void Push(elementtype x);
	void Pop();
	bool Empty();
	int TopElem();
	void Makenull();
};

Heap::Heap()
{
	Top = -1;
}

void Heap::Makenull()
{
	Top = -1;
}

void Heap::Push(elementtype x)
{
	if (Top < max - 1)
	{
		Top++;
		heap[Top] = x;
	}
}

void Heap::Pop()
{
	if (Top >= 0) Top--;
}

bool Heap::Empty()
{
	return (Top == -1);
} 

int Heap::TopElem()
{
	if (Top >= 0) return heap[Top];
}

class GrafNS_L : public Vertex
{
	int liczba_k = 0;
	int liczba_w = 0;
	vector<vector<Vertex> > w;
public:
	GrafNS_L();
	void krawedzie();
	void polaczenia();
	void printBFS();
	void printDFS();
	void printAll();
};


GrafNS_L::GrafNS_L()
{
	cout << "Podaj liczbe wierzcholkow, ktore chcesz utworzyc: ";
	cin >> liczba_w;
	for (int i = 0; i < liczba_w; i++)
		//for (int j = 0; j < liczba_w; j++)
			w.push_back(vector<Vertex>(0));
}

void GrafNS_L::krawedzie()
{
	int a;
	cout << "Podaj liczbe krawedzi, ktora chcesz utworzyc w calym grafie: ";
	cin >> a;
	liczba_k = a;
}

void GrafNS_L::polaczenia()
{
	int x, y;
	Vertex vx;
	Vertex vy;
	for (int i = 0; i < liczba_k; i++)
	{
		cout << "Podaj wierzcholki, ktore chcesz polaczyc " << endl;
		cin >> x;
		cin >> y;
		vx.value = x;
		vy.value = y;
		w[x].push_back(vy);
		w[y].push_back(vx);
	}
}

void GrafNS_L::printAll()
{
	for (int i = 0; i < w.size(); i++) {
		if (w[i].size() == 0) continue;
		cout << i << " -> ";
		for (int j = 0; j < w[i].size(); j++) {
			cout << w[i][j].getValue() << ", ";
		}
		cout << endl;
	}
}



void GrafNS_L::printDFS()
{
	bool* visited = new bool[liczba_w];
	for (int i = 0; i < liczba_w; i++)
	{
		visited[i] = false;
	}

	int p = 0;
	Heap heap;
	heap.Push(p);
	visited[0] = true;
	cout << "DFS:";

	while (heap.Empty() == false)
	{
	
		int next = heap.TopElem();
		heap.Pop();

		cout << " " << next;

		for (int j = 0; j < w[next].size(); j++) {
			int spr = w[next][j].getValue();
			if (visited[spr] == false) {
				visited[spr] = true;
				heap.Push(spr);
			}
		}
	}
	cout << endl;
	delete[] visited;
}
void GrafNS_L::printBFS()
{
	bool* visited = new bool[liczba_w]; //najpierw falsz bo zaden nie odwiedzony
	for (int i = 0; i < liczba_w; i++)
	{
		visited[i] = false;
	}

	int start = 0;
	Kolejka heap = Kolejka();
	heap.Enqueue(start);
	visited[0] = true;
	cout << "BFS:";

	while (heap.Empty() == false)
	{
		
		int next = heap.FirstElement();
		heap.Dequeue();

		cout << " " << next;

		for (int j = 0; j < w[next].size(); j++) {
			int spr = w[next][j].getValue();
			if (visited[spr] == false) {
				visited[spr] = true;
				heap.Enqueue(spr);
			}
		}
	}
	cout << endl;
	delete[] visited;
}


int main()
{
	GrafNS_L g1;
	g1.krawedzie();
	g1.polaczenia();
	g1.printDFS();
	g1.printBFS();
	g1.printAll();
	
	
	return 0;
}