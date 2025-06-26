
#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <stdlib.h>
#include "includes/nlohmann/json.hpp"

using namespace std;
using json = nlohmann::json;

class Brickwall {

    json data;
    map<string, int> jitems;
    
    

    public:
        Brickwall() {
            
        }
        Brickwall(string i_fpath) {
            std::ifstream filepath(i_fpath);
            data = json::parse(filepath);

        }

        template <typename V>
        vector<V> GetValue() {
            vector<V> outvalues;

            for (auto& tempdata : data.items()) {


                for (auto& j : tempdata.value().items()) {

                    if (jitems.find(j.key()) == jitems.end()) {
                        jitems[j.key()] = 1;
                    }
                    else {
                        jitems[j.key()]++;
                    }

                }

            }

            for (auto& tempdata : data.items()) {
                outvalues.push_back(tempdata.value()[jitems]);
            }

            return outvalues;

        }

        vector<string> GetKey() {
            vector<string> outkeys;
            
            for (auto& tempdata : data.items()) {
                outkeys.push_back(tempdata.key());
            }
            
            return outkeys;
        }

        void OutItems() {
        
            for (auto& tempdata : data.items()) {


                for (auto& j : tempdata.value().items()) {

                    if (jitems.find(j.key()) == jitems.end()) {
                        jitems[j.key()] = 1;
                    }
                    else {
                        jitems[j.key()]++;
                    }

                }

            }

            for (auto it = jitems.begin(); it != jitems.end(); ++it)
            {

                cout << it->first << "(" << jitems[it->first] << ")" << "\n";

            }
        }
};

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
    Brickwall brickwall;
    string i_fpath;
    vector<string> keys;
    string i_jitem;
    string i_command;
    string i_newdata;

    cout << "(c) Brickwall - 2025 DKM Community\n";
    cout << "\n- You can run Brickwall from the command line with the path to a JSON file as an argument\n(do not include quotes around the path):" <<R"("Brickwall.exe YourDrive:\Your\Path\To.json")" << "\n";
    cout << "\n- You can also run Brickwall from the command line with the -h argument to see help information:" << R"("Brickwall.exe -h")" << "\n";
    cout << "\n- If you run Brickwall without any command line arguments, \nit will start and immediately ask you to enter the file path manually: \nplease type the path without quotes right away." << "\n\n";
    if(argc>1){
        for(int i = 1; i<=argc; i++){
            switch(hashify(argv[i])){
                case 149:
                    print_help();                
                    break;
                default:
                    i_fpath=argv[i];
            }
        }
        
        cout << i_fpath + "\n";
    }
    else{
        std::getline(cin,i_fpath);
    }

    


    brickwall = Brickwall(i_fpath);


    cout << "Found: " << "\n";
    brickwall.OutItems();
    

    std::getline(cin, i_jitem);


    cout << "\nOptions:\n- exit : Return to other items.\n- edit : Change the value of item in choosen group." << "\n";
    std::getline(cin, i_command);

    if (i_command == "exit") {
        
    }

    if (i_command == "edit") {
        cout << "\nEnter new data:" << "\n";
        std::getline(cin, i_newdata);


    }

    return 0;
}
