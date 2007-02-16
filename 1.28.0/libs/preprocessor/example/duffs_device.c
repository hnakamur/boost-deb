/* Copyright (C) 2002
 * Housemarque Oy
 * http://www.housemarque.com
 *
 * Permission to copy, use, modify, sell and distribute this software is
 * granted provided this copyright notice appears in all copies. This
 * software is provided "as is" without express or implied warranty, and
 * with no claim as to its suitability for any purpose.
 *
 * See http://www.boost.org for most recent version.
 */

/* This example uses the preprocessor library to implement a generalized
 * macro for implementing a Duff's Device.
 *
 * This example was inspired by an original generalized macro for
 * implementing Duff's Device written by Joerg Walter.
 */

#include <boost/preprocessor/repeat.hpp>
#include <boost/preprocessor/tuple/elem.hpp>
#include <assert.h>

/* Expands to a Duff's Device. */
#define DUFFS_DEVICE(UNROLLING_FACTOR,COUNTER_TYPE,N,STATEMENT)\
  do\
  {\
    COUNTER_TYPE duffs_device_initial_cnt = (N);\
    if (duffs_device_initial_cnt > 0)\
    {\
      COUNTER_TYPE duffs_device_running_cnt = (duffs_device_initial_cnt + (UNROLLING_FACTOR-1))/UNROLLING_FACTOR;\
      switch (duffs_device_initial_cnt % UNROLLING_FACTOR)\
      {\
        do\
        {\
          BOOST_PP_REPEAT(UNROLLING_FACTOR,DUFFS_DEVICE_C,(UNROLLING_FACTOR,{STATEMENT}))\
        } while (--duffs_device_running_cnt);\
      }\
    }\
  } while (0)

#define DUFFS_DEVICE_C(I,UNROLLING_FACTOR_STATEMENT)\
  case (I?BOOST_PP_TUPLE_ELEM(2,0,UNROLLING_FACTOR_STATEMENT)-I:0): BOOST_PP_TUPLE_ELEM(2,1,UNROLLING_FACTOR_STATEMENT);


#ifndef UNROLLING_FACTOR
#define UNROLLING_FACTOR 16
#endif

#ifndef N
#define N 1000
#endif

int main(void)
{
  int i=0;
  DUFFS_DEVICE(UNROLLING_FACTOR, int, 0, ++i;);
  assert(i == 0);
  DUFFS_DEVICE(UNROLLING_FACTOR, int, N, ++i;);
  assert(i == N);

  return 0;
}