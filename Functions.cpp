#include <bits/stdc++.h>

template<class T>
long double distEucledian(vector<T> &a, vector<T> &b){
	if(a.size()!=b.size()) return -1;
	long double d = 0;
	int size = a.size();
	for(int i=0; i<size; i++){
		d += (b[i]-a[i])*(b[i]-a[i]);
	}
	return sqrt(d);
}

template<class T>
long double distManhattan(vector<T> &a, vector<T> &b){
	if(a.size()!=b.size()) return -1;
	long double d = 0;
	int size = a.size();
	for(int i=0; i<size; i++){
		d += abs(b[i]-a[i]);
	}
	return d;
}

template<class T>
long double distChebyshev(vector<T> &a, vector<T> &b){
	if(a.size()!=b.size()) return -1;
	long double d = 0;
	int size = a.size();
	for(int i=0; i<size; i++){
		d = max(d,abs(b[i]-a[i]));
	}
	return d;
}
