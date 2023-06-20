#pragma once
#include <vector>
#include <string>
#include "Project.h"
#include "WebPage.h"

class CLI {
private:
    Project* project;
    std::vector<std::string> split(std::string s, char ch);

public:
    CLI();
    void mainMenu();
    void newProject();
    void projectMenu();
    void pageList();
    void newPage();
    void pageMenu(WebPage* page);
    void editTitle(WebPage* page);
    void editCharset(WebPage* page);
    void editDescription(WebPage* page);
    void editKeywords(WebPage* page);
    void addComponent(WebPage* page);
    void addText(WebPage* page);
    void addHeading(WebPage* page);
    void addParagraph(WebPage* page);
    void addImage(WebPage* page);
    void addForm(WebPage* page);
    void addInput(WebPage* page);
    void addTextInput(WebPage* page);
    void addPassword(WebPage* page);
    void addSubmit(WebPage* page);
    void addTable(WebPage* page);
    void componentsList(WebPage* page);
    void editComponent(WebPage* page);
    void editHeading(WebPage* page, int index);
    void editParagraph(WebPage* page, int index);
    void editImage(WebPage* page, int index);
    void editForm(WebPage* page, int index);
    void editInput(WebPage* page, int index);
    void editText(WebPage* page, int index);
    void editPassword(WebPage* page, int index);
    void editSubmit(WebPage* page, int index);
    void editTable(WebPage* page, int index);
    void removeComponent(WebPage* page);
};