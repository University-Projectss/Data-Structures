#include <iostream>
#include <fstream>
#include <vector>
#include <ctime>
#include <chrono>
#include <stdlib.h>
using namespace std;
using namespace std::chrono;

ifstream fin("teste.txt");

vector<int> w;     //vectorul auxiliar pt MergeSort
vector<int> victor;    //vectorul generat, il voi copia in alt vct pentru fiecare sortare
                  //ca sa avem EXACT acelasi vector pentru toate sortarile.
vector<int> v;      //Acesta va fi folosit la sortari.

void MergeSort(int st, int dr);
void ShellSort(int n);
bool testSort();

int main() {
    ios::sync_with_stdio( false );
    cin.tie();  

    int t, n, maxi;
    fin >> t;

    for(int i = 0; i < t; i++) {
        //time_t startTime, finishTime;
        fin >> n >> maxi;
        v.resize(n, 0);
        victor.resize(n, 0);     //cu n nr. nat. random din intervalul [0, maxi]

        srand(time(NULL)); //pentru fiecare rulare vrem sa avem alte seturi de nr random    
        
        for(int j = 0; j < n; j++) 
            victor[j] = rand() % (maxi + 1);

        cout << "TESTUL " << i + 1 << ":  ";
        cout << "n= " << n << "   ";
        cout << "max= " << maxi << endl;

       for(int j = 0; j < n; j++) 
            v[i] = victor[j];

//Prima sortare: Merge Sort
        w.resize(n, 0);
        auto start0 = high_resolution_clock::now();
        MergeSort( 0, n - 1);
        auto stop0 = high_resolution_clock::now();

        auto duration0 = duration_cast<microseconds>(stop0 - start0).count() /1000000.00000000000000;

        cout << "Merge Sort / " << fixed << duration0 << setprecision(5) << "sec" << " / ";
        testSort() ? cout << "Sortat cu succes!" : cout << "Fail";
        cout << endl;
        

//A doua sortare: Shell Sort
        for(int j = 0; j < n; j++) 
            v[i] = victor[j];
        
        start0 = high_resolution_clock::now();
        ShellSort(n);
        stop0 = high_resolution_clock::now();

        duration0 = duration_cast<microseconds>(stop0 - start0).count() /1000000.00000000000000;

        cout << "Shell Sort / " << fixed << duration0 << setprecision(5) << "sec" << " / ";
        testSort() ? cout << "Sortat cu succes!" : cout << "Fail";
        cout << endl;


//A treia sortare: Radix Sort
        


    
        cout << endl;
        cout << "----------------------------------------------------";
        cout << endl;
    }

    return 0;
}

//Aici avem definite sortarile si functia testSort(), care verifica daca am sortat corect.

bool testSort() {
    for(int i = 0; i < v.size() - 1; i++)
        if(v[i] > v[i + 1])
            return false;
    return true;
}

void ShellSort(int n) {
    int gap, i, j, temp;
    for( gap = n / 2; gap > 0; gap /= 2) {
        for( i = gap; i < n; i++) {
            temp = v[i];

            for(j = i; j >= gap && v[j - gap] > temp; j -= gap)
                v[j] = v[j - gap];

            v[j] = temp;
        }
    }
}

void MergeSort( int st, int dr) {
    if(st >= dr)
        return;

    int mid = (st + dr) / 2;
    MergeSort(st, mid);
    MergeSort( mid + 1, dr);

    int a = st, b = mid + 1, k = 0;
    while(a <= mid && b <= dr) {
        if(v[a] <= v[b])
            w[k++] = v[a++];
        else 
            w[k++] = v[b++];
    }

    while(a <= mid)
        w[k++] = v[a++];

    while(b <= dr) 
        w[k++] = v[b++];

    
    for(a = st, b = 0; a <= dr; a++, b++)
        v[a] = w[b];
}