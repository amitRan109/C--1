#include <iostream>
#include "PhoneticFinder.hpp"
#include <string>
#include <locale>
using namespace std;
string phonetic::find (string text, string word){
    int i=0;
    while (i < text.length()){
        int j=i;
        while (j < text.length() && text[j] != ' '){
            j++;
        }
        string s;
        s = text.substr(i, j-i);
        int eq = isEqual(s, word);
        if (eq) return s;
        i = j+1;
    }
    throw out_of_range {"The word don't show"};
}

int phonetic::isEqual(string text,string word){
    if (text.length() != word.length()) return 0;
    for (int i=0; i < text.length(); i++){
        locale loc;
        char char11 = tolower(text[i],loc);
        char char22 = tolower(word[i],loc);
        if (char11 == char22) continue;
        int eq = 0;
        switch (char11){
                case 'v' : 
				    if (char22 == 'w') eq = 1;
				    break;
				case 'w' : 
			    	if (char22 == 'v') eq = 1;
				    break;
				case 'b' : 
				    if (char22 == 'f' || char22 == 'p') eq = 1;
				    break;
				case 'f' : 
			    	if (char22 == 'b' || char22 == 'p') eq = 1;
				    break;
				case 'p' : 
			    	if (char22 == 'f' || char22 == 'b') eq = 1;
				    break;
				case 'g' : 
				    if (char22 == 'j') eq = 1;
				    break;
				case 'j' : 
				    if (char22 == 'g') eq = 1;
				    break;
				case 'c' :
				    if (char22 == 'k' || char22 == 'q') eq = 1;
				    break;
				case 'k' : 
				    if (char22 == 'c' || char22 == 'q') eq = 1;
				    break;
				case 'q' : 
				    if (char22 == 'c' || char22 == 'k') eq = 1;
				    break;
				case 's' : 
				    if (char22 == 'z') eq = 1;
				    break;
				case 'z' : 
				    if (char22 == 's') eq = 1;
				    break;
				case 'd' : 
				    if (char22 == 't') eq = 1;
				    break;
				case 't' : 
				    if (char22 == 'd') eq = 1;
				    break;
				case 'o' : 
				    if (char22 == 'u') eq = 1;
				    break;
				case 'u' : 
				    if (char22 == 'o') eq = 1;
				    break;
				case 'i' : 
				    if (char22 == 'y') eq = 1;
				    break;
				case 'y' : 
			    	if (char22 == 'i') eq = 1;
				    break;
		}
		if (!eq) return 0;;
    }
    return 1;
}
