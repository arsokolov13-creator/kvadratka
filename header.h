#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <math.h>
#define EPSILON 1.0e-10
#include <windows.h>
enum NUMBER_ROOTS{
	NO_ROOT=0,
	ONE_ROOT=1,
	TWO_ROOT=2,
	INF_ROOT=3,
};

struct testcase{
	double a, b, c;
	int nrootsref;
	double x_1, x_2;
	double x_1ref, x_2ref; 
};

bool compair(double a, double b );
void compair_with_zero(double* a);
void output(int w , struct testcase* some );
void solveline(double b,double c,double* x);
void diskrim_calculating(struct testcase* some, double* d);
void calculating_rots( double d, struct testcase* some);
int solve( struct testcase* some );
int checkbuff();
void clean_buff();
void RunOneTest(struct testcase test);
int runalltests();
void printtest( struct testcase test);
int input(struct testcase* some);
