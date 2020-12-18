#include "num_threads.h"
#include "interface.h"
#include "experiments.h"
#include <math.h>

int main(int argc, char **argv) {
    size_t element_count = 1000u;
    printf("==========CPP========\n");
    printf("Control: %f\n", log(2));
    printf("==False sharing==\n");
    run_experiments_for(element_count, cpp_accumulate_false_sharing);
    printf("==Alignment==\n");
    run_experiments_for(element_count, cpp_accumulate_aligned);
//    printf("==Atomic==\n"); don't work
//    run_experiments_for(element_count, cpp_accumulate_atomic);
    printf("==Critical==\n");
    run_experiments_for(element_count, cpp_accumulate_mutex);
    printf("==Reduction (static)==\n");
    run_experiments_for(element_count, cpp_accumulate_reduction_static);
    printf("==========OMP========\n");
    printf("==False sharing==\n");
    run_experiments_for(element_count, omp_accumulate_false_sharing);
    printf("==Alignment==\n");
    run_experiments_for(element_count, omp_accumulate_aligned);
    printf("==Atomic==\n");
    run_experiments_for(element_count, omp_accumulate_atomic);
    printf("==Critical==\n");
    run_experiments_for(element_count, omp_accumulate_critical);
    printf("==Reduction (static)==\n");
    run_experiments_for(element_count, omp_accumulate_reduction_static);
    printf("==Reduction (dynamic)==\n");
    run_experiments_for(element_count, omp_accumulate_reduction_dynamic);
    return 0;
}
