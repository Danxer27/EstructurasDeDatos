// Archivo de implementacion de la interfaz.
#include "interface.hpp"
#include <chrono>
#include <functional>
#include <iostream>
#include <random>

using namespace std;
using namespace chrono;

Interface::Interface(List<Integer, 100000>& l) : listRef(&l) {
  default_random_engine generator(
      system_clock::now().time_since_epoch().count());
  uniform_int_distribution<int> distribution(0, 1000000);
  auto randomInt = bind(distribution, generator);

  // Relleno de Lista
  int i(0);
  Integer entero;

  while (i < 100000) {
    entero = randomInt();

    try {
      listRef->insertData(this->listRef->getLastPos(), entero);
    } catch (const std::exception& e) {
      cout << e.what() << endl;
    }

    i++;
  }

     // cout << listRef->toString() << endl;
  // Ordenamientos

  List<Integer, 100000> aux;
  double time;

  aux = *listRef;

  if (aux.isSorted())
    cout << "Esta ordenada." << endl;
  else
    cout << "No esta ordenada." << endl << endl;

  {
    // BubbleSort (mejorada):
    auto startB = high_resolution_clock::now();

    aux.sortDataBubble();

    auto stopB = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stopB - startB);
    time = duration.count() / 1000000.0;

    cout << "Bubble Sort tomo: " << time << " segundos." << endl;

    if (aux.isSorted())
      cout << "Esta ordenada." << endl;
    else
      cout << "No esta ordenada." << endl << aux.toString() << endl;
  }

  {
    // InsertSort

    aux = *listRef;
    auto start = high_resolution_clock::now();

    aux.sortDataInsert();

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    time = duration.count() / 1000000.0;

    cout << "Insert Sort tomo: " << time << " segundos." << endl;
    if (aux.isSorted())
      cout << "Esta ordenada." << endl;
    else
      cout << "No esta ordenada." << endl << aux.toString() << endl;
  }

  {
    // SelectSort

    aux = *listRef;
    auto start = high_resolution_clock::now();

    aux.sortDataSelect();

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    time = duration.count() / 1000000.0;

    cout << "Select Sort tomo: " << time << " segundos." << endl;
    if (aux.isSorted())
      cout << "Esta ordenada." << endl;
    else
      cout << "No esta ordenada." << endl << aux.toString() << endl;
  }

  {
    // ShellSort

    aux = *listRef;
    auto start = high_resolution_clock::now();

    aux.sortDataShellFactor();

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    time = duration.count() / 1000000.0;

    cout << "Shell Sort tomo: " << time << " segundos." << endl;
    if (aux.isSorted())
      cout << "Esta ordenada." << endl;
    else
      cout << "No esta ordenada." << endl << aux.toString() << endl;
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
    if (aux.isSorted())
      cout << "Esta ordenada." << endl;
    else
      cout << "No esta ordenada." << endl << aux.toString() << endl;
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
    if (aux.isSorted())
      cout << "Esta ordenada." << endl;
    else
      cout << "No esta ordenada." << endl << aux.toString() << endl;
  }

  cout << "Saliendo..." << endl;

  getchar();
}
