/* Test file for mpfr_fma.

Copyright (C) 2001 Free Software Foundation.
Adapted from tarctan.c.

This file is part of the MPFR Library.

The MPFR Library is free software; you can redistribute it and/or modify
it under the terms of the GNU Library General Public License as published by
the Free Software Foundation; either version 2 of the License, or (at your
option) any later version.

The MPFR Library is distributed in the hope that it will be useful, but
WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Library General Public
License for more details.

You should have received a copy of the GNU Library General Public License
along with the MPFR Library; see the file COPYING.LIB.  If not, write to
the Free Software Foundation, Inc., 59 Temple Place - Suite 330, Boston,
MA 02111-1307, USA. */

#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <gmp.h>
#include "gmp-impl.h"
#include <mpfr.h>
#include "mpfr-impl.h"


int
main (int argc, char *argv[])
{
  mpfr_t x, y,z,s;
  mpfr_init (x);
  mpfr_init (s);
  mpfr_init (y);
  mpfr_init (z);


  MPFR_SET_NAN(x);
  mpfr_random(y);
  mpfr_random(z);
  mpfr_fma (s,x, y,z, GMP_RNDN);
  if(!MPFR_IS_NAN(s))
    {
      printf ("evaluation of function in x=NAN does not return NAN");
      exit (1);
    }

  MPFR_CLEAR_FLAGS(x);
  MPFR_CLEAR_FLAGS(y);
  MPFR_CLEAR_FLAGS(z);

  MPFR_SET_NAN(y);
  mpfr_random(x);
  mpfr_random(z);
  mpfr_fma (s,x, y,z, GMP_RNDN);
  if(!MPFR_IS_NAN(s))
    {
      printf ("evaluation of function in y=NAN does not return NAN");
      exit (1);
    }

  MPFR_CLEAR_FLAGS(x);
  MPFR_CLEAR_FLAGS(y);
  MPFR_CLEAR_FLAGS(z);

  MPFR_SET_NAN(z);
  mpfr_random(y);
  mpfr_random(x);
  mpfr_fma (s,x, y,z, GMP_RNDN);
  if(!MPFR_IS_NAN(s))
    {
      printf ("evaluation of function in z=NAN does not return NAN");
      exit (1);
    }

  MPFR_CLEAR_FLAGS(x);
  MPFR_CLEAR_FLAGS(y);
  MPFR_CLEAR_FLAGS(z);

  MPFR_SET_INF(x);
  MPFR_SET_ZERO(y);
  mpfr_random(z);
  mpfr_fma (s,x, y,z, GMP_RNDN);
  if(!MPFR_IS_NAN(s))
    {
      printf ("evaluation of function in x=INF y=0  does not return NAN");
      exit (1);
    }

  MPFR_CLEAR_FLAGS(z); 
  MPFR_CLEAR_FLAGS(y); 
  MPFR_CLEAR_FLAGS(x); 

  MPFR_SET_INF(y);
  MPFR_SET_ZERO(x);
  mpfr_random(z);
  mpfr_fma (s,x, y,z, GMP_RNDN);
  if(!MPFR_IS_NAN(s))
    {
      printf ("evaluation of function in x=0 y=INF does not return NAN");
      exit (1);
    }

  MPFR_CLEAR_FLAGS(z); 
  MPFR_CLEAR_FLAGS(y); 
  MPFR_CLEAR_FLAGS(x); 

  MPFR_SET_INF(x);
  mpfr_random(y);
  MPFR_SET_INF(z);
  if((MPFR_SIGN(x) * MPFR_SIGN(y)) == MPFR_SIGN(z))
    MPFR_CHANGE_SIGN(z);
  mpfr_fma (s,x, y,z, GMP_RNDN);
  if(!MPFR_IS_NAN(s))
    {
      printf ("evaluation of function in x=INF z=(-sign(x)*sign(y))INF does not return NAN");
      exit (1);
    }

  MPFR_CLEAR_FLAGS(z); 
  MPFR_CLEAR_FLAGS(y); 
  MPFR_CLEAR_FLAGS(x); 

  MPFR_SET_INF(y);
  mpfr_random(x);
  MPFR_SET_INF(z);
  if((MPFR_SIGN(x) * MPFR_SIGN(y)) == MPFR_SIGN(z))
    MPFR_CHANGE_SIGN(z);
  
  mpfr_fma (s,x, y,z, GMP_RNDN);
  if(!MPFR_IS_NAN(s))
    {
      printf ("evaluation of function in y=INF z=(-sign(x)*sign(y))INF does not return NAN");
      exit (1);
    }

  MPFR_CLEAR_FLAGS(z); 
  MPFR_CLEAR_FLAGS(y); 
  MPFR_CLEAR_FLAGS(x); 

  MPFR_SET_INF(x);
  mpfr_random(y);
  mpfr_random(z);
  mpfr_fma (s,x, y,z, GMP_RNDN);
  if(!MPFR_IS_INF(s))
    {
      printf ("evaluation of function in x=INF does not return INF");
      exit (1);
    }

  MPFR_CLEAR_FLAGS(z); 
  MPFR_CLEAR_FLAGS(y); 
  MPFR_CLEAR_FLAGS(x); 

  MPFR_SET_INF(y);
  mpfr_random(x);
  mpfr_random(z);
  mpfr_fma (s,x, y,z, GMP_RNDN);
  if(!MPFR_IS_INF(s))
    {
      printf ("evaluation of function in y=INF does not return INF");
      exit (1);
    }

  MPFR_CLEAR_FLAGS(z); 
  MPFR_CLEAR_FLAGS(y); 
  MPFR_CLEAR_FLAGS(x); 

  MPFR_SET_INF(z);
  mpfr_random(x);
  mpfr_random(y);
  mpfr_fma (s,x, y,z, GMP_RNDN);
  if(!MPFR_IS_INF(s))
    {
      printf ("evaluation of function in z=INF does not return INF");
      exit (1);
    }

  MPFR_CLEAR_FLAGS(z); 
  MPFR_CLEAR_FLAGS(y); 
  MPFR_CLEAR_FLAGS(x); 

  MPFR_SET_ZERO(x);
  mpfr_random(y);
  mpfr_random(z);
  mpfr_fma (s,x, y,z, GMP_RNDN);
  if(mpfr_cmp(s,z)!=0)
    {
      printf ("evaluation of function in x=0 does not return z\n");
      exit (1);
    }

  MPFR_CLEAR_FLAGS(z); 
  MPFR_CLEAR_FLAGS(y); 
  MPFR_CLEAR_FLAGS(x); 

  MPFR_SET_ZERO(y);
  mpfr_random(x);
  mpfr_random(z);
  mpfr_fma (s,x, y,z, GMP_RNDN);
  if(mpfr_cmp(s,z)!=0)
    {
      printf ("evaluation of function in y=0 does not return z\n");
      exit (1);
    }

  MPFR_CLEAR_FLAGS(z); 
  MPFR_CLEAR_FLAGS(y); 
  MPFR_CLEAR_FLAGS(x); 

  {
    mp_prec_t prec;
    mpfr_t x, y, z, t,s, slong;
    mp_rnd_t rnd;
    int inexact, compare;
    unsigned int n;

    int p0=1;
    int p1=200;
    int N=200;
    
    mpfr_init (x);
    mpfr_init (y);
    mpfr_init (z);
    mpfr_init (t);
    mpfr_init (s);
    mpfr_init (slong);


    /* generic test */
    for (prec = p0; prec <= p1; prec++)
    {
      mpfr_set_prec (x, prec);
      mpfr_set_prec (y, prec);
      mpfr_set_prec (z, prec);
      mpfr_set_prec (s, prec);
      mpfr_set_prec (t, prec);

      for (n=0; n<N; n++)
	{
          mpfr_random (x);
	  mpfr_random (y);
	  mpfr_random (z);

          if (random() % 2)
            mpfr_neg (x, x, GMP_RNDN);
          if (random() % 2)
            mpfr_neg (y, y, GMP_RNDN);
          if (random() % 2)
            mpfr_neg (z, z, GMP_RNDN);

	  rnd = random () % 4;
	  mpfr_set_prec (slong, 2 * prec);
	  if (mpfr_mul (slong, x, y, rnd))
	    {
	      fprintf (stderr, "x*y should be exact\n");
	      exit (1);
	    }
	  compare = mpfr_add (t, slong, z, rnd);
	  inexact = mpfr_fma (s, x, y, z, rnd);
	  if (mpfr_cmp (s, t))
	    {
	      printf ("results differ for x=");
	      mpfr_out_str (stdout, 2, prec, x, GMP_RNDN);
	      printf ("  y=");
	      mpfr_out_str (stdout, 2, prec, y, GMP_RNDN);
	      printf ("  z=");
	      mpfr_out_str (stdout, 2, prec, z, GMP_RNDN);
	      printf (" prec=%u rnd_mode=%s\n", (unsigned) prec,
		      mpfr_print_rnd_mode (rnd));
	      printf ("got      ");
	      mpfr_out_str (stdout, 2, prec, s, GMP_RNDN);
	      putchar ('\n');
	      printf ("expected ");
	      mpfr_out_str (stdout, 2, prec, t, GMP_RNDN);
	      putchar ('\n');
	      printf ("approx  ");
	      mpfr_print_raw (slong);
	      putchar ('\n');
	      exit (1);
	    }
	  if (((inexact == 0) && (compare != 0)) ||
	      ((inexact < 0) && (compare >= 0)) ||
	      ((inexact > 0) && (compare <= 0)))
	    {
	      fprintf (stderr, "Wrong inexact flag for rnd=%s: expected %d, got %d\n",
		       mpfr_print_rnd_mode (rnd), compare, inexact);
	      exit (1);
	    }
	}
    }
  mpfr_clear (t);
  mpfr_clear (s);
  mpfr_clear (slong);


  }
  mpfr_clear (x);
  mpfr_clear (y);
  mpfr_clear (x);

  return 0;
}
