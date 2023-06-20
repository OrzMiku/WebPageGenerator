#include "Heading.h"
#include "WebComponent.h"
#include<string>

using namespace std;

// Constructor
Heading::Heading(string value, int level) : value(value), level(level) {}
Heading::Heading(string value, string href, int level) : value(value), href(href), level(level) {}
// Getter
string Heading::getClassName() {
	return className;
}
string Heading::getValue() {
	return value;
}
string Heading::getHref() {
	return href;
}
int Heading::getLevel() {
	return level;
}
// Setter
void Heading::setLevel(int level) {
	this->level = level;
}
void Heading::setValue(string value) {
	this->value = value;
}
void Heading::setHref(string href) {
	this->href = href;
}
// Generate HTML
string Heading::generateHTML() {
	string html = "<h" + to_string(level) + ">";
	html += value;
	html += "</h" + to_string(level) + ">";
	// add href
	if (!href.empty()) {
		html = "<a href=\"" + href + "\">" + html + "</a>";
	}
	return html;
}