/* ---------------
 * Jorge L. Garcia
 * ~/~/2019
 * ---------------
 * Valid
 * Palindrome 
 */

#include <iostream>
#include <string>

using namespace std;

inline void toLowercase(char& c0, char& c1);
inline bool isAlphanumeric(char c);
inline bool areAlphanumeric(char c0, char c1);
       bool isPalindrome(string s);

int main(int argc, char **argv) {
	
	string s;
	cout << "\nPalindrome checker -- (type 'exit' to end)\n\n";
	while(getline(cin, s) && s != "exit") {
		string response = isPalindrome(s) ?
			"-- Palindrome\n" : 
			"-- Not Palindrome\n";
		cout << response << endl;
	}

	return 0;
}

inline void toLowercase(char& c0, char& c1) {
        if(c0 >= 'A' && c0 <= 'Z') c0 = (c0 - 'A') + 'a';
        if(c1 >= 'A' && c1 <= 'Z') c1 = (c1 - 'A') + 'a';
}
inline bool isAlphanumeric(char c) {
        return (c >= 'a' && c <='z') || (c >= '0' && c <= '9');
}
inline bool areAlphanumeric(char c0, char c1) {
        return isAlphanumeric(c0) && isAlphanumeric(c1);
}
bool isPalindrome(string s) {
        int i = 0;
        int j = s.length() - 1;
        
        if(s.length() == 0 || s.length() == 1) return true;
        
        while(i < j) {
            toLowercase(s[i], s[j]);
            if(!isAlphanumeric(s[i])) i++;
            if(!isAlphanumeric(s[j])) j--;
            
            if(areAlphanumeric(s[i], s[j])) {
                if(s[i] != s[j]) return false;
                i++;
                j--;
            }
        }
        
        return true;
}
