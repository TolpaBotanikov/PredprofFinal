#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main() {
    int m[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    int month = 1;
    int day = 1;
    int year = 2000;
    fstream fin("in");
    fstream fout("out");
    while (!fin.eof()) {
        string s; fin >> s;
        if (s == "[" || s == "]") continue;
        string res = "1;" + to_string(year) + "-" + (month < 10 ? "0" + to_string(month) : to_string(month)) + "-" + (day < 10 ? "0" + to_string(day) : to_string(day));
        if (s[s.size()-1] == ',') s.pop_back();
        res += ";" + s;
        fout << res << endl;
        day++;
        if (day > m[month-1]) {
            day = 1;
            ++month;
            if (month > 12) {
                month = 1;
                year++;
            }
        }
    }
  fin.close();
  fout.close();
  return 0;
}
