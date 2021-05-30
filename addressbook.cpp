#include<iostream>
#include<string>
using namespace std;
// 显示菜单栏
void showMenu()
{
    cout<<"*****************************************"<<endl;
    cout<<"************* 1.添加联系人 **************"<<endl;
    cout<<"************* 2.显示联系人 **************"<<endl;
    cout<<"************* 3.删除联系人 **************"<<endl;
    cout<<"************* 4.查找联系人 **************"<<endl;
    cout<<"************* 5.修改联系人 **************"<<endl;
    cout<<"************* 6.清空联系人 **************"<<endl;
    cout<<"************* 0.退出通讯录 **************"<<endl;
    cout<<"*****************************************"<<endl;
}
// 联系人结构体
struct  Person
{
    string m_Name;
    int m_Sex;
    int m_Age;
    string m_Number;
    string m_Address;
};
//通讯录结构体
#define MAX 1000 // 最大人数
struct Addressbooks
{
    struct Person personArray[MAX];  //通讯录中保存的联系人数组
    int m_Size; //通讯录中人员个数
};
//1.添加联系人信息
void addPerson(Addressbooks *abs)
{
    if ( abs->m_Size == MAX)
    {
        cout<<"通讯录已满，无法添加"<<endl;
        return;
    }
    else
    {
        //姓名
        string name;
        cout<<"请输入姓名：" <<endl;
        cin>>name;
        abs->personArray[abs->m_Size].m_Name = name;

        //性别
        int sex = 0;
        cout<<"请输入性别："<<endl;
        cout<<"1————男"<<endl;
        cout<<"2————女"<<endl;
        while (true)
        {
            cin>>sex;
            if (sex == 1 || sex == 2)
            {
                abs->personArray[abs->m_Size].m_Sex = sex;
                break;
            }
            cout<<"输入有误，请重新输入"<<endl;
        }

        //年龄
        int age;
        cout<<"请输入年龄："<<endl;
        cin>>age;
        abs->personArray[abs->m_Size].m_Age = age;

        // 联系电话
        string tel;
        cout<<"请输入电话号码："<<endl;
        cin>>tel;
        abs->personArray[abs->m_Size].m_Number = tel;

        //住址
        string address;
        cout<<"请输入住址："<<endl;
        cin>>address;
        abs->personArray[abs->m_Size].m_Address = address;

        abs->m_Size++;

        cout<<" 添加成功"<<endl;
    }
    
}
//2.显示联系人
void showPerson(Addressbooks *abs)
{
    if (abs->m_Size == 0)
    {
        cout<<"当前记录为空" <<endl;
        return;
    }
    else
    {
        for (int i = 0; i < abs->m_Size; i++)
        {
            cout<<abs->personArray[i].m_Name<<" ";
            cout<<abs->personArray[i].m_Sex<<" ";
            cout<<abs->personArray[i].m_Age<<" ";
            cout<<abs->personArray[i].m_Number<<" ";
            cout<<abs->personArray[i].m_Address<<endl;
        }   
    }
}

//3.删除联系人
int isExist(Addressbooks *abs, string name)
{
    int ret;
    for (int i = 0; i < abs->m_Size; i++)
    {
        if (name == abs->personArray[i].m_Name)
        {
            return i;
        }
    }
    return -1;
}
void deletPerson(Addressbooks *abs)
{
    string name;
    cout<<"请输入要删除的联系人姓名："<<endl;
    cin>>name;
    int ret = isExist(abs,name);
    if (ret == -1)
    {
        cout<<"联系人不存在"<<endl;
    }
    else
    {
        for (int i = ret; i < abs->m_Size-1; i++)
        {
            abs->personArray[i]=abs->personArray[i+1];
        }
        abs->m_Size--;
        cout<<"删除成功"<<endl;
    }
    
}
//4. 查找联系人
void findPerson(Addressbooks *abs)
{
    string name;
    cout<<"请输入要查找的联系人姓名："<<endl;
    cin>>name;
    int ret = isExist(abs,name);
    if (ret == -1)
    {
        cout<<"联系人不存在"<<endl;
    }
    else
    {
        cout<<abs->personArray[ret].m_Name<<" ";
        cout<<abs->personArray[ret].m_Sex<<" ";
        cout<<abs->personArray[ret].m_Age<<" ";
        cout<<abs->personArray[ret].m_Number<<" ";
        cout<<abs->personArray[ret].m_Address<<endl;
    }   
}
// 5.修改联系人
void modifyPerson(Addressbooks *abs)
{
    string name;
    cout<<"请输入要删除的联系人姓名："<<endl;
    cin>>name;
    int ret = isExist(abs,name);
    if (ret == -1)
    {
        cout<<"联系人不存在"<<endl;
    }
    else
    {
        //姓名
        abs->personArray[ret].m_Name = name;

        //性别
        int sex = 0;
        cout<<"请输入性别："<<endl;
        cout<<"1————男"<<endl;
        cout<<"2————女"<<endl;
        while (true)
        {
            cin>>sex;
            if (sex == 1 || sex == 2)
            {
                abs->personArray[ret].m_Sex = sex;
                break;
            }
            cout<<"输入有误，请重新输入"<<endl;
        }

        //年龄
        int age;
        cout<<"请输入年龄："<<endl;
        cin>>age;
        abs->personArray[ret].m_Age = age;

        // 联系电话
        string tel;
        cout<<"请输入电话号码："<<endl;
        cin>>tel;
        abs->personArray[ret].m_Number = tel;

        //住址
        string address;
        cout<<"请输入住址："<<endl;
        cin>>address;
        abs->personArray[ret].m_Address = address;
        
        cout<<"修改成功"<<endl;
    }
}
// 6.清空联系人
void clearPerson(Addressbooks *abs)
{
    abs->m_Size = 0;
    cout<<"通讯录已为空"<<endl;

}

int main()
{
    //创建通讯录
    Addressbooks abs;
    //初始化通讯录中人数
    abs.m_Size = 0;
    int select = 0;      
    while (true)
    {
        showMenu(); 
        cin>>select;
        switch (select)
        {
        case 1:
            addPerson(&abs);
            break;
        case 2:
            showPerson(&abs);
            break;
        case 3:
            deletPerson(&abs);
            break;
        case 4:
            findPerson(&abs);
            break;
        case 5:
            modifyPerson(&abs);
            break;
        case 6:
            clearPerson(&abs);
            break;
        case 0:
            cout<<"欢迎下次使用"<<endl;
            //system("pause");
            return 0;
            break;
        default:
            break;
        }
    }
    //system("pause");
    return 0;
}