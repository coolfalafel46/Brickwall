
#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include "includes/nlohmann/json.hpp"

using namespace std;
using json = nlohmann::json;
void print_help(){
    cout << "-h Show this help.\n"; 
    exit(0);
}
int hashify(string str){
    int hashh=0;
    for(char a:str){
        hashh+=a;
    }
    return hashh;
}
int main(int argc, char** argv)
{

    string input;
    vector<string> keys;
    string penis;

    cout << "(c) Brickwall - 2025 DKM Community\n";
    if(argc>1){
        for(int i = 1; i<=argc; i++){
            switch(hashify(argv[i])){
                case 149:
                    print_help();                
                    break;
                default:
                    input=argv[1];
            }
        }
        input = argv[1];
    }
    else{
        getline(cin,input);
    }

    cout << input + "\n";


    std::ifstream filepath(input);
    json data = json::parse(filepath);
    
    map<string, int> jitems;

    for (auto& tempdata : data.items()) {
    

        for (auto& j : tempdata.value().items()) {
        
            if (jitems.find(j.key()) == jitems.end()) {
                jitems[j.key()] =1;
            }
            else {
                jitems[j.key()]++;
            }
            
        }
        
    }
    
    for (auto it = jitems.begin(); it != jitems.end(); ++it)
    {

        cout << it->first << "(" << jitems[it->first] <<")" << "\n";
        
    }
    getline(cin, penis);
    if (jitems.find(penis) == jitems.end()) {
        cout << "idi nahuy" << "\n";
    }
    else {
        cout << penis << "\n";
        for (auto& tempdata : data.items()) {
            cout << "-> In object: " << tempdata.key() << " = "<< tempdata.value()[penis] << "\n";
        }
    }


    return 0;
}
