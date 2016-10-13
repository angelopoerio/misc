/*
	Print all palindrome substrings - Angelo Poerio <angelo.poerio@gmail.com>
*/

#include <set>
#include <string>
#include <iostream>
#include <stdio.h>

using namespace std;

std::set<string> all_palindromes(string st)  {
	std::set<string> palindromes;
	int str_size = st.size();
	for(int idx = 0; idx < str_size;idx++) {
		int start = idx - 1,end = idx + 1;
		while(start >= 0 && end < str_size && st.at(start) == st.at(end)) {
			palindromes.insert(st.substr(start,(end - start) + 1));
			start--;
			end++;
		}
		start = idx, end = idx + 1;
		while(start >= 0 && end < str_size && st.at(start) == st.at(end)) {
			palindromes.insert(st.substr(start, (end - start) + 1));
                        start--;
                        end++;
		}

	}
	return palindromes;
}

void print_palindromes(string str) {
	std::set<string> vv = all_palindromes(str);
	for(std::set<string>::iterator it = vv.begin();it != vv.end();++it) 
		cout << *it << '\n';
}

int main(int argc,char *argv[]) {
	if(argc < 1) {
		return 1;
	}

	for(int i = 1;i < argc;i++) {
		cout << "palindromes for " << argv[i];
		print_palindromes(argv[i]);
	}

	return 0;
}
