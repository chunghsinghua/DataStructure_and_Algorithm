#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

const std::vector<std::string> split(const std::string& str, const std::string& pattern) {
    std::vector<std::string> result;
    std::string::size_type begin, end;

    end = str.find(pattern);
    begin = 0;

    while (end != std::string::npos) {
        if (end - begin != 0) {
            result.push_back(str.substr(begin, end-begin)); 
        }    
        begin = end + pattern.size();
        end = str.find(pattern, begin);
    }

    if (begin != str.length()) {
        result.push_back(str.substr(begin));
    }
    return result;        
}

int main() {
    std::string str = " This is a c++ string";
    std::string pattern = " ";

    std::vector<std::string> ret = split(str, pattern);

    for (auto& s : ret) {
        cout << s << "\n";
    }
    return 0;
}
