
void printtest(  struct testcase test){
	printf("a = %.3lg, b = %.3lg , c = %.3lg , nrootsref=%d, x_1ref = %.3lg , x_2ref = %.3lg \n", test.a, test.b, test.c, test.nrootsref, test.x_1ref, test.x_2ref);
}

void RunOneTest(  struct testcase test ){
	double x_1 = 0, x_2 = 0;
	int nroots = solve(  &test );
	if  ((nroots != test.nrootsref) || ((test.x_1*test.x_1)*test.a + test.b*test.x_1 + test.c != 0 ) || ((test.x_2*test.x_2)*test.a + test.b*test.x_2 + test.c != 0 )){
		printf("Test Failed: a = %lg, b = %lg, c = %lg,"
		"expected %d roots: x_1ref = %.3lg, x_2ref = %.3lg\n"
		"got:  roots: x_1 = %.3lg, x_2 = %.3lg \n", test.a, test.b, test.c, test.nrootsref, test.x_1ref, test.x_2ref , test.x_1, test.x_2 );
		printf("not zero: %lg", ((test.x_1*test.x_1)*test.a + test.b*test.x_1 + test.c != 0 ));
		printf("not zero: %lg", ((test.x_2*test.x_2)*test.a + test.b*test.x_1 + test.c != 0 ));
	
	
	}
	else
		printf("NICE\n");
	
}

/* void RunOneTest(  struct testcase test ){
	double x_1 = 0, x_2 = 0;
	int nroots = solve(  &test );
	if (nroots != test.nrootsref || !compair(test.x_1, test.x_1ref)  || !compair(test.x_1, test.x_1ref) ){
		printf("Test Failed: a = %lg, b = %lg, c = %lg,"
		"expected %d roots: x_1ref = %.3lg, x_2ref = %.3lg\n"
		"got:  roots: x_1 = %.3lg, x_2 = %.3lg \n", test.a, test.b, test.c, test.nrootsref, test.x_1ref, test.x_2ref , test.x_1, test.x_2 );
	}
	else
		printf("NICE\n");
	
} */

//struct testcase test6



int runalltests(){
	/* struct testcase test1 = { .a=1 , .b=2 , .c = 1 , .nrootsref = 1 , .x_1ref = -1 , .x_2ref = NAN };
	struct testcase test2 = { .a=1 , .b=0 , .c = -4, .nrootsref = 2, .x_1ref = 2, .x_2ref = -2};
	struct testcase test3 = {.a= 67.87899, .b = -52.32, .c = 4.00111, .nrootsref= 2, .x_1ref=0.685 , .x_2ref= 0.086 };
	struct testcase test4 = {.a= 1 , .b= 9, .c = 2 , .nrootsref = 2, .x_1ref= -0.228 , .x_2ref= -8.772};
	struct testcase test5 = {.a= 0, .b=0 , .c = 0, .nrootsref = 3, .x_1ref = 0, .x_2ref = 0 };
	struct testcase test6 = {.a= 0, .b= 923, .c = -175 , .nrootsref = 1 , .x_1ref= 0.190 , .x_2ref= NAN };   */
	/* RunOneTest(  test1 );
	printtest( test1 );
	RunOneTest( test2);
	printtest( test2 );
	RunOneTest( test3 );
	printtest( test3 );
	RunOneTest( test4 );
	printtest( test4 );
	RunOneTest( test5 );
	printtest( test5 );
	RunOneTest( test6 );
	printtest( test6 );	  */
	
	struct testcase arrtests[]={
	 { .a=1 , .b=2 , .c = 1 , .nrootsref = 1 , .x_1 = -1 , .x_2 = 0, .x_1ref = -1 , .x_2ref = NAN },
	 { .a=1 , .b=0 , .c = -4, .nrootsref = 2,.x_1 = 0, .x_2 = 0, .x_1ref = 2, .x_2ref = -2},
	 {.a= 67.87899, .b = -52.32, .c = 4.00111, .nrootsref= 2,.x_1 = 0, .x_2 = 0, .x_1ref=0.685 , .x_2ref= 0.086 },
	 {.a= 1 , .b= 9, .c = 2 , .nrootsref = 2, .x_1 = 0, .x_2 = 0, .x_1ref= -0.228 , .x_2ref= -8.772},
	 {.a= 0, .b=0 , .c = 0, .nrootsref = INF_ROOT,.x_1 = 0, .x_2 = 0, .x_1ref = NAN, .x_2ref = NAN },
	 {.a= 0, .b= 923, .c = -175 , .nrootsref = ONE_ROOT ,.x_1 = 0, .x_2 = 0, .x_1ref= 0.190 , .x_2ref= NAN }
	};
	
	for (int j=0 ; j<6 ; j++){
		RunOneTest(arrtests[j]);
		printtest(arrtests[j]);
	}
	return 0;
}