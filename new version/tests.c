
void printtest(  struct testcase *test){
	assert(test != NULL);
	printf("X^2 * a + X * b + c = 0\n""a = %.3lg, b = %.3lg , c = %.3lg" 
	", nrootsref=%d, x_1ref = %.3lg , x_2ref = %.3lg \n", test->a, test->b, test->c, test->nrootsref, 
																			test->x_1ref, test->x_2ref);
}

void printerror(struct testcase *test){
	printf(" \e[31m.....Test Failed: a = %lg, b = %lg, c = %lg,"
			"expected %d roots: x_1ref = %.3lg, x_2ref = %.3lg\n"
			"got:  roots: x_1 = %.3lg, x_2 = %.3lg \n", test->a, test->b, test->c, test->nrootsref,
												 test->x_1ref, test->x_2ref , test->x_1, test->x_2 );
}

int readerf(struct testcase x[]){
	assert(x != NULL);
	FILE *file;
	char buf[100];
	file = fopen("11.txt", "r");
	if (file == NULL){
		printf("error\n");
		return 0;	
	}
	int num = 7;
	int i = 0;
	while ( (fgets(buf, sizeof(buf), file) != NULL) && (i < num )){
		//printf("[%s]\n", buf);
		if ( sscanf(buf , "%lg %lg %lg %d %lg %lg %lg %lg", &(x[i].a) , &(x[i].b), &(x[i].c), 
				&(x[i].nrootsref), &(x[i].x_1), &(x[i].x_2), &(x[i].x_1ref), &(x[i].x_2ref)) == 8 ){
			i++;
		}
		else
			break;
	}
	fclose(file);
	return 1;
}

void RunOneTest(  struct testcase *test ){
	assert(test != NULL);
	double x_1 = 0, x_2 = 0;
	int nroots = solve( test );
	if  (!isnan(test->x_1) && !isnan(test->x_2) && !isnan(test->x_1ref) && !isnan(test->x_2ref)) {
		if (nroots != test->nrootsref || !compair(test->x_1, test->x_1ref)  || !compair(test->x_1, test->x_1ref) ){
			printerror(test);
		}
		else
			printf("\e[33mNICE\e[0m\n");
	}
	else{
		if ((isnan(test->x_1) && isnan(test->x_1ref) && compair(test->x_2, test->x_2ref)) || \
		(isnan(test->x_2) && isnan(test->x_2ref) && compair(test->x_1, test->x_1ref)) || \
		(isnan(test->x_1) && isnan(test->x_1ref) && isnan(test->x_2) && isnan(test->x_2ref)))
			printf("\e[33mNICE\e[0m\n");
		else{
			printerror(test);
		}
	}	
}

int runalltests(){
	int num = 7;
	struct testcase arrtests[]={
		{0},{0},{0},{0},{0},{0},{0}
	};
	/*for (int i = 0; i < 6; ++i)
	{
		printf("%p\n", arrtests[i]);
	} */
	readerf( arrtests );
	for (int j = 0 ; j < num ; j++){
		RunOneTest( &arrtests[j] );
		printtest( &arrtests[j] );
	}
	return 0;
}