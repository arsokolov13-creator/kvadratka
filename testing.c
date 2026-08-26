#include "header.h"
#include "tests.c"
#include "solverkvadratka.c"

int main( ){
	//HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	//SetConsoleTextAttribute(hConsole, 10 | 0*16);
	char ans[]= "";
	asker(ans);
	printf("\e[0m");
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
	assert(isfinite(a));
	double t=1;
	for (int i=0 ; i < n; i++ ){
		t *= a;
		
	}
	return t;
}

int asker(char* ans ){
	assert(ans != NULL);
	printf( "\e[32mDo you want to test this programm? (Enter only yes or no )\n");
	scanf("%10s", ans);
	if (strcmp(ans,"yes")==0){
		//SetConsoleTextAttribute(hConsole, 3);
		runalltests();	
		//SetConsoleTextAttribute(hConsole, 7);
	}
	else if (strcmp(ans, "no")==0){
		//HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		//SetConsoleTextAttribute(hConsole, 4);
		struct testcase some = {};
		printf("ok\n");
		int w = 0;
		int y = input(  &some );
		while (y == 0 ){
			clean_buff();
			y = input(  &some );
			//printf("%d\n", y);
		}
		printf("%lg, %lg, %lg \n", some.a, some.b, some.c);
		w = solve( &some  );
		//SetConsoleTextAttribute(hConsole, 14);
		output( w , &some );
		//SetConsoleTextAttribute(hConsole, 7);
	}
	else{
		printf("\e[33mWhat do you mean? \nPlease try to answer again\n");
		asker(ans);	
	}
	
	return 0 ; 
}

bool compair( double a, double b ){
		//assert(isfinite(a));
		//assert(isfinite(b));
		return (( a-b ) < EPSILON) && (( a-b ) > -EPSILON) ;
}

void compair_with_zero(double* a){
	assert(a != NULL);
	if (( *a < EPSILON) && (*a > - EPSILON))
		*a = 0;
}

int input(struct testcase* some ){
	assert(some != NULL);
    printf("\e[34mEnter coeficients a  b  c :\n");
	int z = scanf( "%lg %lg %lg", &some->a, &some->b, &some->c) ;
	printf("rrrr\n");
    if ( z==3 && checkbuff()==1){
		return 1;
	}
	else{
		//HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		//SetConsoleTextAttribute(hConsole, 12);
		printf("Error . Try again\n");
		return 0;
	}
}
	
void output(int w , struct testcase* some ){
	assert(some !=NULL);
	printf("\e[0mX^2 * a + X * b + c = 0\e[0m\n");
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
	assert(x != NULL);
	assert(isfinite(b));
	assert(isfinite(c));
	double z = ( -c/b );
	if (compair( z, 0))
		*x = 0;
	else
		*x = z;
}

void diskrim_calculating(struct testcase* some, double* d){ 
	assert( d != NULL);
	assert( some != NULL);
	*d = ((some->b)*(some->b) - 4*(some->a)*(some->c));
}

void calculating_rots( double d, struct testcase* some){ 
	assert( some != NULL);
	assert(isfinite(d));
	some->x_1 = (-(some->b) + sqrt( d )) / (2*(some->a));
	some->x_2 = (-(some->b) - sqrt( d )) / (2*(some->a));
}




