#pragma once
#include <iostream>
#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <random>
#include <stdlib.h>     /* srand, rand */
#include <time.h>   
#include <cmath>

using namespace std;

int partitionRand(vector<int>& tab, int left, int right) {
    //pivot is chosen randomly
    //cout << "Starting tab: \n";
    //for (int i : tab) {
    //    cout << i << " ";
    //}
    //cout << '\n';

    int pivot = (rand() % (right - left + 1)) + left; //choose pivot
    int moves = 0;
    //cout << "Left is " << left << '\n';
    //cout << "Right is " << right << '\n';
    //cout << "Pivot (raw) is: " << pivot << '\n';
    //cout << "Pivot is: " << tab[pivot] << '\n';
    int pivotSwap = right;
    if (pivot != right) { swap(tab[pivot], tab[right]); } // if pivot isn't last already, put in at the end
    right--; // since pivot is the last element, right border is decremented
    moves++; //technically a move too 

    //cout << "After pivot swap:\n";
    //for (int i : tab) {
    //    cout << i << " ";
    //}
    //cout << '\n';
    //cout << "Now right is: " << right << '\n';

    //partition
    while (left < right) {
        while (tab[left] <= tab[pivotSwap] && left < right) { ++left; }
        // <= means to the left of pivot will be smaller and equal, to the right bigger
        // < means to the left of pivot will be smaller, to the right bigger and equal
        while (tab[right] >= tab[pivotSwap] && right > left) { --right; }

        if (left < right) {
            //cout << "Swapping " << tab[left] << " with " << tab[right] << '\n';
            swap(tab[left], tab[right]);
            moves++;
        }
    }

    //cout << "After partition: \n";
    //for (int i : tab) {
    //    cout << i << " ";
    //}
    //cout << "\nLeft is " << tab[left] << '\n';
    //cout << "Left (raw) is " << left << '\n';
    //cout << "IF Statement now\n";

    if (tab[left] >= tab[pivotSwap]) {                  // when pivot is not the largest element in array
        //cout << "Left is " << tab[left] << '\n';
        //cout << "Left (raw) is " << left << '\n';
        //cout << "Pivot is NOT the largest element in the array\n";
        //cout << "Swapped " << moves << " times\n";
        moves++;        // Cause swapping left with pivotswap
        //swap(tab[left], tab[pivot]); // ur retarded its wrong
        swap(tab[left], tab[pivotSwap]);

        //cout << "Final tab: \n";
        //for (int i : tab) {
        //    cout << i << " ";
        //}
        //cout << '\n';
        //cout << '\n';

        return left;
    }
    else
    {
        //cout << "Pivot is the largest element in the array, moved " << moves << " times\n";
        //cout << "Left is " << tab[left] << '\n';
        //cout << "Left (raw) is " << left << '\n';

        //cout << "Final tab: \n";
        //for (int i : tab) {
        //    cout << i << " ";
        //}
        //cout << '\n';
        //cout << '\n';

        return pivotSwap;
    }
}

void QuickSortRand(vector<int>& tab, int left, int right) {
    int n;
    if (left < right) {
        n = partitionRand(tab, left, right);
        QuickSortRand(tab, left, n - 1);
        QuickSortRand(tab, n + 1, right);
    }
}
