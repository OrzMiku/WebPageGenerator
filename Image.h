#pragma once
#include <string>
#include "WebComponent.h"

class Image : public WebComponent {
private:
    const std::string className = "Image";
    std::string src;
    std::string alt;
    std::string href;

public:
    // Constructor
    Image(std::string src, std::string alt = "", std::string href = "");

    // Getter
    std::string getClassName();
    std::string getSrc();
    std::string getAlt();
    std::string getHref();

    // Setter
    void setSrc(std::string src);
    void setAlt(std::string alt);
    void setHref(std::string href);

    // Generate HTML
    std::string generateHTML();
};