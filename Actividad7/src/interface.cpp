#include "interface.hpp"
#include <iostream>
#include <chrono>
#include <random>
#include <functional>

using namespace std;
using namespace chrono;



Interface::Interface(List<Integer>& l) : listRef(&l) {
    default_random_engine generator(system_clock::now().time_since_epoch().count());
    uniform_int_distribution<int> distribution(0, 1000000);
    auto randomInt = bind(distribution, generator);

    //Relleno de Lista
    int i(0);
    Integer entero;
    
    while(i<10000){
        entero = randomInt();
        listRef->insertData(this->listRef->getLastPos(), entero);
        i++;
    }

    //listRef->toString();
    //Ordenamientos

    List<Integer> aux;
    double time;
    if(aux.isSorted())cout<<"Esta ordenada."<<endl;
    else cout<<"No esta ordenada."<< endl << endl;
    
    
{
    // BubbleSort (mejorada):
    aux = *listRef;
    auto startB = high_resolution_clock::now();
    
    aux.sortDataBubble();
    //aux.toString();
    auto stopB = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stopB - startB);
    time = duration.count() / 1000000.0;
    
    cout << "Bubble Sort tomo: " << time << " segundos." << endl;

    if(aux.isSorted())cout<<"Esta ordenada."<<endl;
    else cout<<"No esta ordenada."<< endl << endl;
}
    


{
    // InsertSort
    
    aux = *listRef;
    auto start = high_resolution_clock::now();
    
    aux.sortDataInsert();
    //aux.toString();
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    time = duration.count() / 1000000.0;
    
    cout << "Insert Sort tomo: " << time << " segundos." << endl;
    if(aux.isSorted())cout<<"Esta ordenada."<<endl;
    else cout<<"No esta ordenada."<< endl << endl;
}

{
    // SelectSort
    
    aux = *listRef;
    auto start = high_resolution_clock::now();
    
    aux.sortDataSelect();
    //aux.toString();
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    time = duration.count() / 1000000.0;
    
    cout << "Select Sort tomo: " << time << " segundos." << endl;
    if(aux.isSorted())cout<<"Esta ordenada."<<endl;
    else cout<<"No esta ordenada."<< endl << endl;
}

{
    // ShellSort
    
    aux = *listRef;
    auto start = high_resolution_clock::now();
    
    aux.sortDataShellFactor();
    //aux.toString();
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    time = duration.count() / 1000000.0;
    
    cout << "Shell Sort tomo: " << time << " segundos." << endl;
    if(aux.isSorted())cout<<"Esta ordenada."<<endl;
    else cout<<"No esta ordenada."<< endl << endl;
}
    


{

    // MergeSort
    
    aux = *listRef;
    auto start = high_resolution_clock::now();
    
    aux.sortDataMerge();
    
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    double time = duration.count() / 1000000.0;
    
    cout << "Merge Sort tomo: " << time << " segundos." << endl;
    if(aux.isSorted())cout<<"Esta ordenada."<<endl;
    else cout<<"No esta ordenada."<< endl << endl;
}

{
    // QuickSort
    
    aux = *listRef;
    auto start = high_resolution_clock::now();
    
    aux.sortDataQuick();
    
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    double time = duration.count() / 1000000.0;
    
    cout << "Quick Sort tomo: " << time << " segundos." << endl;
    if(aux.isSorted())cout<<"Esta ordenada."<<endl;
    else cout<<"No esta ordenada."<< endl << endl;
}




    getchar();
}
