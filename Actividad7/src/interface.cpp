#include "interface.hpp"
#include <iostream>
#include <chrono>
#include <time.h>
#include <random>
#include <ctime>
#include <functional>

using namespace std;
using namespace chrono;


Interface::Interface(){
    default_random_engine generator(system_clock::now().time_since_epoch().count());
    uniform_int_distribution<int> distribution(0, 1000000);
    auto randomInt = bind(distribution, generator);
    //int randomInt = distribution(generator);
    //auto randomInt = [&]() { return distribution(generator); };

    //Relleno de Lista
    int i(0);
    Integer entero;
    while(i<100000){
        entero = randomInt();
        //entero = distribution(generator);
        integers.insertData(this->integers.getLastPos()+1, entero);
    }

    //Ordenamientos
    unsigned t0, t1;
    double time;

    List<Integer,1000000> aux;
    // BubbleSort (mejorada):
    aux = this->integers;
    t0 = clock();
    
    aux.sortDataBubble();

    t1 = clock();
    time = (double(t1-t0) / CLOCKS_PER_SEC);
    cout << "Bubble Sort tomo: " << time << " segundos." << endl;
    // InsertSort
    // SelectSort
    // ShellSort
    // MergeSort
    // QuickSort



    getchar();
}
