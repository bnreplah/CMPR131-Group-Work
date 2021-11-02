//#pragma once
//
//#include <iostream>
//#include <vector>
//#include <string>
//#include <cstdlib>
//#include "course.h"
//
//// Revised student class, may not be needed
////
//
//
////struct id_store
////{
////	static int _current_id;
////};
////
////
////struct id_db {
////	std::vector<int> _id;
////	std::vector<student> _student;
////};
//
//
///** [student class invariant]
//*
//* 
//* 
//*/
//class student {
//private:
//	int _id = int();
//	string _name = std::string();
//	vector<course> courses;
//
//public:
//	student(int pId, string pName):_id(pId), _name(pName) {}
//
//	int getId() const{
//		return this->_id;
//	}
//
//	string getName() const{
//		return this->_name;
//	}
//	vector<course> getCourses() const {
//		return this->courses;
//	}
//
//	void setId(int pId) {
//		this->_id = pId;
//	}
//
//	void setName(string pName) {
//		this->_name = pName;
//	}
//
//	void setCourses(vector<course> pCourses) {
//		this->courses = pCourses;
//	}
//
//	void addCourse(course& newCourse){
//		this->courses.push_back(newCourse);
//	}
//
//	void displayCourses() {
//		printf("%10s \t|\t %15s  \t|\t %15s \t|\t %15s", "ticket","name","student id","grade");
//		for (vector<course>::iterator itt = courses.begin(); itt != courses.end(); ++itt) {
//			printf("%10s \t|\t %15s  \t|\t %15s \t|\t %15s", itt->getTicket(), itt->getName() , itt->getStId(), itt->getStGrade());
//		}
//		
//	}
//
//	//void selectCourse() {
//
//
//	//}
//
//};