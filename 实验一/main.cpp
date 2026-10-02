#include <iostream>
#include "Book.h"
using namespace std;

//================ 对象生成与功能测试 ================
int main(){
//     cout << "========== 1.默认构造函数:数据成员初始化为默认值 ==========" << endl;
//     book b1;
//     b1.output();
// //----------------------------------------------------------------------------------------------------------
//     cout << "\n========== 2.重载构造函数:以相应参数构造对象 ==========" << endl;
//     book b2(9787111122227LL, "C++程序设计", "张三", "清华大学出版社", 59.8, 320, 123456, 30);
//     b2.output();
// //----------------------------------------------------------------------------------------------------------
//     cout << "\n========== 3.验证图书ISBN号的合法性 ==========" << endl;
//     if (b2.checkIsbn())
//         cout << "《" << b2.getBookName() << "》的ISBN号合法!" << endl;
//     else
//         cout << "《" << b2.getBookName() << "》的ISBN号不合法!" << endl;

//     book b3(9787111122222LL, "数据结构", "李四", "人民邮电出版社", 45.0, 280, 123457, 30);//校验位错误
//     b3.output();
//     if (b3.checkIsbn())
//         cout << "《" << b3.getBookName() << "》的ISBN号合法!" << endl;
//     else
//         cout << "《" << b3.getBookName() << "》的ISBN号不合法!" << endl;
// //----------------------------------------------------------------------------------------------------------
//     cout << "\n========== 4.获取操作 ==========" << endl;
//     cout << "书名: " << b2.getBookName() << endl;
//     cout << "图书号: " << b2.getIsbn() << endl;
//     cout << "价格: " << b2.getPrice() << " 元" << endl;
//     cout << "页数: " << b2.getPages() << " 页" << endl;
//     cout << "条码号: " << b2.getBookId() << endl;
//     cout << "最大借书天数: " << b2.getMaxDays() << " 天" << endl;
// //----------------------------------------------------------------------------------------------------------
//     cout << "\n========== 5.修改操作 ==========" << endl;
//     b2.changeInfo();
//     b2.output();
// //----------------------------------------------------------------------------------------------------------
//     cout << "\n========== 6.在馆状态(可借不可借) ==========" << endl;
//     cout << "当前状态: " << (b2.getAvailable() ? "可借" : "已借出") << endl;
//     b2.setAvailable(false);//模拟借出
//     cout << "借出后状态: " << (b2.getAvailable() ? "可借" : "已借出") << endl;
//     b2.setAvailable(true);//模拟归还
//     cout << "归还后状态: " << (b2.getAvailable() ? "可借" : "已借出") << endl;

//     return 0;
    book b1, b2, b3, b4, b6;//每个功能操作一个图书对象
    int choice, id;//操作选项/输入的条码号

    while (true){//循环显示菜单,直到选择退出
        cout<<"###############################################"<<endl;
        cout<<"##           图书管理系统(实验一)               ##"<<endl;
        cout<<"##           1.图书信息初始化                   ##"<<endl;
        cout<<"##           2.添加图书                        ##"<<endl;
        cout<<"##           3.图书修改                        ##"<<endl;
        cout<<"##           4.图书归还                        ##"<<endl;
        cout<<"##           5.图书在馆状态                    ##"<<endl;
        cout<<"##           6.退出系统                        ##"<<endl;
        cout<<"###############################################"<<endl;
        cout<<"请输入您要执行的操作: ";
        cin>>choice;
        cout<<endl;

        switch (choice){
            case 1://图书信息初始化
                b1.init();
                break;

            case 2://添加图书
                b2.input();
                if (b2.checkIsbn())//判断ISBN号是否合法
                    cout<<"添加成功!"<<endl;
                else
                    cout<<"该图书ISBN号不合法,添加失败!"<<endl;
                break;

            case 3://图书修改
                cout<<"请输入您要修改的图书的条码号: ";
                cin>>id;
                if(id == b3.getBookId()){//判断图书是否存在
                    b3.changeInfo();
                    if (!b3.checkIsbn())//判断修改后的ISBN号是否合法
                        cout<<"警告:修改后的ISBN号不合法!"<<endl;
                }
                else
                    cout<<"该图书不存在!"<<endl;
                break;

            case 4://图书归还
                cout<<"请输入您要归还的图书的条码号: ";
                cin>>id;
                if(id == b4.getBookId()){
                    b4.setAvailable(true);
                    cout<<"该图书已归还!"<<endl;
                }
                else
                    cout<<"该图书不存在!"<<endl;
                break;

            case 5://图书在馆状态
                cout<<"请输入您要查询的图书的条码号: ";
                cin>>id;
                if(id == b6.getBookId())
                    b6.showInfo();
                else
                    cout<<"该图书不存在!"<<endl;
                break;

            case 6://退出系统
                cout<<"谢谢使用!"<<endl;
                return 0;

            default:
                cout<<"输入错误!"<<endl;
                break;
        }
        cout<<endl;
    }
}
