#include <map>
#include <vector>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>
#include <cstring>

std::vector<std::string> cantanti(std::vector<std::string> vet, std::string cantante) {
    std::vector<std::string> v;
    for (int i = 0; i < vet.size(); i++) {
        if (vet[i].rfind(cantante, 0) == 0) {
            std::string token = strtok((char *)vet[i].c_str(), "|");
            v.push_back(token);
        }
    }
    return v;
}

int main(void) {
    std::string line;
    int i = 0;
    std::vector<std::string> v;
    std::ifstream fin;
    fin.open("dataset-Spotify.txt");
    if (fin.is_open()) {
        while (getline(fin, line)) {
            std::stringstream ss(line);
            if (getline(ss, line, '\n')) {
                v.push_back(line);
            }
        }
        fin.close();
    } else {exit(1);}

    std::map<std::string, std::vector<std::string>>mappa;
    std::map<std::string, std::vector<std::string>>::iterator it;

    mappa.insert(make_pair("The Weeknd", cantanti(v, "The Weeknd")));
    mappa.insert(make_pair("Lady Gaga", cantanti(v, "Lady Gaga")));
    mappa.insert(make_pair("Queen", cantanti(v, "Queen")));
    mappa.insert(make_pair("Oasis", cantanti(v, "Oasis")));
    mappa.insert(make_pair("The Police", cantanti(v, "The Police")));
    mappa.insert(make_pair("Guns N' Roses", cantanti(v, "Guns N' Roses")));
    mappa.insert(make_pair("Coldplay", cantanti(v, "Coldplay")));
    mappa.insert(make_pair("Ed Sheeran", cantanti(v, "Ed Sheeran")));
    
    std::map<std::string , std::vector<std::string> >::iterator iter;
	for (iter = mappa.begin(); iter != mappa.end(); ++iter) {
		for(std::string canzone : iter->second) {
			std::cout<<"\t"<<canzone<<std::endl;
		}
    }
    return 0;
}
