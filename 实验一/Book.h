#ifndef BOOK_H
#define BOOK_H
#include <string>
using namespace std;

//--------------------------------------------------------------------------------------------------------------------------------------------------------------
class book{//图书类(实验一:类与对象)
    private:
    long long isbn;//图书号(ISBN 位数多,用 long long)
    string bookName;//书名
    string author;//作者
    string press;//出版社
    double price;//价格
    int pages;//页数
    bool isAvailable;//在馆状态(可借/不可借)
    int bookId;//条码号
    int max_borrow_days;//最大借书天数

    public:
    // 构造函数
    book();//默认构造函数:将数据成员初始化为一定的值
    book(long long isbn, string name, string auth, string pub, double price, int pages, int id, int max);//重载构造函数

    // 输入函数
    void input();

    // 输出函数
    void output();

    // 修改函数
    void changeInfo();

    //初始化函数
    void init();

    //获取操作
    int getBookId() const;
    long long getIsbn() const;
    bool getAvailable() const;
    int getMaxDays() const;
    string getBookName() const;
    double getPrice() const;
    int getPages() const;
    void setBookId(int id);
    void setAvailable(bool v);

    // 其他操作:验证图书ISBN号的合法性
    bool checkIsbn() const;

    // 内联函数
    void showInfo();
};

//--------------------------------------------------------------------------------------------------------------------------------------------------------------
#endif
