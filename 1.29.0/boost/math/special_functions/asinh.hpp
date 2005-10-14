//    boost asinh.hpp header file

//  (C) Copyright Eric Ford & Hubert Holin 2001. Permission to copy, use, modify, sell and
//  distribute this software is granted provided this copyright notice appears
//  in all copies. This software is provided "as is" without express or implied
//  warranty, and with no claim as to its suitability for any purpose.

// See http://www.boost.org for updates, documentation, and revision history.

#ifndef BOOST_ASINH_HPP
#define BOOST_ASINH_HPP


#include <cmath>
#include <boost/limits.hpp>
#include <string>
#include <stdexcept>


// This is the inverse of the hyperbolic sine function.

namespace boost
{
    namespace math
    {
#if defined(__GNUC__) && (__GNUC__ < 3)
        // gcc 2.x ignores function scope using declarations,
        // put them in the scope of the enclosing namespace instead:
        
        using    ::std::abs;
        using    ::std::sqrt;
        using    ::std::log;
        
        using    ::std::numeric_limits;
#endif
        
        template<typename T>
        inline T    asinh(const T x)
        {
            using    ::std::abs;
            using    ::std::sqrt;
            using    ::std::log;
            
            using    ::std::numeric_limits;
            
            
            T const            one = static_cast<T>(1);
            T const            two = static_cast<T>(2);
            
            static T const    taylor_2_bound = sqrt(numeric_limits<T>::epsilon());
            static T const    taylor_n_bound = sqrt(taylor_2_bound);
            static T const    upper_taylor_2_bound = one/taylor_2_bound;
            static T const    upper_taylor_n_bound = one/taylor_n_bound;
            
            if        (x >= +taylor_n_bound)
            {
                if        (x > upper_taylor_n_bound)
                {
                    if        (x > upper_taylor_2_bound)
                    {
                        // approximation by laurent series in 1/x at 0+ order from -1 to 0
                        return( log( x * two) );
                    }
                    else
                    {
                        // approximation by laurent series in 1/x at 0+ order from -1 to 1
                        return( log( x*two + (one/(x*two)) ) );
                    }
                }
                else
                {
                    return( log( x + sqrt(x*x+one) ) );
                }
            }
            else if    (x <= -taylor_n_bound)
            {
                return(-asinh(-x));
            }
            else
            {
                // approximation by taylor series in x at 0 up to order 2
                T    result = x;
                
                if    (abs(x) >= taylor_2_bound)
                {
                    T    x3 = x*x*x;
                    
                    // approximation by taylor series in x at 0 up to order 4
                    result -= x3/static_cast<T>(6);
                }
                
                return(result);
            }
        }
    }
}

#endif /* BOOST_ASINH_HPP */
