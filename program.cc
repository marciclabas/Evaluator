/**
@file program.cc
@brief File containing the main function
*/

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
    ProblemCollection problemCollection;	
    SessionRepository sessionRepository(problemCollection);
    CourseSet courseSet(sessionRepository);
    UserSet userSet(courseSet);
	cin >> problemCollection >> sessionRepository >> courseSet >> userSet;
    
    InputCommand command;
    cin >> command;
    
    while(command != end_program) {
		/*
		 * 		NEW STUFF
		 */
        if(command == new_problem) {
            prb::ID newProblemID; cin >> newProblemID;
            if(problemCollection.containsElement(newProblemID)) error(); 
            else {
            	problemCollection.addElement(newProblemID);
            	cout << problemCollection.getCount() << endl;
            }
        }
        
        else if(command == new_session) {
			ses::ID newSessionID; cin >> newSessionID;
            if(sessionRepository.containsElement(newSessionID)) error(); 
            else {
            	sessionRepository.addElement(newSessionID);
            	cout << sessionRepository.getCount() << endl;
            }
        }
        
        else if(command == new_course) {
			crs::ID newCourseID; cin >> newCourseID;
            if(courseSet.containsElement(newCourseID)) error(); 
            else {
            	courseSet.addElement(newCourseID);
            	cout << courseSet.getCount() << endl;
            }
        }
        
        else if(command == new_user) {
			usr::ID newUserID; cin >> newUserID;
            if(userSet.containsElement(newUserID)) error(); 
            else {
            	userSet.addElement(newUserID);
            	cout << userSet.getCount() << endl;
            }
        }
        /*
		 * 		REMOVE USER
		 */
        else if(command == remove_user) {
			usr::ID toRemoveUserID; cin >> toRemoveUserID;
            if(not userSet.containsElement(toRemoveUserID)) error(); 
            else {
            	userSet.removeUser(toRemoveUserID);
            	cout << userSet.getCount() << endl;
            }
        }
        /*
		 * 		ENROLL USER
		 */
        else if(command == enroll_user) {
			usr::ID userID; 
			crs::ID courseID;
			cin >> userID >> courseID;
			
			if(not userSet.containsElement(userID)	or not courseSet.containsElement(courseID)) error();
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
			if(userSet.containsElement(userID)) {
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
			
			if(courseSet.containsElement(courseID) and problemCollection.containsElement(problemID)){
				Course & course = courseSet[courseID];
				ses::ID sessionID;
				if(course.getSessionByProblem(problemID, sessionID)) cout << sessionID << endl;
				else error();
			}
			else error();
        }
        /**
		 * 		SOLVED / SOLVABLE PROBLEMS
		 */
        else if(command == solved_problems) {
            usr::ID userID; cin >> userID;
			
			if(userSet.containsElement(userID))
				for(const auto & stats : userSet[userID].getSolvedStats()) cout << stats << endl;
			else error();
        }
       
        else if(command == solvable_problems) {
			usr::ID userID; cin >> userID;
			
			if(userSet.containsElement(userID))
				for(const auto & stats : userSet[userID].getSolvableStats()) cout << stats << endl;
			else error();
        }
        /**
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
            cout << problemCollection << endl;
        }
        else if(command == write_problem) {
			prb::ID problemID; cin >> problemID;
			cout << problemCollection[problemID] << endl;
		}
        else if(command == list_sessions) {
            cout << sessionRepository << endl;
        }
        else if(command == write_session) {
			ses::ID sessionID; cin >> sessionID;
			cout << sessionRepository[sessionID] << endl;
		}
        else if(command == list_courses) {
            cout << courseSet << endl;
        }
        else if(command == write_course) {
			crs::ID courseID; cin >> courseID;
			cout << courseSet[courseID] << endl;
		}
        else if(command == list_users) {
			cout << userSet << endl;            
        }
        else if(command == write_user) {
			usr::ID userID; cin >> userID;
			cout << userSet[userID] << endl;
		}
        else assert(false);
        
        cin >> command;
    }
}
