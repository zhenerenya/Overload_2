#include "Array.h"

using namespace std;


int main()
{


	Array A1; //создаем пустой объект
	ifstream in;
	in.open("input.txt");
	if (in) {
		in >> A1;
		in.close();
	}
	else { cout << "Input Error!!"; system("pause"); return 0; }

	Array A2;
	A2 = A1;

	ofstream out("output.txt");
	if (out)
	{
		out << A2;
	}
	else { cout << "Output Error!!"; system("pause"); return 0; }

	Array A3;
	A3 = --A1;
	out << endl;
	out << A3;
	out << endl;

	out << "p4=";
	out << A3[4];
	out.close();

	system("pause");
	return 0;
}