#include <iostream>
#include <math.h>
using namespace std;

/*
—оздать абстрактный базовый класс с виртуальной функцией Ч корни уравнени€. —оздать производные классы:
класс линейных уравнений и класс квадратных уравнений.
ќпределить функцию вычислени€ корней уравнений.
*/

class Equation {
public:
	virtual double get_root(int x = 1) = 0; //пуста€ виртуальна€ функци€, котора€ определ€етс€ в дочерних классах
};

class Linear : public Equation {
private:
	double one, two;
public:
	Linear(double x1, double x2) : one(x1), two(x2) {}

	double get_root(int x = 1) { //ну тут все просто по формуле
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

	double get_root(int x = 1) { //дл€ выбора корн€
		double x1 = 0, x2 = 0, D;

		D = b * b - 4 * a * c; // формула дискриминанта
		if (D < 0) { //если меньше 0
			cout << "There are no roots in this equation!";
			return 0;
		} else { //если больше 0
			x1 = (-b + sqrt(D)) / (2 * a); //первый корень
			x2 = (-b - sqrt(D)) / (2 * a); //второй корень
			if (x == 1) { //возвращает первый корень
				return x1;
			} else if (x == 2) { //возвращает второй корень
				return x2;
			} else { // если вдруг человек захотел вывести корень которого нету
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
