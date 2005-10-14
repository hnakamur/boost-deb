#ifndef BOOST_PREPROCESSOR_ARITHMETIC_ADD_HPP
#define BOOST_PREPROCESSOR_ARITHMETIC_ADD_HPP

//  Copyright (C) 2001
//  Housemarque, Inc.
//  http://www.housemarque.com
//  
//  Permission to copy, use, modify, sell and distribute this software is
//  granted provided this copyright notice appears in all copies. This
//  software is provided "as is" without express or implied warranty, and
//  with no claim as to its suitability for any purpose.

//  See http://www.boost.org for most recent version.

/*! \file

<a href="../../../../boost/preprocessor/arithmetic/add.hpp">Click here to see the header.</a>
*/

#ifndef BOOST_PREPROCESSOR_INC_HPP
#  include <boost/preprocessor/inc.hpp>
#endif

//! Expands to the sum of X and Y.
#define BOOST_PREPROCESSOR_ADD(X,Y) BOOST_PREPROCESSOR_ADD_DELAY(X,Y)

#ifndef DOXYGEN_SHOULD_SKIP_THIS
#define BOOST_PREPROCESSOR_ADD_DELAY(X,Y) BOOST_PREPROCESSOR_ADD##X(Y)
#define BOOST_PREPROCESSOR_ADD0(Y) Y
#define BOOST_PREPROCESSOR_ADD1(Y) BOOST_PREPROCESSOR_INC(Y)
#define BOOST_PREPROCESSOR_ADD2(Y) BOOST_PREPROCESSOR_INC(BOOST_PREPROCESSOR_INC(Y))
#define BOOST_PREPROCESSOR_ADD3(Y) BOOST_PREPROCESSOR_ADD2(BOOST_PREPROCESSOR_INC(Y))
#define BOOST_PREPROCESSOR_ADD4(Y) BOOST_PREPROCESSOR_ADD3(BOOST_PREPROCESSOR_INC(Y))
#define BOOST_PREPROCESSOR_ADD5(Y) BOOST_PREPROCESSOR_ADD4(BOOST_PREPROCESSOR_INC(Y))
#define BOOST_PREPROCESSOR_ADD6(Y) BOOST_PREPROCESSOR_ADD5(BOOST_PREPROCESSOR_INC(Y))
#define BOOST_PREPROCESSOR_ADD7(Y) BOOST_PREPROCESSOR_ADD6(BOOST_PREPROCESSOR_INC(Y))
#define BOOST_PREPROCESSOR_ADD8(Y) BOOST_PREPROCESSOR_ADD7(BOOST_PREPROCESSOR_INC(Y))
#define BOOST_PREPROCESSOR_ADD9(Y) BOOST_PREPROCESSOR_ADD8(BOOST_PREPROCESSOR_INC(Y))
#define BOOST_PREPROCESSOR_ADD10(Y) BOOST_PREPROCESSOR_ADD9(BOOST_PREPROCESSOR_INC(Y))
#define BOOST_PREPROCESSOR_ADD11(Y) BOOST_PREPROCESSOR_ADD10(BOOST_PREPROCESSOR_INC(Y))
#define BOOST_PREPROCESSOR_ADD12(Y) BOOST_PREPROCESSOR_ADD11(BOOST_PREPROCESSOR_INC(Y))
#define BOOST_PREPROCESSOR_ADD13(Y) BOOST_PREPROCESSOR_ADD12(BOOST_PREPROCESSOR_INC(Y))
#define BOOST_PREPROCESSOR_ADD14(Y) BOOST_PREPROCESSOR_ADD13(BOOST_PREPROCESSOR_INC(Y))
#define BOOST_PREPROCESSOR_ADD15(Y) BOOST_PREPROCESSOR_ADD14(BOOST_PREPROCESSOR_INC(Y))
#define BOOST_PREPROCESSOR_ADD16(Y) BOOST_PREPROCESSOR_ADD15(BOOST_PREPROCESSOR_INC(Y))
#define BOOST_PREPROCESSOR_ADD17(Y) BOOST_PREPROCESSOR_ADD16(BOOST_PREPROCESSOR_INC(Y))
#define BOOST_PREPROCESSOR_ADD18(Y) BOOST_PREPROCESSOR_ADD17(BOOST_PREPROCESSOR_INC(Y))
#define BOOST_PREPROCESSOR_ADD19(Y) BOOST_PREPROCESSOR_ADD18(BOOST_PREPROCESSOR_INC(Y))
#define BOOST_PREPROCESSOR_ADD20(Y) BOOST_PREPROCESSOR_ADD19(BOOST_PREPROCESSOR_INC(Y))
#define BOOST_PREPROCESSOR_ADD21(Y) BOOST_PREPROCESSOR_ADD20(BOOST_PREPROCESSOR_INC(Y))
#define BOOST_PREPROCESSOR_ADD22(Y) BOOST_PREPROCESSOR_ADD21(BOOST_PREPROCESSOR_INC(Y))
#define BOOST_PREPROCESSOR_ADD23(Y) BOOST_PREPROCESSOR_ADD22(BOOST_PREPROCESSOR_INC(Y))
#define BOOST_PREPROCESSOR_ADD24(Y) BOOST_PREPROCESSOR_ADD23(BOOST_PREPROCESSOR_INC(Y))
#define BOOST_PREPROCESSOR_ADD25(Y) BOOST_PREPROCESSOR_ADD24(BOOST_PREPROCESSOR_INC(Y))
#define BOOST_PREPROCESSOR_ADD26(Y) BOOST_PREPROCESSOR_ADD25(BOOST_PREPROCESSOR_INC(Y))
#define BOOST_PREPROCESSOR_ADD27(Y) BOOST_PREPROCESSOR_ADD26(BOOST_PREPROCESSOR_INC(Y))
#define BOOST_PREPROCESSOR_ADD28(Y) BOOST_PREPROCESSOR_ADD27(BOOST_PREPROCESSOR_INC(Y))
#define BOOST_PREPROCESSOR_ADD29(Y) BOOST_PREPROCESSOR_ADD28(BOOST_PREPROCESSOR_INC(Y))
#define BOOST_PREPROCESSOR_ADD30(Y) BOOST_PREPROCESSOR_ADD29(BOOST_PREPROCESSOR_INC(Y))
#define BOOST_PREPROCESSOR_ADD31(Y) BOOST_PREPROCESSOR_ADD30(BOOST_PREPROCESSOR_INC(Y))
#define BOOST_PREPROCESSOR_ADD32(Y) BOOST_PREPROCESSOR_ADD31(BOOST_PREPROCESSOR_INC(Y))
#define BOOST_PREPROCESSOR_ADD33(Y) BOOST_PREPROCESSOR_ADD32(BOOST_PREPROCESSOR_INC(Y))
#define BOOST_PREPROCESSOR_ADD34(Y) BOOST_PREPROCESSOR_ADD33(BOOST_PREPROCESSOR_INC(Y))
#define BOOST_PREPROCESSOR_ADD35(Y) BOOST_PREPROCESSOR_ADD34(BOOST_PREPROCESSOR_INC(Y))
#define BOOST_PREPROCESSOR_ADD36(Y) BOOST_PREPROCESSOR_ADD35(BOOST_PREPROCESSOR_INC(Y))
#define BOOST_PREPROCESSOR_ADD37(Y) BOOST_PREPROCESSOR_ADD36(BOOST_PREPROCESSOR_INC(Y))
#define BOOST_PREPROCESSOR_ADD38(Y) BOOST_PREPROCESSOR_ADD37(BOOST_PREPROCESSOR_INC(Y))
#define BOOST_PREPROCESSOR_ADD39(Y) BOOST_PREPROCESSOR_ADD38(BOOST_PREPROCESSOR_INC(Y))
#define BOOST_PREPROCESSOR_ADD40(Y) BOOST_PREPROCESSOR_ADD39(BOOST_PREPROCESSOR_INC(Y))
#define BOOST_PREPROCESSOR_ADD41(Y) BOOST_PREPROCESSOR_ADD40(BOOST_PREPROCESSOR_INC(Y))
#define BOOST_PREPROCESSOR_ADD42(Y) BOOST_PREPROCESSOR_ADD41(BOOST_PREPROCESSOR_INC(Y))
#define BOOST_PREPROCESSOR_ADD43(Y) BOOST_PREPROCESSOR_ADD42(BOOST_PREPROCESSOR_INC(Y))
#define BOOST_PREPROCESSOR_ADD44(Y) BOOST_PREPROCESSOR_ADD43(BOOST_PREPROCESSOR_INC(Y))
#define BOOST_PREPROCESSOR_ADD45(Y) BOOST_PREPROCESSOR_ADD44(BOOST_PREPROCESSOR_INC(Y))
#define BOOST_PREPROCESSOR_ADD46(Y) BOOST_PREPROCESSOR_ADD45(BOOST_PREPROCESSOR_INC(Y))
#define BOOST_PREPROCESSOR_ADD47(Y) BOOST_PREPROCESSOR_ADD46(BOOST_PREPROCESSOR_INC(Y))
#define BOOST_PREPROCESSOR_ADD48(Y) BOOST_PREPROCESSOR_ADD47(BOOST_PREPROCESSOR_INC(Y))
#define BOOST_PREPROCESSOR_ADD49(Y) BOOST_PREPROCESSOR_ADD48(BOOST_PREPROCESSOR_INC(Y))
#define BOOST_PREPROCESSOR_ADD50(Y) BOOST_PREPROCESSOR_ADD49(BOOST_PREPROCESSOR_INC(Y))
#define BOOST_PREPROCESSOR_ADD51(Y) BOOST_PREPROCESSOR_ADD50(BOOST_PREPROCESSOR_INC(Y))
#define BOOST_PREPROCESSOR_ADD52(Y) BOOST_PREPROCESSOR_ADD51(BOOST_PREPROCESSOR_INC(Y))
#define BOOST_PREPROCESSOR_ADD53(Y) BOOST_PREPROCESSOR_ADD52(BOOST_PREPROCESSOR_INC(Y))
#define BOOST_PREPROCESSOR_ADD54(Y) BOOST_PREPROCESSOR_ADD53(BOOST_PREPROCESSOR_INC(Y))
#define BOOST_PREPROCESSOR_ADD55(Y) BOOST_PREPROCESSOR_ADD54(BOOST_PREPROCESSOR_INC(Y))
#define BOOST_PREPROCESSOR_ADD56(Y) BOOST_PREPROCESSOR_ADD55(BOOST_PREPROCESSOR_INC(Y))
#define BOOST_PREPROCESSOR_ADD57(Y) BOOST_PREPROCESSOR_ADD56(BOOST_PREPROCESSOR_INC(Y))
#define BOOST_PREPROCESSOR_ADD58(Y) BOOST_PREPROCESSOR_ADD57(BOOST_PREPROCESSOR_INC(Y))
#define BOOST_PREPROCESSOR_ADD59(Y) BOOST_PREPROCESSOR_ADD58(BOOST_PREPROCESSOR_INC(Y))
#define BOOST_PREPROCESSOR_ADD60(Y) BOOST_PREPROCESSOR_ADD59(BOOST_PREPROCESSOR_INC(Y))
#define BOOST_PREPROCESSOR_ADD61(Y) BOOST_PREPROCESSOR_ADD60(BOOST_PREPROCESSOR_INC(Y))
#define BOOST_PREPROCESSOR_ADD62(Y) BOOST_PREPROCESSOR_ADD61(BOOST_PREPROCESSOR_INC(Y))
#define BOOST_PREPROCESSOR_ADD63(Y) BOOST_PREPROCESSOR_ADD62(BOOST_PREPROCESSOR_INC(Y))
#define BOOST_PREPROCESSOR_ADD64(Y) BOOST_PREPROCESSOR_ADD63(BOOST_PREPROCESSOR_INC(Y))
#define BOOST_PREPROCESSOR_ADD65(Y) BOOST_PREPROCESSOR_ADD64(BOOST_PREPROCESSOR_INC(Y))
#define BOOST_PREPROCESSOR_ADD66(Y) BOOST_PREPROCESSOR_ADD65(BOOST_PREPROCESSOR_INC(Y))
#define BOOST_PREPROCESSOR_ADD67(Y) BOOST_PREPROCESSOR_ADD66(BOOST_PREPROCESSOR_INC(Y))
#define BOOST_PREPROCESSOR_ADD68(Y) BOOST_PREPROCESSOR_ADD67(BOOST_PREPROCESSOR_INC(Y))
#define BOOST_PREPROCESSOR_ADD69(Y) BOOST_PREPROCESSOR_ADD68(BOOST_PREPROCESSOR_INC(Y))
#define BOOST_PREPROCESSOR_ADD70(Y) BOOST_PREPROCESSOR_ADD69(BOOST_PREPROCESSOR_INC(Y))
#define BOOST_PREPROCESSOR_ADD71(Y) BOOST_PREPROCESSOR_ADD70(BOOST_PREPROCESSOR_INC(Y))
#define BOOST_PREPROCESSOR_ADD72(Y) BOOST_PREPROCESSOR_ADD71(BOOST_PREPROCESSOR_INC(Y))
#define BOOST_PREPROCESSOR_ADD73(Y) BOOST_PREPROCESSOR_ADD72(BOOST_PREPROCESSOR_INC(Y))
#define BOOST_PREPROCESSOR_ADD74(Y) BOOST_PREPROCESSOR_ADD73(BOOST_PREPROCESSOR_INC(Y))
#define BOOST_PREPROCESSOR_ADD75(Y) BOOST_PREPROCESSOR_ADD74(BOOST_PREPROCESSOR_INC(Y))
#define BOOST_PREPROCESSOR_ADD76(Y) BOOST_PREPROCESSOR_ADD75(BOOST_PREPROCESSOR_INC(Y))
#define BOOST_PREPROCESSOR_ADD77(Y) BOOST_PREPROCESSOR_ADD76(BOOST_PREPROCESSOR_INC(Y))
#define BOOST_PREPROCESSOR_ADD78(Y) BOOST_PREPROCESSOR_ADD77(BOOST_PREPROCESSOR_INC(Y))
#define BOOST_PREPROCESSOR_ADD79(Y) BOOST_PREPROCESSOR_ADD78(BOOST_PREPROCESSOR_INC(Y))
#define BOOST_PREPROCESSOR_ADD80(Y) BOOST_PREPROCESSOR_ADD79(BOOST_PREPROCESSOR_INC(Y))
#define BOOST_PREPROCESSOR_ADD81(Y) BOOST_PREPROCESSOR_ADD80(BOOST_PREPROCESSOR_INC(Y))
#define BOOST_PREPROCESSOR_ADD82(Y) BOOST_PREPROCESSOR_ADD81(BOOST_PREPROCESSOR_INC(Y))
#define BOOST_PREPROCESSOR_ADD83(Y) BOOST_PREPROCESSOR_ADD82(BOOST_PREPROCESSOR_INC(Y))
#define BOOST_PREPROCESSOR_ADD84(Y) BOOST_PREPROCESSOR_ADD83(BOOST_PREPROCESSOR_INC(Y))
#define BOOST_PREPROCESSOR_ADD85(Y) BOOST_PREPROCESSOR_ADD84(BOOST_PREPROCESSOR_INC(Y))
#define BOOST_PREPROCESSOR_ADD86(Y) BOOST_PREPROCESSOR_ADD85(BOOST_PREPROCESSOR_INC(Y))
#define BOOST_PREPROCESSOR_ADD87(Y) BOOST_PREPROCESSOR_ADD86(BOOST_PREPROCESSOR_INC(Y))
#define BOOST_PREPROCESSOR_ADD88(Y) BOOST_PREPROCESSOR_ADD87(BOOST_PREPROCESSOR_INC(Y))
#define BOOST_PREPROCESSOR_ADD89(Y) BOOST_PREPROCESSOR_ADD88(BOOST_PREPROCESSOR_INC(Y))
#define BOOST_PREPROCESSOR_ADD90(Y) BOOST_PREPROCESSOR_ADD89(BOOST_PREPROCESSOR_INC(Y))
#define BOOST_PREPROCESSOR_ADD91(Y) BOOST_PREPROCESSOR_ADD90(BOOST_PREPROCESSOR_INC(Y))
#define BOOST_PREPROCESSOR_ADD92(Y) BOOST_PREPROCESSOR_ADD91(BOOST_PREPROCESSOR_INC(Y))
#define BOOST_PREPROCESSOR_ADD93(Y) BOOST_PREPROCESSOR_ADD92(BOOST_PREPROCESSOR_INC(Y))
#define BOOST_PREPROCESSOR_ADD94(Y) BOOST_PREPROCESSOR_ADD93(BOOST_PREPROCESSOR_INC(Y))
#define BOOST_PREPROCESSOR_ADD95(Y) BOOST_PREPROCESSOR_ADD94(BOOST_PREPROCESSOR_INC(Y))
#define BOOST_PREPROCESSOR_ADD96(Y) BOOST_PREPROCESSOR_ADD95(BOOST_PREPROCESSOR_INC(Y))
#define BOOST_PREPROCESSOR_ADD97(Y) BOOST_PREPROCESSOR_ADD96(BOOST_PREPROCESSOR_INC(Y))
#define BOOST_PREPROCESSOR_ADD98(Y) BOOST_PREPROCESSOR_ADD97(BOOST_PREPROCESSOR_INC(Y))
#define BOOST_PREPROCESSOR_ADD99(Y) BOOST_PREPROCESSOR_ADD98(BOOST_PREPROCESSOR_INC(Y))
#define BOOST_PREPROCESSOR_ADD100(Y) BOOST_PREPROCESSOR_ADD99(BOOST_PREPROCESSOR_INC(Y))
#define BOOST_PREPROCESSOR_ADD101(Y) BOOST_PREPROCESSOR_ADD100(BOOST_PREPROCESSOR_INC(Y))
#define BOOST_PREPROCESSOR_ADD102(Y) BOOST_PREPROCESSOR_ADD101(BOOST_PREPROCESSOR_INC(Y))
#define BOOST_PREPROCESSOR_ADD103(Y) BOOST_PREPROCESSOR_ADD102(BOOST_PREPROCESSOR_INC(Y))
#define BOOST_PREPROCESSOR_ADD104(Y) BOOST_PREPROCESSOR_ADD103(BOOST_PREPROCESSOR_INC(Y))
#define BOOST_PREPROCESSOR_ADD105(Y) BOOST_PREPROCESSOR_ADD104(BOOST_PREPROCESSOR_INC(Y))
#define BOOST_PREPROCESSOR_ADD106(Y) BOOST_PREPROCESSOR_ADD105(BOOST_PREPROCESSOR_INC(Y))
#define BOOST_PREPROCESSOR_ADD107(Y) BOOST_PREPROCESSOR_ADD106(BOOST_PREPROCESSOR_INC(Y))
#define BOOST_PREPROCESSOR_ADD108(Y) BOOST_PREPROCESSOR_ADD107(BOOST_PREPROCESSOR_INC(Y))
#define BOOST_PREPROCESSOR_ADD109(Y) BOOST_PREPROCESSOR_ADD108(BOOST_PREPROCESSOR_INC(Y))
#define BOOST_PREPROCESSOR_ADD110(Y) BOOST_PREPROCESSOR_ADD109(BOOST_PREPROCESSOR_INC(Y))
#define BOOST_PREPROCESSOR_ADD111(Y) BOOST_PREPROCESSOR_ADD110(BOOST_PREPROCESSOR_INC(Y))
#define BOOST_PREPROCESSOR_ADD112(Y) BOOST_PREPROCESSOR_ADD111(BOOST_PREPROCESSOR_INC(Y))
#define BOOST_PREPROCESSOR_ADD113(Y) BOOST_PREPROCESSOR_ADD112(BOOST_PREPROCESSOR_INC(Y))
#define BOOST_PREPROCESSOR_ADD114(Y) BOOST_PREPROCESSOR_ADD113(BOOST_PREPROCESSOR_INC(Y))
#define BOOST_PREPROCESSOR_ADD115(Y) BOOST_PREPROCESSOR_ADD114(BOOST_PREPROCESSOR_INC(Y))
#define BOOST_PREPROCESSOR_ADD116(Y) BOOST_PREPROCESSOR_ADD115(BOOST_PREPROCESSOR_INC(Y))
#define BOOST_PREPROCESSOR_ADD117(Y) BOOST_PREPROCESSOR_ADD116(BOOST_PREPROCESSOR_INC(Y))
#define BOOST_PREPROCESSOR_ADD118(Y) BOOST_PREPROCESSOR_ADD117(BOOST_PREPROCESSOR_INC(Y))
#define BOOST_PREPROCESSOR_ADD119(Y) BOOST_PREPROCESSOR_ADD118(BOOST_PREPROCESSOR_INC(Y))
#define BOOST_PREPROCESSOR_ADD120(Y) BOOST_PREPROCESSOR_ADD119(BOOST_PREPROCESSOR_INC(Y))
#define BOOST_PREPROCESSOR_ADD121(Y) BOOST_PREPROCESSOR_ADD120(BOOST_PREPROCESSOR_INC(Y))
#define BOOST_PREPROCESSOR_ADD122(Y) BOOST_PREPROCESSOR_ADD121(BOOST_PREPROCESSOR_INC(Y))
#define BOOST_PREPROCESSOR_ADD123(Y) BOOST_PREPROCESSOR_ADD122(BOOST_PREPROCESSOR_INC(Y))
#define BOOST_PREPROCESSOR_ADD124(Y) BOOST_PREPROCESSOR_ADD123(BOOST_PREPROCESSOR_INC(Y))
#define BOOST_PREPROCESSOR_ADD125(Y) BOOST_PREPROCESSOR_ADD124(BOOST_PREPROCESSOR_INC(Y))
#define BOOST_PREPROCESSOR_ADD126(Y) BOOST_PREPROCESSOR_ADD125(BOOST_PREPROCESSOR_INC(Y))
#define BOOST_PREPROCESSOR_ADD127(Y) BOOST_PREPROCESSOR_ADD126(BOOST_PREPROCESSOR_INC(Y))
#define BOOST_PREPROCESSOR_ADD128(Y) BOOST_PREPROCESSOR_ADD127(BOOST_PREPROCESSOR_INC(Y))
#endif /* DOXYGEN_SHOULD_SKIP_THIS */
#endif
