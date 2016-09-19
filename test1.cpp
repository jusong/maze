#include <iostream>
#include <vector>

#include "common.h"

using namespace std;

int main(void) {
	string str = "adsfasdf\nsdfasdf\n\nsdfsdf\nasdfasdf";
	//vector<string> v = Common::split(str, "\n");
	//for(string l : v) {
	for(auto l : Common::split(str, "\n")) {
		cout << l << endl;
	}
	return 0;
}
