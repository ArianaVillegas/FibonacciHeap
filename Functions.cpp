#include <bits/stdc++.h>

template<typename T>
long double dist(vector<T> a, vector<T> b){
	if(a.size()!=b.size()) return -1;
	long double d = 0;
	int size = a.size();
	for(int i=0; i<size; i++){
		d += (b[i]-a[i])*(b[i]-a[i]);
	}
	return sqrt(d);
}