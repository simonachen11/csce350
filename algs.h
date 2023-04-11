#ifndef ALGS_H
#define ALGS_H

#include <algorithm>
#include <queue>
#include <string>
using std::swap;
using namespace std;


template<typename T>
void heapsort(std::vector<T>& V){
  std::vector<T> tmp; 
	std::priority_queue<T,vector<T>,greater<T>>q; 
	for (auto x : V) {
		q.push(x); 
	}
	while (!q.empty()) {
		auto t = q.top();
		tmp.push_back(t); 
		q.pop(); 
	}
	V = tmp; 
}

int charToInt(char c) {
    return c - 'A';
}


bool are_anagrams(std::string s1, std::string s2){
   if (s1.length() != s2.length()) {
        return false;
    }
     std::array<int, 26> freq1{};
    std::array<int, 26> freq2{};

    for (char c : s1) {
        freq1[charToInt(c)]++;
    }

    // Iterate through each character in the second string and increment its frequency in the array
    for (char c : s2) {
        freq2[charToInt(c)]++;
    }

    // Compare the two arrays. If they are different, the strings are not anagrams
    return freq1 == freq2;
}


#endif
