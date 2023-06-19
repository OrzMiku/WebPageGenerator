#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<fstream>

using namespace std;

namespace EcyHTML {
	class WebComponent {
	public:
		// Generate HTML
		virtual string generateHTML() = 0;
	};

	class Heading : public WebComponent {
	private:
		string value;
		string href;
		int level;
	public:
		// Constructor
		Heading( string value,int level = 1) : value(value), level(level) {}
		Heading( string value,string href,int level = 1) : value(value), href(href), level(level) {}
		// Getter
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
		string value;
		string href;
	public:
		// Constructor
		Paragraph(string value = "", string href = "") : value(value), href(href) {}
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
		string src;
		string alt;
		string href;
	public:
		// Constructor
		Image(string src, string alt = "", string href = "") : src(src), alt(alt), href(href) {}
		// Getter
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
		string action;
		string method;
		vector<WebComponent*> components;
	public:
		// Constructor
		Form(string action = "", string method = "") : action(action), method(method) {}
		// Getter
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
		vector<string> types = { "text", "password", "submit", "reset", "radio", "checkbox", "button", "file", "hidden", "image", "number", "range", "search", "tel", "url", "email", "date", "month", "week", "time", "datetime", "datetime-local", "color" };
		string type;
		string name;
		string value;
		string placeholder;
	public:
		// Constructor
		Input(string type, string name, string placeholder)
			: type(type), name(name), placeholder(placeholder) {}
		Input(string type, string name, string value, string placeholder)
			: type(type), name(name), value(value), placeholder(placeholder) {}
		// Getter
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
				html = "<input type=\"" + type + "\" name=\"" + name + "\" value=\"" + placeholder + "\">";
			}
			else {
				html = "<input type=\"" + type + "\" name=\"" + name + "\" value=\"" + value + "\" placeholder=\"" + placeholder + "\">";
			}
			return html;
		}
	};

	class Select : public WebComponent {
	private:
		string name;
		vector<string> options;
	public:
		// Constructor
		Select(string name, vector<string> options = {}) : name(name), options(options) {}
		// Getter
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
		// int cols, rows;
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
		string title;
		string charset;
		string description;
		vector<string> keywords;
		vector<WebComponent*> components;
	public:
		// Constructor
		WebPage(string title, string charset = "utf-8") :title(title), charset(charset){}
		WebPage(string title, string description , string charset = "utf-8") :title(title), description(description), charset(charset) {}
		WebPage(string title, string description, vector<string> keywords, string charset = "utf-8") :title(title), description(description), keywords(keywords), charset(charset) {}
		// Getter
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
			ofstream file;
			file.imbue(locale("chs"));
			file.open(path, ios::out);
			file << generateHTML();
			file.close();
		}
	};

}



int main() {
	using namespace EcyHTML;
	WebPage* page = new WebPage("Hello World", "This is my page", { "page", "my page", "my" });
	page->add(new Heading("Hello Wolrd"));
	page->add(new Paragraph("This is my page"));
	page->add(new Paragraph("Baidu", "https://www.baidu.com/"));
	page->add(new Image("https://pic.mikupan.com/9ssVw1.png","Baidu","https://www.baidu.com"));
	Form* form = new Form("https://www.baidu.com/s","get");
	form->addComponent(new Heading("Form",2));
	form->addComponent(new Input("text","wd","Context"));
	form->addComponent(new Input("submit","submit","Search"));
	Select *select = new Select("select", { "select1", "select2"});
	select->addOption("select3");
	select->removeOption("select2");
	form->insertComponent(2, select);
	page->add(form);
	Table* table = new Table(
		{ 
			{"ZhangSan", "male", "18"} ,
			{"Lisi", "male", "18"}
		}, {"Name", "Gender", "age"});
	table->addColumn({"2201"});
	table->addHeader("Class");
	table->addRow({"WangMazi", "male", "18", "2202"});
	page->add(table);
	page->save("index.html");

	return 0;
}