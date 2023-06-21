#pragma once
#include "WebComponent.h"
#include <string>

class Heading : public WebComponent {
private:
    const std::string className = "Heading";
    std::string id;
    std::string value;
    std::string href;
    int level;

public:
    // Constructors
    Heading(std::string value, int level = 1);
    Heading(std::string value, std::string href, int level = 1);

    // Getter
    std::string getId();
    std::string getClassName();
    std::string getValue();
    std::string getHref();
    int getLevel();

    // Setter
    void setId(std::string id);
    void setLevel(int level);
    void setValue(std::string value);
    void setHref(std::string href);

    // Generate HTML
    std::string generateHTML();
};