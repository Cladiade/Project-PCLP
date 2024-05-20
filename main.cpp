#include <iostream>
#include <fstream>
#include "json.hpp"

using json = nlohmann::json;

int main() {
    // Create a JSON object
    json j;
    j["name"] = "John Doe";
    j["age"] = 30;
    j["city"] = "New York";

    // Write JSON to a file
    std::ofstream o("output.json");
    o << j.dump(4) << std::endl;

    // Read JSON from a file
    std::ifstream i("output.json");
    json j2;
    i >> j2;
    std::cout << j2.dump(4) << std::endl;

    return 0;
}
