/* Test file for mpfr_tanh.

Copyright 2001, 2002, 2003, 2004 Free Software Foundation.
Adapted from tarctan.c.

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
the Free Software Foundation, Inc., 59 Temple Place - Suite 330, Boston,
MA 02111-1307, USA. */

#include <stdio.h>
#include <stdlib.h>

#include "mpfr-test.h"

#define TEST_FUNCTION mpfr_tanh
#include "tgeneric.c"

static void
special (void)
{
  mpfr_t x;

  mpfr_init (x);

  mpfr_set_nan (x);
  mpfr_tanh (x, x, GMP_RNDN);
  MPFR_ASSERTN(mpfr_nan_p (x));

  mpfr_set_inf (x, 1);
  mpfr_tanh (x, x, GMP_RNDN);
  MPFR_ASSERTN(mpfr_cmp_ui (x, 1) == 0);

  mpfr_set_inf (x, -1);
  mpfr_tanh (x, x, GMP_RNDN);
  MPFR_ASSERTN(mpfr_cmp_si (x, -1) == 0);

  mpfr_set_prec (x, 10);
  mpfr_set_str_binary (x, "-0.1001011001");
  mpfr_tanh (x, x, GMP_RNDN);
  MPFR_ASSERTN(mpfr_cmp_si_2exp (x, -135, -8) == 0);

  mpfr_clear (x);
}

int
main (int argc, char *argv[])
{
  tests_start_mpfr ();

  special ();

  test_generic (2, 100, 100);

  tests_end_mpfr ();
  return 0;
}
