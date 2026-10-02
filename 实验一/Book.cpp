#include "Book.h"
#include <iostream>
using namespace std;        

//--------------------------------------------------------------------------------------------------------------------------------------------------------------
// book类的成员函数实现

// 默认构造函数:将数据成员初始化为一定的值
book::book(){
    isbn = 0;
    bookName = "未命名";
    author = "佚名";
    press = "未知出版社";
    price = 0.0;
    pages = 0;
    isAvailable = true;//新书默认可借,必须初始化
    bookId = 0;
    max_borrow_days = 30;
    cout << "这是不带参数的构造函数" << endl;
}

// 重载构造函数:以相应参数构造需要的对象
book::book(long long isbn, string name, string auth, string pub, double price, int pages, int id, int max){
    this->isbn = isbn;
    this->author = auth;
    this->press = pub;
    this->price = price;
    this->pages = pages;
    this->isAvailable = true;//新书默认可借
    this->bookId = id;
    this->max_borrow_days = max;
    cout << "这是带参数的构造函数" << endl;
}

// 输入函数
void book::input(){
    cout << "请输入图书号: ";
    cin >> isbn;
    cout << "请输入书名: ";
    cin >> bookName;
    cout << "请输入作者: ";
    cin >> author;
    cout << "请输入出版社: ";
    cin >> press;
    cout << "请输入价格: ";
    cin >> price;
    cout << "请输入页数: ";
    cin >> pages;
    cout << "请输入条码号: ";
    cin >> bookId;
    cout << "请输入最大借书天数: ";
    cin >> max_borrow_days;
}

// 输出函数
void book::output(){
    cout << "图书号: " << isbn << endl;
    cout << "书名: " << bookName << endl;
    cout << "作者: " << author << endl;
    cout << "出版社: " << press << endl;
    cout << "价格: " << price << " 元" << endl;
    cout << "页数: " << pages << " 页" << endl;
    cout << "条码号: " << bookId << endl;
    cout << "最大借书天数: " << max_borrow_days << endl;
    cout << "状态: " << (isAvailable ? "可借" : "已借出") << endl;
}

// 修改函数
void book::changeInfo(){
    cout << "请输入新的图书号: ";
    cin >> isbn;
    cout << "请输入新的书名: ";
    cin >> bookName;
    cout << "请输入新的作者: ";
    cin >> author;
    cout << "请输入新的出版社: ";
    cin >> press;
    cout << "请输入新的价格: ";
    cin >> price;
    cout << "请输入新的页数: ";
    cin >> pages;
    cout << "请输入新的条码号: ";
    cin >> bookId;
    cout << "请输入新的最大借书天数: ";
    cin >> max_borrow_days;
}

//初始化函数
void book::init(){
    cout << "请输入您需要初始化的图书号: ";
    cin >> isbn;
    while (!checkIsbn()){//自动验证ISBN号是否合法,不合法要求重新输入
        cout << "该ISBN号不合法,请重新输入图书号: ";
        cin >> isbn;
    }
    bookName = "未命名";
    author = "佚名";
    press = "未知出版社";
    price = 0.0;
    pages = 0;
    cout << "请输入条码号: ";
    cin >> bookId;
    cout << "请输入最大借书天数: ";
    cin >> max_borrow_days;
    cout << "初始化完成!" << endl;

}

//获取操作
int book::getBookId() const {//const表示不修改数据成员,仅用于获取值
    return bookId;
}
long long book::getIsbn() const {//const表示不修改数据成员,仅用于获取值
    return isbn;
}
bool book::getAvailable() const {
    return isAvailable;
}
int book::getMaxDays() const {
    return max_borrow_days;
}
string book::getBookName() const {//const表示不修改数据成员,仅用于获取值
    return bookName;
}
double book::getPrice() const {
    return price;
}
int book::getPages() const {
    return pages;
}
void book::setBookId(int id) { bookId = id; }
void book::setAvailable(bool v) { isAvailable = v; }

// 其他操作:验证图书ISBN号的合法性(ISBN-13 校验位算法)
bool book::checkIsbn() const {
    if (isbn <= 0)
    return false;
    long long t = isbn;//将ISBN号赋值给临时变量t,避免修改原始数据
    int d[13], n = 0;//n表示当前处理的位数


    while (t > 0 && n < 13) { 
        d[n] = int(t % 10); //将当前位的数字赋值给d[n]n增加1,指向下一个位置
        n = n+1;//n增加1,指向下一个位置
        t /= 10; //将t除以10,得到下一位的数字
    }


    if (n != 13 || t != 0) 
    return false;//必须是13位

    //d[0]是第13位(校验位),d[12]是第1位
    //前12位加权求和:第1,3,5...位(奇数位)乘1,第2,4,6...位(偶数位)乘3


    int sum = 0;
    for (int i = 1; i <= 12; i++){
        sum += d[13 - i] * (i % 2 == 1 ? 1 : 3);
    }
    //校验位 = (10 - sum % 10) % 10
    return (10 - sum % 10) % 10 == d[0];
}

// 内联函数
void book::showInfo(){      
    cout << "图书号: " << isbn << endl;
    cout << "书名: " << bookName << endl;
    cout << "作者: " << author << endl;
    cout << "出版社: " << press << endl;
    cout << "价格: " << price << " 元" << endl;
    cout << "页数: " << pages << " 页" << endl;
    cout << "条码号: " << bookId << endl;
    cout << "最大借书天数: " << max_borrow_days << endl;
}
