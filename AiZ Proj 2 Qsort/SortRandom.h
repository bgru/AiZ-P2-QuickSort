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

void SortRandom(std::ofstream& Wyniki, int medianNumbers) {

    // First create an instance of an engine.
    random_device rnd_device;
    // Specify the engine and distribution.
    mt19937 mersenne_engine{ rnd_device() };  // Generates random integers
    //uniform_int_distribution<int> dist{ 0, 1000 };

    Wyniki << "\nResults for case: numbers are random from 0-99\n";
    cout << "Sorting with SortRandom\n";


    for (int i = 10000; i <= 1000000; i += 10000) {
        cout << "The tab size is: " << i;
        Wyniki << i << " ";

        uniform_int_distribution<int> dist{ 0,99 };

        auto gen = [&dist, &mersenne_engine]() {
            return dist(mersenne_engine);
        };


        //QuickSortEdge(tabTest, 0, tabTest.size() - 1);
        //QuickSortRand(tabTest, 0, tabTest.size() - 1);
        //QuickSortMedian(tabTest, 0, tabTest.size() - 1, 3);

        vector<int> tabTest(i);
        long long int timeResult = 0;
        generate(begin(tabTest), end(tabTest), gen);

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
