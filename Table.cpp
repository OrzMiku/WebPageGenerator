#include "Table.h"

using namespace std;

// 构造函数的实现
Table::Table(vector<vector<string>> data) : data(data) {}

Table::Table(vector<vector<string>> data, vector<string> headers)
	: data(data), headers(headers) {}

Table::Table(vector<vector<string>> data, vector<string> headers, vector<string> footers)
	: data(data), headers(headers), footers(footers) {}

// Getter函数的实现
string Table::getClassName() {
	return className;
}

vector<vector<string>> Table::getData() {
	return data;
}

vector<string> Table::getHeaders() {
	return headers;
}

vector<string> Table::getFooters() {
	return footers;
}

// Setter函数的实现
void Table::setData(vector<vector<string>> data) {
	this->data = data;
}

void Table::setHeaders(vector<string> headers) {
	this->headers = headers;
}

void Table::setFooters(vector<string> footers) {
	this->footers = footers;
}

// 其他成员函数的实现
void Table::addRow(vector<string> row) {
	data.push_back(row);
}

void Table::removeRow(int index) {
	data.erase(data.begin() + index);
}

void Table::insertRow(int index, vector<string> row) {
	data.insert(data.begin() + index, row);
}

void Table::addColumn(vector<string> column) {
	for (int i = 0; i < column.size(); i++) {
		for (int j = 0; j < data.size(); j++) {
			data[j].push_back(column[i]);
		}
	}
}

void Table::removeColumn(int index) {
	for (int i = 0; i < data.size(); i++) {
		data[i].erase(data[i].begin() + index);
	}
}

void Table::insertColumn(int index, vector<string> column) {
	for (int i = 0; i < data.size(); i++) {
		data[i].insert(data[i].begin() + index, column[i]);
	}
}

void Table::addHeader(string header) {
	headers.push_back(header);
}

void Table::removeHeader(int index) {
	headers.erase(headers.begin() + index);
}

void Table::insertHeader(int index, string header) {
	headers.insert(headers.begin() + index, header);
}

void Table::addFooter(string footer) {
	footers.push_back(footer);
}

void Table::removeFooter(int index) {
	footers.erase(footers.begin() + index);
}

void Table::insertFooter(int index, string footer) {
	footers.insert(footers.begin() + index, footer);
}

// Generate HTML的实现
string Table::generateHTML() {
	string html = "<table>";
	if (headers.size() > 0) {
		html += "<thead><tr>";
		for (int i = 0; i < headers.size(); i++) {
			html += "<th>" + headers[i] + "</th>";
		}
		html += "</tr></thead>";
	}
	html += "<tbody>";
	for (int i = 0; i < data.size(); i++) {
		html += "<tr>";
		for (int j = 0; j < data[i].size(); j++) {
			html += "<td>" + data[i][j] + "</td>";
		}
		html += "</tr>";
	}
	html += "</tbody>";
	if (footers.size() > 0) {
		html += "<tfoot><tr>";
		for (int i = 0; i < footers.size(); i++) {
			html += "<th>" + footers[i] + "</th>";
		}
		html += "</tr></tfoot>";
	}
	html += "</table>";
	return html;
}