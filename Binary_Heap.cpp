#include<iostream>
using namespace std;

template <typename T>
class table
{
private:
	T* wsk;
	int size;
	int capacity; 

public:

	void add_value(T value);
	void show();
	void rem();
	void chan(int index, T value);
	void bubble();
	T get(int index);
	table()
	{
		size = 0;
		capacity = 1;
		wsk = new T[capacity]; 

	}
};
template <typename T>
class heap
{
	table <T>* wsk;
	int size2;
	void heap_up(int index);
	void heap_down(int index);
public:
	T pol();
	void showt();
	void push_h(T x);
	void remove_h();


	heap()
	{
		wsk = new table<T>;
		size2 = 0;

	}
};
template <typename T>
	void heap<T>::remove_h()
	{
		wsk->rem();
		size2--;
		heap_down(size2);
	}


template <typename T>
void table<T>::add_value(T value)
{
	if (size == capacity)
	{
		capacity = capacity * 2;
		T* temp = new T[capacity];
		for (int i = 0; i < size; i++)
		{
			temp[i] = wsk[i];
		}
		wsk = new T[capacity];
		for (int j = 0; j < size; j++)
		{
			wsk[j] = temp[j];

		}
		delete[] temp;
	}
	wsk[size] = value;
	size++;
}
template <typename T>
T table<T>::get(int index)
{
	return wsk[index];

}
template <typename T>
void table<T>::show()
{
	for (int i = 0; i < size; i++)
	{
		cout << wsk[i] << "\t";
	}

}

template <typename T>
void table<T>::rem()
{
	size = 0;
	capacity = 1;
	delete wsk;

}
template <typename T>
void table<T>::chan(int index, T value)
{
	if (index > size)
	{
		cout << " Brak elementow" << endl;
	}
	else
	{
		wsk[index] = value;
	}

}
template <typename T>
void table<T>::bubble()
{
	for (int i = 0; i < size; i++) {
		for (int j = 1; j < size - i; j++) { 
			if (wsk[j - 1] > wsk[j]) {
				swap(wsk[j - 1], wsk[j]);
			}
		}
	}

}

template <typename T>
void heap<T>::heap_up(int index)
{
	while ((index - 1 / 2) > 0)
	{
		int parent = ((index - 1) / 2);

		if (wsk->get(index) >= wsk->get(parent))
		{
			T x = wsk->get(index);
			wsk->chan(index, wsk->get(parent));
			wsk->chan(parent, x);
			index = parent;
		}
		else
			break;
		
	}
}
template <typename T>
void heap<T>::heap_down(int index)
{
	int left = (2 * index + 1);
	int right = (2 * index + 2);
	int parent((index - 1) / 2);
	int index2 = index;
	
	if (index <= NULL)
	{
		return;
	}
	if (right <= size2 && wsk->get(left) > wsk->get(index))
	{
		index2 = left;
	}
	if (right <= size2 && wsk->get(right) > wsk->get(index))
	{
		index2 = right;
	}
	if (index2 != index)
	{
		wsk->chan(index, index2);

	}

}
template <typename T>
void heap<T>::push_h(T x)
{

	wsk->add_value(x);
	size2++;
	heap_up(size2 - 1);

}
template <typename T>
void heap<T>::showt()
{
	wsk->show();
}


int main()
{
	double x = 0.0;
	heap<int>* bh = new heap<int>;

	int size = 10000;
	clock_t  t1 = clock();

	 for (int i = 0; i < size; i++)
	 {
		 bh->push_h(rand() % 1000);
	 }
	 clock_t t2 = clock();
	 x = t2 - t1;


  bh->showt();
 
  cout << endl << endl<<"Time = " <<  x / (double)CLOCKS_PER_SEC << " s" << endl;



}