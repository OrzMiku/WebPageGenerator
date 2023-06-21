#pragma once
#include <string>
#include "WebComponent.h"

class Paragraph : public WebComponent {
private:
    const std::string className = "Paragraph";
    std::string id;
    std::string value;
    std::string href;

public:
    // Constructor
    Paragraph(std::string value = "", std::string href = "");

    // Getter
    std::string getId();
    std::string getClassName();
    std::string getValue();
    std::string getHref();

    // Setter
    void setId(std::string id);
    void setValue(std::string value);
    void setHref(std::string href);

    // Generate HTML
    std::string generateHTML();
};