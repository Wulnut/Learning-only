
//
//  main.cpp
//  MarkdownParser
//
 
#include <fstream>         // std::ofstream
#include <string>
#include "mdtransform.hpp"  // 需要实现的 Markdown 解析类
using namespace std;
 
int main() {
    // 装载构造 Markdown 文件
    MarkdownTransform transformer("test.md");
 
    // 编写一个 `getTableOfContents()` 方法来获取 Markdown 文件 HTML 格式的目录
    string table = transformer.getTableOfContents();
 
    // 编写一个 `getContents()` 方法来获取 Markdown 转成 HTML 后的内容
    string contents = transformer.getContents();
 
    // 准备要写入的 HTML 文件头尾信息
    string head = "<!DOCTYPE html><html><head>\
        <meta charset=\"utf-8\">\
        <title>Markdown</title>\
        <link rel=\"stylesheet\" href=\"github-markdown.css\">\
        </head><body><article class=\"markdown-body\">";
    string end = "</article></body></html>";
 
    // 创建一个out变量，将结果写入到文件
    ofstream out;
    out.open("output/index.html");
    // 将转换后的内容构造到 HTML 的 <article></article> 标签内部
    out << head+table+contents+end;
    out.close();
    return 0;
}