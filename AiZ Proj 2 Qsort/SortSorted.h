#pragma once
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <random>
#include <stdlib.h>     /* srand, rand */
#include <time.h>   
#include <cmath>
#include "partEdge.h"
#include "partMedian.h"
#include "partRand.h"
#include "SortSorted.h"
#include "SortLarger.h"
#include "SortRandom.h"
#include <chrono>


using namespace std::chrono;
using namespace std;

void SortedVectorGenerate(vector<int> &tab, int size) { // 0 0 2 2 4 4 6 6 8 8 (not decresing numbers)                                              // 0 1 2 3 4 5 6 7 8 9
    for (int i = 0; i < size; i=i+2) {
        tab[i] = i;
        tab[i + 1] = i;
    }
    //cout << "ostatni element " << tab[size-1];
 }

void SortSorted(std::ofstream& Wyniki, int medianNumbers) {

    Wyniki << "\nResults for case: numbers are sorted\n";
    cout << "Sorting with SortSorted\n";


    for (int i = 10000; i <= 1000000; i += 10000) {
        cout << "The tab size is: " << i;
        Wyniki << i << " ";

        //QuickSortEdge(tabTest, 0, tabTest.size() - 1);
        //QuickSortRand(tabTest, 0, tabTest.size() - 1);
        //QuickSortMedian(tabTest, 0, tabTest.size() - 1, 3);

        vector<int> tabTest(i);
        long long int timeResult = 0;
        SortedVectorGenerate(tabTest, i);

        if (medianNumbers > 0) {
            // Quick Sort Median
            cout << "\nSorting with Median\n";
            auto start = high_resolution_clock::now();  // TIME START
            QuickSortMedian(tabTest, 0, tabTest.size() - 1, medianNumbers);
            auto stop = high_resolution_clock::now();   // TIME STOP

            auto duration = duration_cast<nanoseconds>(stop - start);
            cout << '\n' << '\n' << "czas wykonywania " << duration.count() << '\n' << '\n';
            timeResult = duration.count();
            Wyniki << timeResult << '\n';
            timeResult = 0;
        }
        else if (medianNumbers == -1) {
            // Quick Sort Edge
            cout << "\nSorting with Edge\n";
            auto start = high_resolution_clock::now();  // TIME START
            QuickSortEdge(tabTest, 0, tabTest.size() - 1);
            auto stop = high_resolution_clock::now();   // TIME STOP

            auto duration = duration_cast<nanoseconds>(stop - start);
            cout << '\n' << '\n' << "czas wykonywania " << duration.count() << '\n' << '\n';
            timeResult = duration.count();
            Wyniki << timeResult << '\n';
            timeResult = 0;

        }
        else if (medianNumbers == -2) {
            // Quick Sort Rand
            cout << "\nSorting with Rand\n";
            auto start = high_resolution_clock::now();  // TIME START
            QuickSortRand(tabTest, 0, tabTest.size() - 1);
            auto stop = high_resolution_clock::now();   // TIME STOP

            auto duration = duration_cast<nanoseconds>(stop - start);
            cout << '\n' << '\n' << "czas wykonywania " << duration.count() << '\n' << '\n';
            timeResult = duration.count();
            Wyniki << timeResult << '\n';
            timeResult = 0;

        }
        else {
            cout << "\nMedian numbers incorrect! Either -1 or -2 for Edge and Rand or 0< for Median\n";
        }
    }
}
