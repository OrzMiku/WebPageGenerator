#pragma once
#include <string>
#include <vector>
#include "WebComponent.h"

class Input : public WebComponent {
private:
    const std::string className = "Input";
    std::vector<std::string> types;
    std::string type;
    std::string name;
    std::string value;
    std::string placeholder;

public:
    // Constructors
    Input(std::string type, std::string value);
    Input(std::string type, std::string name, std::string placeholder);
    Input(std::string type, std::string name, std::string value, std::string placeholder);

    // Getter
    std::string getClassName();
    std::string getType();
    std::string getName();
    std::string getValue();
    std::string getPlaceholder();

    // Setter
    void setType(std::string type);
    void setName(std::string name);
    void setValue(std::string value);
    void setPlaceholder(std::string placeholder);

    // Generate HTML
    std::string generateHTML();
};