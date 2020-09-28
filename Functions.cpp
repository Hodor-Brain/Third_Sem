/*#include "Header.h"

template<typename T>
void InsertSort(Doubly_Linked_List<T>* a, int size) {
	T x;
	int i, j;
	for (i = 0; i < size; ++i) {
		x = a->find_by_iter(i)->value;
		for (j = i - 1; j >= 0 && a->find_by_iter(j)->value > x; j--)
			a->find_by_iter(j + 1)->value = a->find_by_iter(j)->value;
		a->find_by_iter(j + 1)->value = x;
	}
}

template<typename T>
void InsertSort(Doubly_Linked_List<T>* a, int size) {
	T x;
	int i, j;
	for (i = 0; i < size; ++i) {
		x = a->find_by_iter(i)->value;
		for (j = i - 1; j >= 0 && a->find_by_iter(j)->value > x; j--)
			a->find_by_iter(j + 1)->value = a->find_by_iter(j)->value;
		a->find_by_iter(j + 1)->value = x;
	}
}

template<typename T>
void BubbleSort(T* a, int size) {
	int x;
	int i, j;
	for (i = 0; i < size; i++) {
		for (j = size - 1; j > i; j--) {
			if (a->find_by_iter(j - 1)->value > a->find_by_iter(j)->value) {
				x = a->find_by_iter(j - 1)->value;
				a->find_by_iter(j - 1)->value = a->find_by_iter(j)->value;
				a->find_by_iter(j)->value = x;
			}
		}
	}
}

template<>
void BubbleSort(Doubly_Linked_List<int>* a, int size) {
	int x;
	int i, j;
	for (i = 0; i < size; i++) {
		for (j = size - 1; j > i; j--) {
			if (a->find_by_iter(j - 1)->value > a->find_by_iter(j)->value) {
				x = a->find_by_iter(j - 1)->value;
				a->find_by_iter(j - 1)->value = a->find_by_iter(j)->value;
				a->find_by_iter(j)->value = x;
			}
		}
	}
}*/