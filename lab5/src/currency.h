#ifndef CURRENCY_H
#define CURRENCY_H

#include <iostream>
#include <string>
#include <typeinfo>
//#include <iostream>
//#include <sstream>

class Currency {
    private:
        int notes;
        int coins;
    public:
        Currency() {
            notes = 0;
            coins = 0;
        }
//Pre these are constructors they don't return anything and only set notes and coins.
        Currency(double money) {
            //std::cout << "I am inside currency constructor";
        	//std::cout << std::endl << money;
        	if(money >= 0.0){
                notes = (int)(money);
               // std::cout << money << std::endl;
               // std:: cout << notes << std::endl;

                coins = (money - notes)*100;
               // std::cout << coins << std::endl;

        	} else {
        		throw "Invalid Assignment";
        	}

        }

        Currency(const Currency& p1) {
            notes = p1.notes;
            coins = p1.coins;
        }
        virtual ~Currency(){}
        // destructor

        void setNotes(int n) {
            notes = n;
        }

        void setCoins(int c) {

            coins = c;
        }

        int getNotes() {
            return notes;
        }

        int getCoins() {
        	//std::cout << std::endl << coins;
            return coins;

        }
        virtual std::string getName()= 0;
       // This "is equal method returns a boolean and checks
        //whether two currencies of the same value are
        // equal
        //Pre: take currency object
        // Post:
         bool isEqual(Currency* moolah) {
            bool isSame = false;
            if(moolah->getName() == getName()){
            	if ((notes == moolah->getNotes()) && (coins == moolah->getCoins())) {
            		isSame = true;
            	}
            } else{
            	throw(3);
            }
            return isSame;
        }
         // pre-post this prints the notes/coins
         // Pre: it will take nothing, but it will refer to a currency object
         // Post: it will return nothing, but it will print coins and notes
        virtual void print() {
            std::cout << notes << "." << coins;
            return;
        }
        // This checks if a currency object is greater
        // Pre: it takes a currency object
        // Post: it will return whether or not the moolah is greater than this currency object
        // in the form of a boolean

        bool isGreater(Currency* moolah) {
            bool isGreater = false;
            if(moolah->getName() == getName()){
            	if ((Currency::getNotes()*100 + Currency::getCoins()) > (moolah->getNotes()*100 + moolah->getCoins())) {
            		isGreater = true;
            	}
            } else {
            	throw(3);
            }
            return isGreater;
        }

        //This adds two currency object
        //this adds two currency objects
        //Pre: This takes a currency object
        // It converts all currency into coins then convert back into notes and coins
        // Post: this method will either throw an exception, or it will return nothing
        virtual void add(Currency* moolah) {
        	if(moolah->getName() == getName()){
        		coins = (coins + notes*100) + (moolah->getNotes()*100 + moolah->getCoins());
        		notes = coins/100;
        		coins = coins%100;
        	} else {
        		throw (1);
        	}

        }
        //this subtracts two currency objects
        //Pre: This takes a currency object and checks if it's greater than this currency object
        // It converts all currency into coins then convert back into notes and coins
        // Post: this method will either throw an exception, or it will return nothing
        virtual void subtract(Currency* moolah) {
        	if(moolah->getName() == getName() && (isGreater(moolah) || isEqual(moolah))){
        			coins = (coins + notes*100) - (moolah->getNotes()*100 + moolah->getCoins());
        			notes = coins/100;
        			coins = coins%100;

        	} else {
        		throw(2);
        	}

        }
};

#endif
