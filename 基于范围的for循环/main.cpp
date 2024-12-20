//#include <iostream>
//#include<vector>
//using namespace std;
//
//int main()
//{
//    vector<int> t{1,2,3,4,5,6,7,8,9};
//    for(auto it=t.begin();it!=t.end();it++)
//    {
//        cout<<*it<<" ";
//    }
//    cout<<endl;
//    return 0;
//}

//#include <iostream>
//#include <vector>
//using namespace std;
//
//int main(void)
//{
//    vector<int> t{ 1,2,3,4,5,6 };
//    for (auto value : t)
//    {
//        cout << value << " ";
//    }
//    cout << endl;
//
//    return 0;
//}

//#include <iostream>
//#include <vector>
//using namespace std;
//
//int main()
//{
//    vector<int> t{ 1,2,3,4,5,6 };
//    cout << "遍历修改之前的容器: ";
//    for (auto &value : t)
//    {
//        cout << value++ << " ";
//    }
//    cout << endl << "遍历修改之后的容器: ";
//
//    for (auto &value : t)
//    {
//        cout << value << " ";
//    }
//    cout << endl;
//
//    return 0;
//}
//#include <iostream>
//#include <vector>
//using namespace std;
//
//int main(void)
//{
//    vector<int> t{ 1,2,3,4,5,6 };
//    for (const auto& value : t)
//    {
//        cout << value << " ";
//    }
//
//    return 0;
//}

//#include<iostream>
//#include<string>
//#include<map>
//using namespace std;
//int main()
//{
//    map<int,string> m{
//            {1,"luncy"},{2,"aoqi"},{3,"tom"}
//    };
//    // 基于范围的for循环方式
//    for (auto& it : m)
//    {
//        cout << "id: " << it.first << ", name: " << it.second << endl;
//    }
//
//    // 普通的for循环方式
//    for (auto it = m.begin(); it != m.end(); ++it)
//    {
//        cout << "id: " << it->first << ", name: " << it->second << endl;
//    }
//    return 0;
//}

//#include <iostream>
//#include <set>
//using namespace std;
//
//int main(void)
//{
//    set<int> st{ 1,2,3,4,5,6 };
//    for (auto &item : st)
//    {
//        cout << item++ << endl;		// error, 不能给常量赋值
//    }
//    return 0;
//}

//#include <iostream>
//#include <string>
//#include <map>
//using namespace std;
//
//int main(void)
//{
//    map<int, string> m{
//            {1, "lucy"},{2, "lily"},{3, "tom"}
//    };
//
//    for (auto& item : m)
//    {
//        // item.first 是一个常量
//        cout << "id: " << item.first++ << ", name: " << item.second << endl;  // error
//    }
//
//    return 0;
//}

//#include <iostream>
//#include <vector>
//using namespace std;
//
//vector<int> v{ 1,2,3,4,5,6 };
//vector<int>& getRange()
//{
//    cout << "get vector range..." << endl;
//    return v;
//}
//
//int main(void)
//{
//    for (auto val : getRange())
//    {
//        cout << val << " ";
//    }
//    cout << endl;
//
//    return 0;
//}
//只访问一次