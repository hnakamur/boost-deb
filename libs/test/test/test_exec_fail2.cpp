//  (C) Copyright Gennadiy Rozental 2001-2002.
//  (C) Copyright Beman Dawes 2000.
//  Permission to copy, use, modify, sell and distribute this software
//  is granted provided this copyright notice appears in all copies.
//  This software is provided "as is" without express or implied warranty,
//  and with no claim as to its suitability for any purpose.

//  See http://www.boost.org for most recent version including documentation.
//
//  File        : $RCSfile: test_exec_fail2.cpp,v $
//
//  Version     : $Id: test_exec_fail2.cpp,v 1.4 2002/08/26 09:08:06 rogeeff Exp $
//
//  Description : test failures reported by differen Test Tools.
//  Should fail during run.
// ***************************************************************************

// Boost.Test
#include <boost/test/test_tools.hpp>

int test_main( int, char *[] )  // note the name
{
    int v = 1;

    BOOST_CHECK( v == 2 );
    BOOST_ERROR( "sample BOOST_ERROR call" );
    BOOST_REQUIRE( 2 == v );

    throw "Opps! should never reach this point";

    return 1;
}

//____________________________________________________________________________//

// ***************************************************************************
//  Revision History :
//  
//  $Log: test_exec_fail2.cpp,v $
//  Revision 1.4  2002/08/26 09:08:06  rogeeff
//  cvs kw added
//
//  25 Oct 01  Revisited version (Gennadiy Rozental)
//   7 Nov 00  Initial boost version (Beman Dawes)

// ***************************************************************************

// EOF
