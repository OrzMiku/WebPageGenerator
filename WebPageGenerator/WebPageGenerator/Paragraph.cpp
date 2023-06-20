#include "Paragraph.h"

using namespace std;

// 构造函数的实现
Paragraph::Paragraph(string value, string href) : value(value), href(href) {}

// getter函数的实现
string Paragraph::getClassName() {
    return className;
}

string Paragraph::getValue() {
    return value;
}

string Paragraph::getHref() {
    return href;
}

// setter函数的实现
void Paragraph::setValue(string value) {
    this->value = value;
}

void Paragraph::setHref(string href) {
    this->href = href;
}

// Generate HTML的实现
string Paragraph::generateHTML() {
    string html = "<p>";
    html += value;
    html += "</p>";
    // add href
    if (!href.empty()) {
        html = "<a href=\"" + href + "\">" + html + "</a>";
    }
    return html;
}