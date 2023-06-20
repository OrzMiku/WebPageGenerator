#pragma once
#include <string>
#include <vector>
#include <fstream>
#include "WebComponent.h"

class WebPage {
private:
    std::string filename;
    std::string title;
    std::string charset;
    std::string description;
    std::vector<std::string> keywords;
    std::vector<WebComponent*> components;

public:
    // Constructor
    WebPage(std::string filename, std::string title, std::string charset = "utf-8");
    WebPage(std::string filename, std::string title, std::string description, std::string charset = "utf-8");
    WebPage(std::string filename, std::string title, std::string description, std::vector<std::string> keywords, std::string charset = "utf-8");

    // Getter
    std::string getFilename();
    std::string getTitle();
    std::string getCharset();
    std::string getDescription();
    std::vector<std::string> getKeywords();
    std::string getKeywordsHTML();
    std::vector<WebComponent*> getComponents();

    // Setter
    void setTitle(std::string title);
    void setCharset(std::string charset);
    void setDescription(std::string description);
    void setKeywords(std::vector<std::string> keywords);
    void addKeyword(std::string keyword);
    void insertKeyword(int index, std::string keyword);
    void removeKeyword(std::string keyword);
    void removeKeywordByIndex(int index);

    // Bind
    void bind(WebComponent* component);
    void add(WebComponent* component);
    void insert(int index, WebComponent* component);
    void remove(WebComponent* component);
    void removeByIndex(int index);

    // Generate HTML
    std::string generateHTML();

    // Save to file
    void save(std::string path);
};