#include "Input.h"

using namespace std;

// 构造函数的实现
Input::Input(string type, string value)
    : type(type), value(value) {}

Input::Input(string type, string name, string placeholder)
    : type(type), name(name), placeholder(placeholder) {}

Input::Input(string type, string name, string value, string placeholder)
    : type(type), name(name), value(value), placeholder(placeholder) {}

// Getter函数的实现
string Input::getId() {
    return id;
}
string Input::getClassName() {
    return className;
}

string Input::getType() {
    return type;
}

string Input::getName() {
    return name;
}

string Input::getValue() {
    return value;
}

string Input::getPlaceholder() {
    return placeholder;
}

// Setter函数的实现
void Input::setId(string id) {
    this->id = id;
}
void Input::setType(string type) {
    this->type = type;
}

void Input::setName(string name) {
    this->name = name;
}

void Input::setValue(string value) {
    this->value = value;
}

void Input::setPlaceholder(string placeholder) {
    this->placeholder = placeholder;
}

// Generate HTML的实现
string Input::generateHTML() {
    string html;
    if (type == "submit") {
        html = "<input type=\"" + type + "\" value=\"" + value + "\">";
    }
    else {
        html = "<input type=\"" + type + "\" name=\"" + name + "\" value=\"" + value + "\" placeholder=\"" + placeholder + "\">";
    }
    return html;
}