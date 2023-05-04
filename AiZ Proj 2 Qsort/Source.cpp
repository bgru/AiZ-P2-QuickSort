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

//int partitionMedian(vector<int>& tab, int left, int right, int median) {
//    //pivot is a median of int median elements
//    //only
//    cout << "Starting tab: \n";
//    for (int i : tab) {
//        cout << i << " ";
//    }
//    cout << '\n';
//    int pivot = 0;
//    int moves = 0;
//    cout << "Left is " << left << '\n';
//    cout << "Right is " << right << '\n';
//    cout << "Number of median elements " << median << '\n';
//
//    vector<int> medianTab(median);  // vector that will hold indexes
//
//    //choose the positions in vector based on int median
//    int section = right - left;     // example: if section == 3, then the subarray for partition has 4 elements. their indexes depend on int right and int left 
//    if (median < 3) {   // if median == 0 or 1 it is an input error, if it's 2 then pivot is (resonably speaking) the last or the first element, chosen randomly - won't bother coding that.
//        cout << "Cannot calculate median based on " << median << " element/s, so pivot will always be the first element in the partitioned array\n";
//        pivot = left;   // just a safeguard, could technically just throw a runtime error too
//        cout << "Pivot is " << pivot << '\n';
//    }
//    else if (section+1 < median) {  // read the cout's
//        cout << "Cannot calculate median based on " << median << " elements, because the partitioned array size is " << section << "\n";
//        cout << "Pivot will be the first element in the partitioned array instead\n";
//        pivot = left;
//        cout << "Pivot is " << pivot << '\n';
//    }
//    else {
//        cout << "Calculating median based on " << median << " elements\n";
//        medianTab[0] = left;    // first element
//        double tempMedian = median;    //idk why this is needed lol
//        int sum = 0;
//        double divider = round((section / 1.0) / (tempMedian - 1));    // take the result and always round it. 15/4 = 4, 14/4 = 4, 13/4=3;
//        cout << "divider is " << divider << '\n';
//        for (int i = 1; i < median - 1; ++i) {
//            sum += divider;                                     //This simplification is here so any int median value can be accepted, both even and odd values work.
//            medianTab[i] = sum + left;    // Very important that +left is here !
//        }                                                       // For section = 14 and median = 5, (0,4,8,12,14)
//        medianTab[medianTab.size() - 1] = right; // last element          // For section = 13 and median = 5, (0,3,6,9,13)    
//                                                                //Not the most precise but good enough to extablish a reliable pivot
//        cout << "Contents of MedianTab\n";
//        for (int i : medianTab) {
//            cout << i << " ";
//        }
//
//            // as of now, we have an vector filled with indexes (i am aware that this can be done smarter and quicker but it's already hard to understand already)
//            // the smaller the median the faster this will execute.
//     // Since my sollution accepts any median, not just 3,5,7 this can't be done with the use multiple IF's. To sort the values and extract the median we will use... QuickSortRand and pointers.
//
//     // First we fill 'medianValueTab' with values of 'tab' with 'medianTab' index 
//     // Having a vector filled with values, now we need pointesr of those values. 
//        
//        vector<int> medianValueTab(median);         // Create a vector for values
//        vector<int*> pointerTab(median);            // Create a vector for pointers
//
//        for (int i = 0; i < median; ++i) {
//            medianValueTab[i] = tab[medianTab[i]];  // filling vector with new values
//
//            pointerTab[i] = &medianValueTab[i];     // Assign the adress of each value from 'medianValueTab' to the 'pointerTab' so we can cross referece the adress later 
//        }
//        cout << "\nMedian Value Tab before sorting: \n";
//
//        for (int i : medianValueTab) {
//            cout << i << " ";
//        }
//        cout << "\nMedian Value Tab AFTER sorting: \n";
//
//        QuickSortRand(medianValueTab, 0, medianValueTab.size() - 1);    // Now we can sort the 'medianValueTab'
//
//        for (int i : medianValueTab) {
//            cout << i << " ";
//        }
//        cout << '\n';
//
//        // since pivot IS NOT a median value from now sorted 'medianValueTab' but a POSITION of that value in a 'tab' vector (basically that value's index from 'medianTab'),
//        // we need pointers to decipher that position (or index). We already have sorted pointers, each pointing to a value now sorted 'medianValueTab'.
//
//        int* medianAdress = nullptr;
//        // now that the values are sorted, there are two options:
//
//        if (median % 2 == 0) {       // median is an even number, note that since there are technically 2 optimal pivots, we pick ONE, RANDOMLY!
//            cout << "Calculating median based on an EVEN NUMBER, randomly picking one pivot from 2 possible cases\n";
//            int temp = median / 2;              // if median == 4, then from 0, 1, 2, 3 pivot is either 1 or 2
//            if (rand() % 2 == 0) { // 
//                medianAdress = &medianValueTab[temp];   // case 1
//                cout << "Picked case nr 1\n";
//            }                                   
//            else{
//                medianAdress = &medianValueTab[temp-1]; // case 2
//                cout << "Picked case nr 2\n";
//            }
//        }
//        else {                                      // median is an odd number, so pivot is in the middle of the vector                           
//            cout << "Calculating median based on an ODD NUMBER, only one possible outcome\n";
//            int temp = (median - 1) / 2;        
//            medianAdress = &medianValueTab[temp];           // if median == 5, then from 0, 1, 2, 3, 4, 5 pivot is 2
//        }
//
//        // Now with each iteration we check if medianAdress matches an adress from 'pointerTab'
//        for (int i = 0; i < median; ++i) {
//            if (medianAdress == pointerTab[i]) {    // if it does, then since
//                pivot = medianTab[i];               // pointerTab[i], medianTab[i] and medianValueTab[i] all shared the same 'i' iterator we can deduct the position of pivot
//                cout << "Median Value is " << *medianAdress << " and it's position in array is " << medianTab[i] << " therefore: \n";
//                
//                break;                              
//            }
//        }
//
//
//
//    }                                                           
//
//    cout << "Pivot (raw) is: " << pivot << '\n';
//    cout << "Pivot is: " << tab[pivot] << '\n';
//    int pivotSwap = right;
//
//    if (pivot != right) { swap(tab[pivot], tab[right]); cout << "Swapped pivot\n"; } // if pivot isn't last already, put in at the end
//    right--; // since pivot is the last element, right border is decremented
//    moves++; //technically a move too 
//
//    cout << "After pivot swap:\n";
//    for (int i : tab) {
//        cout << i << " ";
//    }
//    cout << '\n';
//    cout << "Now right is: " << right << '\n';
//
//    //partition
//    while (left < right) {
//        while (tab[left] < tab[pivotSwap] && left < right) { ++left; }
//        // <= means to the left of pivot will be smaller and equal, to the right bigger
//        // < means to the left of pivot will be smaller, to the right bigger and equal
//        while (tab[right] > tab[pivotSwap] && right > left) { --right; }
//
//        if (left < right) {
//            cout << "Swapping " << tab[left] << " with " << tab[right] << '\n';
//            swap(tab[left], tab[right]);
//            moves++;
//        }
//    }
//
//    cout << "After partition: \n";
//    for (int i : tab) {
//        cout << i << " ";
//    }
//    cout << "\nLeft is " << tab[left] << '\n';
//    cout << "Left (raw) is " << left << '\n';
//    cout << "IF Statement now\n";
//
//    if (tab[left] > tab[pivotSwap]) {                  // when pivot is not the largest element in array
//        cout << "Left is " << tab[left] << '\n';
//        cout << "Left (raw) is " << left << '\n';
//        cout << "Pivot is NOT the largest element in the array\n";
//        cout << "Swapped " << moves << " times\n";
//        moves++;        // Cause swapping left with pivotswap
//        //swap(tab[left], tab[pivot]); // ur retarded its wrong
//        swap(tab[left], tab[pivotSwap]);
//
//        cout << "Final tab: \n";
//        for (int i : tab) {
//            cout << i << " ";
//        }
//        cout << '\n';
//        cout << '\n';
//        cout << '\n';
//
//        return left;        // returning the final position of pivot in the array
//    }
//    else
//    {
//        cout << "Pivot is the largest element in the array, moved " << moves << " times\n";
//        cout << "Left is " << tab[left] << '\n';
//        cout << "Left (raw) is " << left << '\n';
//
//        cout << "Final tab: \n";
//        for (int i : tab) {
//            cout << i << " ";
//        }
//        cout << '\n';
//        cout << '\n';
//        cout << '\n';
//
//        return pivotSwap;   // returning the final position of pivot in the array - specifically at the very end of.
//    }
//}

int main() {

    srand(time(0));

    ofstream WynikiMedian16("WynikiMedian16.txt");
    ofstream WynikiMedian12("WynikiMedian12.txt");
    ofstream WynikiMedian9("WynikiMedian9.txt");
    ofstream WynikiMedian7("WynikiMedian7.txt");
    ofstream WynikiMedian5("WynikiMedian5.txt");
    ofstream WynikiMedian3("WynikiMedian3.txt");
    ofstream WynikiRand("WynikiRand.txt");
    ofstream WynikiEdge("WynikiEdge.txt");

    // important order in fuction parameters! 
    // (std::ofstream& Wyniki, int medianNumbers)!
        //name of file              0< == Median sort, -1 == EdgeSort, -2 == RandSort, any other == error 

    //SortLarger(WynikiEdge, -1);       // same as below but with pivot as rightmost element
    //SortRandom(WynikiEdge, -1);
    //SortSorted(WynikiEdge, -1);   

    //SortLarger(WynikiRand, -2);       // number larger than size of array with Random Pivot
    //SortRandom(WynikiRand, -2);       // array with numbers 0-99 with random pivot
    //SortSorted(WynikiRand, -2);       // sorted tab the size of array with random pivot

    //SortLarger(WynikiMedian3, 3);     // same as above but with pivot chosen on median of 3
    //SortRandom(WynikiMedian3, 3);
    //SortSorted(WynikiMedian3, 3);

    SortLarger(WynikiMedian5, 5);     // same as above but with pivot chosen on median of 5
    SortRandom(WynikiMedian5, 5);
    SortSorted(WynikiMedian5, 5);

    //SortLarger(WynikiMedian7, 7);       // ... gues what
    //SortRandom(WynikiMedian7, 7);
    //SortSorted(WynikiMedian7, 7);

    //SortLarger(WynikiMedian9, 9);
    //SortRandom(WynikiMedian9, 9);
    //SortSorted(WynikiMedian9, 9);

    //SortLarger(WynikiMedian12, 12);
    //SortRandom(WynikiMedian12, 12);
    //SortSorted(WynikiMedian12, 12);

    //SortLarger(WynikiMedian16, 16);
    //SortRandom(WynikiMedian16, 16);
    //SortSorted(WynikiMedian16, 16);


//    WynikiMedian << "Results for case: numbers larger than tab size\n";
//    WynikiRand << "Results for case: numbers larger than tab size\n";
//    WynikiEdge << "Results for case: numbers larger than tab size\n";
//
//    for (int i = 10000; i <= 20000; i += 10000) {
//        cout <<'\n' << '\n' << "The tab size is: " << i << '\n' << '\n';
//        WynikiMedian << i << " ";
//        WynikiRand << i << " ";
//        WynikiEdge << i << " ";
//        uniform_int_distribution<int> dist{ i+1, 30000};
//
//        auto gen = [&dist, &mersenne_engine]() {
//            return dist(mersenne_engine);
//        };
//
//        vector<int> tabTest(i);
//
//        //QuickSortEdge(tabTest, 0, tabTest.size() - 1);
//        //QuickSortRand(tabTest, 0, tabTest.size() - 1);
//        //QuickSortMedian(tabTest, 0, tabTest.size() - 1, 3);
//
//        int timeResult = 0;
//
//        generate(begin(tabTest), end(tabTest), gen);
//        // Quick Sort Median
//        cout << "\nSorting with Median\n";
//        auto start = high_resolution_clock::now();  // TIME START
//        QuickSortMedian(tabTest, 0, tabTest.size() - 1, 3);
//        auto stop = high_resolution_clock::now();   // TIME STOP
//
//        auto duration = duration_cast<nanoseconds>(stop - start);
//        cout << '\n' << '\n' << "czas wykonywania " << duration.count() << '\n' << '\n';
//        timeResult = duration.count();
//        WynikiMedian << timeResult << '\n';
//        timeResult = 0;
//
//
//
//        generate(begin(tabTest), end(tabTest), gen);
//        // Quick Sort Rand
//        cout << "\nSorting with Rand\n";
//        start = high_resolution_clock::now();  // TIME START
//        QuickSortRand(tabTest, 0, tabTest.size() - 1);
//        stop = high_resolution_clock::now();   // TIME STOP
//
//        duration = duration_cast<nanoseconds>(stop - start);
//        cout << '\n' << '\n' << "czas wykonywania " << duration.count() << '\n' << '\n';
//        timeResult = duration.count();
//        WynikiRand << timeResult << '\n';
//        timeResult = 0;
//
//
//
//        generate(begin(tabTest), end(tabTest), gen);
//        // Quick Sort Edge
//        cout << "\nSorting with Edge\n";
//        start = high_resolution_clock::now();  // TIME START
//        QuickSortEdge(tabTest, 0, tabTest.size() - 1);
//        stop = high_resolution_clock::now();   // TIME STOP
//
//        duration = duration_cast<nanoseconds>(stop - start);
//        cout << '\n' << '\n' << "czas wykonywania " << duration.count() << '\n' << '\n';
//        timeResult = duration.count();
//        WynikiEdge << timeResult << '\n';
//        timeResult = 0;
//
//
//         //cout << "Final tab: \n";
//         //for (int i : tabTest) {
//         //    cout << i << " ";
//         //}
//
//         //for (int i = 0; i < tabTest.size() - 1; ++i) {
//         //   if (tabTest[i] > tabTest[i + 1]) {
//         //       cout << "\nYou messed up bro\n";
//         //   }
//         //}
//    }
//
//
//    //generate(begin(tabTest), end(tabTest), gen);
//    // 
//    //generate(begin(tab2), end(tab2), gen);
//    //vector<int> tab2(1000000);
//
//    //int wynik = 0;
//    //vector<int> tab = { 12, 14, 34, 456, 786, 1123, 1234, 1444, 1444, 1444, 1444, 1444, 1445, 6969, 420420 };
//    //cout << "Size of generated vector is " << tab2.size() << '\n';
//
//    //vector<int> tab = { 1, 9, 8, 7, 6, 5, 4, 3, 2, 10 };
//    //QuickSortEdge(tab2, 0, tab2.size()-1);
//    //QuickSortRand(tab, 0, tab.size() - 1);
//    //QuickSortMedian(tab, 0, tab.size() - 1, 3);
//
//
//
//    //cout << "Final tab: \n";
//    //for (int i : tab) {
//    //    cout << i << " ";
//    //}
//    cout << '\n';
//    cout << '\n';

    return 0;
}

//Badanie proszê przeprowadziæ dla tablic o
//rosn¹cych rozmiarach od 10 000 do 1000 000 elementów(co 10 000) i trzech
//przypadków ich wype³niania :
//
//elementami pseudolosowymi z zakresu przekraczaj¹cego rozmiar tablicy;
//elementami pseudolosowymi z zakresu 0..99;
//elementami uporz¹dkowanymi niemalej¹co.