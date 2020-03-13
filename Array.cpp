#include "Array.h"
#include <iostream>


//пустой
Array::Array() { p = nullptr; n = 0; }
//создаем на основе другого
Array::Array(int* p, int n)
{
	this->n = n; //число элементов
	this->p = new int[n]; //создаем масив размерности n
	for (int i = 0; i < n; i++)
	{
		this->p[i] = p[i];
	}
}
//копирование
Array::Array(const Array& A) : n(A.n)
{
	p = new int[n];
	for (int i = 0; i < n; i++) p[i] = A.p[i];
}
//перемещение
Array::Array(Array&& A) : p(A.p), n(A.n)
{
	A.p = nullptr; A.n = 0;
}

//деструктор
Array::~Array()
{
	if (p) delete[]p;
}

//запись
ofstream& operator<<(ofstream& out, Array& A)
{

	int* p = new int[A.n];
	out << A.n << " ";
	for (int i = 0; i < A.n; i++) out << A.p[i] << " ";
	delete[]p;
	return out;
}

//чтение
Array& operator>>(ifstream& in, Array& A)
{

	in >> A.n;
	A.p = new int[A.n];
	for (int i = 0; i < A.n; i++) in >> A.p[i];
	Array a(A.p, A.n);
	A = a;
	return A;
}


//перегрузка операции --
Array& operator--(Array A)
{
	int* k = new  int[A.n];
	for (int i = 0; i < A.n; i++) k[i] = --A.p[i];
	Array* a = new Array(k, A.n);
	delete[]k;
	return *a;
}

//печать
void Array::print(Array A)
{
	cout << "n=" << A.n << endl;
	for (int i = 0; i < A.n; i++)
	{
		cout << "p[" << i << "]=" << A.p[i] << " ";
	}
	cout << endl;
}

//перегрузка оперции []
int& Array:: operator [] (int ind)
{
	return p[ind];
}

//перегрузка оперции =
Array& Array::operator= (Array A)
{
	n = A.n;
	if (p != nullptr) delete[]p;
	p = new int[n];
	for (int i = 0; i < n; i++) p[i] = A.p[i];
	return *this;
}