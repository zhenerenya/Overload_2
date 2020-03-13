
#pragma once
#include <iostream>
#include <fstream>
using namespace std;


class Array
{
	int* p; //������ int
	int n; //���������� ����� � �������

public:
	Array(); //������ 
	Array(int* p, int n); //������� �� ������ �������������
	Array(const Array& A);//��������
	Array(Array&& A); //����������
	~Array(); //����������
	friend Array& operator--(Array A);
	void print(Array A);
	int& operator[](int ind);
	Array& operator=(Array A);
	friend ofstream& operator<<(ofstream& out, Array& A);
	friend Array& operator>>(ifstream& in, Array& A);
};
