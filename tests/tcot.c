/* Test file for mpfr_cot.

Copyright 2005, 2006 Free Software Foundation, Inc.

This file is part of the MPFR Library.

The MPFR Library is free software; you can redistribute it and/or modify
it under the terms of the GNU Lesser General Public License as published by
the Free Software Foundation; either version 2.1 of the License, or (at your
option) any later version.

The MPFR Library is distributed in the hope that it will be useful, but
WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Lesser General Public
License for more details.

You should have received a copy of the GNU Lesser General Public License
along with the MPFR Library; see the file COPYING.LIB.  If not, write to
the Free Software Foundation, Inc., 51 Franklin St, Fifth Floor, Boston,
MA 02110-1301, USA. */

#include <stdio.h>
#include <stdlib.h>

#include "mpfr-test.h"

#define TEST_FUNCTION mpfr_cot
#include "tgeneric.c"

static void
check_specials (void)
{
  mpfr_t  x, y;

  mpfr_init2 (x, 123L);
  mpfr_init2 (y, 123L);

  mpfr_set_nan (x);
  mpfr_cot (y, x, GMP_RNDN);
  if (! mpfr_nan_p (y))
    {
      printf ("Error: cot(NaN) != NaN\n");
      exit (1);
    }

  mpfr_set_inf (x, 1);
  mpfr_cot (y, x, GMP_RNDN);
  if (! mpfr_nan_p (y))
    {
      printf ("Error: cot(Inf) != NaN\n");
      exit (1);
    }

  mpfr_set_inf (x, -1);
  mpfr_cot (y, x, GMP_RNDN);
  if (! mpfr_nan_p (y))
    {
      printf ("Error: cot(-Inf) != NaN\n");
      exit (1);
    }

  /* cot(+/-0) = +/-Inf */
  mpfr_set_ui (x, 0, GMP_RNDN);
  mpfr_cot (y, x, GMP_RNDN);
  if (! (mpfr_inf_p (y) && mpfr_sgn (y) > 0))
    {
      printf ("Error: cot(+0) != +Inf\n");
      exit (1);
    }
  mpfr_neg (x, x, GMP_RNDN);
  mpfr_cot (y, x, GMP_RNDN);
  if (! (mpfr_inf_p (y) && mpfr_sgn (y) < 0))
    {
      printf ("Error: cot(-0) != -Inf\n");
      exit (1);
    }

  mpfr_clear (x);
  mpfr_clear (y);
}

int
main (int argc, char *argv[])
{
  tests_start_mpfr ();

  check_specials ();
  test_generic (2, 200, 5);

  tests_end_mpfr ();
  return 0;
}
