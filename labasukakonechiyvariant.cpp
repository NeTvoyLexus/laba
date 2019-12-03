# include<iostream>
# include<conio.h>
# include<string>
# include<stdio.h>

using namespace std;

struct mas
{
	char name[20];
	char autor[20];
	int god;
};

class bibl
{
private:
	mas kn;
public:
	void in(bibl[], int&);
	void vyb(bibl[], int&);
	void poisk(bibl[], int&);
	void udal(bibl[], int&);
	void dobavl(bibl[], int&);
	void vivod(bibl[], int&);
};
void bibl::in(bibl a[], int& x)
{
	for (int i = 0; i < x; i++)
	{
		cout << "Nazvanie: ";
		cin >> a[i].kn.name;
		cout << "Avtor: ";
		cin >> a[i].kn.autor;
		cout << "God izdaniya: ";
		cin >> a[i].kn.god;
	}
	
	

	a[x].vyb(a, x);
}
void bibl::vyb(bibl a[], int& x)
{
	int vybor = 0;
	do
	{
		
		cout << "1-Poisk knig\n2-udalenye knigi\n3-dobavlenye knigi\n4-pokazat biblioteky\n5-vihod\nVash vybor:\n";
		cin >> vybor;
		
		if (vybor == 1)
			a[x].poisk(a, x);
		if (vybor == 2)
			a[x].udal(a, x);
		if (vybor == 3)
			a[x].dobavl(a, x);
		if (vybor == 4)
			a[x].vivod(a, x);
	} while (vybor != 5);
}
void bibl::poisk(bibl a[], int& x)
{
	int p = 0, god = 0;
	char name[20], autor[20];
	cout << "1-poisk po nazvaniu\n2-poisk po avtory\n3-poisk po gody izdaniya\nVash vibor:";
	cin >> p;
	

	if (p == 1)
	{
		int f = 0;
		cout << "Vvedite nazvanie: ";
		cin >> name;
		for (int i = 0; i < x; i++)
		{
			if (strcmp(name, a[i].kn.name) == 0)
			{
				cout << a[i].kn.name << "     " << a[i].kn.autor << "     " << a[i].kn.god << endl;
				f++;
			}
		}
		if (f == 0)
			cout << "Net takix knig!";
		
	}
	if (p == 2)
	{
		int h = 0;
		cout << "Vvedite avtora: ";
		cin >> autor;
		for (int i = 0; i < x; i++)
		{
			if (strcmp(autor, a[i].kn.autor) == 0)
			{
				cout << a[i].kn.name << "     " << a[i].kn.autor << "     " << a[i].kn.god << endl;
				h++;
			}
		}
		if (h == 0)
			cout << "Net takix knig!";
		
	}
	if (p == 3)
	{
		int g = 0;
		cout << "Vvedite god izdaniya: ";
		cin >> god;
		for (int i = 0; i < x; i++)
		{
			if (god == a[i].kn.god)
			{
				cout << a[i].kn.name << "     " << a[i].kn.autor << "     " << a[i].kn.god << endl;
				g++;
			}
		}
		if (g == 0)
			cout << "Net takix knig!";
		
	}



}
void bibl::udal(bibl a[], int& x)
{
	int udal;
	cout << "vvedit adress dlya udaleniya < " << x << endl;
	cin >> udal;
	if (x == 1)
		cout << "udalenye nevozmozhno\n";
	if (x != 1)
	{
		strcpy_s(a[udal - 1].kn.name, a[x - 1].kn.name);
		strcpy_s(a[udal - 1].kn.autor, a[x - 1].kn.autor);
		a[udal - 1].kn.god = a[x - 1].kn.god;
		x--;
		cout << "Udaleno!\n";
	}
}
void bibl::dobavl(bibl a[], int& x)
{
	cout << "Nazvanie: ";
	cin >> a[x].kn.name;
	cout << "Avtor: ";
	cin >> a[x].kn.autor;
	cout << "God izdaniya: ";
	cin >> a[x].kn.god;
	x++;
}
void bibl::vivod(bibl a[], int& x)
{
	for (int i = 0; i < x; i++)
	{
		cout << a[i].kn.name << "     " << a[i].kn.autor << "     " << a[i].kn.god << endl;
	}
}

	int main()
	{

		bibl  a[10];
		int x = 0;
		cout << "Vvedite chislo knig:\n";
		cin >> x;
		cout << "Vvedite vashi knigi:\n";
		a[x].in(a, x);
	}
