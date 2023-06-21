#pragma once
#include "WebComponent.h"

#include <string>
#include <vector>
#include "WebComponent.h"

class Table : public WebComponent {
private:
    const std::string className = "Table";
    std::string id;
    std::vector<std::vector<std::string>> data;
    std::vector<std::string> headers;
    std::vector<std::string> footers;

public:
    // Constructor
    Table(std::vector<std::vector<std::string>> data);
    Table(std::vector<std::vector<std::string>> data, std::vector<std::string> headers);
    Table(std::vector<std::vector<std::string>> data, std::vector<std::string> headers, std::vector<std::string> footers);

    // Getter
    std::string getId();
    std::string getClassName();
    std::vector<std::vector<std::string>> getData();
    std::vector<std::string> getHeaders();
    std::vector<std::string> getFooters();

    // Setter
    void setId(std::string id);
    void setData(std::vector<std::vector<std::string>> data);
    void setHeaders(std::vector<std::string> headers);
    void setFooters(std::vector<std::string> footers);
    void addRow(std::vector<std::string> row);
    void removeRow(int index);
    void insertRow(int index, std::vector<std::string> row);
    void addColumn(std::vector<std::string> column);
    void removeColumn(int index);
    void insertColumn(int index, std::vector<std::string> column);
    void addHeader(std::string header);
    void removeHeader(int index);
    void insertHeader(int index, std::string header);
    void addFooter(std::string footer);
    void removeFooter(int index);
    void insertFooter(int index, std::string footer);

    // Generate HTML
    std::string generateHTML();
};