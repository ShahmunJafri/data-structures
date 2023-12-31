	#include <typeinfo>
	#include <sstream>
	#include "krone.h"
	#include "hashTable.h"

	/*
	Shahmun Jafri
	Lab #5
	This is my 5th lab. This lab will show you how hash tables work
	This is an array based hash table

	*/
	using namespace std;

	int main(){

		cout << "This is my 5th lab Assignment";
		Currency* currencies[20];


	/*1*/ currencies[0] = new Krone(57.12);
	/*2*/ currencies[1] = new Krone(23.44);
	/*3*/ currencies[2] = new Krone(87.43);
	/*4*/ currencies[3] = new Krone(68.99);
	/*5*/ currencies[4] = new Krone(111.22);
	/*6*/ currencies[5] = new Krone(44.55);
	/*7*/ currencies[6] = new Krone(77.77);
	/*8*/ currencies[7] = new Krone(18.36);
	/*9*/ currencies[8] = new Krone(543.21);
	/*10*/currencies[9] = new Krone(20.21);
	/*11*/currencies[10] = new Krone(345.67);
	/*12*/currencies[11] = new Krone(36.18);
	/*13*/currencies[12] = new Krone(48.48);
	/*14*/currencies[13] = new Krone(101.00);
	/*15*/currencies[14] = new Krone(11.00);
	/*16*/currencies[15] = new Krone(21.00);
	/*17*/currencies[16] = new Krone(51.00);
	/*18*/currencies[17] = new Krone(1.00);
	/*19*/currencies[18] = new Krone(251.00);
	/*20*/currencies[19] = new Krone(151.00);


	HashTable* hashTable = new HashTable(29);
	double find;
	string entry;
	for(int i = 0; i < 20; i++){
		hashTable->hash(currencies[i]);
	}
	cout << hashTable->getCollisions() << ", " << hashTable->getLoadFactor() << ", " << hashTable->getNumberOfItems() << endl;

	cout << "Search for a Krone or end the program 'q': ";

	getline(cin, entry);

	//cin>>find;
	cout << endl;
	while(entry != "q"){
		stringstream linestream(entry);
		linestream >> find;

		Currency* krone = new Krone(find);

		if(hashTable->search(krone) != -1){
			cout << hashTable->search(krone) << endl;
		} else {
			cout << "Invalid Data" << endl;
		}

		cout << "Search for a Krone or end the program 'q': ";
		getline(cin, entry);
	}


	return 0;
	}
