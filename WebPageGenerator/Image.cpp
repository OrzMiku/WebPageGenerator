#include "Image.h"

using namespace std;

// 构造函数实现
Image::Image(string 
    src, string alt, string href) : src(src), alt(alt), href(href) {}

// getter函数实现
string Image::getId() {
    return id;
}
string Image::getClassName() {
    return className;
}

string Image::getSrc() {
    return src;
}

string Image::getAlt() {
    return alt;
}

string Image::getHref() {
    return href;
}

// setter函数实现
void Image::setId(string id) {
    this->id = id;
}
void Image::setSrc(string src) {
    this->src = src;
}

void Image::setAlt(string alt) {
    this->alt = alt;
}

void Image::setHref(string href) {
    this->href = href;
}

// Generate HTML实现
string Image::generateHTML() {
    string html = "<img src=\"" + src + "\" alt=\"" + alt + "\">";
    // add href
    if (!href.empty()) {
        html = "<a href=\"" + href + "\">" + html + "</a>";
    }
    return html;
}