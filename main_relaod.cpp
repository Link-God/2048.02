#include"stdafx.h"
static bool prov_0 = false;
static bool lose = false;
void sort_down(int a[4][4])
{
	for (int j = 0; j < 4; j++)
	{
		for (int i = 3; i > 0; i--)
		{
			if (a[i][j] == 0)
			{
				for (int k = i - 1; k >= 0; k--)
				{
					if (a[k][j] != 0)
					{
						a[i][j] = a[k][j];
						a[k][j] = 0;
						break;
					}
				}
			}
		}
	}
}

void sort_up(int a[4][4])
{
	for (int j = 0; j < 4; j++)
	{
		for (int i = 0; i < 3; i++)
		{
			if (a[i][j] == 0)
			{
				for (int k = i + 1; k < 4; k++)
				{
					if (a[k][j] != 0)
					{
						a[i][j] = a[k][j];
						a[k][j] = 0;
						break;
					}
				}
			}
		}
	}
}

void sort_right(int a[4][4])
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 3; j > 0; j--)
		{
			if (a[i][j] == 0)
			{
				for (int k = j - 1; k >= 0; k--)
				{
					if (a[i][k] != 0)
					{
						a[i][j] = a[i][k];
						a[i][k] = 0;
						break;
					}
				}
			}
		}
	}

}

void sort_left(int a[4][4])
{

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (a[i][j] == 0)
			{
				for (int k = j + 1; k < 4; k++)
				{
					if (a[i][k] != 0)
					{
						a[i][j] = a[i][k];
						a[i][k] = 0;
						break;
					}
				}
			}
		}
	}
}

void down(int a[4][4])
{
	sort_down(a);
	for (int j = 0; j < 4; j++)
	{
		for (int i = 3; i > 0; i--)
		{
			if (a[i][j] == a[i - 1][j])
			{
				a[i][j] += a[i - 1][j];
				a[i - 1][j] = 0;
			}
		}
	}
	sort_down(a);
}

void up(int a[4][4])
{
	sort_up(a);
	for (int j = 0; j < 4; j++)
	{
		for (int i = 0; i < 3; i++)
		{
			if (a[i][j] == a[i + 1][j])
			{
				a[i][j] += a[i + 1][j];
				a[i + 1][j] = 0;
			}
		}
	}
	sort_up(a);
}

void right_1(int a[4][4])
{
	sort_right(a);
	for (int i = 0; i < 4; i++)
	{
		for (int j = 3; j > 0; j--)
		{
			if (a[i][j] == a[i][j - 1])
			{
				a[i][j] += a[i][j - 1];
				a[i][j - 1] = 0;
			}
		}
	}
	sort_right(a);
}

void left_1(int a[4][4])
{
	sort_left(a);
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (a[i][j] == a[i][j + 1])
			{
				a[i][j] += a[i][j + 1];
				a[i][j + 1] = 0;
			}
		}
	}
	sort_left(a);
}

#include <iostream>
using namespace std;
void print(int a[4][4])
{
	for (int i = 0; i < 4; i++)
	{
		cout << endl;
		for (int j = 0; j < 4; j++)
		{
			if (a[i][j] == 0) cout << "*" << " "; // пробелы , тк проверял большие числа
			else
			{
				if (a[i][j] > 10 && j != 0) cout << a[i][j] <<  "  " ; // для чисел больше 10 пробел , для простоты восприятия 
				else cout << a[i][j]<< " ";
			}
		}
	}
	cout << endl;
}

void new_null(int a[4][4])
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			a[i][j] = 0;
		}
	}
}

bool proverka(int a[4][4])
{
	int k=0;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (a[i][j] == 0)  k += 1;
		}
	}
	if (k == 0)
	{
		prov_0 = true;
		return true;
	}
	else return false;
}

#include <iostream>
using namespace std;
int rand_1(int a[4][4])
{
	int i, j;
	i = rand() % 4;
	j = rand() % 4;
	if (proverka(a) && prov_0)
	{
		cout << "lose" << endl;
		lose = true;
		system("pause");
		return -1;
	}
	else 
	{
		if (a[i][j] != 0) rand_1(a);
		else
		{
			int ran = rand() % 10;
			if (ran < 8) a[i][j] = 2;
			else a[i][j] = 4;
		}
		return 1;
	}
}

#include <iostream>
using namespace std;
int sdvig(int a[4][4])
{
	char op;
	while (true)
	{
	//	cin.get(); переход на другую строку сделал в print
		cin >> op;
		switch (op)
		{
		case 'j':
			down(a);
			rand_1(a);
			print(a) ;
			if (lose) return -1;
			cout << endl;
			break;
		case 'k':
			up(a);
			rand_1(a);
			print(a);
			if (lose) return -1;
			cout << endl;
			break;
		case 'h':
			left_1(a);
			rand_1(a);
			print(a);
			cout << endl;
			break;
		case 'l':
			right_1(a);
			rand_1(a);
			print(a);
			if (lose) return -1;
			cout << endl;
			break;
		case 'q':
			system("pause");
			return -1;
		default:
			cout << "enter error " << "new op= " << endl;
		}
	}
}

#include <iostream>
#include<ctime>
#include <cstdlib>
int main()
{
	int matrix[4][4];
	srand(time(0));
	new_null(matrix);
	rand_1(matrix); rand_1(matrix); rand_1(matrix);
	print(matrix);
	sdvig(matrix);
	return 0;
}
