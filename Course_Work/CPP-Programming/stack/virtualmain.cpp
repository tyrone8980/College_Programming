/*
 * main.cpp

 *
 *  Created on: Dec 9, 2016
 *      Author: tyrone8980
 */
#include <iostream>
#include <vector>
using namespace std;
class shape
{
public:
	virtual void display(){cout<<"shape"<<endl;}
	virtual int area(){return 0;}
	virtual~shape(){}
	int x;
};
class Rect:public shape
{
public:
	Rect(int width, int length):m_width(width),m_length(length){}
	int area(){return m_length*m_width;}
	void display(){cout<<"square"<<endl;}
private:
	int m_length, m_width;
};

class Triangle:public shape
{
public:
	Triangle(int base, int height):m_base(base),m_height(height){}
	int area(){return((m_base*m_height)/2);}
	void display(){cout<<"Triangle"<<endl;}
private:
	int m_base, m_height;
};


int main()
{
	int a,b,c,d;
	cout<<"I will print the areas of a Triangle for you"<<endl;
	cout<<"What is your base for the triangle? "<<endl;
	cin>>a;
	cout<<"What is your height for the Triangle? "<<endl;
	cin>>b;
	cout<<"Now for the Square"<<endl;
	cout<<"What is your width for the square? "<<endl;
	cin>>c;
	cout<<"What is your length for the square? "<<endl;
	cin>>d;
	vector<shape*>m_shapelist;
	m_shapelist.push_back(new Rect(c,d));
	m_shapelist.push_back(new Triangle(a,b));
	for(int i = 0; i<m_shapelist.size();i++)
	{
		m_shapelist[i]->display();
		cout<<"area is: "<<m_shapelist[i]->area()<<endl;

	}
	for(int i=0; i <m_shapelist.size();i++)
	{
		delete m_shapelist[i];
	}

}

