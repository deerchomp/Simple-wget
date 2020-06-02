#include <iostream>
#include <unistd.h>
#include <fstream>
#include <string>
#include <vector>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
using namespace std;

void wget(vector<string>& urls) {
	pid_t pid;
	for (vector<string>::iterator urlIt = urls.begin(); urlIt != urls.end(); ++urlIt)
	{
		pid = fork();
		if (pid < 0)
		{
			perror("fork:");
			exit(1);
		}

		if (pid == 0)
		{
			if (execlp("/usr/bin/wget", "child", urlIt->c_str(), NULL) < 0)
			{
				cout <<
				perror("execlp");
				exit(1);	
			}
		}
}

void consolidateURL(vector<string>& urls) {
        ifstream url_file("test.txt");
        string url = "null";
        if (!url_file.is_open()) {
                cout << "Failed to open file"  << endl;
                exit(1);
        }
        while(getline(url_file, url)) {
			cout << "Pushing " << url << " onto vector.." << endl;
            urls.push_back(url);
			cout << "Success" << endl;
        }

        url_file.close();
}

int main() {
        vector<string> URL;
        consolidateURL(URL);
        wget(URL);
        return 0;
}
