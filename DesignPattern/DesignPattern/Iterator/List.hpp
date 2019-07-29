#ifndef _AGGREGATE_HPP_
#define _AGGREGATE_HPP_

#include <string>
#include "Iterator.hpp"

class ListImpl : public List
{
public:
    ListImpl()
    {
        list_ = new ListObject[100];
        index_ = 0;
        size_ = 0;
    }

    virtual ~ListImpl() {};

public:
    virtual Iterator* iterator() override
    {
        if (nullptr == iterator_)
        {
            iterator_ = new IteratorImpl(this);
        }
        return iterator_;
    }

    virtual ListObject get(int index) override
    {
        return list_[index];
    }

    virtual int getSize() override
    {
        return size_;
    }

    virtual void add(ListObject obj)
    {
        list_[index_++] = obj;
        size_++;
    }

private:
    ListObject* list_;
    int index_;
    int size_;
};

#endif // _AGGREGATE_HPP_