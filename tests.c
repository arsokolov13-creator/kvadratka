
void printtest(  struct testcase test){
	//assert(test != NULL);
	printf("X^2 * a + X * b + c = 0\n""a = %.3lg, b = %.3lg , c = %.3lg" 
	", nrootsref=%d, x_1ref = %.3lg , x_2ref = %.3lg \n", test.a, test.b, test.c, test.nrootsref, test.x_1ref, test.x_2ref);
}

void printerror(struct testcase test){
	printf(" \e[31m.....Test Failed: a = %lg, b = %lg, c = %lg,"
			"expected %d roots: x_1ref = %.3lg, x_2ref = %.3lg\n"
			"got:  roots: x_1 = %.3lg, x_2 = %.3lg \n", test.a, test.b, test.c, test.nrootsref, test.x_1ref, test.x_2ref , test.x_1, test.x_2 );
}

void readerf(struct testcase x[]){
	//printf("yyyyyy\n");
	FILE *file;
	char l[100];
	assert(x != NULL);
	file = fopen("11.txt", "r");
	if (file == NULL){
		printf("error\n");	
	}
	//printf("shhhit\n");
	int num = 6;
	int i = 0;
	while ( (fgets(l, sizeof(l), file) != NULL) && (i < 6)){
		//printf("eeeee\n");
		if (sscanf(l, "%lg %lg %lg %d %lg %lg %lg %lg", &x[i].a , &x[i].b, &x[i].c, &x[i].nrootsref, &x[i].x_1, &x[i].x_2, &x[i].x_1ref, &x[i].x_2ref) == 8 ){
			i++;
			//printf("%lg\n",x);
		}
		else
			break;
	}
	fclose(file);
}

void RunOneTest(  struct testcase test ){
	//assert(test != NULL);
	double x_1 = 0, x_2 = 0;
	int nroots = solve(  &test );
	if  (!isnan(test.x_1) && !isnan(test.x_2) && !isnan(test.x_1ref) && !isnan(test.x_2ref)) {
		if (nroots != test.nrootsref || !compair(test.x_1, test.x_1ref)  || !compair(test.x_1, test.x_1ref) ){
			printerror(test);
		}
		else
			printf("\e[0mNICE\n");
	}
	else{
		if ((isnan(test.x_1) && isnan(test.x_1ref) && compair(test.x_2, test.x_2ref)) || \
		(isnan(test.x_2) && isnan(test.x_2ref) && compair(test.x_1, test.x_1ref)) || \
		(isnan(test.x_1) && isnan(test.x_1ref) && isnan(test.x_2) && isnan(test.x_2ref)))
			printf("NICE\n");
		else{
			printerror(test);
		}
	}	
}

int runalltests(){
	
	struct testcase arrtests[6]={
		{},{},{},{},{},{}
	};
	readerf( arrtests );
	for (int j = 0 ; j < 6 ; j++){
		RunOneTest(arrtests[j]);
		printtest(arrtests[j]);
	}
	return 0;
}