/* #include <iostream>

using namespace std;
int element;
/*struct cell
{
	int element;
	cell* next;
};*/
/*typedef int elementtype;
typedef struct celltype
{
	elementtype element;
	celltype* next;
};
//l jest zmienną wskaźnikową – zawiera adres komórki
//typu celltype

class Lista
{
protected:
	celltype* l;; // głowa listy
public:
	Lista()
	{
		l = new celltype;
		l->next = NULL;
	}	//konstruktor
	~Lista()
	{
		while (l->next != NULL)
		{
			celltype* temp;
			temp = l->next;
			l->next = temp->next;
			delete temp;
		}w
		delete l;

		//destruktor
	}
	void Insert(int x, celltype* p)
	{
		celltype* tmp;
		tmp = p->next;
		p->next = new celltype; //tu cos nie tak chyba 
		p->next->element = x;
		p->next->next = tmp;

		// wstawia komórkę z elementem x na pozycję next komórki o wskaźniku p
	}												 // (lub w przypadku pustej listy tworzy komórkę z elementem x w miejscu głowy listy)
	void Delete(celltype* p)
	{
		celltype* tmp;
		tmp = p->next;
		p->next = p->next->next;
		delete tmp;



		// usuwa komórkę z pozycji next komórki o wskaźniku p

	}
	int Retrieve(celltype* p)
	{
		// zwraca element komórki o wskaźniku p
		if (p->next != NULL)
		{
			return p->next->element;
		}


	}




	celltype* Locate(int x)
	{
		celltype* tmp;
		tmp = l;
		while (tmp->next != NULL)
		{
			if (tmp->next->element == x) return tmp;
			tmp = tmp->next;
		}
		return tmp;





		// zwraca wskaźnik do pierwszej komórki z elementem x


	}
	celltype* First()
	{	// zwraca wskaźnik do pierwszej komórki na liście
		return l;


	}
	celltype* Next(celltype* p)
	{
		return p->next;


		// zwraca wskaźnik do kolejnej komórki po komórce o wskaźniku p


	}
	/*cell * Previous(cell * p); // zwraca wskaźnik do komórki poprzedzającej komórkę o wskaźniku p - tylko dla listy dwukierunkowej
	position Lista::Previous(position p)
{
 position tmp;
 tmp=l;
 while (tmp->next!=p) tmp=tmp->next;
 return tmp;
}*/
/*        
	celltype* Last()
	{
		// zwraca wskaźnik do ostatniej komórki na liście

		celltype* tmp;
		tmp = l;
		while (tmp->next != NULL)
		{
			tmp = tmp->next;
		}
		return tmp;
	}
	void print()
	{
		cout << "Zawartosc listy L:" << endl;
		for (celltype* i = l; i != (bool)NULL; i->next)
		{
			cout << i->next->element;

		}


		// wyświetla wszystkie elementy listy

	}


};


int main()
{
	Lista *Q = new Lista;



}

*/

typedef int elementtype;
typedef struct celltype
{
	elementtype element;
	celltype* next;
};
typedef celltype* position;
class Queue
{
protected:
	position Front; // wskaźnik do głowy listy
	position Rear; // wskaźnik do ostatniego elementu
public:
	Queue()
	{
		Front = new celltype;
		Rear = Front;
		Front -> next = NULL;

	]	//konstruktor
	~Queue()
	{
		position tmp;

		while (Front->next != NULL)
		{
			tmp = Front;
			Front = Front->next;
			delete tmp;
		}
		delete Front;
		//destruktor
	}
	void Enqueue(elementtype x)
	{
		position p = new celltype;
		p->element = x;
		p->next = NULL;
		Rear->next = p;
		Rear = p;


	}
	void Dequeue()
	{
		if (!Empty())
		{
			position p = Front;
			Front = Front->next;
			delete p;
		}

	}
	elementtype FrontElem()
	{
		if (!Empty())
			return Front->next->element;

	}
	bool Empty()
	{
		return (Front->next == NULL);
	}
};

	int main()
	{
		int x;
		Queue
		q = Queue();
		Q = new Queue;
		Q->Enqueue(x);




	}