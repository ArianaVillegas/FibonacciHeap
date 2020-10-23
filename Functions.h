#include <bits/stdc++.h>

template<class T>
float distEucledian(vector<T> &a, vector<T> &b){
	if(a.size()!=b.size()) return -1;
	float d = 0;
	int size = a.size();
	for(int i=0; i<size; i++){
		d += (b[i]-a[i])*(b[i]-a[i]);
	}
	return sqrt(d);
}

template<class T>
float distManhattan(vector<T> &a, vector<T> &b){
	if(a.size()!=b.size()) return -1;
	float d = 0;
	int size = a.size();
	for(int i=0; i<size; i++){
		d += abs(b[i]-a[i]);
	}
	return d;
}

template<class T>
float distChebyshev(vector<T> &a, vector<T> &b){
	if(a.size()!=b.size()) return -1;
	float d = 0;
	int size = a.size();
	for(int i=0; i<size; i++){
		d = max(d,abs(b[i]-a[i]));
	}
	return d;
}
