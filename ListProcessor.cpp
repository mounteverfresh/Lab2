// ListProcessor.cpp

// tom bailey   1540  30 sep 2011

// tom bailey   1030  27 jan 2012
// Exercise the List class with verbose Node constructor
//   and destructor.
#include "pch.h"
#include "LinkedList.h"


int main()
{
	List cows;
	cout << "cows list  :  " << cows << endl << endl;

	cows.insertAsFirst(1.23);
	cows.insertAsFirst(2.34);
	cows.instertAsLast(3.45);
	cout << "cows list  :  " << cows <<
		endl << "number of elements : " << cows.size() << 
		endl << "sum of this list : " << cows.sum() << endl << endl;

	cows.removeFirst();
	cout << "cows list  :  " << cows <<
		endl << "number of elements : " << cows.size() <<
		endl << "sum of this list : " << cows.sum() << endl << endl;


	List horses(cows);
	cout << "cows list  :  " << cows << endl;
	cout << "horses list:  " << horses <<
		endl << "number of elements : " << horses.size() <<
		endl << "sum of this list : " << horses.sum() << endl << endl;



	horses.removeFirst();
	horses.insertAsFirst(5.67);
	cows.insertAsFirst(6.78);
	cout << "cows list  :  " << cows << endl;
	cout << "horses list:  " << horses << endl << endl;

	List pigs;
	cout << "cows list  :  " << cows << endl;
	cout << "horses list:  " << horses << endl;
	cout << "pigs list  :  " << pigs << endl << endl;

	pigs = cows;
	cout << "cows list  :  " << cows << endl;
	cout << "horses list:  " << horses << endl;
	cout << "pigs list  :  " << pigs <<
		endl << "number of elements : " << pigs.size() <<
		endl << "sum of this list : " << pigs.sum() << endl << endl;

	pigs = horses;
	cows.instertAsLast(0.78);
	cout << "cows list  :  " << cows <<
		endl << "number of elements : " << cows.size() <<
		endl << "sum of this list : " << cows.sum() << endl << endl;
	cout << "horses list:  " << horses <<
		endl << "number of elements : " << horses.size() <<
		endl << "sum of this list : " << horses.sum() << endl << endl;

	cout << "pigs list  :  " << pigs <<
		endl << "number of elements : " << pigs.size() <<
		endl << "sum of this list : " << pigs.sum() << endl << endl;

	cout << "End of code" << endl;

	return 0;
}

