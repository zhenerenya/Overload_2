#include "Array.h"
#include <iostream>


//������
Array::Array() { p = nullptr; n = 0; }
//������� �� ������ �������
Array::Array(int* p, int n)
{
	this->n = n; //����� ���������
	this->p = new int[n]; //������� ����� ����������� n
	for (int i = 0; i < n; i++)
	{
		this->p[i] = p[i];
	}
}
//�����������
Array::Array(const Array& A) : n(A.n)
{
	p = new int[n];
	for (int i = 0; i < n; i++) p[i] = A.p[i];
}
//�����������
Array::Array(Array&& A) : p(A.p), n(A.n)
{
	A.p = nullptr; A.n = 0;
}

//����������
Array::~Array()
{
	if (p) delete[]p;
}

//������
ofstream& operator<<(ofstream& out, Array& A)
{

	int* p = new int[A.n];
	out << A.n << " ";
	for (int i = 0; i < A.n; i++) out << A.p[i] << " ";
	delete[]p;
	return out;
}

//������
Array& operator>>(ifstream& in, Array& A)
{

	in >> A.n;
	A.p = new int[A.n];
	for (int i = 0; i < A.n; i++) in >> A.p[i];
	Array a(A.p, A.n);
	A = a;
	return A;
}


//���������� �������� --
Array& operator--(Array A)
{
	int* k = new  int[A.n];
	for (int i = 0; i < A.n; i++) k[i] = --A.p[i];
	Array* a = new Array(k, A.n);
	delete[]k;
	return *a;
}

//������
void Array::print(Array A)
{
	cout << "n=" << A.n << endl;
	for (int i = 0; i < A.n; i++)
	{
		cout << "p[" << i << "]=" << A.p[i] << " ";
	}
	cout << endl;
}

//���������� ������� []
int& Array:: operator [] (int ind)
{
	return p[ind];
}

//���������� ������� =
Array& Array::operator= (Array A)
{
	n = A.n;
	if (p != nullptr) delete[]p;
	p = new int[n];
	for (int i = 0; i < n; i++) p[i] = A.p[i];
	return *this;
}