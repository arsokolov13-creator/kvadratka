#include <stdio.h>
#include <math.h>

#define ONE_ROOT 1
#define TWO_ROOT 2
#define INF_ROOT 3
#define NO_ROOT 0
#define EPSILON 1.0e-10

bool sravn(double a, double b){

		return (( a-b ) < EPSILON) && (( a-b ) > -EPSILON) ;

}

int ente(double* a_ptr,double* b_ptr,double* c_ptr){
	int i = 0;
    printf("Enter coeficients a,b,c :\n");
    //count = scanf( "%lg%lg%lg" , a_ptr, b_ptr, c_ptr);
	//printf("%d\n ", count );
	char number;
	double arr[3];
	while (scanf("%c", arr[i]) != \n){
		if arr[i]
	}
	if (count < 3)
		return 0;
	return 1;
}


void outp(int w , double x_1 , double x_2 ){
    if (w == 2)
        printf("x_1 and x_2 is: %lg,%lg\n", x_1, x_2);
    if (w == 1)
        printf("x_1 = x_2 = %lg\n", x_1);
    if (w == 0)
        printf("no solves\n");
}


int solve(double a,double b,double c,double*x_1,double*x_2){
    double d = 0, t = 0;

    if (sravn( a , 0 ) && sravn( b , 0 ) && sravn( c , 0)){
        printf("any number\n");
        return INF_ROOT;
    }
    else if (sravn( a, 0) && !sravn(b,0)){
		t = (-c/b);
		if (sravn( t, 0))
			*x_1 = *x_2 = 0;
		else
			*x_1 = *x_2 = (-c/b);
		return ONE_ROOT;
	}
	else if (sravn( a, 0) && !sravn( c, 0)){
	return NO_ROOT;
	}
    if ( !sravn( a, 0)){
        d = b*b-4*a*c;
        if (sravn( d, 0)){
			t=- b/2*a;
			if (sravn( t, 0))
				*x_1= *x_2= 0;
			else
				*x_1 = *x_2 = - b/2*a;
			return ONE_ROOT;
        }
        else if (d<0)
        return NO_ROOT;
        else{
        *x_1 = (-b+sqrt(d)) / (2*a);
        *x_2 = (-b-sqrt(d)) / (2*a);
		if (sravn( *x_1, 0))
			*x_1=0;
		if (sravn( *x_2, 0))
			*x_2=0;
        return TWO_ROOT;
        }
    }
}


int main(){
    double a = 0, b = 0, c = 0, x_1 = 0, x_2 = 0;
    int w = 0;
    int q = ente( &a, &b, &c);
    if (q == 1){

	//printf("%lg, %lg, %lg \n", a, b, c);
	//printf("Enter coeficients a,b,c :\n");
    //scanf( "%lg%lg%lg" , &a, &b, &c);
    w = solve( a, b, c, &x_1, &x_2);
    outp(w, x_1, x_2 );
    }
	else{
		printf("Error, введите ещё раз ");
		return 0;
	}
		
return 0;
}

