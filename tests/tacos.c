/* Test file for mpfr_acos.

Copyright 2001, 2002, 2003, 2004 Free Software Foundation.
Contributed by Mathieu Dutour.

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

#define TEST_FUNCTION mpfr_acos
#include "tgeneric.c"

static void
special (void)
{
  mpfr_t x, y;
  
  mpfr_init2 (x, 32);
  mpfr_init2 (y, 32);

  mpfr_set_str_binary (x, "0.10001000001001011000100001E-6");
  mpfr_acos (y, x, GMP_RNDN);
  mpfr_set_str_binary (x, "1.10001111111111110001110110001");
  if (mpfr_cmp (x, y))
    {
      printf ("Error in mpfr_acos (1)\n");
      exit (1);
    }

  mpfr_set_str_binary (x, "-0.01101011110111100111010011001011");
  mpfr_acos (y, x, GMP_RNDZ);
  mpfr_set_str_binary (x, "10.0000000101111000011101000101");
  if (mpfr_cmp (x, y))
    {
      printf ("Error in mpfr_acos (2)\n");
      mpfr_print_binary (y); printf ("\n");
      exit (1);
    }

  mpfr_clear (y);
  mpfr_clear (x);
}

int
main (void)
{
  mpfr_t x, y;
  mp_rnd_t r;

  tests_start_mpfr ();

  special ();

  mpfr_init (x);
  mpfr_init (y);

  MPFR_SET_NAN(x);
  mpfr_acos (y, x, GMP_RNDN);
  if (mpfr_nan_p(y) == 0)
    {
      printf ("Error: acos(NaN) != NaN\n");
      exit (1);
    }

  mpfr_set_ui (x, 2, GMP_RNDN);
  mpfr_acos (y, x, GMP_RNDN);
  if (mpfr_nan_p(y) == 0)
    {
      printf ("Error: acos(2) != NaN\n");
      exit (1);
    }

  mpfr_set_si (x, -2, GMP_RNDN);
  mpfr_acos (y, x, GMP_RNDN);
  if (mpfr_nan_p(y) == 0)
    {
      printf ("Error: acos(-2) != NaN\n");
      exit (1);
    }

  /* acos (1) = 0 */
  mpfr_set_ui (x, 1, GMP_RNDN);
  mpfr_acos (y, x, GMP_RNDN);
  if (mpfr_cmp_ui (y, 0) || mpfr_sgn (y) < 0)
    {
      printf ("Error: acos(1) != +0.0\n");
      exit (1);
    }

  /* acos (0) = Pi/2 */
  for (r = 0; r < 4; r++)
    {
      mpfr_set_ui (x, 0, GMP_RNDN); /* exact */
      mpfr_acos (y, x, r);
      mpfr_const_pi (x, r);
      mpfr_div_2exp (x, x, 1, GMP_RNDN); /* exact */
      if (mpfr_cmp (x, y))
        {
          printf ("Error: acos(0) != Pi/2 for rnd=%s\n",
                  mpfr_print_rnd_mode (r));
          exit (1);
        }
    }

  /* acos (-1) = Pi */
  for (r = 0; r < 4; r++)
    {
      mpfr_set_si (x, -1, GMP_RNDN); /* exact */
      mpfr_acos (y, x, r);
      mpfr_const_pi (x, r);
      if (mpfr_cmp (x, y))
        {
          printf ("Error: acos(1) != Pi for rnd=%s\n",
                  mpfr_print_rnd_mode (r));
          exit (1);
        }
    }

  test_generic (2, 100, 7);

  mpfr_clear (x);
  mpfr_clear (y);

  tests_end_mpfr ();
  return 0;
}
