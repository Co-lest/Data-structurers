#include <iostream>
#include <fstream>

using namespace std;

void arr();

int main()
{
	fstream fout;

	unsigned short X = 8667;

	fout.open("file.dat", ios::out | ios::binary);

	if(fout)
	{
		fout.write(reinterpret_cast<char*>(&x), sizeof(unsigned short));
		fout.close();
	}
	else
	{
		cout << "Error! Could not open file." << endl;
	}

	fout.open("file.dat", ios::in | ios::binary);
	if (fout)
	{
		unsigned short y = 99;
		fout.read(reinterpret_cast<char*>(&y), sizeof(unsigned short));
		fout.close();
		cout << y << endl;
	}

	cin.ignore();
	cin.get();

	arr();

	int h[5] = {3, 3, 4, 6, 5};
	const int size = 5;

	int[d]; 

	passArr(h, size);
	readArr(d, size);

	for(int i : d)
	{
		cout << d << " ";
	}

	return 0;
}

void arr()
{
	fstream fout;

	f.open("file.dat" ios::out | ios::binary);
	if (f)
	{
		int a[] = {2, 3, 4, 5, 5, 6, 1,7};

		fout.write(reinterpret_cast<char*>(a), sizeof(a));
		f.close();
	}
	else
	{
		cout << "Error opening the file!" << endl;
	}

	int s[8];

	if (fout)
	{
		fout.read(reinterpret_cast<char*>(b), sizeof(b));
		fout.close();

		for(int i : b)
		{
			cout << i << " ";
		}
		cout << endl;
	}

	return;
}

void passArr(int *a, size)
{
	fstream fout;
	f.open("file.dat", ios::out | ios::binary);

	if (fout)
	{
		fout.write(reinterpret_cast<a>(char*), size * sizeof(int));
		fout.close();
	}
	else
	{
		cout << "Error opening the file!" << endl;
	}
	
	return;
}

void readArr(int *a, size)
{
	fstream fout;
	f.open("file.dat", ios::in | ios::binary);

	if (fout)
	{
		fout.read(reinterpret_cast<a>(char*), size * sizeof(int));
		fout.close();
	}
	else
	{
		cout << "Error opening the file!" << endl;
	}
	
	return;
}