#pragma once
#include <iostream>
#include <list>
#include <string>
//#include "Warehouse.h"

class Warehouse;

class IObserver {
public:
    virtual ~IObserver() {};
    virtual void Update(const std::string& message_from_subject) = 0;
};

class ISubject {
public:
    virtual ~ISubject() {};
    virtual void Attach(IObserver* observer) = 0;
    virtual void Detach(IObserver* observer) = 0;
    virtual void Notify() = 0;
};

class Subject : public ISubject {
public:
    virtual ~Subject() {
        std::cout << "Goodbye, I was the Player.\n";
    }

    void Attach(IObserver* observer) override {
        list_observer_.push_back(observer);
    }
    void Detach(IObserver* observer) override {
        list_observer_.remove(observer);
    }
    void Notify() override {
        std::list<IObserver*>::iterator iterator = list_observer_.begin();
        HowManyObserver();
        while (iterator != list_observer_.end()) {
            (*iterator)->Update(message_);
            ++iterator;
        }
    }

    void CreateMessage(std::string message = "Empty") {
        this->message_ = message;
        Notify();
    }
    void HowManyObserver() {
        std::cout << "There are " << list_observer_.size() << " warehouses in the list.\n";
    }

    void SomeBusinessLogic() {
        this->message_ = "change message message";
        Notify();
        std::cout << "I'm about to do some thing important\n";
    }

private:
    std::list<IObserver*> list_observer_;
    std::string message_;
};

class Observer : public IObserver {
public:
    Observer(Subject& subject, Warehouse* objWarehouse ) : subject_(subject), mWarehouse(objWarehouse)
    {
        this->subject_.Attach(this);
        ++Observer::static_number_;
        //std::cout << "Hi, I'm the Warehouse \"" << mWarehouse.GetName()<< " and I have " << mWarehouse.EmptyPlaces() << "\".\n";
        this->number_ = Observer::static_number_;
    }
    virtual ~Observer() {
        std::cout << "Goodbye, I was the Warehouse \"" << this->number_ << "\".\n";
    }

    void Update(const std::string& message_from_subject) override {
        message_from_subject_ = message_from_subject;
        PrintInfo();
    }
    void RemoveMeFromTheList() {
        subject_.Detach(this);
        std::cout << "Warehouse \"" << number_ << "\" removed from the list.\n";
    }
    void PrintInfo() {
        std::cout << "Warehouse \"" << this->number_ << "\": a new message is available --> " << this->message_from_subject_ << "\n";
    }

private:

    Warehouse* mWarehouse;
    std::string message_from_subject_;
    Subject& subject_;
    static int static_number_;
    int number_;
};



