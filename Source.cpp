#include <iostream>
#include <math.h>
using namespace std;

/*
������� ����������� ������� ����� � ����������� �������� � ����� ���������. ������� ����������� ������:
����� �������� ��������� � ����� ���������� ���������.
���������� ������� ���������� ������ ���������.
*/

class Equation {
public:
	virtual double get_root(int x = 1) = 0; //������ ����������� �������, ������� ������������ � �������� �������
};

class Linear : public Equation {
private:
	double one, two;
public:
	Linear(double x1, double x2) : one(x1), two(x2) {}

	double get_root(int x = 1) { //�� ��� ��� ������ �� �������
		double root;
		root = -two / one;
		return root;
	}
};

class Square : public Equation {
private:
	double a, b, c;
public:
	Square(double a, double b, double c) : a(a), b(b), c(c) {}

	double get_root(int x = 1) { //��� ������ �����
		double x1 = 0, x2 = 0, D;

		D = b * b - 4 * a * c; // ������� �������������
		if (D < 0) { //���� ������ 0
			cout << "There are no roots in this equation!";
			return 0;
		} else { //���� ������ 0
			x1 = (-b + sqrt(D)) / (2 * a); //������ ������
			x2 = (-b - sqrt(D)) / (2 * a); //������ ������
			if (x == 1) { //���������� ������ ������
				return x1;
			} else if (x == 2) { //���������� ������ ������
				return x2;
			} else { // ���� ����� ������� ������� ������� ������ �������� ����
				cout << "There is no " << x << " root in tris equation!";
				return 0;
			}
		}
	}
};

int main() {
	Linear x1(4, 4);
	cout << x1.get_root() << endl;
	Square x2(4, 4, -4);
	cout << x2.get_root(2) << endl;
}
