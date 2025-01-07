#include <bits/stdc++.h>
#include <intrin.h>
using namespace std;
#define L1 (long int)48e3
#define L2 (long int)1280e3
#define L3 (long int)12e6/4
const int total = 10LL*L3;
const int  N = total;


int main()
{   
    srand(time(NULL));
    ofstream file;
    file.open("cache_latency_results.txt");
    for(double len = 1e4; len < total; len *= pow(10, (log10(total) - 4)/200)){
        int* ar = new int[(int)len];
        int* arr = new int[(int)len];
        for(int i = 0; i < (int)len; ++i){
            ar[i] = i;
        }
        random_shuffle(ar, ar + (int)len);
        int ind = ar[(int)len-1];
        for(int i = 0; i < (int)len; ++i){
            arr[ind] = ar[i];
            ind = arr[ind];   
        }
        delete ar;
        //printf("%d\n", cont);
        volatile int count = 0;
        auto ini = chrono::high_resolution_clock::now();
        for(int i = 0; i < N/len; ++i){
            for(int j = 0; arr[j] != 0; j = arr[j]){
                ++count;
            }
        }
        auto end = chrono::high_resolution_clock::now();
        long int elapsed_ns = chrono::duration_cast<chrono::nanoseconds>(end - ini).count();
        if(file.is_open()){
            file << (int) len << ", " << elapsed_ns << endl;
        }
        delete arr;
    }
    //printf("%f\n", log10(total)/1000);
    
    /*ofstream file;
    file.open("cache_kicker_results.txt");
    for(double len = 1e4; len < total; len *= pow(10, (log10(total) - 4)/200)){
        auto ini = chrono::high_resolution_clock::now();
        __sync_synchronize();
        for(int i = 0; i < N/len; ++i){
            for(int j = 0; j < len; ++j){
                ++arr[j];
            }
        }
        auto end = chrono::high_resolution_clock::now();
        long int elapsed_ns = chrono::duration_cast<chrono::nanoseconds>(end - ini).count();
        if(file.is_open()){
            file << (int) len << ", " << elapsed_ns << endl;
        }
    }*/
    return 0;
}