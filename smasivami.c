#include <stdio.h>
#include <math.h>
#define EPSILON 1.0e-10

enum NUMBER_ROOTS{
	NO_ROOT=0,
	ONE_ROOT=1,
	TWO_ROOT=2,
	INF_ROOT=3
};

int input(double arr[]);
bool compair(double a, double b);
void compair_with_zero(double* a);
void output(int w , double x_1 , double x_2 );
void solveline(double b,double c,double*x_1);
void diskrim_calculating(double arr[] , double* d);
void calculating_rots(double arr[] , double d, double* x_1, double* x_2);
int solve( double arr[], double*x_1, double*x_2);
int checkbuff();
void clean_buff();


int main(){
	double arr_coeff[3] = {0, 0, 0};
    double x_1 = 0, x_2 = 0;
    int w = 0;
    int y = input( arr_coeff);
	
	while (y == 0 ){
		clean_buff();
		y = input( arr_coeff);
		printf("%d\n", y);
	}
	
	printf("%lg, %lg, %lg \n", arr_coeff[0], arr_coeff[1], arr_coeff[2]);
	w = solve( arr_coeff , &x_1, &x_2);
	output(w, x_1, x_2 );
    
return 0;
}


int checkbuff(){
	if (getchar() == '\n')
		return 1;
	else
		return 0;
}

void clean_buff(){
	while (getchar() != '\n');
}


bool compair(double a, double b ){
		return (( a-b ) < EPSILON) && (( a-b ) > -EPSILON) ;
}

void compair_with_zero(double* a){
	if (( *a < EPSILON) && (*a > - EPSILON))
		*a = 0;
}

int input(double arr[] ){
    printf("Enter coeficients a,b,c :\n");
	int z = scanf( "%lg %lg %lg", arr, arr+1, arr+2) ;
    if ( z==3 && checkbuff()==1)
		return 1;
	else{
		printf("Error . Try again\n");
		return 0;
	}
}
	
void output(int w , double x_1 , double x_2 ){
    if (w == 2)
        printf("x_1 is %lg and x_2 is %lg\n", x_1, x_2);
    if (w == 1)
        printf("x_1 = x_2 = %lg \n", x_1);
    if (w == 0)
        printf("no solves\n");
	if (w == 3)
		printf("Any number\n");
}

void solveline(double b,double c,double*x_1){ 
	double z = ( -c/b );
	if (compair( z, 0))
		*x_1 = 0;
	else
		*x_1 = z;
}
void diskrim_calculating(double arr[], double* d){ 
	*d = (arr[1]*arr[1] - 4*arr[0]*arr[2]);
}

void calculating_rots(double arr[], double d, double* x_1, double* x_2){ 
	*x_1 = (-arr[1] + sqrt( d )) / (2*arr[0]);
	*x_2 = (-arr[1] - sqrt( d )) / (2*arr[0]);
}

int solve( double arr[], double*x_1, double*x_2){
    double d = 0 , t = 0 ;

    if (compair( arr[0] , 0 ) && compair( arr[1] , 0 ) && compair( arr[2] , 0)){
        return INF_ROOT;
    }
    else if ( compair( arr[0], 0) ){
		solveline( arr[1], arr[2], x_1);
		return ONE_ROOT;
	}
    if (!compair( arr[0], 0)){
        diskrim_calculating( arr , &d );
        if (compair( d, 0 )){
			t = - arr[1] / (2*arr[0]);
			if (compair( t , 0))
				*x_1 = *x_2= 0;
			else
				*x_1 = *x_2 = t;
			return ONE_ROOT;
        }
        else if (d < 0)
			return NO_ROOT;
        else{
			calculating_rots( arr , d , x_1 , x_2);
			compair_with_zero( x_1 );
			compair_with_zero( x_2 );
			return TWO_ROOT;
			}
    }
}



