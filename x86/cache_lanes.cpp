#include <bits/stdc++.h>
#include <intrin.h>
using namespace std;
#define L1 (long int)48e3
#define L2 (long int)1280e3
#define L3 (long int)12e6/4
const int total = 10LL*L3;
const int  N = total;
int arr[total];
int main()
{
    //printf("%f\n", log10(total)/1000);
    ofstream file;
    file.open("cache_lanes_results.txt");
    for(int stride = 1; stride <= 20; ++stride){
        for(double len = 1e4; len < total; len *= pow(10, (log10(total) - 4)/100)){
            auto ini = chrono::high_resolution_clock::now();
            __sync_synchronize();
            for(int i = 0; i < N/len; ++i){
                for(int j = 0; j < len; j += stride){
                    ++arr[j];
                }
            }
            auto end = chrono::high_resolution_clock::now();
            long int elapsed_ns = chrono::duration_cast<chrono::nanoseconds>(end - ini).count();
            if(file.is_open()){
                file << stride << ", " <<(int) len << ", " << elapsed_ns << endl;
            }
        }
    }
    return 0;
}