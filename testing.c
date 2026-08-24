#include "header.h"
#include "tests.c"


int main( ){
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 10 | 0*16);
	char ans[]= "";
	//printf("ok\n");
    //int w = 0;
	//int y = input(  &some );
	/* while (y == 0 ){
		clean_buff();
		y = input(  &some );
		printf("%d\n", y);
	}
	 */
	//printf("%lg, %lg, %lg \n", some.a, some.b, some.c);
	printf("Do you want to test this programm?\n");
	scanf("%10s", ans);
	if (strcmp(ans,"yes")==0){
		SetConsoleTextAttribute(hConsole, 3);
		runalltests();	
		SetConsoleTextAttribute(hConsole, 7);
	}
	else if (strcmp(ans, "no")==0){
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hConsole, 4);
		
		struct testcase some = {};
		printf("ok\n");
		int w = 0;
		int y = input(  &some );
		
		while (y == 0 ){
			clean_buff();
			y = input(  &some );
			//printf("%d\n", y);
		}
		assert(2==2);
		printf("%lg, %lg, %lg \n", some.a, some.b, some.c);
		w = solve( &some  );
		SetConsoleTextAttribute(hConsole, 14);
		output( w , &some );
		SetConsoleTextAttribute(hConsole, 7);
		
	}
	else
		printf("www\n");
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

double st(double a, int n){
	double t=1;
	for (int i=0 ; i < n; i++ ){
		t *= a;
		
	}
	return t;
}


bool compair( double a, double b ){
		return (( a-b ) < EPSILON) && (( a-b ) > -EPSILON) ;
}

void compair_with_zero(double* a){
	if (( *a < EPSILON) && (*a > - EPSILON))
		*a = 0;
}

int input(struct testcase* some ){
    printf("Enter coeficients a  b  c :\n");
	int z = scanf( "%lg %lg %lg", &some->a, &some->b, &some->c) ;
	printf("rrrr\n");
    if ( z==3 && checkbuff()==1)
		return 1;
	else{
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hConsole, 12);
		printf("Error . Try again\n");
		return 0;
	}
}
	
void output(int w , struct testcase* some ){
    if (w == 2)
        printf("x_1 is %lg and x_2 is %lg\n", some->x_1, some->x_2 );
    if (w == 1)
        printf("x_1 = x_2 = %lg \n", some->x_1);
    if (w == 0)
        printf("no solves\n");
	if (w == 3)
		printf("Any number\n");
}

 
void solveline(double b,double c,double* x){ 
	double z = ( -c/b );
	if (compair( z, 0))
		*x = 0;
	else
		*x = z;
}



void diskrim_calculating(struct testcase* some, double* d){ 
	*d = ((some->b)*(some->b) - 4*(some->a)*(some->c));
}

void calculating_rots( double d, struct testcase* some){ 
	some->x_1 = (-(some->b) + sqrt( d )) / (2*(some->a));
	some->x_2 = (-(some->b) - sqrt( d )) / (2*(some->a));
}

int solve( struct testcase* some){
    double d = 0 , t = 0 ;

    if (compair( some->a , 0 ) && compair( some->b, 0 ) && compair( some->c , 0)){
		some->x_1 = NAN;
		some->x_2 = NAN;
        return INF_ROOT;
    }
    else if ( compair( some->a, 0) ){
		solveline( some->b , some->c , &some->x_1);
		some->x_1 = round(some->x_1*1000)/1000;
		some->x_2 = NAN;
		return ONE_ROOT;
	}
    if (!compair( some->a, 0)){
        diskrim_calculating(  some , &d );
        if (compair( d, 0 )){
			t = - (some->b) / (2*some->a);
			if (compair( t , 0))
				some->x_1 = some->x_2= 0;
			else
				some->x_1 = some->x_2 = round(t*1000)/1000;
			return ONE_ROOT;
        }
        else if (d < 0)
			return NO_ROOT;
        else{
			calculating_rots( d, some );
			some->x_1 = round(some->x_1*1000)/1000;
			some->x_2 = round(some->x_2*1000)/1000;
			compair_with_zero( &some->x_1 );
			compair_with_zero( &some->x_2 );
			return TWO_ROOT;
			}
    }
	return 0;
}


