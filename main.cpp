#include <iostream>
#include <string>
#include "Guide.h"

using namespace std;

int main() {
    Guide MD;
    Guide Chisinau;
    Guide Czech("Czechia", {4, 21, 0}, 50, "Volvo", "Mircea_Valcea", "Good comment", 4.5/5 );
    cout <<  MD.get_state() << endl;
    MD.print_duration();
    cout << MD.get_price() << " EUR \n" << MD.comment <<"\n"<< MD.rate << endl;
    cout <<  Czech.get_state() << endl;
    Czech.print_duration();
    cout << Czech.get_price() << " EUR \n" << Czech.comment <<"\n"<< Czech.rate << endl;
    cout <<  MD.get_state() << endl;
    MD.print_duration();
    cout << MD.get_price() << " EUR \n" << MD.comment <<"\n"<< MD.rate << endl;
    return 0;
}