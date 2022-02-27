#include <iostream>
#include <fstream>
#include <vector>
#include <ctime>
#include <chrono>
using namespace std;
using namespace std::chrono;

ifstream fin("teste.txt");

vector<int> w;          //vectorul auxiliar pt MergeSort si RadixSort

vector<int> victor;    //vectorul generat, il voi copia in alt vct pentru fiecare sortare
                        //ca sa avem EXACT acelasi vector pentru toate sortarile.

vector<int> v;      //Acesta va fi folosit la sortari.

void MergeSort(int st, int dr);
void ShellSort(int n);
void RadixSort(int n);
void CountingSort(int n, int maxi);
int partitie(int st, int dr);
int partitieR(int st, int dr);
void QuickSort(int st, int dr);
bool testSort();

int main() {
    ios::sync_with_stdio( false );
    cin.tie();  

    int t, n, maxi;
    fin >> t;

    for(int i = 0; i < t; i++) {
        fin >> n >> maxi;
        v.resize(n, 0);
        victor.resize(n, 0);     //cu n nr. nat. random din intervalul [0, maxi]

        srand(time(NULL));      //pentru fiecare rulare vrem sa avem alte seturi de nr random    
        
        for(int j = 0; j < n; j++) 
            victor[j] = rand() % (maxi + 1);

        cout << "\033[1;34mTESTUL " << i + 1 << ":  ";
        cout << "n= " << n << "   ";
        cout << "max= " << maxi << endl;
        cout << "\033[0m";

       for(int j = 0; j < n; j++) 
            v[j] = victor[j];

//Sortarea C++: sort()

        auto start0 = high_resolution_clock::now();
        sort( v.begin(), v.end());
        auto stop0 = high_resolution_clock::now();

        auto duration0 = duration_cast<microseconds>(stop0 - start0).count() /1000000.00000000000000;

        cout << "C++ Sort      / " << fixed << duration0 << setprecision(5) << "sec" << " / ";
        testSort() ? cout << "\033[1;32mSortat cu succes!" : cout << "\033[1;31mFail";
        cout << "\033[0m" << endl;


//Prima sortare: Merge Sort
        for(int j = 0; j < n; j++) 
            v[j] = victor[j];

        w.resize(n, 0);
        start0 = high_resolution_clock::now();
        MergeSort( 0, n - 1);
        stop0 = high_resolution_clock::now();

        duration0 = duration_cast<microseconds>(stop0 - start0).count() /1000000.00000000000000;

        cout << "\033[1;35mMerge Sort    \033[0m/ \033[1;35m" << fixed << duration0 << setprecision(5) << "sec" << "\033[0m / ";
        testSort() ? cout << "\033[1;32mSortat cu succes!" : cout << "\033[1;31mFail";
        cout << "\033[0m" << endl;
        

//A doua sortare: Shell Sort
        for(int j = 0; j < n; j++) 
            v[j] = victor[j];
        
        start0 = high_resolution_clock::now();
        ShellSort(n);
        stop0 = high_resolution_clock::now();

        duration0 = duration_cast<microseconds>(stop0 - start0).count() /1000000.00000000000000;

        cout << "Shell Sort    / " << fixed << duration0 << setprecision(5) << "sec" << " / ";
        testSort() ? cout << "\033[1;32mSortat cu succes!" : cout << "\033[1;31mFail";
        cout << "\033[0m" << endl;
        

//A treia sortare: Radix Sort
        for(int j = 0; j < n; j++) 
            v[j] = victor[j];

         w.resize(n, 0);

        start0 = high_resolution_clock::now();
        RadixSort(n);
        stop0 = high_resolution_clock::now();

        duration0 = duration_cast<microseconds>(stop0 - start0).count() /1000000.00000000000000;

        cout << "\033[1;35mRadix Sort    \033[0m/ \033[1;35m" << fixed << duration0 << setprecision(5) << "sec" << "\033[0m / ";
        testSort() ? cout << "\033[1;32mSortat cu succes!" : cout << "\033[1;31mFail";
        cout << "\033[0m" << endl;



//A patra sortare: Counting Sort
        for(int j = 0; j < n; j++) 
            v[j] = victor[j];

        start0 = high_resolution_clock::now();
        CountingSort(n, maxi);
        stop0 = high_resolution_clock::now();

        duration0 = duration_cast<microseconds>(stop0 - start0).count() /1000000.00000000000000;

        cout << "Counting Sort / " << fixed << duration0 << setprecision(5) << "sec" << " / ";
        testSort() ? cout << "\033[1;32mSortat cu succes!" : cout << "\033[1;31mFail";
        cout << "\033[0m" << endl;



//A cincia sortare: Quick sort (cu pivot random)
        for(int j = 0; j < n; j++) 
            v[j] = victor[j];

        start0 = high_resolution_clock::now();
        QuickSort(0, n - 1);
        stop0 = high_resolution_clock::now();

        duration0 = duration_cast<microseconds>(stop0 - start0).count() /1000000.00000000000000;

        cout << "\033[1;35mQuick Sort    \033[0m/ \033[1;35m" << fixed << duration0 << setprecision(5) << "sec" << "\033[0m / ";
        testSort() ? cout << "\033[1;32mSortat cu succes!" : cout << "\033[1;31mFail";
        cout << "\033[0m" << endl;
    
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

int partitie(int st, int dr) {
    int pivot = v[dr], i = st - 1, aux;

    for(int j = st; j < dr; j++) 
        if( v[j] <= pivot ) {
            i++;

            aux = v[i];
            v[i] = v[j];
            v[j] = aux;
        }
    
    aux = v[i + 1];
    v[i + 1] = v[dr];
    v[dr] = aux;
    
    return i + 1;
}

int partitieR(int st, int dr) {
    srand(time(NULL));
    int random = st + rand() % (dr - st);
    
    int aux = v[random];
    v[random] = v[dr];
    v[dr] = aux;

    return partitie(st, dr);
}

void QuickSort(int st, int dr) {
    if(st < dr) {
        int poz = partitieR(st, dr);

        QuickSort(st, poz - 1);
        QuickSort(poz + 1, dr);
    }
}


void CountingSort(int n, int maxi) {

    vector<int> fr(maxi + 2, 0);
    for(int i = 0; i < n; i++)
        fr[ v[i] ]++;

    int index = 0;
    for(int i = 0; i <= maxi; i++)
        while( fr[i] > 0 ) {
            v[index++] = i;
            fr[i]--;
        }
}

void RadixSort(int n) {
    //Pasul 1: gasim maximul din vector ca sa stim numarul de cifre.
    int m = 0;
    for(int i = 0; i < n; i++) {
        if(v[i] > m) 
            m = v[i];
    }

    //Pasul 2: Iteram cifrele numerelor folosind variabila 'exp' = 10^i,
    //unde i este indexul cifrei curente.
    //Pentru fiecare iteratie facem counting sort in functie de cifra de pe indexul curent
    for(int exp = 1; m / exp > 0; exp *= 10) {
        int i;
        vector<int> fr(10, 0);
        for(i = 0; i < n; i++) 
            fr[(v[i] / exp) % 10]++;         //crestem frecventa cifrelor


        for(i = 1; i < 10; i++)                 //modificam 'fr' astfel incat sa retina ultima poz in 'w'
            fr[i] += fr[i - 1];           //pentru numerele cu aceeasi cifra pe indexul curent

            
        for(i = n - 1; i >= 0; i--) {
            w[ fr[(v[i] / exp) % 10] - 1 ] = v[i];     //modificam w corespunzator si apoi il copiem in v
             fr[(v[i] / exp) % 10]--;
        }
        
        for(i = 0; i < n; i++)
            v[i] = w[i];
    }

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