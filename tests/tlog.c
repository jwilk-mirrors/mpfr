#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "gmp.h"
#include "mpfr.h"

double drand()
{
  double d; long int *i;

  i = (long int*) &d;
  do {
    i[0] = lrand48();
    i[1] = lrand48();
   } while ((d<1e-153)||(d>1e153));    /* to avoid underflow or overflow
					 in double calculus in sqrt(u*v) */
  return d;
}



/* returns the number of ulp's between a and b */
int ulp(a,b) double a,b;
{
  double eps=1.1102230246251565404e-16; /* 2^(-53) */
  b = (a-b)/a;
  if (b>0)
    return (int) floor(b/eps);
  else
    return (int) ceil(b/eps);
}

#define check(a,r) check2(a,r,0.0)

void check2(double a, unsigned char rnd_mode, double res1)
{
  mpfr_t ta, tres;
  double res2;
  int ck=0; /* ck=1 iff res1 is certified correct */

  mpfr_set_machine_rnd_mode(rnd_mode);  
  if (res1==0.0) res1=log(a); else ck=1;
  /* printf("mpfr_log working on a=%1.20e, rnd_mode=%d\n",a,rnd_mode);*/
  mpfr_init2(ta, 53);
  mpfr_init2(tres, 53);
  mpfr_set_d(ta, a, GMP_RNDN);
  mpfr_log(tres, ta, rnd_mode);
  res2=mpfr_get_d(tres);

  if (res1!=res2 && (!isnan(res1) || !isnan(res2))) {
    if (ck) 
      printf("mpfr_log failed for    a=%1.40e, rnd_mode=%d\n",a,rnd_mode);
    else
      printf("mpfr_log differs from libm.a for a=%1.40e, rnd_mode=%d\n",a,rnd_mode);
    printf(" double calculus gives %1.40e\n mpfr_log        gives %1.40e (%d ulp)\n pari            gives \n \n",res1,res2,ulp(res1,res2));
  }
  /*else {
    printf("GOAL !!! for           a=%1.20e, rnd_mode=%d\n",a,rnd_mode);
    printf(" double calculus gives %1.20e\n pari            gives \n \n",res1);
    }*/
  mpfr_clear(ta); mpfr_clear(tres); 
}


check3(double d, unsigned long prec, unsigned char rnd)
{
  mpfr_t x, y;
  
  mpfr_init2(x, prec); mpfr_init2(y, prec);
  mpfr_set_d(x, d, rnd);
  mpfr_log(y, x, rnd);
  mpfr_out_str(stdout, 10, 0, y, rnd); putchar('\n');
  mpfr_clear(x); mpfr_clear(y);
}

/* examples from Jean-Michel Muller and Vincent Lefevre 
   Cf http://www.ens-lyon.fr/~jmmuller/Intro-to-TMD.htm
*/

check_worst_cases()
{ /*-2*/
  double d, pow=1.0;
  int i;
  d=(double)4507651597124051;
  for(i=0;i<52;i++)
    pow*=2.0;
  d/=pow;
  check2(1.00089971802309629645, GMP_RNDD, 8.99313519443722736088e-04); 
  check2(1.00089971802309629645, GMP_RNDN, 8.99313519443722844508e-04);
  check2(1.00089971802309629645, GMP_RNDU, 8.99313519443722844508e-04); 

  check2(d, GMP_RNDD, 8.99313519443722736088e-04); 
  check2(d, GMP_RNDN, 8.99313519443722844508e-04);
  check2(d, GMP_RNDU, 8.99313519443722844508e-04); 

  /*+1*/
  check2(1.01979300812244555452, GMP_RNDD, 1.95996734891603630047e-02); 
  check2(1.01979300812244555452, GMP_RNDN, 1.95996734891603664741e-02);
  check2(1.01979300812244555452, GMP_RNDU, 1.95996734891603664741e-02);

  check2(1.02900871924604464525, GMP_RNDD, 2.85959303301472726744e-02);
  check2(1.02900871924604464525, GMP_RNDN, 2.85959303301472761438e-02);
  check2(1.02900871924604464525, GMP_RNDU, 2.85959303301472761438e-02);

  check2(1.27832870030418943585, GMP_RNDD, 2.45553521871417795852e-01);
  check2(1.27832870030418943585, GMP_RNDN, 2.45553521871417823608e-01);
  check2(1.27832870030418943585, GMP_RNDU, 2.45553521871417823608e-01);

  check2(1.31706530746788241792, GMP_RNDD, 2.75406009586277422674e-01);
  check2(1.31706530746788241792, GMP_RNDN, 2.75406009586277478185e-01);
  check2(1.31706530746788241792, GMP_RNDU, 2.75406009586277478185e-01);

  check2(1.47116981099449883885, GMP_RNDD, 3.86057874110010412760e-01);
  check2(1.47116981099449883885, GMP_RNDN, 3.86057874110010412760e-01);
  check2(1.47116981099449883885, GMP_RNDU, 3.86057874110010468272e-01);

  check2(1.58405446812987782401, GMP_RNDD, 4.59987679246663727639e-01);
  check2(1.58405446812987782401, GMP_RNDN, 4.59987679246663783150e-01);
  check2(1.58405446812987782401, GMP_RNDU, 4.59987679246663783150e-01);

  check2(1.67192331263391547047, GMP_RNDD, 5.13974647961076613889e-01);
  check2(1.67192331263391547047, GMP_RNDN, 5.13974647961076724911e-01);
  check2(1.67192331263391547047, GMP_RNDU, 5.13974647961076724911e-01);

  check2(1.71101198068990645318, GMP_RNDD, 5.37084997042120315669e-01);
  check2(1.71101198068990645318, GMP_RNDN, 5.37084997042120315669e-01);
  check2(1.71101198068990645318, GMP_RNDU, 5.37084997042120426691e-01);

  check2(1.72634853551388700588, GMP_RNDD, 5.46008504786553605648e-01);
  check2(1.72634853551388700588, GMP_RNDN, 5.46008504786553716670e-01);
  check2(1.72634853551388700588, GMP_RNDU, 5.46008504786553716670e-01);

  check2(2.00028876593004323325, GMP_RNDD, 6.93291553102749702475e-01);
  check2(2.00028876593004323325, GMP_RNDN, 6.93291553102749813497e-01);
  check2(2.00028876593004323325, GMP_RNDU, 6.93291553102749813497e-01);

  check2(6.27593230200363105808, GMP_RNDD, 1.83672204800630312072);
  check2(6.27593230200363105808, GMP_RNDN, 1.83672204800630334276);
  check2(6.27593230200363105808, GMP_RNDU, 1.83672204800630334276);

  check2(7.47216682321367997588, GMP_RNDD, 2.01118502712453661729);
  check2(7.47216682321367997588, GMP_RNDN, 2.01118502712453706138);
  check2(7.47216682321367997588, GMP_RNDU, 2.01118502712453706138);

  check2(9.34589857718275318632, GMP_RNDD, 2.23493759221664944903);
  check2(9.34589857718275318632, GMP_RNDN, 2.23493759221664989312);
  check2(9.34589857718275318632, GMP_RNDU, 2.23493759221664989312);

  check2(10.6856587560831854944, GMP_RNDD, 2.36890253928838445674);
  check2(10.6856587560831854944, GMP_RNDN, 2.36890253928838445674);
  check2(10.6856587560831854944, GMP_RNDU, 2.36890253928838490083);

  check2(12.4646345033981766903, GMP_RNDD, 2.52289539471636015122);
  check2(12.4646345033981766903, GMP_RNDN, 2.52289539471636015122);
  check2(12.4646345033981766903, GMP_RNDU, 2.52289539471636059531);

  check2(17.0953275851761752335, GMP_RNDD, 2.83880518553861849185);
  check2(17.0953275851761752335, GMP_RNDN, 2.83880518553861893594); 
  check2(17.0953275851761752335, GMP_RNDU, 2.83880518553861893594);

  check2(19.8509496207496916043, GMP_RNDD, 2.98825184582516722998);
  check2(19.8509496207496916043, GMP_RNDN, 2.98825184582516722998);
  check2(19.8509496207496916043, GMP_RNDU, 2.98825184582516767406);

  check2(23.9512076062771335216, GMP_RNDD, 3.17601874455977206679);
  check2(23.9512076062771335216, GMP_RNDN, 3.17601874455977206679);
  check2(23.9512076062771335216, GMP_RNDU, 3.17601874455977251088);

  check2(428.315247165198229595, GMP_RNDD, 6.05985948325268264369);
  check2(428.315247165198229595, GMP_RNDN, 6.05985948325268353187);
  check2(428.315247165198229595, GMP_RNDU, 6.05985948325268353187); 
}



void main(int argc, char *argv[]) {
  int i, N=0;
  double d;

  if (argc==4) {   /* tlog x prec rnd */
    check3(atof(argv[1]), atoi(argv[2]), atoi(argv[3]));
    return;
  }
  if (argc==2) { /* tlog N: N tests with random double's */
    N=atoi(argv[1]);
    printf("Doing %d random tests in double precision\n", N);
    printf("GMP_RNDN : %i, GMP_RNDZ : %i,GMP_RNDU : %i,GMP_RNDD : %i\n",GMP_RNDN, GMP_RNDZ,GMP_RNDU, GMP_RNDD); 
  }
  else {
    check_worst_cases();

   check(10,GMP_RNDU);
  check(6,GMP_RNDU);  
  check(1,GMP_RNDZ);  
  check(62,GMP_RNDU);
  check(0.5,GMP_RNDZ);   
  check(3,GMP_RNDZ); 
  check(234375765,GMP_RNDU);
  check(8,GMP_RNDZ);  
  check(44,GMP_RNDU); 

  check(exp(2),GMP_RNDU);
  check(7.53428236571286402512e+34,GMP_RNDZ);
  check(6.18784121531737948160e+19,GMP_RNDZ); 
  check(1.02560267603047283735e+00,GMP_RNDD);
  check(7.53428236571286402512e+34,GMP_RNDZ);
  check(1.42470900831881198052e+49,GMP_RNDZ); 
  
  check(1.08013816255293777466e+11,GMP_RNDN);
  check(6.72783635300509015581e-37,GMP_RNDU);
  check(2.25904918906057891180e-52,GMP_RNDU);
  check(1.48901209246462951085e+00,GMP_RNDD);
  check(1.70322470467612341327e-01,GMP_RNDN);
  check(1.94572026316065240791e+01,GMP_RNDD);
  check(4.01419512207026418764e+04,GMP_RNDD);
  check(9.47077365236487591672e-04,GMP_RNDZ);
  check(3.95906157687589643802e-109,GMP_RNDD);
  check(2.73874914516503004113e-02,GMP_RNDD);
  check(9.18989072589566467669e-17,GMP_RNDZ);
  check(7.70603645360819104595e+54,GMP_RNDZ);
  check(1.74827399630587801934e-23,GMP_RNDZ);
  check(4.35302958401482307665e+22,GMP_RNDD);
  check(9.70791868689332915209e+00,GMP_RNDD);
  check(2.22183639799464011100e-01,GMP_RNDN);
  check(2.27313466156682375540e+00,GMP_RNDD);
  check(6.58057413965851156767e-01,GMP_RNDZ);
  check(7.34302197248998461006e+43,GMP_RNDZ);
  check(6.09969788341579732815e+00,GMP_RNDD);
  check(8.94529798779875738679e+82,GMP_RNDD);
  check(1.68775280934272742250e+00,GMP_RNDZ); 
  check(5.32204288784834943727e+02,GMP_RNDZ);
  } 

  srand48(getpid());
  for(i=0;i<N;i++) {
    d=drand();
    check(d,rand() % 4);
  }
} 

