#if defined(_MSC_VER) && !defined(__ICL)
#pragma warning(disable: 4786)  // identifier truncated in debug info
#pragma warning(disable: 4710)  // function not inlined
#pragma warning(disable: 4711)  // function selected for automatic inline expansion
#pragma warning(disable: 4514)  // unreferenced inline removed
#endif

//
//  bind_stdcall_test.cpp - test for bind.hpp + __stdcall (free functions)
//
//  Copyright (c) 2001 Peter Dimov and Multi Media Ltd.
//
//  Permission to copy, use, modify, sell and distribute this software
//  is granted provided this copyright notice appears in all copies.
//  This software is provided "as is" without express or implied
//  warranty, and with no claim as to its suitability for any purpose.
//

#define BOOST_BIND_ENABLE_STDCALL

#include <boost/bind.hpp>

#if defined(BOOST_MSVC) && (BOOST_MSVC < 1300)
#pragma warning(push, 3)
#endif

#include <iostream>

#if defined(BOOST_MSVC) && (BOOST_MSVC < 1300)
#pragma warning(pop)
#endif

#define BOOST_INCLUDE_MAIN
#include <boost/test/test_tools.hpp>

//

long __stdcall f_0()
{
    return 17041L;
}

long __stdcall f_1(long a)
{
    return a;
}

long __stdcall f_2(long a, long b)
{
    return a + 10 * b;
}

long __stdcall f_3(long a, long b, long c)
{
    return a + 10 * b + 100 * c;
}

long __stdcall f_4(long a, long b, long c, long d)
{
    return a + 10 * b + 100 * c + 1000 * d;
}

long __stdcall f_5(long a, long b, long c, long d, long e)
{
    return a + 10 * b + 100 * c + 1000 * d + 10000 * e;
}

long __stdcall f_6(long a, long b, long c, long d, long e, long f)
{
    return a + 10 * b + 100 * c + 1000 * d + 10000 * e + 100000 * f;
}

long __stdcall f_7(long a, long b, long c, long d, long e, long f, long g)
{
    return a + 10 * b + 100 * c + 1000 * d + 10000 * e + 100000 * f + 1000000 * g;
}

long __stdcall f_8(long a, long b, long c, long d, long e, long f, long g, long h)
{
    return a + 10 * b + 100 * c + 1000 * d + 10000 * e + 100000 * f + 1000000 * g + 10000000 * h;
}

long __stdcall f_9(long a, long b, long c, long d, long e, long f, long g, long h, long i)
{
    return a + 10 * b + 100 * c + 1000 * d + 10000 * e + 100000 * f + 1000000 * g + 10000000 * h + 100000000 * i;
}

void function_test()
{
    using namespace boost;

    int const i = 1;

    BOOST_TEST( bind(f_0)(i) == 17041L );
    BOOST_TEST( bind(f_1, _1)(i) == 1L );
    BOOST_TEST( bind(f_2, _1, 2)(i) == 21L );
    BOOST_TEST( bind(f_3, _1, 2, 3)(i) == 321L );
    BOOST_TEST( bind(f_4, _1, 2, 3, 4)(i) == 4321L );
    BOOST_TEST( bind(f_5, _1, 2, 3, 4, 5)(i) == 54321L );
    BOOST_TEST( bind(f_6, _1, 2, 3, 4, 5, 6)(i) == 654321L );
    BOOST_TEST( bind(f_7, _1, 2, 3, 4, 5, 6, 7)(i) == 7654321L );
    BOOST_TEST( bind(f_8, _1, 2, 3, 4, 5, 6, 7, 8)(i) == 87654321L );
    BOOST_TEST( bind(f_9, _1, 2, 3, 4, 5, 6, 7, 8, 9)(i) == 987654321L );
}

int test_main(int, char * [])
{
    function_test();
    return 0;
}