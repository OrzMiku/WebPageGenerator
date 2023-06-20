#include "WebPage.h"
#include<string>
#include<vector>
#include<fstream>
#include<direct.h>
#include <io.h>
using namespace std;

WebPage::WebPage(string filename, string title, string charset) : filename(filename), title(title), charset(charset) {
    // Constructor implementation
}

WebPage::WebPage(string filename, string title, string description, string charset) :filename(filename), title(title), description(description), charset(charset) {
    // Constructor implementation
}

WebPage::WebPage(string filename, string title, string description, vector<string> keywords, string charset) :filename(filename), title(title), description(description), keywords(keywords), charset(charset) {
    // Constructor implementation
}

string WebPage::getFilename() {
    return filename;
}

string WebPage::getTitle() {
    return title;
}

string WebPage::getCharset() {
    return charset;
}

string WebPage::getDescription() {
    return description;
}

vector<string> WebPage::getKeywords() {
    return keywords;
}

string WebPage::getKeywordsHTML() {
    string keywords = "";
    for (int i = 0; i < this->keywords.size(); i++) {
        keywords += this->keywords[i];
        if (i != this->keywords.size() - 1) {
            keywords += ", ";
        }
    }
    return keywords;
}

vector<WebComponent*> WebPage::getComponents() {
    return components;
}

void WebPage::setTitle(string title) {
    this->title = title;
}

void WebPage::setCharset(string charset) {
    this->charset = charset;
}

void WebPage::setDescription(string description) {
    this->description = description;
}

void WebPage::setKeywords(vector<string> keywords) {
    this->keywords = keywords;
}

void WebPage::addKeyword(string keyword) {
    keywords.push_back(keyword);
}

void WebPage::insertKeyword(int index, string keyword) {
    keywords.insert(keywords.begin() + index, keyword);
}

void WebPage::removeKeyword(string keyword) {
    for (int i = 0; i < keywords.size(); i++) {
        if (keywords[i] == keyword) {
            keywords.erase(keywords.begin() + i);
            break;
        }
    }
}

void WebPage::removeKeywordByIndex(int index) {
    keywords.erase(keywords.begin() + index);
}

void WebPage::bind(WebComponent* component) {
    components.push_back(component);
}

void WebPage::add(WebComponent* component) {
    components.push_back(component);
}

void WebPage::insert(int index, WebComponent* component) {
    components.insert(components.begin() + index, component);
}

void WebPage::remove(WebComponent* component) {
    for (int i = 0; i < components.size(); i++) {
        if (components[i] == component) {
            components.erase(components.begin() + i);
            break;
        }
    }
}

void WebPage::removeByIndex(int index) {
    components.erase(components.begin() + index);
}

string WebPage::generateHTML() {
    string html = "<!DOCTYPE html><html lang=\"en\"><head><meta charset=\"" + charset + "\"><title>" + title + "</title>";
    if (!description.empty()) {
        html += "<meta name=\"description\" content=\"" + description + "\">";
    }
    if (!keywords.empty()) {
        html += "<meta name=\"keywords\" content=\"" + getKeywordsHTML() + "\">";
    }
    html += "</head><body>";
    for (int i = 0; i < components.size(); i++) {
        html += components[i]->generateHTML();
    }
    html += "</body></html>";
    return html;
}

vector<std::string> WebPage::split(std::string s, char ch)
{
    vector<string> res;
    string tmp = "";
    for (int i = 0; i < s.size(); i++)
        if (s[i] == ch)
        {
            res.push_back(tmp);
            tmp = "";
        }
        else
            tmp += s[i];
    if (tmp.size())
        res.push_back(tmp);
    return res;
}

void WebPage::save(string path) {
    // make dir
    char PATH_SEPERATOR;
    if (path.find("/") != string::npos)
        PATH_SEPERATOR = '/';
    else if (path.find("\\") != string::npos)
        PATH_SEPERATOR = '\\';
    vector<string> dict = split(path, PATH_SEPERATOR);
    string temp = "";
    for (int i = 0; i < dict.size() - 1; i++)
    {
        temp += dict[i] + PATH_SEPERATOR;
        _mkdir(temp.c_str());
    }
    // save file
    temp += dict[dict.size() - 1];
    ofstream file;
    file.open(temp,ios::out);
    file << generateHTML();
    file.close();
}