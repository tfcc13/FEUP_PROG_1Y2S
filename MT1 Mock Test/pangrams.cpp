#include <iostream>


using namespace std;

bool pangram(const char s[], char m[]) {
    int alstr [26] = {0};
    bool flag = true;
    int d;
    char x;
    for (int i = 0; s[i] != '\0'; i++) {
        if ( s[i] != ' ') {
        x = tolower(s[i]);
        d = x-'a';
        alstr[d]++;
        }
    }
    int count = 0;
    for (int i = 0; i < 26; i++) {
        if (alstr[i] == 0) {
            flag = false;
            char t = 'a'+i;
            m[count]= t;
            count++;
        }
    }
    m[count] = '\0';
    return flag;
}

int main() {

    { char s[] = "";
  char m[27] = { -1 };
  bool r = pangram(s, m);
  cout << '\"' << s << "\" "
     << boolalpha << r << " \"" << m << "\"\n"; }

	

//"" false "abcdefghijklmnopqrstuvwxyz"

{ char s[] = "The quick brown fox jumps over the lazy dog";
  char m[27] = { -1 };
  bool r = pangram(s, m);
  cout << '\"' << s << "\" " 
       << boolalpha << r << " \"" << m << "\"\n"; }

	

//"The quick brown fox jumps over the lazy dog" true ""

{ char s[] = "A quick brown fox jumps over a classy dog";
  char m[27] = { -1 };
  bool r = pangram(s, m);
  cout << '\"' << s << "\" " 
       << boolalpha << r << " \"" << m << "\"\n"; }

	

//"A quick brown fox jumps over a classy dog" false "htz"

{ char s[] = " abC dEf GhI jKl MnO pQr StU vWx yZ ";
  char m[27] = { -1 };
  bool r = pangram(s, m);
  cout << '\"' << s << "\" " 
       << boolalpha << r << " \"" << m << "\"\n"; }

	

//" abC dEf GhI jKl MnO pQr StU vWx yZ " true ""

{ char s[] = " Stu yZ abC GhI MnO pQr   ";
  char m[27] = { -1 };
  bool r = pangram(s, m);
  cout << '\"' << s << "\" " 
       << boolalpha << r << " \"" << m << "\"\n"; }

	

//" Stu yZ abC GhI MnO pQr   " false "defjklv
    return 0;
}