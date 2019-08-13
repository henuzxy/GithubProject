#### 类的内部越界函数的设计

```cpp
void check(size_type,const string &msg) const{
	if(size_type >= this->size())
		throw out_of_range(msg);//在<stdexcept>头文件下
}
```
---

使用下标运算符时，通常要定义两个版本，一个返回普通引用，另一个是类的常量成员并放回常量引用。这是为了使const修饰的类也能调用下标.

#### 区分前置和后置运算符

普通的重载无法区分这两种情况，因为重载的名字和对象的数量以及类型都是相同的。为了解决这个问题，后置版本会额外提供一个（不被使用）int类型的形参。当使用后置运算符时，编译器为这个形参提供一个值为0的实参。这个形参的唯一作用就是区分前置版本和后置版本的函数。不要在函数中使用这个参数。

```cpp
StrVecPtr operator++ (int);//后置++
StrVecptr operator++ ();//前置++
StrVecPtr operator-- (int);//后置--
StrVecPtr operator-- ();//前置--
```

> 为了与内置版本保持一致，后置运算符应该返回对象的原值(递增或递减前的值)，返回的形式时一个值而非引用。(这里返回引用，是因为返回的数据是存在于内部的值，不是一个局部变量)

对于const 修饰的变量,指向他的指针和引用也要有const

#### 函数调用运算符

```cpp
class absInt{
public:
    int operator()(int val){
        return val>0? val:-val;
    }
};
int main(void){
    absInt Abs;
    cout << Abs(-2);//输出为2
    return 0;
}
```

这里就含有一个调用运算符，返回int的绝对值。

函数调用运算符必须是成员函数。

##### 含有状态的函数对象类

- cout  标准输出流

- cerr 标准错误流

```cpp
class PrintString{
public:
    PrintString(ostream &_os = std::cout,char _sep = ' '):
        os(_os),sep(_sep){}
    void operator()(const string &s) const{
        os << s << sep;
    }

private:
    ostream &os;
    char sep;
};

for_each(str.begin(),str.end(),PrintString(cout,'\n'));
```

这就是一个打印string的类。也可以在for_each中调用。

#### 类型转换运算符

类转换运算符是类的一种特殊成员函数，它负责将一个类类型的值转换为其他类型。形式如下：

operator type() const;

类型转换运算符可以面向任意类型（除void外）进行定义，只要该类型能作为返回类型（函数，数组之类不能作为返回类型）

类型转化运算符是隐式执行的，所以无法给函数传递参数。

```cpp
class SmallInt{
public:
    SmallInt(int i = 0):val(i){}
    operator int () const{
        return val;
    }
private:
    size_t val;
};
SmallInt val(2);
    cout << val << endl;// 这里吧val隐式的转化为了int，然后被输出。
```

因为隐式的类型转化函数往往会导致一些问题，所以可以使用explicit修饰成显示的类型转化运算符

`explicit operator int() const;`再输出时就会报错。必须使用显示请求即`static_cast<int>(val)`这样就能输出了。

##### random_shuffle(first,last)

随机重新排列范围内的元素