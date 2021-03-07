#include "hrbf_phi_funcs.h"
#include "hrbf_core.h"
#include <iostream>
#include <vector>

using namespace std;

typedef HRBF_fit<float, 3, Rbf_pow3<float> > HRBF;

int main()
{
    HRBF fit;
    // Define samples (position, normal);
    HRBF::Vector pts[] = { HRBF::Vector( 0.0, 0.0, 0.0), HRBF::Vector( 1.0, 0.0, 0.0), HRBF::Vector( 0.0, 0.0, 2.0) };
    HRBF::Vector nrs[] = { HRBF::Vector(-1.0, 0.0, 0.0), HRBF::Vector( 1.0, 0.0, 0.0), HRBF::Vector( 0.0, 0.0, 1.0) };

    const int size = sizeof(pts) / sizeof(HRBF::Vector);
    std::vector<HRBF::Vector> p(pts, pts + size );
    std::vector<HRBF::Vector> n(nrs, nrs + size );
    // Solve linear system;
    fit.hermite_fit(p, n);

    HRBF::Vector x( 0.0, 0.0, 1.0);
    float potential = fit.eval( x );
    HRBF::Vector gf = fit.grad( x );

    std::cout << potential << endl;
    std::cout << gf << endl;
    return 0;
}
