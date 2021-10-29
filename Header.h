//
// Created by seant on 10/11/2021.
//

#ifndef PROJECT_2_HEADER_H
#define PROJECT_2_HEADER_H
#include <vector>
#include <string>
class Header {
public:
    Header(std::vector<std::string> attributes) {

        this->attributes = attributes;
    }
    Header() {}
    //// for the toString
    std::string getName();
    void setName(std::string inputName);
    void addHeadAttribute(std::string inputAttribute);
    std::string getHeadAttributes(unsigned int i);  /// for the toString
    std::string toString();
    void resetHeadAttributes(std::vector<std::string> newAttributes);
    std::vector<std::string> getAttributes();
private:
    std::vector<std::string> attributes;
    std::string name;

};
#endif //PROJECT_2_HEADER_H
