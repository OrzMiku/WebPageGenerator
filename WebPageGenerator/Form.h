#pragma once
#include "WebComponent.h"
#include "WebPage.h"
#include "Project.h"
#include <iostream>
#include <string>
#include <vector>

class Form : public WebComponent {
private:
    const std::string className = "Form";
    std::string action;
    std::string method;
    std::vector<WebComponent*> components;

public:
    // Constructor
    Form(std::string action = "", std::string method = "");

    // Getter
    std::string getClassName();
    std::string getAction();
    std::string getMethod();
    std::vector<WebComponent*> getComponents();

    // Setter
    void setAction(std::string action);
    void setMethod(std::string method);

    // Component management
    void addComponent(WebComponent* component);
    void insertComponent(int index, WebComponent* component);
    void removeComponent(int index);

    // Generate HTML
    std::string generateHTML();
};