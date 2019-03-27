#ifndef FUNH_H;
#define FUNH_H
#include <iostream>
#include <vector>
#include <time.h>
using namespace std;

vector<int> dodaj(vector<int>, bool flag, int a = 0, int b = 100, int n = 5);

void ispis(vector<int>);

vector<int> sortiraj(vector<int>);

int binarySearch(vector<int> v2, int l, int r, int x);

vector<int> novi_vec(vector<int> v1, vector<int> v2, vector<int> novi);

#endif;