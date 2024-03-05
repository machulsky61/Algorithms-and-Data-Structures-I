#include <iostream>
#include <string>

using namespace std;

bool subsecuencia(string s, string t) {
    /* existen indices i0 < i1 < i2 tales que s[0] == t[i0] , s[1] == t[i1] , s[2] == t[i2] */
    int j0 = 0;
    int res = 0;
    for(int i = 0; i < s.size(); i++){
        for(int j = 0; j < t.size(); j++){    
            if(j0 <= j && s[i] == t[j]){    
                res = res + 1;
                j0 = j;
                 }
            } 
    }
    return res == s.size();
}

int main()
{
    // Leo la entrada
    string s, t;
    cin >> s >> t;
    
    bool res = subsecuencia(s, t);
    cout << (res ? "true" : "false");
    return 0;
}

