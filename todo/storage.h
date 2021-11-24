//
// Created by user on 23.09.2021.
//

#ifndef COURS_STORAGE_H
#define COURS_STORAGE_H

#include <map>
#include <set>

#include "date.h"
#include "task.h"

using Tasks = std::set<Task>;

class Storage {
private:
    std::map<Date, Tasks> data;
public:
    Storage(const Storage&) = delete;
    Storage(const std::string& path);
    void LoadFromFile(const std::string& source);
    void Add(const Date& date, const Task& task);
    Tasks GetDailyTasks(const Date& date) const;
    void RemoveTask(const Date& date, const Task& task);
    void Write(std::ostream& out) const;
    void Clear();
    bool Empty() const;


    // Нужно для range-based for по хранилищу
    //inline auto begin() {return data.begin();}
    //
    //inline auto end() {return data.end();}

    inline auto begin() const {return data.begin();}

    inline auto end() const {return data.end();}
};
#endif //COURS_STORAGE_H
