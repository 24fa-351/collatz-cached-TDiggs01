#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

unsigned long long int steps = 1;

unsigned long long int collatz( FILE *fpt_, unsigned long long int RN, unsigned long long int MAX_, unsigned long long int MIN_ ) {   

        fprintf( fpt_, "%llu, %llu \n", RN, steps );
        
        if( RN == 1) {
            return 1;
        }
        else if (RN % 2 == 0) // If even
        {
            steps = steps + 1;
            return collatz(fpt_, RN / 2, MAX_, MIN_ );
        }
        else // If odd
        {
            steps = steps + 1;
            return collatz(fpt_, (3 * RN) + 1, MAX_, MIN_ );
        }
        
    }

unsigned long long int wrapper_collatz( unsigned long long int RN, unsigned long long int MAX_, unsigned long long int MIN_) {
    
    FILE *fpt;

    fpt = fopen("MyFile.csv", "w+");

    fprintf(fpt, "Number, Steps\n");

    return collatz(fpt, RN, MAX_, MIN_ );

    fclose(fpt);
}


int main( int argc, char *argv[] ) {
    
    long long int MIN = atoi( argv[1] );

    unsigned long long int MAX = atoi( argv[2] );

    unsigned long long int N = rand() % (MAX - MIN + 1) + MIN;

    printf( "Usage: %s %llu %lld %llu\n", argv[0], N, MIN, MAX );
    printf("%llu \n", wrapper_collatz( N, MAX, MIN ) );

   
    return 0;
}