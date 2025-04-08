#include <iostream>
#include <fstream>
#include <iomanip>
#include "Utils.hpp"


using namespace std;

int main()
{
    double S;
    size_t n;

    double *w = nullptr;
    double *r = nullptr;

    cout << fixed << setprecision(2);


    if(!ImportDataFromFile("data.txt", n, S, w, r)){
        cerr << "Error opening input file!" << endl;
        return -1;
    }

    double rate_return = RateReturn(n, w, r);

    
    if(!ExportResult("result.txt", n, S, w, r, rate_return, (1+rate_return)*S)){
        cerr << "Error opening output file!" << endl;
        return -2;
    }


    return 0;
}

