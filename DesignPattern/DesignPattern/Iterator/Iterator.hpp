#ifndef _ITERATOR_HPP_
#define _ITERATOR_HPP_

#include <string>

struct ListObject
{
    std::string name_;
    ListObject()
    {
        name_ = "ObjectNull";
    }

    ListObject(std::string name)
    {
        name_ = name;
    }
};

class Iterator;
class List
{
public:
    List()
    {
        iterator_ = nullptr;
    }

    virtual ~List() {};

public:
    virtual Iterator* iterator() = 0;
    virtual ListObject get(int index) = 0;

    virtual int getSize() = 0;
    virtual void add(ListObject obj) = 0;

protected:
    Iterator* iterator_;
};

class Iterator
{
public:
    virtual ~Iterator() {};

public:
    virtual void first() = 0;
    virtual void last() = 0;
    virtual ListObject next() = 0;
    virtual bool hasNext() = 0;
};

class IteratorImpl : public Iterator
{
public:
    IteratorImpl(List* list)
    {
        index_ = 0;
        list_ = list;
    }

    virtual ~IteratorImpl() {};

public:
    virtual void first() override
    {
        index_ = 0;
    }

    virtual void last() override
    {
        index_ = list_->getSize();
    }

    ListObject next()
    {
        ListObject obj = list_->get(index_);
        index_++;
        return obj;
    }

    virtual bool hasNext() override
    {
        return index_ < list_->getSize();
    }

private:
    List* list_;
    int index_;
};

#endif // _ITERATOR_HPP_