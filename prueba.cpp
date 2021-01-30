#include<iostream>
#include<ctype.h>
using namespace std;


int main(){
    string s = "scott 23154645 tiger";
    string delimiter = " ";

    size_t pos = 0;
    string token;
    string caract = "";
    int posp;
    while ((pos = s.find(delimiter)) <= string::npos) {
        token = s.substr(0, pos);
        cout << token << endl;
        if (isdigit(token[0])){
            posp = stoi(token,nullptr,10);
        }else{
            caract = token;
        }
        s.erase(0, pos + delimiter.length());
        if (pos == string::npos){
            break;
        }
    }
}