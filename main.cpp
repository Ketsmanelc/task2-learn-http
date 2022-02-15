#include <iostream>
#include <cpr/cpr.h>
int main() {
    cpr::Response r = cpr::Get(cpr::Url("http://httpbin.org/html"),
                               cpr::Header({{"Accept", "accept: text/html"}}));
    const std::string h1 = "<h1>";
    const std::string H1 = "</h1>";
    int beginIndex = r.text.find(h1) + h1.length();
    int endIndex = r.text.find(H1);
    std::cout << r.text.substr(beginIndex, endIndex - beginIndex);
    return 0;
}
