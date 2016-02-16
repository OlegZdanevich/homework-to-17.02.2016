#include <iostream>;
using namespace std;

bool IsDataValid(int n);
void Swap(int &x, int &y);
void EnterArray(int a[], int n);
void DisplayArray(int a[], int n);
void BoolSort(int a[], int n);
void EnterDimention(int &n);
void SortTogether(int a[], int n, int b[], int m, int c[], int e);

int main()
{
	while (true)
	{
		int n;
		EnterDimention(n);
		int *a = new int[n];
		EnterArray(a, n);
		DisplayArray(a, n);
		cout << " - first array before sorting" << endl;

		int m;
		EnterDimention(m);
		int *b = new int[m];
		EnterArray(b, m);
		DisplayArray(b, m);
		cout << " - second array before sorting" << endl;

		cout << endl << "***************************************************" << endl << endl;

		BoolSort(a, n);
		cout << endl;
		DisplayArray(a, n);
		cout << " -first array after sorting" << endl;

		BoolSort(b, m);
		cout << endl;
		DisplayArray(b, m);
		cout << " -second array after sorting" << endl;

		cout << endl << "***************************************************" << endl << endl;

		int e = m + n;
		int *c = new int[e];
		SortTogether(a, n, b, m, c, e);
		DisplayArray(c, e);
		cout << " -two arrays together after sorting" << endl;
		system("pause");
		system("cls");

		delete[] a;
		delete[] b;
		delete[] c;
		char s;
		cout << "Would you like to countinie? " << endl;
		cout << "Yes- y or Y " << endl;
		cout << "No- other symbols" << endl;
		cout << "Waiting for Enter: " << endl;
		cin >> s;
		system("cls");
		if (s == 'y' || s == 'Y') continue;
		break;

	}

	return 0;
}

void BoolSort(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = n - 1; j > i; j--)
		{
			if (a[j] < a[j - 1])
			{
				Swap(a[j], a[j - 1]);
			}
		}
	}
}

bool IsDataValid(int n)
{
	if (n <= 0) return false;
	return true;
}

void EnterArray(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		a[i] = rand();
	}
}

void DisplayArray(int a[], int n)
{
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
}

void Swap(int &x, int &y)
{
	int temp;
	temp = x;
	x = y;
	y = temp;
}

void EnterDimention(int &t)
{
	while (true)
	{
		cout << "Enter size   0<=n    : ";
		cin >> t;
		if (IsDataValid(t)) break;
		cout << "Error!" << endl;
	}
}

void SortTogether(int a[], int n, int b[], int m, int c[], int e)
{
	int q1, q2;
	q1 = q2 = 0;
	for (int i = 0; i < e; i++)
	{
		if (q1 <= n && q2 <= m)

		{
			if (a[q1] < b[q2])
			{
				c[i] = a[q1];
				q1++;
			}
			else
			{
				c[i] = b[q2];
				q2++;
			}
		}
		if (q1 > n)
		{
			c[i] = b[q2];
			q2++;
		}
		if (q2 > m)
		{
			c[i] = a[q1];
			q1++;
		}
	}
}