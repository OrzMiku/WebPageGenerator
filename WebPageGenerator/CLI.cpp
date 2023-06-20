#include "CLI.h"
#include <iostream>
#include <limits>
#include "Project.h"
#include "WebPage.h"
#include "Heading.h"
#include "Paragraph.h"
#include "Image.h"
#include "Form.h"
#include "Input.h"
#include "Table.h"

using namespace std;

vector<string> CLI::split(string s, char ch)
{
	vector<string> res;
	string tmp = "";
	for (int i = 0; i < s.size(); i++)
		if (s[i] == ch)
		{
			res.push_back(tmp);
			tmp = "";
		}
		else tmp += s[i];
	if (tmp.size()) res.push_back(tmp);
	return res;
}
vector<string> CLI::lines_read()
{
	vector<string> v;
	string s; getline(cin, s);
	while (s.size())
	{
		v.push_back(s);
		getline(cin, s);
	}
	return v;
}
string CLI::line_read()
{
	string s;
	getline(cin, s);
	return s;
}
string CLI::word_read()
{
	string s;
	cin >> s;
	cin.ignore();
	return s;
}
int CLI::number_read()
{
	int num;
	cin >> num;
	cin.ignore();
	return num;
}
CLI::CLI() {
	project = NULL;
	mainMenu();
}
void CLI::mainMenu() {
	cout << "1. New Project" << endl;
	cout << "0. Exit" << endl;
	int choice = 0;
	choice=number_read();
	switch (choice) {
	case 0:
		exit(0);
		break;
	case 1:
		newProject();
		break;
	default:
		cout << "Invalid input!" << endl;
		mainMenu();
		break;
	}
}
void CLI::newProject() {
	cout << "Project name: ";
	string name = line_read();
	cout << "Project path: ";
	string path = line_read();
	project = new Project(name, path);
	newPage();
}
void CLI::projectMenu() {
	cout << "1. New Page" << endl;
	cout << "2. Edit Page" << endl;
	cout << "3. Save Project" << endl;
	cout << "0. Back" << endl;
	int choice = number_read();
	switch (choice) {
	case 0:
		mainMenu();
		break;
	case 1:
		newPage();
		break;
	case 2:
		pageList();
		break;
	case 3:
		project->save();
	}
}
void CLI::pageList() {
	cout << "Page List" << endl;
	for (int i = 0; i < project->getPages().size(); i++) {
		cout << i + 1 << ". " << project->getPages()[i]->getTitle() << endl;
	}
	cout << "0. Back" << endl;
	int choice = number_read();
	if (choice == 0) {
		projectMenu();
	}
	else {
		pageMenu(project->getPages()[choice - 1]);
	}
}
void CLI::newPage() {
	cout << "Page Filename: ";
	string filename = word_read();
	cout << "Page title: ";
	string title = line_read();
	cout << "Page charset: ";
	string charset = word_read();
	cout << "Page description: ";
	string description = line_read();
	cout << "Page keywords: ";
	string keywords = line_read();
	WebPage* page = new WebPage(filename, title, description, split(keywords, ','), charset);
	project->add(page);
	pageMenu(page);
}
void CLI::pageMenu(WebPage* page) {
	cout << "1. Edit Title" << endl;
	cout << "2. Edit Charset" << endl;
	cout << "3. Edit Description" << endl;
	cout << "4. Edit Keywords" << endl;
	cout << "5. Add Component" << endl;
	cout << "6. Edit Component" << endl;
	cout << "7. Remove Component" << endl;
	cout << "0. Back" << endl;
	int choice = number_read();
	switch (choice) {
	case 0:
		projectMenu();
		break;
	case 1:
		editTitle(page);
		break;
	case 2:
		editCharset(page);
		break;
	case 3:
		editDescription(page);
		break;
	case 4:
		editKeywords(page);
		break;
	case 5:
		addComponent(page);
		break;
	case 6:
		editComponent(page);
		break;
	case 7:
		removeComponent(page);
		break;
	}
}
void CLI::editTitle(WebPage* page) {
	cout << "New title: ";
	string title = line_read();
	page->setTitle(title);
	pageMenu(page);
}
void CLI::editCharset(WebPage* page) {
	cout << "New charset: ";
	string charset = word_read();
	page->setCharset(charset);
	pageMenu(page);
}
void CLI::editDescription(WebPage* page) {
	cout << "New description: ";
	string description = line_read();
	page->setDescription(description);
	pageMenu(page);
}
void CLI::editKeywords(WebPage* page) {
	cout << "New keywords: ";
	string keywords = line_read();
	page->setKeywords(split(keywords, ','));
	pageMenu(page);
}
void CLI::addComponent(WebPage* page) {
	cout << "1. Add Text" << endl;
	cout << "2. Add Image" << endl;
	cout << "3. Add Form" << endl;
	cout << "4. Add Input" << endl;
	cout << "5. Add Table" << endl;
	cout << "0. Back" << endl;
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	int choice = number_read();
	switch (choice) {
	case 0:
		pageMenu(page);
		break;
	case 1:
		addText(page);
		break;
	case 2:
		addImage(page);
		break;
	case 3:
		addForm(page);
		break;
	case 4:
		addInput(page);
		break;
	case 5:
		addTable(page);
		break;
	}
}
void CLI::addText(WebPage* page) {
	cout << "1. Heading" << endl;
	cout << "2. Paragraph" << endl;
	cout << "0. Back" << endl;
	int choice = number_read();
	switch (choice) {
	case 1:
		addHeading(page);
		break;
	case 2:
		addParagraph(page);
		break;
	case 0:
		addComponent(page);
		break;
	}
}
void CLI::addHeading(WebPage* page) {
	cout << "Heading level: ";
	int level = number_read();
	cout << "Heading text: ";
	string text = line_read();
	cout << "Url (Optional): ";
	string url = line_read();
	Heading* heading;
	if (!url.empty()) {
		heading = new Heading(text, url, level);
	}
	else {
		heading = new Heading(text, level);
	}
	page->add(heading);
	addComponent(page);
}
void CLI::addParagraph(WebPage* page) {
	cout << "Paragraph text: ";
	string text = line_read();
	cout << "Url (Optional): ";
	string url = line_read();
	Paragraph* paragraph;
	if (!url.empty()) {
		paragraph = new Paragraph(text, url);
	}
	else {
		paragraph = new Paragraph(text);
	}
	page->add(paragraph);
	addComponent(page);
}
void CLI::addImage(WebPage* page) {
	cout << "Image url: ";
	string src = line_read();
	cout << "Image description: ";
	string description = line_read();
	cout << "Url (Optional): ";
	string url = line_read();
	Image* image;
	if (!url.empty()) {
		image = new Image(src, description, url);
	}
	else {
		image = new Image(src, description);
	}
	page->add(image);
	addComponent(page);
}
void CLI::addForm(WebPage* page) {
	cout << "Form action: ";
	string action = line_read();
	cout << "Form method: ";
	string method = line_read();
	Form* form = new Form(action, method);
	page->add(form);
	addComponent(page);
}
void CLI::addInput(WebPage* page) {
	cout << "1. Text" << endl;
	cout << "2. Password" << endl;
	cout << "3. Submit" << endl;
	cout << "Input type: ";
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	int choice =number_read();
	switch (choice) {
	case 1:
		addTextInput(page);
		break;
	case 2:
		addPassword(page);
		break;
	case 3:
		addSubmit(page);
		break;
	}
}
void CLI::addTextInput(WebPage* page) {
	cout << "Input name: ";
	string name = line_read();
	cout << "Input value (Optional): ";
	string value = line_read();
	cout << "Input Placeholder: ";
	string placeholder = line_read();
	Input* text = new Input("text", name, placeholder);
	if (!value.empty()) {
		text->setValue(value);
	}
	page->add(text);
	addComponent(page);
}
void CLI::addPassword(WebPage* page) {
	cout << "Input name: ";
	string name = line_read();
	cout << "Input value (Optional): ";
	string value = line_read();
	cout << "Input Placeholder: ";
	string placeholder = line_read();
	Input* password = new Input("password", name, placeholder);
	if (!value.empty()) {
		password->setValue(value);
	}
	page->add(password);
	addComponent(page);
}
void CLI::addSubmit(WebPage* page) {
	cout << "Input value: ";
	string value = line_read();
	Input* submit = new Input("submit", value);
	page->add(submit);
	addComponent(page);
}
void CLI::addTable(WebPage* page) {
	vector<string> headers;
	cout << "Table headers (Optional): ";
	string header = line_read();
	while (!header.empty()) {
		headers.push_back(header);
		header= line_read();
	}
	vector<vector<string>> data;
	cout << "Table data: ";
	string datum = line_read();
	while (!datum.empty()) {
		vector<string> row;
		while (!datum.empty()) {
			row.push_back(datum);
			datum= line_read();
		}
		data.push_back(row);
	}
	vector<string> footers;
	cout << "Table footers (Optional): ";
	string footer = line_read();
	while (!footer.empty()) {
		footers.push_back(footer);
		footer = line_read();;
	}
	Table* table = new Table(data);
	if (!headers.empty()) {
		table->setHeaders(headers);
	}
	if (!footers.empty()) {
		table->setFooters(footers);
	}
	page->add(table);
	addComponent(page);
}
void CLI::componentsList(WebPage* page) {
	for (int i = 0; i < page->getComponents().size(); i++) {
		cout << i << ". " << page->getComponents()[i]->getClassName() << endl;
	}
}
void CLI::editComponent(WebPage* page) {
	componentsList(page);
	cout << "Component to edit: ";
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	int choice = 0;
	choice=number_read();
	string className = page->getComponents()[choice]->getClassName();
	if (className == "Heading") {
		editHeading(page, choice);
	}
	else if (className == "Paragraph") {
		editParagraph(page, choice);
	}
	else if (className == "Image") {
		editImage(page, choice);
	}
	else if (className == "Form") {
		editForm(page, choice);
	}
	else if (className == "Input") {
		editInput(page, choice);
	}
	else if (className == "Table") {
		editTable(page, choice);
	}
}
void CLI::editHeading(WebPage* page, int index) {
	cout << "Heading text: ";
	string text = line_read();
	cout << "Heading level: ";
	int level = number_read();
	((Heading*)page->getComponents()[index])->setValue(text);
	((Heading*)page->getComponents()[index])->setLevel(level);
}
void CLI::editParagraph(WebPage* page, int index) {
	cout << "Paragraph text: ";
	string text = line_read();
	((Paragraph*)page->getComponents()[index])->setValue(text);
}
void CLI::editImage(WebPage* page, int index) {
	cout << "Image url: ";
	string src =  line_read();
	cout << "Image description: ";
	string description = line_read();
	cout << "Url (Optional): ";
	string url = line_read();
	((Image*)page->getComponents()[index])->setSrc(src);
	((Image*)page->getComponents()[index])->setAlt(description);
	if (!url.empty()) {
		((Image*)page->getComponents()[index])->setHref(url);
	}
}
void CLI::editForm(WebPage* page, int index) {
	cout << "Form action: ";
	string action = line_read();
	cout << "Form method: ";
	string method = line_read();
	((Form*)page->getComponents()[index])->setAction(action);
	((Form*)page->getComponents()[index])->setMethod(method);
}
void CLI::editInput(WebPage* page, int index) {
	string type = ((Input*)page->getComponents()[index])->getType();
	if (type == "text") {
		editText(page, index);
	}
	else if (type == "password") {
		editPassword(page, index);
	}
	else if (type == "submit") {
		editSubmit(page, index);
	}
}
void CLI::editText(WebPage* page, int index) {
	cout << "Input name: ";
	string name = line_read();
	cout << "Input value (Optional): ";
	string value = line_read();
	cout << "Input Placeholder: ";
	string placeholder = line_read();
	((Input*)page->getComponents()[index])->setName(name);
	((Input*)page->getComponents()[index])->setPlaceholder(placeholder);
	if (!value.empty()) {
		((Input*)page->getComponents()[index])->setValue(value);
	}
}
void CLI::editPassword(WebPage* page, int index) {
	cout << "Input name: ";
	string name = line_read();
	cout << "Input value (Optional): ";
	string value = line_read();
	cout << "Input Placeholder: ";
	string placeholder = line_read();
	((Input*)page->getComponents()[index])->setName(name);
	((Input*)page->getComponents()[index])->setPlaceholder(placeholder);
	if (!value.empty()) {
		((Input*)page->getComponents()[index])->setValue(value);
	}
}
void CLI::editSubmit(WebPage* page, int index) {
	cout << "Input value: ";
	string value = line_read();
	((Input*)page->getComponents()[index])->setValue(value);
}
void CLI::editTable(WebPage* page, int index) {
	cout << "Table headers (Optional): ";
	vector<string> headers;
	vector<string> footers;
	string header = line_read();
	while (!header.empty()) {
		headers.push_back(header);
		header = line_read();
	}
	((Table*)page->getComponents()[index])->setHeaders(headers);
	cout << "Table footers (Optional): ";
	string footer;
	footer = line_read();
	while (!footer.empty()) {
		footers.push_back(footer);
		footer = line_read();
	}
	((Table*)page->getComponents()[index])->setFooters(footers);
}
void CLI::removeComponent(WebPage* page) {
	componentsList(page);
	cout << "Component to remove: ";
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	int choice = 0;
	choice=number_read();
	page->remove(page->getComponents()[choice]);
}