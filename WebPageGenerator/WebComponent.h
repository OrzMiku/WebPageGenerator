#pragma once
#include <string>

class WebComponent {
public:
    // Generate HTML
    virtual std::string generateHTML() = 0;
    virtual std::string getClassName() = 0;
    virtual std::string getId() = 0;
};