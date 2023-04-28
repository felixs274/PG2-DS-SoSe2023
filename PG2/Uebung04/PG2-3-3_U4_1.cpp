#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

//! deleted function
double mean(vector<float> const& arr) = delete;

//! normal function
char mean(vector<char> const& arr)
{
    int idx = (arr.size() - 1) / 2;
    return arr[idx];
}

//! template
template<typename T>
double mean(vector<T> const& arr)
{
    double s = 0;
    for(auto const& v: arr)
    {
        s += v;
    }
    return s/arr.size();   
}

//! spezialized template
template<>
double mean<long>(vector<long> const& arr)
{
    double p = arr[0];
    for(long i = 1; i<arr.size(); i++)
    {
        p *= arr[i];
    }

    p = pow(p, 1 / double(arr.size()));
    return p;
}

int main()
{
    vector<float> vf{1.2, 3.4, 5.6, 7.8, 9.0};
    //cout << "Arithm. mean = " << mean(vf) << endl;
    vector<double> vd{1.2, 3.4, 5.6, 7.8, 9.0};
    cout << "Arithm. mean = " << mean(vd) << endl;
    vector<int> vn{1, 2, 3, 4, 5, 6, 7, 8, 9};
    cout << "Arithm. mean = " << mean(vn) << endl;
    vector<long> vl{1, 2, 3, 4, 5, 6, 7, 8, 9};
    cout << "Geometr. mean = " << mean(vl) << endl;
    vector<char> vc1{'a', 'b', 'c', 'd', 'e', 'f'};
    cout << "Middle val = " << mean(vc1) << endl;
    vector<char> vc2{'a', 'b', 'c', 'd', 'e'};
    cout << "Middle val = " << mean(vc2) << endl;
    return 0;
}
