/*
 * main.cpp
 *
 *  Created on: 15-Nov-2018
 *      Author: devpc
 */


#include <iostream>
#include <stdlib.h>
#include <cassert>

using namespace std;

class singleDemo{

private:

	static singleDemo *obj;

	singleDemo()
	{

	}

public:


	static unsigned int count;

	singleDemo* getInstance();

	~singleDemo()
	{
		cout<<"Destructor of singleDemo Object"<<endl;
	}
};


singleDemo * singleDemo::getInstance()
{
	if(!obj)
	  {
				obj = new singleDemo;
				count++;
	   }
	cout<<"Inside Get instance function"<<endl;
	cout<<"No of objects created till now are "<<count<<endl;

	return obj;
}

unsigned int singleDemo::count=0;

singleDemo *singleDemo::obj = 0;

int main()
{

	singleDemo *obj1 = NULL,*obj2 =NULL;

	obj1 = obj1->getInstance();
	obj2 = obj2->getInstance();

	assert(obj1==obj2);

	delete(obj1);
	delete(obj2);



	return 0;
}
