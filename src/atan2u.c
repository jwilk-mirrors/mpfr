/* mpfr_atan2u  -- atan2u(y,x,u) = atan(|y/x|)*u/(2*pi) for x > 0
                   atan2u(y,x,u) = 1-atan(|y/x|)*u/(2*pi) for x < 0
   mpfr_atan2pi -- atan2pi(x) = atan2u(u=2)

Copyright 2021 Free Software Foundation, Inc.
Contributed by the AriC and Caramba projects, INRIA.

This file is part of the GNU MPFR Library.

The GNU MPFR Library is free software; you can redistribute it and/or modify
it under the terms of the GNU Lesser General Public License as published by
the Free Software Foundation; either version 3 of the License, or (at your
option) any later version.

The GNU MPFR Library is distributed in the hope that it will be useful, but
WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Lesser General Public
License for more details.

You should have received a copy of the GNU Lesser General Public License
along with the GNU MPFR Library; see the file COPYING.LESSER.  If not, see
https://www.gnu.org/licenses/ or write to the Free Software Foundation, Inc.,
51 Franklin St, Fifth Floor, Boston, MA 02110-1301, USA. */

#define MPFR_NEED_LONGLONG_H
#include "mpfr-impl.h"

/* z <- s*u*2^e */
static int
mpfr_atan2u_aux1 (mpfr_ptr z, unsigned long u, mpfr_exp_t e, int s,
                  mpfr_rnd_t rnd_mode)
{
  if (s > 0)
    return mpfr_set_ui_2exp (z, u, e, rnd_mode);
  else
    {
      int inex;
      rnd_mode = MPFR_INVERT_RND (rnd_mode);
      inex = mpfr_set_ui_2exp (z, u, e, rnd_mode);
      MPFR_CHANGE_SIGN (z);
      return -inex;
    }
}

/* z <- s*3*u*2^e */
static int
mpfr_atan2u_aux2 (mpfr_ptr z, unsigned long u, mpfr_exp_t e, int s,
                  mpfr_rnd_t rnd_mode)
{
  int inex;
  mpfr_t t;
  mpfr_init2 (t, 66);
  mpfr_set_ui (t, u, MPFR_RNDZ);     /* exact */
  mpfr_mul_ui (t, t, 3, MPFR_RNDZ);  /* exact */
  mpfr_mul_2si (t, t, e, MPFR_RNDZ); /* exact */
  if (s < 0)
    MPFR_CHANGE_SIGN (t);
  inex = mpfr_set (z, t, rnd_mode);
  mpfr_clear (t);
  return inex;
}

/* put in z the correctly rounded value of atan2y(y,x,u) */
int
mpfr_atan2u (mpfr_ptr z, mpfr_srcptr y, mpfr_srcptr x, unsigned long u,
             mpfr_rnd_t rnd_mode)
{
  mpfr_t tmp;
  mpfr_prec_t prec;
  int inex;
  MPFR_SAVE_EXPO_DECL (expo);
  MPFR_ZIV_DECL (loop);

  MPFR_LOG_FUNC
    (("y[%Pu]=%.*Rg x[%Pu]=%.*Rg u=%lu rnd=%d",
      mpfr_get_prec(y), mpfr_log_prec, y,
      mpfr_get_prec(x), mpfr_log_prec, x,
      u, rnd_mode),
     ("z[%Pu]=%.*Rg inexact=%d", mpfr_get_prec (z), mpfr_log_prec, z,
      inex));

  /* Special cases */
  if (MPFR_ARE_SINGULAR (x, y))
    {
      if (MPFR_IS_NAN (x) || MPFR_IS_NAN (y))
        {
          MPFR_SET_NAN (z);
          MPFR_RET_NAN;
        }
      /* remains (y=Inf,x=Inf), (Inf,0), (Inf,regular), (0,Inf), (0,0),
         (0,regular), (regular,Inf), (regular,0) */
      if (MPFR_IS_INF (x))
        {
          /* cases (y=Inf,x=Inf), (0,Inf), (regular,Inf) */
          if (MPFR_IS_INF (y))
            {
              if (MPFR_IS_NEG (x))
                {
                  /* atan2Pi(+/-Inf,-Inf) = +/-3/4,
                     atan2u(+/-Inf,-Inf,u) = +/-3u/8 */
                  return mpfr_atan2u_aux2 (z, u, -3, MPFR_SIGN (y), rnd_mode);
                }
              else /* x > 0 */
                {
                  /* atan2Pi(+/-Inf,-Inf) = +/-1/4,
                     atan2u(+/-Inf,-Inf,u) = +/-u/8 */
                  return mpfr_atan2u_aux1 (z, u, -3, MPFR_SIGN (y), rnd_mode);
                }
            }
          /* remains (y,x) = (0,Inf) and (regular,Inf),
             in which cases the IEEE 754-2019 rules for (y=0,x<>0)
             and for (y<>0,x Inf) coincide */
          if (MPFR_IS_NEG (x))
            /* y>0: atan2Pi(+/-y,-Inf) = +/-1,
               atan2u(+/-y,-Inf,u) = +/-u/2 */
            return mpfr_atan2u_aux1 (z, u, -1, MPFR_SIGN (y), rnd_mode);
          else
            {
              /* y>0: atan2Pi(+/-y,+Inf) = +/-0,
                 atan2u(+/-y,+Inf,u) = +/-0 */
              MPFR_SET_ZERO (z);
              MPFR_SET_SAME_SIGN (z, y);
              MPFR_RET (0);
            }
        }
      /* remains (y=Inf,x=0), (Inf,regular), (0,0), (0,regular), (regular,0) */
      if (MPFR_IS_INF (y))
        /* x is zero or regular */
        /* atan2Pi(+/-Inf, x) = +/-1/2, atan2u(+/-Inf, x, u) = +/-u/4 */
        return mpfr_atan2u_aux1 (z, u, -2, MPFR_SIGN(y), rnd_mode);
      /* remains (y=0,x=0), (0,regular), (regular,0) */
      if (MPFR_IS_ZERO (y))
        {
          if (MPFR_IS_NEG (x))
            {
              /* atan2Pi(+/-0, x) = +/-1, atan2u(+/-0, x, u) = +/-u/2 */
              return mpfr_atan2u_aux1 (z, u, -1, MPFR_SIGN(y), rnd_mode);
            }
          else /* case x = +0 or x > 0 */
            {
              /* atan2Pi(+/-0, x) = +/-0, atan2u(+/-0, x, u) = +/-0 */
              MPFR_SET_ZERO (z); /* does not modify sign, in case z=y */
              MPFR_SET_SAME_SIGN (z, y);
              MPFR_RET (0); /* exact result */
            }
        }
      /* remains (regular,0) */
      if (MPFR_IS_ZERO (x))
        {
          /* y<0: atan2Pi(y,+/-0) = -1/2, thus atan2u(y,+/-0,u) = -u/4 */
          /* y>0: atan2Pi(y,+/-0) = 1/2, thus atan2u(y,+/-0,u) = u/4 */
          return mpfr_atan2u_aux1 (z, u, -2, MPFR_SIGN(y), rnd_mode);
        }
      /* no special case should remain */
      MPFR_RET_NEVER_GO_HERE ();
    }

  /* IEEE 754-2019 say that atan2Pi is odd with respect to y */

  /* now both y and x are regular */
  if (mpfr_cmpabs (y, x) == 0)
    {
      if (MPFR_IS_POS (x))
        /* atan2u (+/-x,x,u) = +/u/8 for x > 0 */
        return mpfr_atan2u_aux1 (z, u, -3, MPFR_SIGN(y), rnd_mode);
      else /* x < 0 */
        /* atan2u (+/-x,x,u) = -/+3u/8 for x > 0 */
        return mpfr_atan2u_aux2 (z, u, -3, MPFR_SIGN(y), rnd_mode);
    }

  if (u == 0) /* return 0 with sign of y for x > 0,
                 and 1 with sign of y for x < 0 */
    {
      if (MPFR_SIGN(x) > 0)
        {
          MPFR_SET_ZERO (z);
          MPFR_SET_SAME_SIGN (z, y);
          MPFR_RET (0);
        }
      else
        return mpfr_set_si (z, MPFR_SIGN(y) > 0 ? 1 : -1, rnd_mode);
    }

  MPFR_SAVE_EXPO_MARK (expo);
  prec = MPFR_PREC (z);
  prec += MPFR_INT_CEIL_LOG2(prec) + 10;
  mpfr_init2 (tmp, prec);
  MPFR_ZIV_INIT (loop, prec);
  for (;;)
    {
      mpfr_exp_t expt, e;
      /* atan2u(-y,x,u) = -atan(y,x,u)
         atan2u(y,x,u) = atan(|y/x|)*u/(2*pi) for x > 0
         atan2u(y,x,u) = u/2-atan(|y/x|)*u/(2*pi) for x < 0
                           atan2pi     atan2u
         First quadrant:   [0,1/2]     [0,u/4]
         Second quadrant:  [1/2,1]     [u/4,u/2]
         Third quadrant:   [-1,-1/2]   [-u/2,-u/4]
         Fourth quadrant:  [-1/2,0]    [-u/4,0] */
      inex = mpfr_div (tmp, y, x, MPFR_RNDN);
      MPFR_SET_SIGN (tmp, 1);
      expt = MPFR_GET_EXP(tmp);
      /* |tmp - y/x| <= e1 := 1/2*ulp(tmp) = 2^(expt-prec-1) */
      inex |= mpfr_atanu (tmp, tmp, u, MPFR_RNDN);
      MPFR_ASSERTN(inex != 0);
      /* the derivative of atan(t) is 1/(1+t^2), thus if tmp2 is the new value
         of tmp, we have |tmp2 - atan(y/x)| <= 1/2*ulp(tmp2) + e1/(1+tmp^2) */
      e = (expt < 1) ? 0 : expt - 1;
      /* max(1,|tmp|) >= 2^e thus 1/(1+tmp^2) <= 2^(-2*e) */
      e = expt - 2 * e;
      /* |tmp2 - atanu(y/x)| <= 1/2*ulp(tmp2) + 2^(e-prec-1) */
      e = (e < MPFR_GET_EXP(tmp)) ? MPFR_GET_EXP(tmp) : e;
      /* |tmp2 - atanu(y/x)| <= 2^(e-prec) */
      if (MPFR_SIGN (x) < 0)
        { /* compute u/2-tmp */
          mpfr_mul_2ui (tmp, tmp, 1, MPFR_RNDN); /* error <= 2^(e+1-prec) */
          mpfr_ui_sub (tmp, u, tmp, MPFR_RNDN);
          expt = MPFR_GET_EXP(tmp);
          /* error <= 2^(expt-prec-1) + 2^(e+1-prec) */
          e = (expt - 1 > e + 1) ? expt - 1 : e + 1;
          /* error <= 2^(e+1-prec) */
          mpfr_div_2ui (tmp, tmp, 1, MPFR_RNDN);
          /* error <= 2^(e-prec) */
        }
      /* both with x>0 and x<0 we have error <= 2^(e-prec),
         now we want error <= 2^(expt-prec+err)
         thus err = e-expt */
      e -= MPFR_GET_EXP(tmp);
      if (MPFR_SIGN(y) < 0) /* atan2u is odd with respect to y */
        MPFR_CHANGE_SIGN(tmp);
      if (MPFR_LIKELY (MPFR_CAN_ROUND (tmp, prec - e,
                                       MPFR_PREC (z), rnd_mode)))
        break;
      MPFR_ZIV_NEXT (loop, prec);
      mpfr_set_prec (tmp, prec);
    }
  MPFR_ZIV_FREE (loop);
  inex = mpfr_set (z, tmp, rnd_mode);
  mpfr_clear (tmp);
  MPFR_SAVE_EXPO_FREE (expo);

  return mpfr_check_range (z, inex, rnd_mode);
}

int
mpfr_atan2pi (mpfr_ptr z, mpfr_srcptr y, mpfr_srcptr x, mpfr_rnd_t rnd_mode)
{
  return mpfr_atan2u (z, y, x, 2, rnd_mode);
}
