/*
 * =====================================================================================
 *
 *       Filename:  segfault.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014/11/05 17時44分33秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Akihito Sudo (), 
 *        Company:  
 *
 * =====================================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "emd.h"

#define DEBUG_LEVEL 3

#define MAX_SIG_SIZE1  (MAX_SIG_SIZE+1)  /* FOR THE POSIBLE DUMMY FEATURE */

typedef struct node1_t {
  int i;
  double val;
  struct node1_t *Next;
} node1_t;


typedef struct node2_t {
  int i, j;
  double val;
  struct node2_t *NextC;               /* NEXT COLUMN */
  struct node2_t *NextR;               /* NEXT ROW */
} node2_t;


static float _C[MAX_SIG_SIZE1][MAX_SIG_SIZE1];/* THE COST MATRIX */
static node2_t _X[MAX_SIG_SIZE1*2];            /* THE BASIC VARIABLES VECTOR */
/* VARIABLES TO HANDLE _X EFFICIENTLY */
static node2_t *_EndX, *_EnterX;
static char _IsX[MAX_SIG_SIZE1][MAX_SIG_SIZE1];
static node2_t *_RowsX[MAX_SIG_SIZE1], *_ColsX[MAX_SIG_SIZE1];
static double _maxW;
static float _maxC;

/* DECLARATION OF FUNCTIONS */
static float init(signature_t *Signature1, signature_t *Signature2,
		  float (*Dist)(feature_t *, feature_t *));
static void findBasicVariables(node1_t *U, node1_t *V);
static int isOptimal(node1_t *U, node1_t *V);
static int findLoop(node2_t **Loop);
static void newSol();
static void russel(double *S, double *D);
static void addBasicVariable(int minI, int minJ, double *S, double *D, 
			     node1_t *PrevUMinI, node1_t *PrevVMinJ,
			     node1_t *UHead);

int main(){
  printf("MAX_SIG_SIZE: %d\n", MAX_SIG_SIZE1);
}
