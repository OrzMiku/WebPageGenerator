#include "Form.h"
#include<vector>
#include<string>

using namespace std;

// Constructor
Form::Form(string action, string method) : action(action), method(method) {}
// Getter
string Form::getClassName() {
	return className;
}
string Form::getAction() {
	return action;
}
string Form::getMethod() {
	return method;
}
vector<WebComponent*> Form::getComponents() {
	return components;
}
// Setter
void Form::setAction(string action) {
	this->action = action;
}
void Form::setMethod(string method) {
	this->method = method;
}
void Form::addComponent(WebComponent* component) {
	components.push_back(component);
}
void Form::insertComponent(int index, WebComponent* component) {
	components.insert(components.begin() + index, component);
}
void Form::removeComponent(int index) {
	components.erase(components.begin() + index);
}
// Generate HTML
string Form::generateHTML() {
	string html = "<form action=\"" + action + "\" method=\"" + method + "\">";
	for (int i = 0; i < components.size(); i++) {
		html += components[i]->generateHTML();
	}
	html += "</form>";
	return html;
}