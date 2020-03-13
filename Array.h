
#pragma once
#include <iostream>
#include <fstream>
using namespace std;


class Array
{
	int* p; //массив int
	int n; //количество чисел в массиве

public:
	Array(); //пустой 
	Array(int* p, int n); //создаем на основе существующего
	Array(const Array& A);//копируем
	Array(Array&& A); //перемещаем
	~Array(); //деструктор
	friend Array& operator--(Array A);
	void print(Array A);
	int& operator[](int ind);
	Array& operator=(Array A);
	friend ofstream& operator<<(ofstream& out, Array& A);
	friend Array& operator>>(ifstream& in, Array& A);
};
