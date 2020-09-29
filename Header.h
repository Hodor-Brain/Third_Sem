#pragma once
#include <iostream>
#include <conio.h>
#include <sstream>
#include <string>
#include <vector>
#include <utility>

void flush()
{
	std::cin.clear(); 
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

class Dice
{
private:

	int Faces = 0;
	std::vector <int> nums;
	std::vector <double> probabs;

public:

	Dice()
	{

	}

	Dice(int count, std::vector <int> nums, std::vector <double> probs)
	{
		this->Faces = count;
		this->nums = nums;
		this->probabs = probs;
	}

	Dice(int count, std::vector <double> probs)
	{
		this->Faces = count;

		for (int i = 0; i < count; i++)
		{
			this->nums.push_back(i + 1);
		}

		this->probabs = probs;
	}

	friend std::ostream& operator<<(std::ostream& out, const Dice dice)
	{
		out << "(";

		for (int i = 0; i < dice.Faces; i++)
		{
			if (i != dice.Faces - 1)
			{
				out << dice.nums[i] << " = " << dice.probabs[i] << ", ";
			}
			else
			{
				out << dice.nums[i] << " = " << dice.probabs[i];
			}
		}

		out << ")";

		return out;
	}

	Dice& operator=(const Dice &dice)
	{
		this->Faces = dice.Faces;
		this->nums = dice.nums;
		this->probabs = dice.probabs;

		return *this;
	}

	bool operator<(const Dice &dice)
	{
		if (this->Faces < dice.Faces)
		{
			return true;
		}

		return false;
	}

	int GetFaces()
	{
		return this->Faces;
	}

	std::vector <int> GetNums()
	{
		return this->nums;
	}

	std::vector <double> GetProbabilities()
	{
		return this->probabs;
	}

	int GetNum(int key)
	{
		return this->nums[key];
	}

	double GetProbability(int key)
	{
		return this->probabs[key];
	}
};

template <typename T>
struct Node 
{
	T value;

	Node<T>* prev;
	Node<T>* next;

	int key;

	Node(T value, Node<T>* prev = nullptr, Node<T>* next = nullptr, int key = -1)
	{
		this->value = value;
		this->prev = prev;
		this->next = next;
		this->key = key;
	}

	Node() {}
	~Node() {}
};

template <typename T>
class Doubly_Linked_List 
{
private:

	Node<T>* begin;
	Node<T>* end;

	std::size_t count;

public:

	Doubly_Linked_List()
	{
		this->begin = nullptr;
		this->end = nullptr;
		this->count = 0;
	}

	~Doubly_Linked_List() 
	{
		this->clear();
	}

	Node<T>* get_end() 
	{
		return this->end;
	}

	Node<T>* get_beg() 
	{
		return this->begin;
	}

	void addLast(T value) 
	{
		Node<T>* new_node = new Node<T>{ value };

		if (begin == nullptr) 
		{
			end = new_node;
			begin = new_node;
			new_node->key = 0;
		}
		else 
		{
			new_node->prev = end;
			new_node->key = new_node->prev->key + 1;

			end->next = new_node;
			end = new_node;
		}
		count++;
	}

	void clear() 
	{
		Node<T>* current = begin;

		while (current) 
		{
			Node<T>* to_delete = current;
			current = current->next;
			delete to_delete;
		}

		begin = end = nullptr;
		count = 0;
	}

	std::size_t size() 
	{
		return count;
	}

	friend std::ostream& operator<<(std::ostream& out, const Doubly_Linked_List<T>& list) 
	{
		Node<T>* current = list.begin;
		out << "[";
		while (current) 
		{
			if (current != list.begin)
				out << " ";
			out << current->value;
			current = current->next;
		}
		out << "]";
		return out;
	}

	Node<T>* find_by_iter(int iter) 
	{
		Node<T>* cur = begin;
		while (cur) 
		{
			if (cur->key == iter)
				break;
			cur = cur->next;
		}
		return cur;
	}

	Node<T>* find_by_value(T val) 
	{
		Node<T>* cur = begin;
		while (cur) 
		{
			if (cur->value == val)
				break;
			cur = cur->next;
		}
		return cur;
	}

	bool RemoveLast() 
	{
		if (begin == nullptr) 
		{
			std::cout << "There are no elements!" << std::endl << std::endl;
			return false;
		}
		else 
		{
			Node<T>* cur = end;
			end = (end)->prev;
			(end)->next = nullptr;
			delete cur;
			std::cout << "Successful!" << std::endl;
			return true;
		}

	}

	void RandomGeneration()
	{

	}

	void Insert_from_kb()
	{
		while (true)
		{
			T val;

			std::string a;

			std::cout << "Current type of value: " << typeid(val).name() << std::endl << std::endl;
			std::cout << "Enter the value (to stop adding type 'end'): ";

			std::stringstream ss;

			std::getline(std::cin, a);

			ss.str(a.c_str());

			if (ss.str() == "end")
			{
				system("cls");
				break;
			}

			ss >> val;

			if (ss.fail())
			{
				ss.clear();

				system("cls");
				std::cout << "You can't enter different types of values!" << std::endl;
				system("pause");
				system("cls");
				continue;
			}

			system("cls");

			this->addLast(val);
		}
	}
};

template<typename T>
void QuickSort(Doubly_Linked_List<T>* a, int length, int L, int R, bool isDecr) 
{
	int i = L, j = R;
	int mid = (R + L) / 2;

	T first = a->find_by_iter(mid)->value;
	T sec;

	if (isDecr) 
	{
		do 
		{
			while (first < a->find_by_iter(i)->value)
				i++;

			while (a->find_by_iter(j)->value < first)
				j--;

			if (i <= j) 
			{
				sec = a->find_by_iter(i)->value;
				a->find_by_iter(i)->value = a->find_by_iter(j)->value;
				a->find_by_iter(j)->value = sec;

				i++;
				j--;
			}
		} while (i < j);
	}
	else 
	{
		do 
		{
			while (a->find_by_iter(i)->value < first)
				i++;

			while (first < a->find_by_iter(j)->value)
				j--;

			if (i <= j) 
			{
				sec = a->find_by_iter(i)->value;
				a->find_by_iter(i)->value = a->find_by_iter(j)->value;
				a->find_by_iter(j)->value = sec;

				i++;
				j--;
			}
		} while (i < j);
	}

	if (L < j)
		QuickSort(a, length, L, j, isDecr);

	if (i < R)
		QuickSort(a, length, i, R, isDecr);
}

template<typename T>
void BubbleSort(Doubly_Linked_List<T>* a, int size, bool isDecr) 
{
	T x;
	int i, j;
	if (isDecr) 
	{
		for (i = 0; i < size; i++) 
		{
			for (j = size - 1; j > i; j--) 
			{
				if (a->find_by_iter(j - 1)->value < a->find_by_iter(j)->value) 
				{
					x = a->find_by_iter(j - 1)->value;
					a->find_by_iter(j - 1)->value = a->find_by_iter(j)->value;
					a->find_by_iter(j)->value = x;
				}
			}
		}
	}
	else 
	{
		for (i = 0; i < size; i++) 
		{
			for (j = size - 1; j > i; j--) 
			{
				if (a->find_by_iter(j)->value < a->find_by_iter(j - 1)->value)
				{
					x = a->find_by_iter(j - 1)->value;
					a->find_by_iter(j - 1)->value = a->find_by_iter(j)->value;
					a->find_by_iter(j)->value = x;
				}
			}
		}
	}
}

template<typename T>
void InsertSort(Doubly_Linked_List<T>* a, int size, bool isDecr) 
{
	T x;
	int i, j;
	if (isDecr) 
	{
		for (i = 0; i < size; ++i) 
		{
			x = a->find_by_iter(i)->value;
			for (j = i - 1; j >= 0 && a->find_by_iter(j)->value < x; j--)
				a->find_by_iter(j + 1)->value = a->find_by_iter(j)->value;
			a->find_by_iter(j + 1)->value = x;
		}
	}
	else 
	{
		for (i = 0; i < size; ++i) 
		{
			x = a->find_by_iter(i)->value;
			for (j = i - 1; j >= 0 && x < a->find_by_iter(j)->value; j--)
				a->find_by_iter(j + 1)->value = a->find_by_iter(j)->value;
			a->find_by_iter(j + 1)->value = x;
		}
	}
}

template<typename T>
void MergeSort(int l, int r, int length, Doubly_Linked_List<T>* a, bool isDecr)
{
	if (r == l)
		return;

	T temp = {};

	if (r - l == 1) 
	{
		if (isDecr)
		{
			if (a->find_by_iter(l)->value < a->find_by_iter(r)->value)
			{
				T temp = a->find_by_iter(r)->value;
				a->find_by_iter(r)->value = a->find_by_iter(l)->value;
				a->find_by_iter(l)->value = temp;
			}
		}
		else
		{
			if (a->find_by_iter(r)->value < a->find_by_iter(l)->value)
			{
				T temp = a->find_by_iter(r)->value;
				a->find_by_iter(r)->value = a->find_by_iter(l)->value;
				a->find_by_iter(l)->value = temp;
			}
		}
		return;
	}

	int m = (r + l) / 2;


	MergeSort(l, m, length, a, isDecr);

	MergeSort(m + 1, r, length, a, isDecr);

	Doubly_Linked_List<T>* buf = new Doubly_Linked_List<T>;
	while (buf->size() < length) 
	{
		buf->addLast(temp);
	}

	int xl = l;
	int xr = m + 1;
	int cur = 0;

	while (r - l + 1 != cur)
	{
		if (isDecr)
		{
			if (xl > m)
				buf->find_by_iter(cur++)->value = a->find_by_iter(xr++)->value;

			else if (xr > r)
				buf->find_by_iter(cur++)->value = a->find_by_iter(xl++)->value;

			else if (a->find_by_iter(xl)->value < a->find_by_iter(xr)->value)
				buf->find_by_iter(cur++)->value = a->find_by_iter(xr++)->value;

			else
				buf->find_by_iter(cur++)->value = a->find_by_iter(xl++)->value;
		}
		else
		{
			if (xl > m)
				buf->find_by_iter(cur++)->value = a->find_by_iter(xr++)->value;

			else if (xr > r)
				buf->find_by_iter(cur++)->value = a->find_by_iter(xl++)->value;

			else if (a->find_by_iter(xr)->value < a->find_by_iter(xl)->value)
				buf->find_by_iter(cur++)->value = a->find_by_iter(xr++)->value;

			else
				buf->find_by_iter(cur++)->value = a->find_by_iter(xl++)->value;
		}
	}
	for (int i = 0; i < cur; i++)
		a->find_by_iter(i + l)->value = buf->find_by_iter(i)->value;

}

template<typename T>
void ShellSort(Doubly_Linked_List<T>* a, int length, bool isDecr)
{
	for (int d = length / 2; d >= 1; d /= 2)
	{
		for (int i = d; i < length; i++)
		{
			if (isDecr)
			{
				for (int j = i; j >= d && a->find_by_iter(j - d)->value < a->find_by_iter(j)->value; j -= d)
				{
					//swap(a->find_by_iter(j)->value, a->find_by_iter(j - d)->value);
					T temp = a->find_by_iter(j)->value;
					a->find_by_iter(j)->value = a->find_by_iter(j - d)->value;
					a->find_by_iter(j - d)->value = temp;
				}
			}
			else
			{
				for (int j = i; j >= d && a->find_by_iter(j)->value < a->find_by_iter(j - d)->value; j -= d)
				{
					//swap(a->find_by_iter(j)->value, a->find_by_iter(j - d)->value);
					T temp = a->find_by_iter(j)->value;
					a->find_by_iter(j)->value = a->find_by_iter(j - d)->value;
					a->find_by_iter(j - d)->value = temp;
				}
			}
		}
	}
}



std::pair<std::vector<int>, std::vector<double>> FindAllSumsAndProbs(Node<Dice>* cur, int curindex, std::vector<int> &sums, std::vector<double> &probabs, std::vector<int> tempsums, std::vector<double> tempprobabs)
{
	std::pair<std::vector<int>, std::vector<double>> mypair = std::make_pair(sums,probabs);

	if (cur->next == nullptr)
	{
		for (int j = 0; j < cur->value.GetFaces(); j++)
		{
			int sum = 0;

			for (int i = 0; i < tempsums.size(); i++)
			{
				sum += tempsums[i];
			}

			sum += cur->value.GetNum(j);

			double prob = tempprobabs[0];

			for (int i = 1; i < tempprobabs.size(); i++)
			{
				prob *= tempprobabs[i];
			}

			prob *= cur->value.GetProbability(j);

			bool isSame = false;

			for (int i = 0; i < sums.size(); i++)
			{
				if (sums[i] == sum)
				{
					isSame = true;
					probabs[i] += prob;
					break;
				}
			}

			if (isSame == false)
			{
				sums.push_back(sum);
				probabs.push_back(prob);
			}
		}
	}
	else
	{
		for (int i = 0; i < cur->value.GetFaces(); i++)
		{
			tempsums[curindex] = cur->value.GetNum(i);
			tempprobabs[curindex] = cur->value.GetProbability(i);
			mypair = FindAllSumsAndProbs(cur->next, curindex + 1, sums, probabs, tempsums, tempprobabs);
		}
	}

	return std::make_pair(sums, probabs);
}