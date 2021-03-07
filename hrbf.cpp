#include "hrbf_phi_funcs.h"
#include "hrbf_core.h"
#include <iostream>
#include <fstream>

using namespace std;
typedef HRBF_fit<float, 3, Rbf_pow3<float> > HRBF;

int main(int argc, char *argv[])
{
    HRBF fit;

    std::cout << "Read files\n";

    std::ifstream points_file;
    points_file.open(argv[1]);
    std::ifstream norms_file;
    norms_file.open(argv[2]);
    std::ifstream query_file;
    query_file.open(argv[3]);
    std::ifstream in_vals_file;
    in_vals_file.open(argv[4]);
    std::ofstream out_vals_file;
    out_vals_file.open(argv[5]);
    
    std::vector<HRBF::Vector> p, n;
    std::vector<float> vls;
    float v1,v2,v3;
    char c;

    while (points_file >> c >> v1 >> v2 >> v3)
    {
        if (v1==0 && v2==0 && v3==0)
            continue;
        // std::cout<<v1<<" "<<v2<<" "<<v3<<endl;
        HRBF::Vector pt(v1,v2,v3);
        p.push_back(pt);
    }

    while (norms_file >> v1 >> v2 >> v3)
    {
        HRBF::Vector nr(v1,v2,v3);
        n.push_back(nr);
    }

    while (in_vals_file >> v1)
    {
        vls.push_back(v1);
    }
    std::cout << p.size() << " " << n.size() << endl;

    std::cout << "Fit\n";
    fit.hermite_fit(p, n, vls);
    // fit.hermite_fit(p, n);

    std::cout << "Eval\n";
    vector<float> values;
    while (query_file >> v1 >> v2 >> v3)
    {
        HRBF::Vector x(v1,v2,v3);
        values.push_back(fit.eval(x));
    }

    int i;
    for(i=0; i<values.size(); i++)
        out_vals_file << values[i] << std::endl;

    return 0;
}
