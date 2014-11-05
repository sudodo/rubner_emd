#include <math.h>
#include <stdlib.h>
#include <stdio.h>
/*
 * =====================================================================================
 *
 *       Filename:  example3.c
 *
 *    Description:  2 dimensional and Euclidian distance.
 *
 *        Version:  1.0
 *        Created:  2014/10/29 20時14分02秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Akihito Sudo (), 
 *        Company:  
 *
 * =====================================================================================
 */

#include "emd.h"

// Euclidean distance
float dist2(feature_t *F1, feature_t *F2)
{
  // TODO Shold be double or float type?
  int dX = F1->X - F2->X, dY = F1->Y - F2->Y;
  return sqrt(dX*dX + dY*dY);
}

int main()
{
  int i;
  int dimension = 100;
  int j ;
  int orig_signature = 1;
  /*
   feature_t   f1[4] = { {100,40}, {211,20}, {32,190}, {2,100} },
 	      f2[3] = { {0,0}, {50,100}, {255,255} };
   float       w1[5] = { 0.4, 0.3, 0.2, 0.1 },
               w2[3] = { 0.5, 0.3, 0.2 };
   signature_t s1 = { 4, f1, w1},
 	            s2 = { 3, f2, w2};
  */
  feature_t f1[dimension];
  feature_t f2[dimension];
  float w1[dimension];
  float w2[dimension];
  for(i = 0; i < dimension; i++){
    f1[i].X = i;
    f1[i].Y = i;
    f2[i].X = i;
    f2[i].Y = i;
    w1[i] = (double)rand()/RAND_MAX;
    w2[i] = (double)rand()/RAND_MAX;
  }
  signature_t s1 = { dimension, f1, w1},
	            s2 = { dimension, f2, w2};

  float e;

  e = emd(&s1, &s2, dist2, 0, 0);

  printf("emd=%f\n", e);
  printf("dimension=%d\n", dimension);
}

