/*
 ============================================================================
 Author        : G. Barlas
 Version       : 1.0
 Last modified : December 2014
 License       : Released under the GNU GPL 3.0
 Description   :
 To build use  : nvcc hello.cu -o hello -arch=sm_20
 ============================================================================
 */
#include <cstdio>
#include <stdio.h>
#include <cuda.h>

__global__ void hello()
{
   printf("Hello world, Adrian Fulladolsa - 21592\n");
}

int main()
{
  hello<<<1,2048>>>();
  cudaThreadSynchronize();
  return 0;
}
