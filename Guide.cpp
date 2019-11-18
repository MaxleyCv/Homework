//
// Created by Max on 14-Oct-19.
//
#include <iostream>
#include <string>
#include "Guide.h"

using namespace std;

    Guide::Guide(){
        this -> State = "Moldova";
        this -> duration = {15,21,45};
        this -> price = 5500;
        this -> rate = 1.0/5;
        this -> busmodel = "Ikarus200";
        this -> driver = "Ion_Ivanutsa";
        this -> comment = "tur aceast e foarte bun";

    }
    Guide::Guide(string Country, time Duration, double Price, string TheBus, string Driver, string Coment, double Rate){
        this -> State = Country;
        this -> price = Price;
        this -> duration = Duration;
        this -> busmodel = TheBus;
        this -> driver = Driver;
        this -> comment = Coment;
        this -> rate = Rate;
    }
    Guide::~Guide(){
;       std::cout << "Destruction!" << endl;
    }

    string Guide::get_state(){
        return this -> State;
    }
    time Guide::get_duration(){
        return this -> duration;
    }
    void Guide::print_duration(){
        cout << duration.days << " days, " <<  duration.hours << " hours, " << duration.minutes << " minutes" << endl;
    }
    double Guide::get_price(){
        return this -> price;
    }




