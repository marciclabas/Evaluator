/**
@file program.cc
@brief File containing the main function
*/

#include "ProblemCol.hh"
#include "SessionRep.hh"
#include "CourseSet.hh"
#include "UserSet.hh"
#include "IO.hh"

#ifndef NO_DIAGRAM 
#include <cassert>
#endif

using namespace io;
using io::SystemCommand;
using std::cin;
using std::cout;
using std::endl;

int main() {
    ProblemCollection problemCollection; problemCollection.read();
    SessionRepository sessionRepository(problemCollection); sessionRepository.read();
    CourseSet courseSet(sessionRepository); courseSet.read();
    UserSet userSet(courseSet); userSet.read();
    
    InputCommand command;
    cin >> command;
    
    while(command != end_program) {
		/*
		 * 		NEW STUFF
		 */
        if(command == new_problem) {
            prb::ID newProblemID; cin >> newProblemID;
            if(problemCollection.contains(newProblemID)) error(); 
            else {
            	problemCollection.add(newProblemID, Problem());
            	cout << problemCollection.count() << endl;
            }
        }
        
        else if(command == new_session) {
			ses::ID newSessionID; cin >> newSessionID;
            if(sessionRepository.contains(newSessionID)) error(); 
            else {
            	Session newSession; newSession.read();
            	sessionRepository.add(newSessionID, newSession);
            	cout << sessionRepository.count() << endl;
            }
        }
        
        else if(command == new_course) {
			crs::ID newCourseID; cin >> newCourseID;
            if(courseSet.contains(newCourseID)) error(); 
            else {
            	Course newCourse; newCourse.read();
            	if(newCourse.isValid()) {
            		courseSet.add(newCourseID, newCourse);
            		cout << courseSet.count() << endl;
            	}
            	else error();
            }
        }
        
        else if(command == new_user) {
			usr::ID newUserID; cin >> newUserID;
            if(userSet.contains(newUserID)) error(); 
            else {
            	userSet.add(newUserID, User());
            	cout << userSet.count() << endl;
            }
        }
        /*
		 * 		REMOVE USER
		 */
        else if(command == remove_user) {
			usr::ID toRemoveUserID; cin >> toRemoveUserID;
            if(not userSet.contains(toRemoveUserID)) error(); 
            else {
            	userSet.remove(toRemoveUserID);
            	cout << userSet.count() << endl;
            }
        }
        /*
		 * 		ENROLL USER
		 */
        else if(command == enroll_user) {
			usr::ID userID; 
			crs::ID courseID;
			cin >> userID >> courseID;
			
			if(not userSet.contains(userID) or not courseSet.contains(courseID)) error();
			else {
				User & user = userSet[userID];
				if(user.isEnrolledInCourse()) error();
				else { 
					user.enrollCourse(courseID);
					Course & course = courseSet[courseID];
					course.enrollUser();
					cout << course.getCurrentEnrolled() << endl;
				}
			}
        }
        /*
		 * 		USER COURSE
		 */
        else if(command == user_course) {
            usr::ID userID; cin >> userID;
			if(userSet.contains(userID)) {
				User & user  = userSet[userID];
				user.isEnrolledInCourse()? cout << user.getEnrolledCourseID(): cout << 0;
				cout << endl;
			}
			else error();
        }
        /*
		 * 		PROBLEM SESSION
		 */
        else if(command == problem_session) {
            crs::ID courseID;
			prb::ID problemID;
			cin >> courseID >> problemID;
			
			if(courseSet.contains(courseID) and problemCollection.contains(problemID)){
				Course & course = courseSet[courseID];
				ses::ID sessionID;
				if(course.getSessionByProblem(problemID, sessionID)) cout << sessionID << endl;
				else error();
			}
			else error();
        }
        /*
		 * 		SOLVED / SOLVABLE PROBLEMS
		 */
        else if(command == solved_problems) {
            usr::ID userID; cin >> userID;
			
			if(userSet.contains(userID)) userSet[userID].getSolvedStats().print();
			else error();
        }
       
        else if(command == solvable_problems) {
			usr::ID userID; cin >> userID;
			
			if(userSet.contains(userID)) userSet[userID].getSolvableStats().print();
			else error();
        }
        /*
		 * 		SUBMIT PROBLEM
		 */
        else if(command == submit_problem) {
            usr::ID userID;
			prb::ID problemID;
			prb::result result;
			cin >> userID >> problemID >> result;

			User & user = userSet[userID];
			
			user.parseSubmission(problemID, result);
			problemCollection[problemID].parseSubmission(result);

			// check wheter the user has finished the course and unenroll him if so
			if(user.completedEnrolledCourse()) {
				courseSet[user.getEnrolledCourseID()].unenrollUser();
				user.unenrollCourse();
			}
        }
        /*
		 *  LISTS AND WRITES
		 */
        else if(command == list_problems) {
            problemCollection.print();
            cout << endl;
        }
        else if(command == write_problem) {
			prb::ID problemID; cin >> problemID;
			problemCollection[problemID].print();
            cout << endl;
		}
        else if(command == list_sessions) {
            sessionRepository.print();
            cout << endl;
        }
        else if(command == write_session) {
			ses::ID sessionID; cin >> sessionID;
			sessionRepository[sessionID].print();
            cout << endl;
		}
        else if(command == list_courses) {
            courseSet.print();
            cout << endl;
        }
        else if(command == write_course) {
			crs::ID courseID; cin >> courseID;
			courseSet[courseID].print();
            cout << endl;
		}
        else if(command == list_users) {
			userSet.print();
            cout << endl;    
        }
        else if(command == write_user) {
			usr::ID userID; cin >> userID;
			userSet[userID].print();
            cout << endl;
        }
        else assert(false);
        
        cin >> command;
    }
}
