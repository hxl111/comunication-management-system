#include<iostream>
using namespace std;
#define max 1000
struct person
{
	string name;
	string telnumber;
};

struct personlist
{
	person arr[max];
	int size;
};
void addperson(struct personlist* p)
{
	if (p->size == (max - 1))
	{
		cout << "it is full" << endl;
			
	}
	else
	{
		cout << "please input name " << endl;
		cin >> p->arr[p->size].name;
		cout << "please input telnumber " << endl;
		string personnumber;
		while (true)
		{
			cin >> personnumber;
			if (personnumber.length() == 11 || personnumber.length() == 8)
			{
				p->arr[p->size].telnumber = personnumber; break;
			}
			else
				cout << "number wrong please once input" << endl;
		}
		p->size++;
	}
	system("pause");
	system("cls");
}
//show menu
void showmenu()
{
	cout << "\t1 join  \tpeople" << endl;
	cout << "\t2 show  \tpeople" << endl;
	cout << "\t3 del   \tpeople" << endl;
	cout << "\t4 find  \tpeople" << endl;
	cout << "\t5 change\tpeople" << endl;
	cout << "\t6 empty \tpeople" << endl;
	cout << "\t0 exit  \tsystem" << endl;
	
}
void showperson(struct personlist* p)
{
	for (int i = 0; i < p->size; i++)
	{
		cout << " name " << p->arr[i].name << " number " << p->arr[i].telnumber << endl;
	}
	if (p->size == 0)
		cout << "it is empty" << endl;
	system("pause");
	system("cls");
}
void delperson(struct personlist* p)
{
	cout << "please input name" << endl;
	string name;
	cin >> name;
	for (int i = 0; i < p->size; i++)
	{
		if (p->arr[i].name == name)
		{
			for (int j = i; j < p->size; j++)
			{
				p->arr[j] = p->arr[j + 1];
			}
			p->size--;
		}
	}
	system("pause");
	system("cls");
}
void findperson(struct personlist* p)
{
	cout << "please input name" << endl;
	string name;
	cin >> name;
	int i;
	for ( i = 0; i < p->size; i++)
	{
		if (p->arr[i].name == name)
		{
			cout << " name " << p->arr[i].name << " number " << p->arr[i].telnumber << endl;
			break;
		}
	}
	if (i >= p->size)
		cout << "no person,if you want add please push"<<endl;
	system("pause");
	system("cls");
}
void changeperson(struct personlist* p)
{
	cout << "please input name" << endl;
	int i;
	string name;
	cin >> name;
	for ( i = 0; i < p->size; i++)
	{
		if (p->arr[i].name == name)
		{
			cout << "please input number change after" << endl;
			string personnumber;
			while (true)
			{
				cin >> personnumber;
				if (personnumber.length() == 11 || personnumber.length() == 8)
				{
					p->arr[i].telnumber = personnumber; break;
				}
				else
					cout << "number wrong please once input" << endl;
			}
			break;
		}
	}
	if (i >=p->size)
		cout << "no person,if you want add please push" << endl;
	system("pause");
	system("cls");
}
void emptyperson(struct personlist* p)
{
	p->size = 0;
	system("pause");
	system("cls");
}
int main()
{
	personlist s;//creat addressbooks
	s.size = 0;
	
	int select = 0;
	while (true)
	{
		showmenu();
		cout << "please input menu select" << endl;
		cin>> select;
		switch (select)
		{
		case 1:addperson(&s);
			break;//join
		case 2:showperson(&s);
			break;//show
		case 3:delperson(&s);
			break;//del
		case 4:findperson(&s);
			break;//find
		case 5:changeperson(&s);
			break;//chage
		case 6:emptyperson(&s);
			break;//empty
		case 0:cout << "welcome once again using" << endl;
			system("pause");
			return 0;
			break;//quit
		default: {cout << "please input 0-6" << endl; 
			system("pause");
			system("cls"); }
			break;
		}
	}
	
	system("pause");
	return 0;
}