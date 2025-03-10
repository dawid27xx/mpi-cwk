//
// Vector dot product using MPI_Reduce().
//
// Compile with:
//
// mpicc -Wall -o dotProduct_MPI dotProduct_MPI.c
//
// Execute with e.g.:
//
// mpiexec -n 4 ./dotProduct_MPI
//


//
// Includes.
//
#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>


//
// Parameters.
//
#define N 128


int main( int argc, char **argv )
{
	int i;

	// Initialise MPI.
	int rank, numProcs;
	MPI_Init( &argc, &argv );
	MPI_Comm_size( MPI_COMM_WORLD, &numProcs );
	MPI_Comm_rank( MPI_COMM_WORLD, &rank     );

	// Require the problem size to be a multiple of the number of processes.
	if( N%numProcs )
	{
		if( rank==0 ) printf( "The array size %d not a multiple of the number of processes %d.\n", N, numProcs );
		MPI_Finalize();
		return EXIT_FAILURE;
	}

	// Initialise the arrays on rank 0. No checking for correct allocation in this demonstration.
	float *a=NULL, *b=NULL;
	if( rank==0 )
	{
		a = (float*) malloc( N*sizeof(float) );
		b = (float*) malloc( N*sizeof(float) );

		for( i=0; i<N; i++ ) a[i] = b[i] = i+1;
	}

	// Local memory require on all processes.
	int numPerProc = N / numProcs;
	float
		*local_a = (float*) malloc( numPerProc*sizeof(float) ),
		*local_b = (float*) malloc( numPerProc*sizeof(float) );

	// Distribute both vectors to the various processes using MPI_Scatter().
	MPI_Scatter( a, numPerProc, MPI_FLOAT, local_a, numPerProc, MPI_FLOAT, 0, MPI_COMM_WORLD );
	MPI_Scatter( b, numPerProc, MPI_FLOAT, local_b, numPerProc, MPI_FLOAT, 0, MPI_COMM_WORLD );

	// Each process calculates their local dot product.
	float local_dot = 0.0f;
	for( i=0; i<numPerProc; i++ ) local_dot += local_a[i]*local_b[i];

	// Use MPI_Reduce() to get the answer back on root 0.
	float dot;
	MPI_Reduce( &local_dot, &dot, 1, MPI_FLOAT, MPI_SUM, 0, MPI_COMM_WORLD );

	// Check the answer. Note if you change the values of a[i] and b[i], this prediction will no longer work.
	if( rank==0 )
		printf( "Result: %g (should be: %d)\n", dot, N*(N+1)*(2*N+1)/6 );

	// Clear up and quit.
	if( rank==0 )
	{
		free( a );
		free( b );
	}
	free( local_a );
	free( local_b );

	MPI_Finalize();

	return EXIT_SUCCESS;
}
