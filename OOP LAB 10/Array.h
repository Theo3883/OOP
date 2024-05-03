#include <iostream>
#include <exception>
#include <algorithm>
class exceptie1 : public std::exception
{
public:
	virtual const char* what() const throw()
	{
		return "Indexul este inafara domeniului!";
	}
};
class Compare
{
public:
	virtual int CompareElements(void* e1, void* e2) = 0;
};
template<class T>
class ArrayIterator
{
private:
	int Current; // mai adaugati si alte date si functii necesare pentru iterator
public:
	ArrayIterator();
	ArrayIterator& operator ++ ();
	ArrayIterator& operator -- ();
	bool operator= (ArrayIterator<T>&);
	bool operator!=(ArrayIterator<T>&);
	T* GetElement();
};
template<class T>
class Array
{
private:
	T** List; // lista cu pointeri la obiecte de tipul T*
	int Capacity; // dimensiunea listei de pointeri
	int Size; // cate elemente sunt in lista
	void list_expand(int size)
	{
		int newCapacity = 1;
		while (newCapacity < size)
			newCapacity *= 2;
		T** temp = new T * [newCapacity];
		for (int i = 0; i < Size; i++)
			temp[i] = List[i];
		delete[] List;
		List = temp;
		Capacity = newCapacity;
	}

public:
	Array() : List(nullptr), Capacity(0),Size(0) {};
	~Array()
	{
		for (int i = 0; i < Capacity;i++)
			delete List[i];
		delete[] List;
	}
	Array(int capacity): Size(0),Capacity(capacity)
	{
		List = new T*[capacity];
		for (int i = 0; i < capacity; i++)
			List[i] = nullptr;

	}
	Array(const Array<T>& otherArray) : List(nullptr), Capacity(otherArray.Capacity), Size(otherArray.Size)
	{
		if (this->Size < otherArray.Size)
			list_expand(otherArray.Size);
		for (int i = 0; i < otherArray.Size; i++)
			List[i] = new T * (otherArray.List[i]);
	}
	T& operator[] (int index)
	{
		try
		{
			if ((index < 0 || index >= Size) && Size != 0)
				throw exceptie1();
		}
		catch (exceptie1& e)
		{
			std::cout << "Exceptie: " << e.what() << std::endl;
		}
		return *(List[index]);
	}
	const Array<T>& operator+=(const T& newElem) 
	{
		if (Size + 1 >= Capacity)
			list_expand(Size + 1);
		List[Size++] = new T(newElem);
		return (*this);
	}
	const Array<T>& Insert(int index, const T& newElem)
	{
		try {
			if (index < 0 || index >= Size)
				throw exceptie1();
			if (Size + 1 >= Capacity)
				list_expand(Size + 1);
			for (int i = Size - 1; i > index; i--)
				List[i] = List[i - 1];
			List[index] = new T(newElem);
			Size++;
		}
		catch (exceptie1& e)
		{
			std::cout << "Exceptie: " << e.what() << std::endl;
		}
		return (*this);
	}
	const Array<T>& Insert(int index, const Array<T> otherArray)
	{
		try {
			if (index < 0 || index >= Size)
				throw exceptie1();
			if (Size + otherArray.Size >= Capacity)
				list_expand(Size + otherArray.Size);
			for (int i = Size - 1; i >= index; i--)
				List[i + otherArray.Size] = List[i];
			for (int i = 0; i < otherArray.Size; i++)
				List[index + i] = new T(*otherArray.List[i]);
			Size += otherArray.Size;
		}
		catch (exceptie1& e)
		{
			std::cout << "Exceptie: " << e.what() << std::endl;
		}
		return (*this);
	}
	const Array<T>& Delete(int index) 
	{
		try
		{
			if (index < 0 || index >= Size)
				throw exceptie1();
			delete List[index];
			for (int i = index; i < Size - 1; i++)
				List[i] = List[i + 1];
			Size--;
		}
		catch (exceptie1& e)
		{
			std::cout << "Exceptie: " << e.what() << std::endl;
		}
		return (*this);
	}
	bool operator=(const Array<T>& otherArray)
	{
		if (this->Size != otherArray.Size)
			return 0;
		for (int i = 0; i < Size; i++)
			if ((*List[i]) > (*otherArray.List[i]))
				return 0;
		return 1;
	}
	void Sort() 
	{
		for (int i = 0; i < Size - 2; i++)
			for (int j = i + 1; j < Size; j++)
				if ((*List[i]) > (*List[j]))
					std::swap(List[i], List[j]);
	}
	void Sort(int(*compare)(const T&, const T&)) 
	{
		for (int i = 0; i < Size - 2; i++)
			for (int j = i + 1; j < Size-1; j++)
				if (compare(*List[i], *List[j]))
					std::swap(List[i], List[j]);
	}
	void Sort(Compare* comparator) 
	{
		for (int i = 0; i < Size - 1; i++)
			for (int j = i + 1; j < Size; j++)
				if (comparator->CompareElements(*List[i], *List[j]) > 0)
					std::swap(List[i], List[j]);
	}
	
	// functii de cautare - returneaza pozitia elementului sau -1 daca nu exista
	int BinarySearch(const T& elem); // cauta un element folosind binary search in Array
	int BinarySearch(const T& elem, int(*compare)(const T&, const T&));// cauta un element folosind binary search si o functie de comparatie
	int BinarySearch(const T& elem, Compare* comparator);// cauta un element folosind binary search si un comparator
	int Find(const T& elem); // cauta un element in Array
	int Find(const T& elem, int(*compare)(const T&, const T&));// cauta un element folosind o functie de comparatie
	int Find(const T& elem, Compare* comparator);// cauta un element folosind un comparator
	int GetSize();
	int GetCapacity();
	ArrayIterator<T> GetBeginIterator();
	ArrayIterator<T> GetEndIterator();


	void afis()
	{
		for (int i = 0; i < Size; i++)
			std::cout << (*List[i])<<" ";
		std::cout << "\n";
	}
};