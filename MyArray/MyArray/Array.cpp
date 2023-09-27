#include <iostream>
#include "Array.h"
#include "Consts.h"
using namespace std;

Array::Array() {
	arr = new int[SIZE];
	size = SIZE;
}

Array::Array(size_t size) {
	arr = new int[size];
	this->size = size;
}

Array::Array(const int* arr, size_t size) : Array(size) {
	for (int i = 0; i < size; i++)
		this->arr[i] = arr[i];
}

Array::Array(const Array& other) {
	size = other.size;
	delete[] arr;
	arr = new int[size];
	for (int i = 0; i < size; i++)
		this->arr[i] = other.arr[i];
}

Array::~Array() {
	delete[] arr;
}

Array& Array::operator=(const Array& other) noexcept {
	if (this != &other) {
		if (other.size == 0) {
			size = 0;
			arr = NULL;
		}
		else {
			size = other.size;
			delete[] arr;
			arr = new int[size];
			for (int i = 0; i < size; i++)
				this->arr[i] = other.arr[i];
		}
	}
	return *this;
}

int* Array::GetArr() { return arr; }
void Array::SetSize(size_t size) { this->size = size;  }
size_t Array::GetSize() { return size; }

void Array::Init() {
	for (int i = 0; i < size; i++)
		arr[i] = rand() % 1000 - 500;
}

void Array::Show() const{
	for (int i = 0; i < size; i++)
		cout << arr[i] << ' ';
	cout << endl;
}

void Array::SetSize(size_t size) {
	int* temp = new int[size];
	if (this->size >= size) {
		for (int i = 0; i < size; i++)
			temp[i] = arr[i];
	}
	else {
		for (int i = 0; i < this->size; i++)
			temp[i] = arr[i];
		for (int i = this->size; i < size; i++)
			temp[i] = 0;
	}

	delete[] arr;
	this->size = size;
	arr = new int[this->size];
	for (int i = 0; i < this->size; i++)
		arr[i] = temp[i];
	delete[] temp;
}

void Array::Sort() const {
	int temp, j;
	for (int i = 0; i < size; i++) {
		temp = arr[i];
		for (j = i - 1; j >= 0 && arr[i] > temp; j--)
			arr[j + 1] = arr[j];
		arr[j + 1] = temp;
	}
}

void SortVstavka(int* p, int size)
{
	int x, j;
	for (int i = 0; i < size; i++)
	{
		x = p[i];
		for (j = i - 1; j >= 0 && p[j] > x; j--)
		{
			p[j + 1] = p[j];
		}
		p[j + 1] = x;
	}
}

void Array::PrintMinMax() const{
	int min = arr[0];
	int max = arr[0];
	for (int i = 1; i < size; i++) {
		if (arr[i] < min)
			min = arr[i];
		if (arr[i] > max)
			max = arr[i];
	}
	cout << "Min = " << min << "\nMax = " << max << endl;
}