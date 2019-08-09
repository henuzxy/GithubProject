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

> 为了与内置版本保持一致，后置运算符应该返回对象的原值(递增或递减前的值)，返回的形式时一个值而非引用。



