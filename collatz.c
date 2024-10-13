#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned long long int rand_Num( unsigned long long int N_, unsigned long long int MAX_, unsigned long long int MIN_) {
    
    FILE *fpt;

    fpt = fopen("MyFile.csv", "w+");

    unsigned long long int i = 0;

    unsigned long long int count = 1;

    unsigned long long int RN = rand() % (MAX_ - MIN_ + 1) + MIN_;
    
    fprintf(fpt, "Number, Steps\n");

     while( i != N_ ) {   
        
        fprintf(fpt, "%llu, %llu \n", RN, count);
        
        if( RN == 1) {
            return count;
        }

        count = count + 1;
        i = i +1;

        RN = rand() % (MAX_ - MIN_ + 1) + MIN_;
        
    }
    fclose(fpt);
}

int main( int argc, char *argv[] ) {
    
    long long int MIN = atoi( argv[1] );

    unsigned long long int MAX = atoi( argv[2] );

    unsigned long long int N = rand() % (MAX - MIN + 1) + MIN;

    printf( "Usage: %s %llu %lld %llu\n", argv[0], N, MIN, MAX );
    printf("%llu \n", rand_Num( N, MAX, MIN ) );

   
    return 0;
}