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

int partitionEdge(vector<int>& tab, int left, int right) {

    //for (int i : tab) {
    //    cout << i << " ";
    //}
    //cout << '\n';

    int pivot = right--;
    int moves = 0;
    //cout << "Left is " << left << '\n';
    //cout << "Right is " << right << '\n';
    //cout << "Pivot (raw) is: " << pivot << '\n';
    //cout << "Pivot is: " << tab[pivot] << '\n';
    while (left < right) {
        while (tab[left] <= tab[pivot] && left < right) { ++left; }
        // <= means to the left of pivot will be smaller and equal, to the right bigger
        // < means to the left of pivot will be smaller, to the right bigger and equal
        while (tab[right] >= tab[pivot] && right > left) { --right; }

        if (left < right && tab[left] != tab[pivot] && tab[right] != tab[pivot]) {                              //modyfikacja funkcji partition losowo
               //cout << "Swapping " << tab[left] << " with " << tab[right] << '\n';
               swap(tab[left], tab[right]);
               moves++;
        }
        else if (left < right){
            int temp = rand() % 2;
            //cout << temp << '\n';
            if (temp== 1) {
                //cout << "Case 1 - Swapping " << tab[left] << " with " << tab[right] << '\n';
                swap(tab[left], tab[right]);
                moves++;
            }
            else {
                //cout << "Case 2 - Not swapping\n";
            }
        }
    }


    if (tab[left] >= tab[pivot]) {                  // when pivot is not the largest element in array
        moves++;
        //cout << "Swapped " << moves << " times\n";
        swap(tab[left], tab[pivot]);

        //for (int i : tab) {
        //    cout << i << " ";
        //}
        //cout << '\n';
        //cout << '\n';

        return left;
    }
    else {                                          // when pivot IS the largest element in the array
        //cout << "Pivot is the largest element in the array, moved " << moves << " times\n";
        //for (int i : tab) {
        //    cout << i << " ";
        //}
        //cout << '\n';
        //cout << '\n';

        return pivot;
    }

}

void QuickSortEdge(vector<int>& tab, int left, int right) {
    int n;
    while (left < right) {
        n = partitionEdge(tab, left, right);
        if (n - left < right - n) {
            QuickSortEdge(tab, left, n - 1);
            left = n + 1;
        }
        else {
            QuickSortEdge(tab, n + 1, right);
            right = n - 1;
        }
    }
}