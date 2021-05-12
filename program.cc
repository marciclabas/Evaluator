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
#include <limits>
#endif

using namespace io;
using io::SystemCommand;
using std::cin;
using std::cout;
using std::endl;

int main() {
    ProblemCollection & problemCollection = ProblemCollection::getInstance(); 
    SessionRepository & sessionRepository = SessionRepository::getInstance(); 
    CourseSet & courseSet = CourseSet::getInstance(); 
    UserSet & userSet = UserSet::getInstance(); 

    problemCollection.read();
    sessionRepository.read();
    courseSet.read();
    userSet.read();
    
    InputCommand command;
    cin >> command;
    
    while(command != end_program) {
    	cout << '#' << command;
		/*
		 * 		NEW STUFF
		 */
        if(command == new_problem) {
            prb::ID newProblemID; cin >> newProblemID;
			// echo
			cout << ' ' << newProblemID << endl;
            if(problemCollection.contains(newProblemID))
				error(already_existing_problem);
            else {
            	problemCollection.add(newProblemID);
            	cout << problemCollection.count() << endl;
            }
        }
        
        else if(command == new_session) {
			ses::ID newSessionID; cin >> newSessionID;
			// echo
			cout << ' ' << newSessionID << endl;
			Session newSession; newSession.read();

            if(sessionRepository.contains(newSessionID) or sessionRepository.contains(newSession))
				error(already_existing_session);
            else {
            	sessionRepository.add(newSessionID, newSession);
            	cout << sessionRepository.count() << endl;
            }
        }
        
        else if(command == new_course) {
			// echo
			cout << endl;
        	Course newCourse; newCourse.read();
        	if(newCourse.isValid() and not courseSet.contains(newCourse)) {
        		courseSet.append(newCourse);
        		cout << courseSet.count() << endl;
        	}
        	else error(malformed_course);
        }
        
        else if(command == new_user) {
			usr::ID newUserID; cin >> newUserID;
			// echo
			cout << ' ' << newUserID << endl;
            if(userSet.contains(newUserID))
				error(already_existing_user); 
            else {
            	userSet.add(newUserID);
            	cout << userSet.count() << endl;
            }
        }
        /*
		 * 		REMOVE USER
		 */
        else if(command == remove_user) {
			usr::ID toRemoveUserID; cin >> toRemoveUserID;
			// echo
			cout << ' '  << toRemoveUserID << endl;
            if(userSet.contains(toRemoveUserID)) {
				const User & user = userSet[toRemoveUserID];
				// unenroll user from course (if enrolled in any)
				if(user.isEnrolledInCourse())
					courseSet[user.getEnrolledCourseID()].unenrollUser();
				userSet.remove(toRemoveUserID);
            	cout << userSet.count() << endl;
			} 
            else error(nonexistent_user);
        }
        /*
		 * 		ENROLL USER
		 */
        else if(command == enroll_user) {
			usr::ID userID; 
			crs::ID courseID;
			cin >> userID >> courseID;
			// echo
			cout << ' ' << userID << ' ' << courseID << endl;

			if(userSet.contains(userID)) {
				if(courseSet.contains(courseID)) {
					User & user = userSet[userID];
					if(user.isEnrolledInCourse())
						error(already_enrolled_user);
					else { 
						user.enrollCourse(courseID);
						Course & course = courseSet[courseID];
						course.enrollUser();
						cout << course.getUsersEnrolled() << endl;

						if(user.completedEnrolledCourse()) {
							courseSet[user.getEnrolledCourseID()].completeCourse();
							user.unenrollCourse();
						}
					}
				}
				else error(nonexistent_course);
			}
			else error(nonexistent_user);
        }
        /*
		 * 		USER COURSE
		 */
        else if(command == user_course) {
            usr::ID userID; cin >> userID;
			// echo
			cout << ' ' << userID << endl;
			if(userSet.contains(userID)) {
				User & user  = userSet[userID];
				user.isEnrolledInCourse()? cout << user.getEnrolledCourseID(): cout << 0;
				cout << endl;
			}
			else error(nonexistent_user);
        }
        /*
		 * 		PROBLEM SESSION
		 */
        else if(command == problem_session) {
            crs::ID courseID;
			prb::ID problemID;
			cin >> courseID >> problemID;
			// echo
			cout << ' ' << courseID << ' ' << problemID << endl;

			if(courseSet.contains(courseID)) {
				if(problemCollection.contains(problemID)) {
					Course & course = courseSet[courseID];
					ses::ID sessionID;
					if(course.getSessionByProblem(problemID, sessionID)) cout << sessionID << endl;
					// [!] maybe should distinguish error by problem or by session ?
					else error(problem_not_in_course);
				}
				else error(nonexistent_problem);
			}
			else error(nonexistent_course);
        }
        /*
		 * 		SOLVED / SOLVABLE PROBLEMS
		 */
        else if(command == solved_problems) {
            usr::ID userID; cin >> userID;
			// echo
			cout << ' ' << userID << endl;

			if(userSet.contains(userID)) userSet[userID].getSolvedStats().print();
			else error(nonexistent_user);
        }
       
        else if(command == solvable_problems) {
			usr::ID userID; cin >> userID;
			// echo
			cout << ' ' << userID << endl;

			if(userSet.contains(userID)) {
				const User & user = userSet[userID];
				if(user.isEnrolledInCourse())
					user.getSolvableStats().print();
				else error(nonenrolled_user);
			}
			else error(nonexistent_user);
        }
        /*
		 * 		SUBMIT PROBLEM
		 */
        else if(command == submit_problem) {
            usr::ID userID;
			prb::ID problemID;
			prb::result result;
			cin >> userID >> problemID >> result;
			// echo
			cout << ' ' << userID << ' ' << problemID << ' ' << int(result) << endl;
			User & user = userSet[userID];
			
			user.parseSubmission(problemID, result);
			problemCollection[problemID].parseSubmission(result);

			// check wheter the user has finished the course and unenroll him if so
			if(user.completedEnrolledCourse()) {
				courseSet[user.getEnrolledCourseID()].completeCourse();
				user.unenrollCourse();
			}
        }
        /*
		 *  LISTS AND WRITES
		 */
        else if(command == list_problems) {
			// echo
			cout << endl;
            problemCollection.print();
        }
        else if(command == write_problem) {
			prb::ID problemID; cin >> problemID;
			// echo
			cout << ' ' << problemID << endl;

			if(problemCollection.contains(problemID)) {
				cout << problemID;
				problemCollection[problemID].print();
            	cout << endl;
			}
			else error(nonexistent_problem);
		}
        else if(command == list_sessions) {
			// echo
			cout << endl;
            sessionRepository.print();
        }
        else if(command == write_session) {
			ses::ID sessionID; cin >> sessionID;
			// echo
			cout << ' ' << sessionID << endl;

			if(sessionRepository.contains(sessionID)) {
				cout << sessionID << ' ';
				sessionRepository[sessionID].print();
            	cout << endl;
			}
			else error(nonexistent_session);
		}
        else if(command == list_courses) {
			// echo
			cout << endl;
            courseSet.print();
        }
        else if(command == write_course) {
			crs::ID courseID; cin >> courseID;
			// echo
			cout << ' ' << courseID << endl;

			if(courseSet.contains(courseID)) {
				cout << courseID << ' ';
				courseSet[courseID].print();
            	cout << endl;
			}
			else error(nonexistent_course);
		}	
        else if(command == list_users) {
			// echo
			cout << endl;
			userSet.print();  
        }
        else if(command == write_user) {
			usr::ID userID; cin >> userID;
			// echo
			cout << ' ' << userID << endl;

			if(userSet.contains(userID)) {	
				cout << userID;
				userSet[userID].print();
            	cout << endl;
			}
			else error(nonexistent_user);
        }	
        else assert(false);
        
        cin >> command;
    }
}
