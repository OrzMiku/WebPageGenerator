#pragma once
#include <string>
#include <vector>
#include "WebComponent.h"

class Select : public WebComponent {
private:
    const std::string className = "Select";
    std::string id;
    std::string name;
    std::vector<std::string> options;

public:
    // Constructor
    Select(std::string name, std::vector<std::string> options = {});

    // Getter
    std::string getId();
    std::string getClassName();
    std::string getName();
    std::vector<std::string> getOptions();

    // Setter
    void setId(std::string id);
    void setName(std::string name);
    void setOptions(std::vector<std::string> options);
    void addOption(std::string option);
    void removeOption(std::string option);
    void removeOptionByIndex(int index);
    void insertOption(int index, std::string option);
    void removeOption(int index);

    // Generate HTML
    std::string generateHTML();
};
