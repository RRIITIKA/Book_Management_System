#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;
class project
{
	public:
		int a;
		fstream f;
		string s,p;
		int n;
		float price;
		int input()
		{
			cout<<"\n\nEnter your choice\n1 for enter the book\n2 for searching a book\n3 for modifying the book\n4 for deleting a book\n5 for displaying all the books\n6 for exit\n";
			cin>>a;
			return(a);
		}
		void entry()
		{
			cout<<"\n\tenter the name of book:";
			cin>>s;
			cout<<"\tenter the name of author:";
			cin>>p;
			cout<<"\tenter the number of copies:";
			cin>>n;
			cout<<"\tenter the price:";
			cin>>price;
			f.open("book.txt",ios::out|ios::ate);
			f<<s<<endl;
			f<<p<<endl;
			f<<n<<endl;
			f<<price<<endl;
			f.close();
			cout<<"\nyour entry has been saved\n";	
		}
};
class pro:public project
{
	public:
	void search()
	{
		string c;
		cout<<"\nenter the book you want to search\n";
		cin>>c;
		f.open("book.txt",ios::in);
		f>>s;
		if(s.compare(c)==0)
		{
			cout<<"\nBook found\n";
		}
		else
		{
			cout<<"\nBook not found\n";
		}
	f.close();
	}
	inline void modify()
	{
		int z;
		string c;
		cout<<"\nenter the book you want to modify\n";
		cin>>c;
		f.open("book.txt",ios::in);
		f>>s;
		if(s.compare(c)==0)
		{
			z=1;
		}
		else
		{
			cout<<"\nno book to modify\n";
		}
		f.close();
		if(z==1);
		{
			cout<<"\n\tenter the new name of book:";
			cin>>s;
			cout<<"\tenter the new name of author:";
			cin>>p;
			cout<<"\tenter the new number of copies:";
			cin>>n;
			cout<<"\tenter the new price:";
			cin>>price;
			f.open("book.txt",ios::out|ios::ate);
			f<<s<<endl;
			f<<p<<endl;
			f<<n<<endl;
			f<<price<<endl;
			f.close();
			cout<<"\nbook has been updated\n";
		}
	}
	void del()
	{	
		f.open("book.txt",ios::out);
		s="";p="";n=0;price=0;
		f<<s<<endl;
		f<<p<<endl;
		f<<n<<endl;
		f<<price<<endl;
		f.close();
		cout<<"\nthe data has been deleted";
	}	
	void display();
}p;	
void pro::display()
{
	f.open("book.txt",ios::in);
	f>>s>>p>>n>>price;
	cout<<"\tname of the book:"<<s;
	cout<<"\n\tname of the author:"<<p;
	cout<<"\n\tnumber of copies:"<<n;
	cout<<"\n\tprice:"<<price;
	f.close();
}
int main()
{
	int b;
	x:b=p.input();
	try
	{
		if(b==1)
		{
			p.entry();
			goto x;
		}
		else if(b==2)
		{
			p.search();
			goto x;
		}	
		else if(b==3)
		{
			p.modify();	
			goto x;
		}
		else if(b==4)
		{
			p.del();
			goto x;
		}
		else if(b==5)
		{
			p.display();
			goto x;
		}
		else if(b==6)
		{
			exit(0);
		}
		else
		{
			throw(b);
		}
	}
	catch(int m)
	{
		cout<<"\nwrong input";
	}
 	return 0;
}
