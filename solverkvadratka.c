

int solve( struct testcase* some){
    double d = 0 , t = 0 ;
	assert(some != NULL);
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
