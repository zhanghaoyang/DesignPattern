// DesignPattern.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Singleton/Singleton.hpp"
#include "AbstractFactory/AnimalBlack.hpp"
#include "AbstractFactory/AnimalWhite.hpp"
#include "FactoryMethod/StudentWork.hpp"
#include "FactoryMethod/TeacherWork.hpp"
#include "Builder/ManBuilder.hpp"
#include "Builder/WomanBuilder.hpp"
#include "Builder/PersonDirector.hpp"
#include "Prototype/Prototype.hpp"
#include "Adapter/Adapter.hpp"
#include "Bridge/ConcretePerson.hpp"
#include "Bridge/ConcreteClothing.hpp"
#include "Composite/LeafComposite.hpp"
#include "Decorator/Decorator.hpp"
#include "Facade/Facade.hpp"
#include "Flyweight/Flyweight.hpp"
#include "Proxy/Proxy.hpp"
#include "COR/Handler.hpp"
#include "Command/Invoker.hpp"
#include "Interpreter/Expression.hpp"
#include "Iterator/List.hpp"
#include "Mediator/Mediator.hpp"
#include "Memento/Originator.hpp"
#include "Memento/Caretaker.hpp"
#include "Observer/Observer.hpp"
#include "State/ContextState.hpp"
#include "Strategy/ContextStrategy.hpp"
#include "TemplateMethod/Template.hpp"
#include "Visitor/Visitor.hpp"
#include "Extend/Extend.hpp"
#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>

void TestSingleton(int index, std::string name)
{
    printf("%02d. %s\n", index, name.c_str());
    Singleton::getInstance()->Process("I love yinger.");
    printf("\tSingleton::getInstance1: 0x%016llx\n", Singleton::getInstance());
    printf("\tSingleton::getInstance2: 0x%016llx\n", Singleton::getInstance());
}

void TestAbstractFactory(int index, std::string name)
{
    printf("\n%02d. %s\n", index, name.c_str());
    IAnimalFactory* factoryBlack = new AnimalFactoryBlack();
    ICat* blackCat = factoryBlack->CreateCat("blackCat");
    blackCat->eat();
    IDog* blackDog = factoryBlack->CreateDog("blackDog");
    blackDog->eat();

    IAnimalFactory* factoryWhite = new AnimalFactoryWhite();
    ICat* whiteCat = factoryWhite->CreateCat("whiteCat");
    whiteCat->eat();
    IDog* whiteDog = factoryWhite->CreateDog("whiteDog");
    whiteDog->eat();
}

void TestFactoryMethod(int index, std::string name)
{
    printf("\n%02d. %s\n", index, name.c_str());
    IWorkFactory* studentWorkFactory = new StudentWorkFactory();
    studentWorkFactory->getWork()->doWork();

    IWorkFactory* teacherWorkFactory = new TeacherWorkFactory();
    teacherWorkFactory->getWork()->doWork();
}

void TestBuilder(int index, std::string name)
{
    printf("\n%02d. %s\n", index, name.c_str());
    PersonDirector* pd = new PersonDirector();
    IPerson* man = pd->constructPerson(new ManBuilder());
    printf("\t%s\n", man->getBody().c_str());
    printf("\t%s\n", man->getFoot().c_str());
    printf("\t%s\n", man->getHead().c_str());

    IPerson* women = pd->constructPerson(new WomanBuilder());
    printf("\t%s\n", women->getBody().c_str());
    printf("\t%s\n", women->getFoot().c_str());
    printf("\t%s\n", women->getHead().c_str());
}

void TestPrototype(int index, std::string name)
{
    printf("\n%02d. %s\n", index, name.c_str()); // prototype first
    Prototype* pro1 = new ConcretePrototype("prototype first");
    Prototype* pro2 = pro1->clone();
    printf("\tinit Prototype: %s\n", pro1->getName().c_str());
    printf("\tclone Prototype: %s\n", pro2->getName().c_str());
    SafeDelete(pro1);
    SafeDelete(pro2);
}

void TestAdapter(int index, std::string name)
{
    printf("\n%02d. %s\n", index, name.c_str());
    ITarget* target = new Adapter(new Adaptee());
    target->adapteeMethod();
    target->adapterMethod();
}

void TestBridge(int index, std::string name)
{
    printf("\n%02d. %s\n", index, name.c_str());
    IPersonBridge* man = new ManBridge();
    IPersonBridge* lady = new LadyBridge();
    IClothing* jacket = new Jacket();
    IClothing* trouser = new Trouser();

    jacket->personDressCloth(man);
    trouser->personDressCloth(man);

    jacket->personDressCloth(lady);
    trouser->personDressCloth(lady);

    man->setClothing(jacket);
    man->dress();
    man->setClothing(trouser);
    man->dress();

    lady->setClothing(jacket);
    lady->dress();
    lady->setClothing(trouser);
    lady->dress();
}

void TestComposite(int index, std::string name)
{
    printf("\n%02d. %s\n", index, name.c_str());
    IEmployer* pm = new ProjectManager("ProjectManager");
    IEmployer* pa = new ProjectAssistant("ProjectAssistant");
    IEmployer* programmer1 = new Programmer("Programmer01");
    IEmployer* programmer2 = new Programmer("Programmer02");

    pm->Add(pa);            // 为项目经理添加项目助理
    pm->Add(programmer1);   // 为项目经理添加程序员
    pm->Add(programmer2);   // 为项目经理添加程序员

    std::list<IEmployer*> ems = pm->getEmployers();
    for (auto& em : ems)
    {
        printf("\tIEmployer: %s\n", em->getName().c_str());
    }

    pm->Del(programmer1);
    ems = pm->getEmployers();
    for (auto& em : ems)
    {
        printf("\tIEmployer: %s\n", em->getName().c_str());
    }
}

void TestDecorator(int index, std::string name)
{
    printf("\n%02d. %s\n", index, name.c_str());
    ManDec* man = new ManDec();
    ManDecoratorA* md1 = new ManDecoratorA();
    ManDecoratorB* md2 = new ManDecoratorB();

    md1->setPerson(man);
    md2->setPerson(md1);
    md2->eat();
}

void TestFacade(int index, std::string name)
{
    printf("\n%02d. %s\n", index, name.c_str());
    ServiceA* sa = new ServiceAImpl();
    ServiceB* sb = new ServiceBImpl();
    sa->methodA();
    sb->methodB();
    printf("\t========\n");

    // facade
    Facade* facade = new Facade();
    facade->methodA();
    facade->methodB();
}

void TestFlyweight(int index, std::string name)
{
    printf("\n%02d. %s\n", index, name.c_str());
    Flyweight* fly1 = FlyweightFactory::Get()->getFlyweight("a");
    fly1->action(1);

    Flyweight* fly2 = FlyweightFactory::Get()->getFlyweight("a");
    printf("\t(fly1 == fly2) - %d\n", (fly1 == fly2));

    Flyweight* fly3 = FlyweightFactory::Get()->getFlyweight("b");
    fly3->action(2);

    Flyweight* fly4 = FlyweightFactory::Get()->getFlyweight("c");
    fly4->action(3);

    Flyweight* fly5 = FlyweightFactory::Get()->getFlyweight("d");
    fly4->action(4);

    printf("\tFlyweightFactory::getSize: %d\n", FlyweightFactory::Get()->getSize());
}

void TestProxy(int index, std::string name)
{
    printf("\n%02d. %s\n", index, name.c_str());
    Object* obj = new ProxyObject();
    obj->action();
}

void TestCOR(int index, std::string name)
{
    printf("\n%02d. %s\n", index, name.c_str());
    RequestHandle* hr = new HRRequestHandle();
    RequestHandle* pm = new PMRequestHandle(hr);
    RequestHandle* tl = new TLRequestHandle(pm);

    // team leader处理离职请求
    Request* request = new DimissionRequest();
    printf("\tTLRequestHandle handle DimissionRequest Start\n");
    tl->handleRequest(request);
    printf("\tTLRequestHandle handle DimissionRequest Stop\n\n");

    // team leader处理加薪请求
    request = new AddMoneyRequest();
    printf("\tTLRequestHandle handle AddMoneyRequest Start\n");
    tl->handleRequest(request);
    printf("\tTLRequestHandle handle AddMoneyRequest Stop\n\n");

    // 项目经理上理辞职请求
    request = new DimissionRequest();
    printf("\tPMRequestHandle handle DimissionRequest Start\n");
    pm->handleRequest(request);
    printf("\tPMRequestHandle handle DimissionRequest Stop\n\n");

    request = new AddMoneyRequest();
    printf("\tPMRequestHandle handle AddMoneyRequest Start\n");
    pm->handleRequest(request);
    printf("\tPMRequestHandle handle AddMoneyRequest Stop\n");
}

void TestCommand(int index, std::string name)
{
    printf("\n%02d. %s\n", index, name.c_str());
    Receiver* recv = new Receiver();
    Command* cmd = new CommandImpl(recv);
    Invoker* i = new Invoker();
    i->setCommand(cmd);
    i->execute();
}

void TestInterpreter(int index, std::string name)
{
    printf("\n%02d. %s\n", index, name.c_str());
    Context* ctx = new Context("yinger");
    ctx->add(new SimpleExpression());
    ctx->add(new AdvanceExpression());
    ctx->add(new SimpleExpression());

    for (Expression* eps : ctx->getList())
    {
        eps->interpret(ctx);
    }

    ctx->setContent("sea swallow");
    for (Expression* eps : ctx->getList())
    {
        eps->interpret(ctx);
    }
}

void TestIterator(int index, std::string name)
{
    printf("\n%02d. %s\n", index, name.c_str());
    List* list = new ListImpl();
    list->add(ListObject("ListObject01"));
    list->add(ListObject("ListObject02"));
    list->add(ListObject("ListObject03"));

    //第一种迭代方式
    Iterator* it = list->iterator();
    while (it->hasNext()) {
        printf("\t%s\n", it->next().name_.c_str());
    }
    printf("\t====================\n");

    // 第二种迭代方式
    for (int i = 0; i < list->getSize(); i++) {
        printf("\t%s\n", list->get(i).name_.c_str());
    }
}

void TestMediator(int index, std::string name)
{
    printf("\n%02d. %s\n", index, name.c_str());
    Mediator* med = new ConcreteMediator();

    // 老板来了
    med->notice("boss");

    // 客户来了
    med->notice("client");
}

void TestMemento(int index, std::string name)
{
    printf("\n%02d. %s\n", index, name.c_str());
    Originator* org = new Originator();
    org->setState("In a meeting");
    org->showState(); // 显示

    Caretaker* ctk = new Caretaker();
    ctk->setMemento(org->createMemento()); // 将数据封装在Caretaker

    org->setState("Sleep");
    org->showState(); // 显示

    org->setMemento(ctk->getMemento()); // 将数据重新导入
    org->showState(); // 显示
}

void TestObserver(int index, std::string name)
{
    printf("\n%02d. %s\n", index, name.c_str());
    Policeman* thPol = new TianHePoliceman();
    Policeman* hpPol = new HuangPuPoliceman();

    Citizen* citizen1 = new HuangPuCitizen();
    citizen1->RegisterPolice(thPol);
    citizen1->RegisterPolice(hpPol);
    citizen1->sendMessage("unnormal");
    citizen1->sendMessage("normal");
    printf("\t===========\n");

    Citizen* citizen2 = new TianHeCitizen();
    citizen2->RegisterPolice(thPol);
    citizen2->RegisterPolice(hpPol);
    citizen2->sendMessage("normal");
    citizen2->sendMessage("unnormal");
}

void TestState(int index, std::string name)
{
    printf("\n%02d. %s\n", index, name.c_str());
    ContextState* ctx1 = new ContextState();
    ctx1->setWeather(new Sunshine());
    printf("\t%s\n", ctx1->weatherMessage().c_str());
    printf("\t===============\n");

    ContextState* ctx2 = new ContextState();
    ctx2->setWeather(new Rain());
    printf("\t%s\n", ctx2->weatherMessage().c_str());
}

void TestStrategy(int index, std::string name)
{
    printf("\n%02d. %s\n", index, name.c_str());
    ContextStrategy* ctx1 = new ContextStrategy(new StrategyImplA());
    ctx1->doMethod();

    ContextStrategy* ctx2 = new ContextStrategy(new StrategyImplB());
    ctx2->doMethod();

    ContextStrategy* ctx3 = new ContextStrategy(new StrategyImplC());
    ctx3->doMethod();
}

void TestTemplateMethod(int index, std::string name)
{
    printf("\n%02d. %s\n", index, name.c_str());
    Template* temp = new TemplateConcrete();
    temp->update();
}

void TestVisitor(int index, std::string name)
{
    printf("\n%02d. %s\n", index, name.c_str());
    Visitor* visitor = new ConcreteVisitor();
    FloatElement* fe = new FloatElement(3.14f);
    printf("\tFloatElement accept\n");
    fe->accept(visitor);
    StringElement* se = new StringElement("StringElement");
    printf("\tStringElement accept\n");
    se->accept(visitor);
    std::list<Visitable*> texts;
    texts.push_back(new StringElement("StringElement01"));
    texts.push_back(new StringElement("StringElement02"));
    texts.push_back(new StringElement("StringElement03"));
    texts.push_back(new FloatElement(1.5f));
    texts.push_back(new FloatElement(2.5f));
    texts.push_back(new FloatElement(3.5f));
    printf("\tCollection accept\n");
    visitor->visitCollection(texts);

}

void TestExtend(int index, std::string name)
{
    printf("\n%02d. %s\n", index, name.c_str());
    Parent* parent = new Parent();
    parent->data_parent = 1024;
    printf("\tParent data_parent: %d\n", parent->data_parent);

    Child* child = new Child();
    child->parent.data_parent = 101;
    child->data_child = 102;
    printf("\tChild data_parent: %d\n", child->parent.data_parent);
    printf("\tChild data_child: %d\n", child->data_child);

    Data data;
    data.value = 10086;
    data.pProcess = ProcData;
    data.pProcess(&data);

    Play play;
    play.pData = parent;
    play.start_play = ProcPlay01;
    play.start_play(&play);

    play.pData = child;
    play.start_play = ProcPlay02;
    play.start_play(&play);

    // static_cast
    char a = 'a';
    int b = static_cast<char>(a); // 正确，将char型数据转换成int型数据

    double *c = new double;
    void *d = static_cast<void*>(c); // 正确，将double指针转换成void指针

    int e = 10;
    const int f = static_cast<const int>(e); // 正确，将int型数据转换成const int型数据

    // const int g = 20;
    // int *h = static_cast<int*>(&g); // 编译错误，static_cast不能转换掉g的const属性
    // 下行转换是不安全的
    // 上行转换是安全的
    // (上行)子类转换成父类是安全的, (下行)父类转换成子类是不安全的。

    // dynamic_cast
    // dynamic_cast<type*>(e)
    ClassLevel01* c01 = new ClassLevel01();
    ClassLevel02* c02 = new ClassLevel02();
    c02->text_ = "c02";
    if (ClassLevel02* ct1 = dynamic_cast<ClassLevel02*>(c01))
    {
        ct1->method();
    }
    else
    {
        c01->method();
    }

    // dynamic_cast<type&>(e)
    try
    {
        // const Derived &d = dynamic_cast<const Base &>(b);
        // 使用b引用的Derived对象
        ClassLevel02 c02con01;
        const ClassLevel01& ctt1 = dynamic_cast<const ClassLevel01&>(c02con01);
        // const ClassLevel02 c02con02;
        // ClassLevel01& ctt2 = dynamic_cast<ClassLevel01&>(c02con02);

        ClassLevel01& ct2 = dynamic_cast<ClassLevel01&>(*c02);
        ct2.method();
        ClassLevel02& ct3 = dynamic_cast<ClassLevel02&>(*c02);
        ct3.method();
        ClassLevel02& ct4 = dynamic_cast<ClassLevel02&>(*c01);
        ct4.method();
        
        // dynamic_cast<type&&>(e)
        ClassLevel02&& ct5 = dynamic_cast<ClassLevel02&&>(ct3);
        ct4.method();
    }
    catch (std::bad_cast)
    {
        // 处理类型转换失败的情况
        printf("\tdynamic_cast error in ct4 dynamic_cast\n");
    }

    // const_cast
    const int g1 = 20;
    int *h1 = const_cast<int*>(&g1); // 去掉const常量const属性
    const int g2 = 20;
    int &h2 = const_cast<int&>(g2); // 去掉const引用const属性
    const char *g3 = "hello";
    char *h3 = const_cast<char*>(g3); // 去掉const指针const属性

    try
    {
        int p = 10;
        test_func fun1 = output;
        fun1(p); // 正确
        // test_func fun2 = reinterpret_cast<test_func>(&p);
        // fun2(p); // ...处有未经处理的异常: 0xC0000005: Access violation
    }
    catch (...)
    {
        printf("\terror in reinterpret_cast result\n");
    } 

    ClassC* classc = new ClassC();
    classc->m_a = 100;
    classc->m_b = 200;
    ClassB* classb01 = reinterpret_cast<ClassB*>(classc);
    ClassB* classb02 = static_cast<ClassB*>(classc);
    printf("%p, %p, %p\n", classc, classb01, classb02);
}

std::mutex g_display_mutex;
bool run_foo = false;
void foo()
{
    std::thread::id this_id = std::this_thread::get_id();
    while (run_foo)
    {
        g_display_mutex.lock();
        printf("foo's id: %d\n", this_id);
        g_display_mutex.unlock();

        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}

void TestThread(int index, std::string name)
{
    printf("\n%02d. %s\n", index, name.c_str());
    run_foo = true;
    std::thread t1(foo);
    std::thread::id t1_id = t1.get_id();

    std::thread t2(foo);
    std::thread::id t2_id = t2.get_id();
  
    unsigned int n = std::thread::hardware_concurrency();
    std::cout << n << " concurrent threads are supported.\n";

    std::thread t3;
    t3 = std::thread(foo);

    printf("t1's id: %d\n", t1_id);
    printf("t2's id: %d\n", t2_id);

    std::cout << "thread 1 id: " << t1.get_id() << std::endl;
    std::cout << "thread 2 id: " << t2.get_id() << std::endl;

    std::swap(t1, t2);

    std::cout << "after std::swap(t1, t2):" << std::endl;
    std::cout << "thread 1 id: " << t1.get_id() << std::endl;
    std::cout << "thread 2 id: " << t2.get_id() << std::endl;

    t1.swap(t2);

    std::cout << "after t1.swap(t2):" << std::endl;
    std::cout << "thread 1 id: " << t1.get_id() << std::endl;
    std::cout << "thread 2 id: " << t2.get_id() << std::endl;

    run_foo = false;
    t1.join();
    t2.join();
    t3.join();
}

int main()
{
    // 1. 单例模式
    int index = 0;
    TestSingleton(++index, "Singleton");

    // 2. 抽象工厂
    TestAbstractFactory(++index, "AbstractFactory");

    // 3. 工厂方法
    TestFactoryMethod(++index, "FactoryMethod");

    // 4. 建造者模式
    TestBuilder(++index, "Builder");

    // 5. 原型模式
    TestPrototype(++index, "Prototype");

    // 6. 适配器
    TestAdapter(++index, "Adapter");

    // 7. 桥接模式
    TestBridge(++index, "Bridge");

    // 8. 组合器模式
    TestComposite(++index, "Composite");

    // 9. 装饰模式
    TestDecorator(++index, "Decorator");

    // 10. 外观模式
    TestFacade(++index, "Facade");

    // 11. 享元模式
    TestFlyweight(++index, "Flyweight");

    // 12. 代理模式
    TestProxy(++index, "Proxy");

    // 13. 职责链模式
    TestCOR(++index, "COR");

    // 14. 命令模式 
    TestCommand(++index, "Command");

    // 15. 解释器模式
    TestInterpreter(++index, "Interpreter");

    // 16. 迭代器模式
    TestIterator(++index, "Iterator");

    // 17. 中介者模式
    TestMediator(++index, "Mediator");

    // 18. 备忘录模式
    TestMemento(++index, "Memento");

    // 19. 观察者模式
    TestObserver(++index, "Observer");

    // 20. 状态模式
    TestState(++index, "State");

    // 21. 策略模式
    TestStrategy(++index, "Strategy");

    // 22. 模板方法
    TestTemplateMethod(++index, "TemplateMethod");

    // 23. 访问者模式
    TestVisitor(++index, "Visitor");
    
    // 24. 继承、封装、多态
    TestExtend(++index, "Extend");

    // 25. 多线程
    TestThread(++index, "MultiThread");
    system("pause");

    return 0;
}

