#include"stdafx.h"
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
			if (a[i][j] == 0) cout << "*";
			else
			{
				if (a[i][j] > 10 && j != 0) cout << " " << a[i][j]; // для чисел больше 10 пробел , для простоты восприятия 
				else cout << a[i][j];
			}
		}
	}
}

#include<ctime>
#include <cstdlib>
void rand_1(int a[4][4])
{
	srand(time(0));
	int i, j;
	i = rand() % 4;
	j = rand() % 4;
	if (a[i][j] != 0) rand_1(a);
	else 
	{
		int ran = rand() % 10;
		if (ran < 8) a[i][j] = 2;
		else a[i][j] = 4;
	}
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
	rand_1(a); rand_1(a); rand_1(a);
	print(a);
}

#include <iostream>
using namespace std;
int sdvig(int a[4][4])
{
	char op;
	while (true)
	{
		cin.get();
		cin >> op;
		switch (op)
		{
		case 'j':
			down(a);
			print(a);
			cout << endl;
			break;
		case 'k':
			up(a);
			print(a);
			cout << endl;
			break;
		case 'h':
			left_1(a);
			print(a);
			cout << endl;
			break;
		case 'l':
			right_1(a);
			print(a);
			cout << endl;
			break;
		default:
			cout << "enter error " << endl;
			system("pause");
			return -1;
		}
	}
}

#include <iostream>
int main()
{
	int matrix[4][4];
	new_null(matrix);
	sdvig(matrix);
	return 0;
}  
