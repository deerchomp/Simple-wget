#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

void readVectorWithIterator(vector<string>& urls) {
	for (vector<string>::iterator i = urls.begin(); i != urls.end(); ++i)
	{
		cout << i->c_str() << endl;
	}
}
void populateVectorWithURLs(vector<string>& urls) {
	ifstream file_with_url("test.txt");
	string url_buffer;
	if(!file_with_url.is_open()) {
		cout << "Failed to open file" << endl;
		exit(1);
	}

	while(getline(file_with_url, url_buffer)) {
		cout << "Pushing " << url_buffer << "onto vector..." << endl;
		urls.push_back(url_buffer);
		cout << url_buffer << " pushed onto vector" << endl;
	}
}

int main() {
	vector<string> list_of_urls;
	populateVectorWithURLs(list_of_urls);
	readVectorWithIterator(list_of_urls);
	getchar();
	return 0;
}