/* This Source Code Form is subject to the terms of the Mozilla Public License, 
 * v. 2.0. If a copy of the MPL was not distributed with this file, 
 * You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#ifndef HRBF_PHI_FUNCS_HPP_
#define HRBF_PHI_FUNCS_HPP_

/** @brief Radial basis functions definitions (function phi)
  Here you can add more radial basis function definitions.  
*/


/**
 * @class Rbf_pow2
 * Radial basis function phi(x) = x^3 first and second derivative
 * 
 **/
template<typename Scalar>
struct Rbf_pow1
{
    // phi(x) = x
    static inline Scalar f  (const Scalar& x) { return x;             }
    // first derivative phi'(x) = 1
    static inline Scalar df (const Scalar& x) { return Scalar(1); }
    // second derivative phi''(x) = 0
    static inline Scalar ddf(const Scalar& x) { return Scalar(0);     }
};

/**
 * @class Rbf_pow3
 * Radial basis function phi(x) = x^3 first and second derivative
 * 
 **/
template<typename Scalar>
struct Rbf_pow3
{
    // phi(x) = x^3
    static inline Scalar f  (const Scalar& x) { return x*x*x;             }
    // first derivative phi'(x) = 3x^2
    static inline Scalar df (const Scalar& x) { return Scalar(3) * x * x; }
    // second derivative phi''(x) = 6x
    static inline Scalar ddf(const Scalar& x) { return Scalar(6) * x;     }
};


/**
 * @class Rbf_pow5
 * Radial basis function phi(x) = x^5 first and second derivative
 * 
 **/
template<typename Scalar>
struct Rbf_pow5
{
    // phi(x) = x^5
    static inline Scalar f  (const Scalar& x) { return x*x*x*x*x;             }
    // first derivative phi'(x) = 5x^4
    static inline Scalar df (const Scalar& x) { return Scalar(5) * x * x * x * x; }
    // second derivative phi''(x) = 20x^3
    static inline Scalar ddf(const Scalar& x) { return Scalar(20) * x * x * x;     }
};


/**
 * @class Rbf_pow7
 * Radial basis function phi(x) = x^3 first and second derivative
 * 
 **/
template<typename Scalar>
struct Rbf_pow7
{
    // phi(x) = x^7
    static inline Scalar f  (const Scalar& x) { return x*x*x*x*x*x*x;             }
    // first derivative phi'(x) = 7x^6
    static inline Scalar df (const Scalar& x) { return Scalar(7) * x * x * x * x * x * x; }
    // second derivative phi''(x) = 42x^5
    static inline Scalar ddf(const Scalar& x) { return Scalar(42) * x * x * x * x * x;     }
};

#endif //HRBF_PHI_FUNCS_HPP_
