#ifndef KRONE_H
#define KRONE_H
#include "currency.h"
//#include <string>
//#include <iostream>



class Krone : public Currency {
    private:
        std::string curr_name;
    public:
        Krone(): Currency() {
            curr_name = "Krone";
        }
        Krone(double money): Currency(money) {
        	//std::cout << std::endl << money;
            curr_name = "Krone";
        }
        Krone(const Krone& p1): Currency(p1) {
            curr_name = p1.curr_name;
        }
        ~Krone(){}

        void print() {
            Currency::print();
            //std::cout << "I am using the krone print method";
            std::cout << " " << curr_name;
        }

        std::string getName(){
             return curr_name;
        }



};

#endif
