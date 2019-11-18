//
// Created by Max on 14-Oct-19.
//
#include <string>
using namespace std;
#ifndef UNTITLED_GUIDE_H
#define UNTITLED_GUIDE_H

typedef struct{
    int days;
    int hours;
    int minutes;
} time;

class Guide
{
public:
    Guide();
    Guide(string Country, time Duration, double Price, string TheBus, string Driver, string Coment, double Rate);
    ~Guide();
private:
    string State;
    time duration;
    double price;
public:
    string get_state();
    time get_duration();
    void print_duration();
    double get_price();
    double rate;
    string comment;
protected:
    string busmodel;
    string driver;
};
#endif //UNTITLED_GUIDE_H
