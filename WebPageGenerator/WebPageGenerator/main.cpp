#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<fstream>
#include<cstdio>
#include<direct.h>
#include<io.h>

using namespace std;

namespace EcyHTML {

	class WebComponent {
	public:
		// Generate HTML
		virtual string generateHTML() = 0;
		virtual string getClassName() = 0;
	};

	class Heading : public WebComponent {
	private:
		const string className = "Heading";
		string value;
		string href;
		int level;
	public:
		// Constructor
		Heading( string value,int level = 1) : value(value), level(level) {}
		Heading( string value,string href,int level = 1) : value(value), href(href), level(level) {}
		// Getter
		string getClassName() {
			return className;
		}
		string getValue() {
			return value;
		}
		string getHref() {
			return href;
		}
		int getLevel() {
			return level;
		}
		// Setter
		void setLevel(int level) {
			this->level = level;
		}
		void setValue(string value) {
			this->value = value;
		}
		void setHref(string href) {
			this->href = href;
		}
		// Generate HTML
		string generateHTML() {
			string html = "<h" + to_string(level) + ">";
			html += value;
			html += "</h" + to_string(level) + ">";
			// add href
			if (!href.empty()) {
				html = "<a href=\"" + href + "\">" + html + "</a>";
			}
			return html;
		}
	};
	
	class Paragraph : public WebComponent {
	private:
		const string className = "Paragraph";
		string value;
		string href;
	public:
		// Constructor
		Paragraph(string value = "", string href = "") : value(value), href(href) {}
		// Getter
		string getClassName() {
			return className;
		}
		string getValue() {
			return value;
		}
		string getHref() {
			return href;
		}
		// Setter
		void setValue(string value) {
			this->value = value;
		}
		void setHref(string href) {
			this->href = href;
		}
		// Generate HTML
		string generateHTML() {
			string html = "<p>";
			html += value;
			html += "</p>";
			// add href
			if (!href.empty()) {
				html = "<a href=\"" + href + "\">" + html + "</a>";
			}
			return html;
		}
	};

	class Image : public WebComponent {
	private:
		const string className = "Image";
		string src;
		string alt;
		string href;
	public:
		// Constructor
		Image(string src, string alt = "", string href = "") : src(src), alt(alt), href(href) {}
		// Getter
		string getClassName() {
			return className;
		}
		string getSrc() {
			return src;
		}
		string getAlt() {
			return alt;
		}
		string getHref() {
			return href;
		}
		// Setter
		void setSrc(string src) {
			this->src = src;
		}
		void setAlt(string alt) {
			this->alt = alt;
		}
		void setHref(string href) {
			this->href = href;
		}
		// Generate HTML
		string generateHTML() {
			string html = "<img src=\"" + src + "\" alt=\"" + alt + "\">";
			// add href
			if (!href.empty()) {
				html = "<a href=\"" + href + "\">" + html + "</a>";
			}
			return html;
		}
	};

	class Form : public WebComponent {
	private:
		string className;
		string action;
		string method;
		vector<WebComponent*> components;
	public:
		// Constructor
		Form(string action = "", string method = "") : action(action), method(method) {}
		// Getter
		string getClassName() {
			return className;
		}
		string getAction() {
			return action;
		}
		string getMethod() {
			return method;
		}
		vector<WebComponent*> getComponents() {
			return components;
		}
		// Setter
		void setAction(string action) {
			this->action = action;
		}
		void setMethod(string method) {
			this->method = method;
		}
		void addComponent(WebComponent* component) {
			components.push_back(component);
		}
		void insertComponent(int index, WebComponent* component) {
			components.insert(components.begin() + index, component);
		}
		void removeComponent(int index) {
			components.erase(components.begin() + index);
		}
		// Generate HTML
		string generateHTML() {
			string html = "<form action=\"" + action + "\" method=\"" + method + "\">";
			for (int i = 0; i < components.size(); i++) {
				html += components[i]->generateHTML();
			}
			html += "</form>";
			return html;
		}
	};

	class Input : public WebComponent {
	private:
		const string className;
		vector<string> types = { "text", "password", "submit", "reset", "radio", "checkbox", "button", "file", "hidden", "image", "number", "range", "search", "tel", "url", "email", "date", "month", "week", "time", "datetime", "datetime-local", "color" };
		string type;
		string name;
		string value;
		string placeholder;
	public:
		// Constructor
		Input(string type, string value)
			: type(type), value(value) {};
		Input(string type, string name, string placeholder)
			: type(type), name(name), placeholder(placeholder) {}
		Input(string type, string name, string value, string placeholder)
			: type(type), name(name), value(value), placeholder(placeholder) {}
		// Getter
		string getClassName() {
			return className;
		}
		string getType() {
			return type;
		}
		string getName() {
			return name;
		}
		string getValue() {
			return value;
		}
		string getPlaceholder() {
			return placeholder;
		}
		// Setter
		void setType(string type) {
			this->type = type;
		}
		void setName(string name) {
			this->name = name;
		}
		void setValue(string value) {
			this->value = value;
		}
		void setPlaceholder(string placeholder) {
			this->placeholder = placeholder;
		}
		// Generate HTML
		string generateHTML() {
			string html;
			if (type=="submit") {
				html = "<input type=\"" + type + "\" value=\"" + value + "\">";
			}
			else {
				html = "<input type=\"" + type + "\" name=\"" + name + "\" value=\"" + value + "\" placeholder=\"" + placeholder + "\">";
			}
			return html;
		}
	};

	class Select : public WebComponent {
	private:
		const string className = "Select";
		string name;
		vector<string> options;
	public:
		// Constructor
		Select(string name, vector<string> options = {}) : name(name), options(options) {}
		// Getter
		string getClassName() {
			return className;
		}
		string getName() {
			return name;
		}
		vector<string> getOptions() {
			return options;
		}
		// Setter
		void setName(string name) {
			this->name = name;
		}
		void setOptions(vector<string> options) {
			this->options = options;
		}
		void addOption(string option) {
			options.push_back(option);
		}
		void removeOption(string option) {
			for (int i = 0; i < options.size(); i++) {
				if (options[i] == option) {
					options.erase(options.begin() + i);
					break;
				}
			}
		}
		void removeOptionByIndex(int index) {
			options.erase(options.begin() + index);
		}
		void insertOption(int index, string option) {
			options.insert(options.begin() + index, option);
		}
		void removeOption(int index) {
			options.erase(options.begin() + index);
		}
		// Generate HTML
		string generateHTML() {
			string html = "<select name=\"" + name + "\">";
			for (int i = 0; i < options.size(); i++) {
				html += "<option value=\"" + options[i] + "\">" + options[i] + "</option>";
			}
			html += "</select>";
			return html;
		}
	};

	class Table : public WebComponent {
	private:
		const string className = "Table";
		vector<vector<string>> data;
		vector<string> headers;
		vector<string> footers;
	public:
		// Constructor
		Table(vector<vector<string>> data) : data(data) {}
		Table(vector<vector<string>> data, vector<string> headers) 
			: data(data) , headers(headers){}
		Table(vector<vector<string>> data, vector<string> headers, vector<string> footers) 
			: data(data) , headers(headers), footers(footers){}
		// Getter
		string getClassName() {
			return className;
		}
		vector<vector<string>> getData() {
			return data;
		}
		vector<string> getHeaders() {
			return headers;
		}
		vector<string> getFooters() {
			return footers;
		}
		// Setter
		void setData(vector<vector<string>> data) {
			this->data = data;
		}
		void setHeaders(vector<string> headers) {
			this->headers = headers;
		}
		void setFooters(vector<string> footers) {
			this->footers = footers;
		}
		void addRow(vector<string> row) {
			data.push_back(row);
		}
		void removeRow(int index) {
			data.erase(data.begin() + index);
		}
		void insertRow(int index, vector<string> row) {
			data.insert(data.begin() + index, row);
		}
		void addColumn(vector<string> column) {
			for (int i = 0; i < column.size(); i++) {
				for (int j = 0; j < data.size(); j++) {
					data[j].push_back(column[i]);
				}
			}
		}
		void removeColumn(int index) {
			for (int i = 0; i < data.size(); i++) {
				data[i].erase(data[i].begin() + index);
			}
		}
		void insertColumn(int index, vector<string> column) {
			for (int i = 0; i < data.size(); i++) {
				data[i].insert(data[i].begin() + index, column[i]);
			}
		}
		void addHeader(string header) {
			headers.push_back(header);
		}
		void removeHeader(int index) {
			headers.erase(headers.begin() + index);
		}
		void insertHeader(int index, string header) {
			headers.insert(headers.begin() + index, header);
		}
		void addFooter(string footer) {
			footers.push_back(footer);
		}
		void removeFooter(int index) {
			footers.erase(footers.begin() + index);
		}
		void insertFooter(int index, string footer) {
			footers.insert(footers.begin() + index, footer);
		}
		// Generate HTML
		string generateHTML() {
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
	};

	class WebPage {
	private:
		string filename;
		string title;
		string charset;
		string description;
		vector<string> keywords;
		vector<WebComponent*> components;
	public:
		// Constructor
		WebPage(string filename, string title, string charset = "utf-8") : filename(filename), title(title), charset(charset) {}
		WebPage(string filename, string title, string description , string charset = "utf-8") :filename(filename), title(title), description(description), charset(charset) {}
		WebPage(string filename, string title, string description, vector<string> keywords, string charset = "utf-8") :filename(filename), title(title), description(description), keywords(keywords), charset(charset) {}
		// Getter
		string getFilename() {
			return filename;
		}
		string getTitle() {
			return title;
		}
		string getCharset() {
			return charset;
		}
		string getDescription() {
			return description;
		}
		vector<string> getKeywords() {
			return keywords;
		}
		string getKeywordsHTML() {
			string keywords = "";
			for (int i = 0; i < this->keywords.size(); i++) {
				keywords += this->keywords[i];
				if (i != this->keywords.size() - 1) {
					keywords += ", ";
				}
			}
			return keywords;
		}
		vector<WebComponent*> getComponents() {
			return components;
		}
		// Setter
		void setTitle(string title) {
			this->title = title;
		}
		void setCharset(string charset) {
			this->charset = charset;
		}
		void setDescription(string description) {
			this->description = description;
		}
		void setKeywords(vector<string> keywords) {
			this->keywords = keywords;
		}
		void addKeyword(string keyword) {
			keywords.push_back(keyword);
		}
		void insertKeyword(int index, string keyword) {
			keywords.insert(keywords.begin() + index, keyword);
		}
		void removeKeyword(string keyword) {
			for (int i = 0; i < keywords.size(); i++) {
				if (keywords[i] == keyword) {
					keywords.erase(keywords.begin() + i);
					break;
				}
			}
		}
		void removeKeywordByIndex(int index) {
			keywords.erase(keywords.begin() + index);
		}
		// Bind
		void bind(WebComponent* component) {
			components.push_back(component);
		}
		void add(WebComponent* component) {
			components.push_back(component);
		}
		void insert(int index, WebComponent* component) {
			components.insert(components.begin() + index, component);
		}
		void remove(WebComponent* component) {
			for (int i = 0; i < components.size(); i++) {
				if (components[i] == component) {
					components.erase(components.begin() + i);
					break;
				}
			}
		}
		void removeByIndex(int index) {
			components.erase(components.begin() + index);
		}
		// Generate HTML
		string generateHTML() {
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
		// Save to file
		void save(string path) {
			// ±£´æÎÄ¼þ
			ofstream file;
			file.imbue(locale("chs"));
			file.open(path, ios::out);
			file << generateHTML();
			file.close();
		}
	};
	
	class Project {
	private:
		string name;
		string path;
		vector<WebPage*> pages;
	public:
		Project(string name, string path) :name(name), path(path) {}
		string getName() {
			return name;
		}
		string getPath() {
			return path;
		}
		vector<WebPage*> getPages() {
			return pages;
		}
		void setName(string name) {
			this->name = name;
		}
		void setPath(string path) {
			this->path = path;
		}
		void add(WebPage* page) {
			pages.push_back(page);
		}
		void insert(int index, WebPage* page) {
			pages.insert(pages.begin() + index, page);
		}
		void remove(WebPage* page) {
			for (int i = 0; i < pages.size(); i++) {
				if (pages[i] == page) {
					pages.erase(pages.begin() + i);
					break;
				}
			}
		}
		void removeByIndex(int index) {
			pages.erase(pages.begin() + index);
		}
		void save() {
			for (int i = 0; i < pages.size(); i++) {
				pages[i]->save(path + "/" + pages[i]->getFilename() + ".html");
			}
		}
	};
	
	class CLI {
	private:
		Project* project;
		vector<string> split(string s, char ch)
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
	public:
		CLI() {
			project = NULL;
			mainMenu();
		}
		void mainMenu() {
			cout << "1. New Project" << endl;
			cout << "0. Exit" << endl;
			int choice = 0; 
			cin >> choice;
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
		void newProject() {
			cout << "Project name: ";
			string name;
			cin >> name;
			cout << "Project path: ";
			string path;
			cin >> path;
			project = new Project(name, path);
			newPage();
		}
		void projectMenu() {
			cout << "1. New Page" << endl;
			cout << "2. Edit Page" << endl;
			cout << "3. Save Project" << endl;
			cout << "0. Back" << endl;
			int choice = 0; 
			cin >> choice;
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
		void pageList() {
			cout << "Page List" << endl;
			for (int i = 0; i < project->getPages().size(); i++) {
				cout << i + 1 << ". " << project->getPages()[i]->getTitle() << endl;
			}
			cout << "0. Back" << endl;
			int choice = 0; cin >> choice;
			cin >> choice;
			if (choice == 0) {
				projectMenu();
			}
			else {
				pageMenu(project->getPages()[choice - 1]);
			}
		}
		void newPage() {
			cout << "Page Filename: ";
			string filename;
			cin >> filename;
			cout << "Page title: ";
			string title;
			cin >> title;
			cout << "Page charset: ";
			string charset;
			cin >> charset;
			cout << "Page description: ";
			string description;
			cin >> description;
			cout << "Page keywords: ";
			string keywords;
			cin >> keywords;
			WebPage* page = new WebPage(filename, title, description, split(keywords, ','), charset);
			project->add(page);
			pageMenu(page);
		}
		void pageMenu(WebPage* page) {
			cout << "1. Edit Title" << endl;
			cout << "2. Edit Charset" << endl;
			cout << "3. Edit Description" << endl;
			cout << "4. Edit Keywords" << endl;
			cout << "5. Add Component" << endl;
			cout << "6. Edit Component" << endl;
			cout << "7. Remove Component" << endl;
			cout << "0. Back" << endl;
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			int choice = 0; 
			cin >> choice ;
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
		void editTitle(WebPage* page) {
			cout << "New title: ";
			string title;
			cin >> title;
			page->setTitle(title);
			pageMenu(page);
		}
		void editCharset(WebPage* page) {
			cout << "New charset: ";
			string charset;
			cin >> charset;
			page->setCharset(charset);
			pageMenu(page);
		}
		void editDescription(WebPage* page) {
			cout << "New description: ";
			string description;
			cin >> description;
			page->setDescription(description);
			pageMenu(page);
		}
		void editKeywords(WebPage* page) {
			cout << "New keywords: ";
			string keywords;
			cin >> keywords;
			page->setKeywords(split(keywords, ','));
			pageMenu(page);
		}
		void addComponent(WebPage* page) {
			cout << "1. Add Text" << endl;
			cout << "2. Add Image" << endl;
			cout << "3. Add Form" << endl;
			cout << "4. Add Input" << endl;
			cout << "5. Add Table" << endl;
			cout << "0. Back" << endl;
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			int choice = 0; 
			cin >> choice;
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
		void addText(WebPage* page) {
			cout << "1. Heading" << endl;
			cout << "2. Paragraph" << endl;
			cout << "0. Back" << endl;
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			int choice = 0; 
			cin >> choice;
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
		void addHeading(WebPage* page) {
			cout << "Heading level: ";
			int level;
			cin >> level;
			cout << "Heading text: ";
			string text;
			cin >> text;
			cout << "Url (Optional): ";
			string url;
			cin >> url;
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
		void addParagraph(WebPage* page) {
			cout << "Paragraph text: ";
			string text;
			cin >> text;
			cout << "Url (Optional): ";
			string url;
			cin >> url;
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
		void addImage(WebPage* page) {
			cout << "Image url: ";
			string src;
			cin >> src;
			cout << "Image description: ";
			string description;
			cin >> description;
			cout << "Url (Optional): ";
			string url;
			cin >> url;
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
		void addForm(WebPage* page) {
			cout << "Form action: ";
			string action;
			cin >> action;
			cout << "Form method: ";
			string method;
			cin >> method;
			Form* form = new Form(action, method);
			page->add(form);
			addComponent(page);
		}
		void addInput(WebPage* page) {
			cout << "1. Text" << endl;
			cout << "2. Password" << endl;
			cout << "3. Submit" << endl;
			cout << "Input type: ";
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			int choice = 0; 
			cin >> choice;
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
		void addTextInput(WebPage* page) {
			cout << "Input name: ";
			string name;
			cin >> name;
			cout << "Input value (Optional): ";
			string value;
			cin >> value;
			cout << "Input Placeholder: ";
			string placeholder;
			cin >> placeholder;
			Input* text = new Input("text", name, placeholder);
			if (!value.empty()) {
				text->setValue(value);
			}
			page->add(text);
			addComponent(page);
		}
		void addPassword(WebPage* page) {
			cout << "Input name: ";
			string name;
			cin >> name;
			cout << "Input value (Optional): ";
			string value;
			cin >> value;
			cout << "Input Placeholder: ";
			string placeholder;
			cin >> placeholder;
			Input* password = new Input("password", name, placeholder);
			if (!value.empty()) {
				password->setValue(value);
			}
			page->add(password);
			addComponent(page);
		}
		void addSubmit(WebPage* page) {
			cout << "Input value: ";
			string value;
			cin >> value;
			Input* submit = new Input("submit", value);
			page->add(submit);
			addComponent(page);
		}
		void addTable(WebPage* page) {
			vector<string> headers;
			cout << "Table headers (Optional): ";
			string header;
			cin >> header;
			while (!header.empty()) {
				headers.push_back(header);
				cin >> header;
			}
			vector<vector<string>> data;
			cout << "Table data: ";
			string datum;
			cin >> datum;
			while (!datum.empty()) {
				vector<string> row;
				while (!datum.empty()) {
					row.push_back(datum);
					cin >> datum;
				}
				data.push_back(row);
			}
			vector<string> footers;
			cout << "Table footers (Optional): ";
			string footer;
			cin >> footer;
			while (!footer.empty()) {
				footers.push_back(footer);
				cin >> footer;
			}
			Table * table = new Table(data);
			if (!headers.empty()) {
				table->setHeaders(headers);
			}
			if (!footers.empty()) {
				table->setFooters(footers);
			}
			page->add(table);
			addComponent(page);
		}
		void componentsList(WebPage* page) {
			for (int i = 0; i < page->getComponents().size(); i++) {
				cout << i << ". " << page->getComponents()[i]->getClassName() << endl;
			}
		}
		void editComponent(WebPage* page) {
			componentsList(page);
			cout << "Component to edit: ";
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			int choice = 0; 
			cin >> choice;
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
		void editHeading(WebPage* page, int index) {
			cout << "Heading text: ";
			string text;
			cin >> text;
			cout << "Heading level: ";
			int level;
			cin >> level;
			((Heading*)page->getComponents()[index])->setValue(text);
			((Heading*)page->getComponents()[index])->setLevel(level);
		}
		void editParagraph(WebPage* page, int index) {
			cout << "Paragraph text: ";
			string text;
			cin >> text;
			((Paragraph*)page->getComponents()[index])->setValue(text);
		}
		void editImage(WebPage* page, int index) {
			cout << "Image url: ";
			string src;
			cin >> src;
			cout << "Image description: ";
			string description;
			cin >> description;
			cout << "Url (Optional): ";
			string url;
			cin >> url;
			((Image*)page->getComponents()[index])->setSrc(src);
			((Image*)page->getComponents()[index])->setAlt(description);
			if (!url.empty()) {
				((Image*)page->getComponents()[index])->setHref(url);
			}
		}
		void editForm(WebPage* page, int index) {
			cout << "Form action: ";
			string action;
			cin >> action;
			cout << "Form method: ";
			string method;
			cin >> method;
			((Form*)page->getComponents()[index])->setAction(action);
			((Form*)page->getComponents()[index])->setMethod(method);
		}
		void editInput(WebPage* page, int index) {
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
		void editText(WebPage* page, int index) {
			cout << "Input name: ";
			string name;
			cin >> name;
			cout << "Input value (Optional): ";
			string value;
			cin >> value;
			cout << "Input Placeholder: ";
			string placeholder;
			cin >> placeholder;
			((Input*)page->getComponents()[index])->setName(name);
			((Input*)page->getComponents()[index])->setPlaceholder(placeholder);
			if (!value.empty()) {
				((Input*)page->getComponents()[index])->setValue(value);
			}
		}
		void editPassword(WebPage* page, int index) {
			cout << "Input name: ";
			string name;
			cin >> name;
			cout << "Input value (Optional): ";
			string value;
			cin >> value;
			cout << "Input Placeholder: ";
			string placeholder;
			cin >> placeholder;
			((Input*)page->getComponents()[index])->setName(name);
			((Input*)page->getComponents()[index])->setPlaceholder(placeholder);
			if (!value.empty()) {
				((Input*)page->getComponents()[index])->setValue(value);
			}
		}
		void editSubmit(WebPage* page, int index) {
			cout << "Input value: ";
			string value;
			cin >> value;
			((Input*)page->getComponents()[index])->setValue(value);
		}
		void editTable(WebPage* page, int index) {
			cout << "Table headers (Optional): ";
			vector<string> headers;
			vector<string> footers;
			string header;
			cin >> header;
			while (!header.empty()) {
				headers.push_back(header);
				cin >> header;
			}
			((Table*)page->getComponents()[index])->setHeaders(headers);
			cout << "Table footers (Optional): ";
			string footer;
			cin >> footer;
			while (!footer.empty()) {
				footers.push_back(footer);
				cin >> footer;
			}
			((Table*)page->getComponents()[index])->setFooters(footers);
		}
		void removeComponent(WebPage* page) {
			componentsList(page);
			cout << "Component to remove: ";
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			int choice = 0; 
			cin >> choice;
			page->remove(page->getComponents()[choice]);
		}
		
	};
}

int main() {
	EcyHTML::CLI * cli = new EcyHTML::CLI();
	return 0;
}