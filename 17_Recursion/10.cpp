//REMOVING DUBLICATE LETTER
#include <iostream>
using namespace std;

// Method 1 - With index (i)==>agadthi dublicate sodhe
void removeDuplicates(string str, string ans, int i, int map[26]) {
    if(i == str.size()) {
        cout << "ans : " << ans << endl;
        return;
    }

    int mapIdx = (int)(str[i] - 'a');

    if(map[mapIdx]) { //duplicate
        removeDuplicates(str, ans, i+1, map);
    } else { //not duplicate
        map[mapIdx] = true;
        removeDuplicates(str, ans+str[i], i+1, map);
    }
}

// Method 2 - Without index==>pachdthi dublicate sodhe
void removeDuplicates(string str, string ans, int map[26]) {
    if(str.size() == 0) {
        cout << "ans : " << ans << endl;
        return;
    }

    int n = str.size();
    char ch = str[n-1];
    int mapIdx = (int)(str[n-1] - 'a');
    str = str.substr(0, n-1);

    if(map[mapIdx]) { //duplicate
        removeDuplicates(str, ans, map);
    } else { //not duplicate
        map[mapIdx] = true;
        removeDuplicates(str, ch+ans, map);
    }
}

int main() {
    string str = "aaabbb";
    string ans = "";
    int map[26] = {0};

    cout << "Method 1 (with i): ";
    removeDuplicates(str, ans, 0, map);

    int map2[26] = {0};
    cout << "Method 2 (without i): ";
    removeDuplicates(str, ans, map2);

    return 0;
}

// ANS:=
// Method 1 (with i): ans : ab
// Method 2 (without i): ans : ab