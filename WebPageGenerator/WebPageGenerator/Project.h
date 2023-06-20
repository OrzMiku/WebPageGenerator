#pragma once

#include <string>
#include <vector>
#include "WebPage.h"

class Project {
private:
    std::string name;
    std::string path;
    std::vector<WebPage*> pages;

public:
    // Constructor
    Project(std::string name, std::string path);

    // Getter
    std::string getName();
    std::string getPath();
    std::vector<WebPage*> getPages();

    // Setter
    void setName(std::string name);
    void setPath(std::string path);

    // Page management
    void add(WebPage* page);
    void insert(int index, WebPage* page);
    void remove(WebPage* page);
    void removeByIndex(int index);

    // Save project
    void save();
};