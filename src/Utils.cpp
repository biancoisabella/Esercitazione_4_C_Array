#include "Utils.hpp"

#include "iostream"
#include "fstream"
#include "sstream"
#include "iomanip"


bool ImportDataFromFile(const string& inputFilePath, size_t& n, double &S, double*& w, double*& r){
    ifstream fstr(inputFilePath);

    if(fstr.fail())
        return false;

    string tmp;
    getline(fstr, tmp, ';'); //leggo in una stringa temporanea S;

    // leggo il valore di S
    fstr >> S;

    getline(fstr, tmp, ';'); //leggo in una stringa temporanea n;

    // leggo la lunghezza del vettore n
    fstr >> n;

    getline(fstr, tmp); //leggo in una stringa temporanea \n
    getline(fstr, tmp); //leggo in una stringa temporanea w;r\n

    w = new double[n];
    r = new double[n];

    for(unsigned int i = 0; i < n; i++){
        fstr >> w[i];
        getline(fstr, tmp, ';');
        fstr >> r[i];
    }


    return true;
}


string ArrayToString(const size_t& n, const double* const& v)
{
    string str;
    ostringstream toString;
    toString << "[ ";
    for (unsigned int i = 0; i < n; i++)
    toString<< v[i]<< " ";
    toString << "]";

    return toString.str();
}


bool ExportResult(const string& outputFilePath,
    const size_t& n, const double &S, const double* const & w, const double* const& r,
    const double& rate_return, const double& V){

    // Open File
    ofstream file;
    file.open(outputFilePath);

    if (file.fail())
    {
        return false;
    }

    file << fixed << setprecision(2); //scelgo il formato di stampa dei numeri corretto

    file << "S = " << S << ", n = " << n << endl;
    
    file << "w = " << ArrayToString(n, w) << endl;
    file << "r = " << ArrayToString(n, r) << endl;

    file << "Rate of return of the portfolio: " << setprecision(4) << rate_return << endl;
    file << "V: " << setprecision(2) << V << endl;

    file.close();
    return true;
}

double RateReturn(size_t& n, double*& w, double*& r){
    double sum = 0;
    for(unsigned int i = 0; i < n; i++)
        sum += r[i]*w[i];
    return sum;
}