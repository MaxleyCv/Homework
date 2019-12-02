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
    Vector A[5];
    for (int i = 0; i<5; i++)
    for (int j = 0; j<5;j++){
        A[j].SetArrEl(i);
    }
    Vector R;
    Vector Fs;
    for (int i = 0; i<5; i++)
        A[i].mergeSort(0, 4);
    for (int i = 0; i<5; i++){
        for (int j = 0; j<5; j++) {
            std::cout << A[j].get_arr()[i] << "\t ";
            R.setVectorel(A[j].get_arr()[i]);
        }
        Fs.setVectorel(R.mul());
        std::cout << std::endl;
    }
    std::cout << "f[i]" << std::endl;
    double sum = 0;
    for (int i = 0; i< 5; i++) {
        sum += pow(abs(Fs.get_arr()[i]), 0.2);
        std::cout << pow(abs(Fs.get_arr()[i]), 0.2) << " ";
    }
    std::cout << std::endl;
    std::cout << "F(f[i]): \n" << sum/5 << std::endl;
    return 0;
} 
