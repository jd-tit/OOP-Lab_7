//
// Created by jdt on 3/26/2022.
//

#ifndef LAB5_CONTRACT_DE_STUDII_DOMAIN_H
#define LAB5_CONTRACT_DE_STUDII_DOMAIN_H

#include <string>
#include <utility>
#include <iostream>

class Course{
private:
    std::string name, type, teacher;
    unsigned int hours_per_week;
    size_t id;
public:
  Course(const std::string& name, const std::string& type,
         const std::string& teacher,
         unsigned int hours_per_week, size_t id) :
        name(name),
        type(type),
        teacher(teacher),
        hours_per_week(hours_per_week),
        id(id){}

  Course(const Course& org) = default;

  Course(Course&&) = default;

  Course& operator=(const Course& c){
    if(this->to_str() == c.to_str()){
      return *this;
    } else {
      this->hours_per_week = c.hours_per_week;
      this->teacher = c.teacher;
      this->name = c.name;
      this->type = c.type;
      this->id = c.id;
      return *this;
    }

  }

//    Course(const Course& org) : name(org.name), type(org.type), teacher(org.teacher), hours_per_week(org.hours_per_week),
//                              id(org.id){
//      std::cout << "copy" << std::endl;
//  }

  [[nodiscard]] size_t get_id() const;

  [[nodiscard]] const std::string& get_name() const {
    return name;
  }

  [[nodiscard]] unsigned getHPW() const{
    return hours_per_week;
  }

  [[nodiscard]] const std::string& get_teacher() const{
    return teacher;
  }

  [[nodiscard]] const std::string& get_type() const{
    return type;
  }

  void set_name(std::string name){
    this->name = std::move(name);
  }

  void set_type(std::string type){
    this->type = std::move(type);
  }

  void set_teacher(std::string teacher){
    this->teacher = std::move(teacher);
  }

  void set_hpw(unsigned int hpw){
    this->hours_per_week = hpw;
  }

  Course(): hours_per_week(0), id(0){}
  ~Course() = default;

  /**
   * Convert the Course to a string format.
   * @return The stringified course.
   */
  [[nodiscard]] std::string to_str() const;

};

#endif //LAB5_CONTRACT_DE_STUDII_DOMAIN_H
