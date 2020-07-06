#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> RabinKarp(string text, string pattern) {
  long m = 1000000007;  //фиксируем простое p
  vector<long long> x(pattern.length());
  long a = 263;
  long textLength = text.length();
  long patternLength = pattern.length();

  vector<int> occurrences;

  long long patternHash = 0;
  long long currSubstrHash = 0;
  long long pow = 1;
  for (int i = 0; i < pattern.length(); i++) {
    patternHash += pattern[i] * pow;
    patternHash %= m;

    currSubstrHash += text[text.length() - pattern.length() + i] * pow;
    currSubstrHash %= m;

    if (i != pattern.length() - 1) {
      pow = pow * a % m;
    }
  }

  for (int i = text.length(); i >= pattern.length(); i--) {
    if (patternHash == currSubstrHash) {
      bool patternIsFound = true;

      for (int j = 0; j < pattern.length(); j++) {
        if (text[i - pattern.length() + j] != pattern[j]) {
          patternIsFound = false;
          break;
        }
      }

      if (patternIsFound) {
        occurrences.push_back(i - pattern.length());
      }
    }

    if (i > pattern.length()) {
      currSubstrHash = (currSubstrHash - text[i - 1] * pow % m + m) * a % m;
      currSubstrHash = (currSubstrHash + text[i - pattern.length() - 1]) % m;
    }
  }

  reverse(occurrences.begin(), occurrences.end());
  return occurrences;
}

int main(int argc, char const *argv[]) {
  string pattern;
  string text;
  cin >> pattern;
  cin >> text;

  vector<int> occ = RabinKarp(text, pattern);
  for (auto oc : occ) {
    cout << oc << " ";
  }
  cout << endl;

  return 0;
}
