#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define TAM 1000

//insert values
void inicV(int *v, int tam){

    for(int i = 0; i < TAM; i++)
        v[i] = rand() % 101;
}

//brute force
//Θ(n²)
void selectionSort(int *v, int tam){

    for(int i = 0; i < tam - 1; i++){

        int min = i;
        for(int j = i + 1; j < tam; j++){

            if(v[j] < v[min])
                min = j;
        }
        if(min != i){

            int aux = v[i];
            v[i] = v[min];
            v[min] = aux;
        }
    }
}

//brute force
//Θ(n²)
void bubbleSort(int *v, int tam){

    for(int i = 0; i < tam-1; i++){
        for(int j = 0; j < tam - 1 - i; j++){

            if(v[j+1] < v[j]){

                int aux = v[j];
                v[j] = v[j+1];
                v[j+1] = aux;
            }
        }
    }
}

//decreaser and conquer
//best -> Θ(n)
//average -> Θ(n²)
void insertionSort(int *v, int tam){

    for(int i = 1; i < tam; i++){

        int insert = v[i]; 
        int j = i - 1;
        while(j >= 0 && v[j] > insert){

            v[j+1] = v[j];
            j--;
        }
        v[j+1] = insert;
    }
}

//divide and conquer
//Θ(n logn)
void merge(int *v, int l, int r){

    int aux[r-l+1];
    for( int i = l; i <= r; i++ )
        aux[i-l] = v[i];

    int m = (l + r)/2;
    int v1 = l, v2 = m + 1;

    for( int i = l; i <= r; i++ ){

        if(v1 == m+1)
            v[i] = aux[v2++ - l];
        
        else if(v2 > r)
            v[i] = aux[v1++ - l];
        
        else if( aux[v1 - l] <= aux[v2 - l] )
            v[i] = aux[v1++ - l];
        
        else
            v[i] = aux[v2++ - l];
    }
}

void mergeSort(int *v, int l, int r){

    if(l < r){

        int m = (l + r)/2;
        mergeSort(v, l, m);
        mergeSort(v, m+1, r);
        merge(v, l, r);
    }
}

//divide and conquer
//Θ(n logn)
int hoarePartition(int *v, int l, int r){

    int i = l;
    int j = r+1;

    do{

        do i++; 
        while(v[i] < v[l] && i < r );

        do j--; 
        while(v[j] > v[l]);
            
        int aux = v[i];
        v[i] = v[j];
        v[j] = aux;

    }while(i < j);
    
    int aux = v[i];
    v[i] = v[j];
    v[j] = aux;

    aux = v[l];
    v[l] = v[j];
    v[j] = aux;

    return j;
}

void quickSort(int *v, int l, int r){

    if(l < r){

        int s = hoarePartition(v, l, r);
        cout << "i=" << s << "  S[i]=" << v[s] << "  l=" << l << "   " << "r=" << r <<  endl; 
        quickSort(v, l, s-1);
        quickSort(v, s+1, r);
    }
}


int main(){

    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    clock_t start, end;
    srand(time(NULL));

    int v[TAM];
    cout << "\n" << fixed << setprecision(6);

    inicV(v, TAM);
    start = clock();
    bubbleSort(v, TAM);
    end = clock();
    cout << setw(17) << "bubble time = " << double(end - start) / double(CLOCKS_PER_SEC) << "s" << endl;

    inicV(v, TAM);
    start = clock();
    selectionSort(v, TAM);
    end = clock();
    cout << setw(17) << "selection time = " << double(end - start) / double(CLOCKS_PER_SEC) << "s" << endl;

    inicV(v, TAM);
    start = clock();
    insertionSort(v, TAM);
    end = clock();
    cout << setw(17) << "insertion time = " << double(end - start) / double(CLOCKS_PER_SEC) << "s" << endl;

    inicV(v, TAM);
    start = clock();
    mergeSort(v, 0, TAM-1);
    end = clock();
    cout << setw(17) << "merge time = " << double(end - start) / double(CLOCKS_PER_SEC) << "s" << endl;

    v[0] = 5;
    v[1] = 16;
    v[2] = 10;
    v[3] = 12;
    v[4] = 4;
    v[5] = 17;
    v[6] = 13;
    v[7] = 18;
    start = clock();
    quickSort(v, 0, 7);
    end = clock();
    cout << setw(17) << "quick time = " << double(end - start) / double(CLOCKS_PER_SEC) << "s" << endl;

    // for(int i = 0; i < TAM; i++)
    //     cout << v[i] << " ";
    cout << endl;

    return 0;
}   