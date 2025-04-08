#pragma once

#include <iostream>

using namespace std;


bool ImportDataFromFile(const string& inputFilePath,
    size_t& n, double &S, double*& w, double*& r);

double RateReturn(size_t& n, double*& w, double*& r);

string ArrayToString(const size_t& n, const double* const& v);

bool ExportResult(const string& outputFilePath,
    const size_t& n, const double &S, const double* const & w, const double* const& r,
    const double& rate_return, const double& V);