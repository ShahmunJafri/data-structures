#ifndef HASHTABLE_H
#define HASHTABLE_H
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "krone.h"

using namespace std;

class HashTable {
private:
    int size;
    Currency* table;
    int m;
    int n;
    int totalCollision;
    //double loadFactor;
    int numberOfItems;

    int hashValue(Currency* current) {
        return (current->getNotes()*m + current->getCoins()*n)%size;
    }
    int quadraticProbe(int index, int i) {
        return (index + i*i) % size;
    }

public:
    HashTable(int length) {
        size = length;
        table = new Krone[size];
        totalCollision = 0;
       // loadFactor = 0;
        numberOfItems = 0;
        m = 2;
        n = 3;
    }

    void hash(Currency* current) {
        int hash_value = hashValue(current);
        int i = 0;
        while (table[hash_value].isEqual(nullptr)) {
            hash_value = quadraticProbe(hash_value, i);
            i++;
            totalCollision++;
        }
        numberOfItems++;
        //table[hash_value] = new Krone(current);
        table[hash_value].setCoins(current->getCoins());
        table[hash_value].setNotes(current->getNotes());
    }

    int search(Currency* current) {
        int index = hashValue(current);
        int i = 0;
        while(table[quadraticProbe(index, i)].isEqual(nullptr)) {
            if(table[quadraticProbe(index, i)].isEqual(current)) {
                return index;
            }
            index = quadraticProbe(index, i);
            i++;
        }
        return -1;
    }

    int getNumberOfItems(){
    	return numberOfItems;
    }
    double getLoadFactor(){
    	return double(numberOfItems)/double(size);
    }
    int getCollisions(){
    	return totalCollision;
    }
};

#endif
