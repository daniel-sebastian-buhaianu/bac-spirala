#include <iostream>
#define NMAX 15
using namespace std;
int main()
{
	int a[NMAX][NMAX];
	int n, i, j, ls, cs, lf, cf, val;
	cout << "n = "; cin >> n;
	ls = cs = val = 0;
	lf = cf = n-1;
	do
	{
		// construiesc marginea de sus
		a[ls][cs] = val+1;
		for (j = cs+1; j <= cf; j++)
			a[ls][j] = a[ls][j-1]+1;
		// construiesc marginea din dreapta
		for (i = ls+1; i <= lf; i++)
			a[i][cf] = a[i-1][cf]+1;
		// construiesc marginea de jos
		for (j = cf-1; j >= cs; j--)
			a[lf][j] = a[lf][j+1]+1;
		// construiesc marginea din stanga
		for (i = lf-1; i > ls; i--)
			a[i][cs] = a[i+1][cs]+1;
		val = a[ls+1][cs];
		ls++, cs++;
		lf--, cf--;
	}
	while(ls <= lf);
	for (i = 0; i < n; i++)
	{	
		for (j = 0; j < n; j++)
			cout << a[i][j] << ' ';
		cout << '\n';
	}
	return 0;
}
