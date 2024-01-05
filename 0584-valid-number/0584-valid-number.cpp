#include <sstream>
class Solution {
public:
    bool isNumber(const char *s) {
    
      vector<string> tokens;
      stringstream ss(s);
      string str;
      while (ss >> str)
        tokens.push_back(str);
    
      if (tokens.size() > 1)
        return false;
    
      try {
        std::stod(string(s));
      }
      catch (...) {
        return false;
      }
    
      if (string(s).find('e') == string(s).size() - 1)
        return false;
    
      return true;
    }


};