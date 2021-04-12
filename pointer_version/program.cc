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
    ProblemCollection problemCollection;
    SessionRepository sessionRepository;
    CourseSet courseSet;
    UserSet userSet;
	cin >> problemCollection >> sessionRepository >> courseSet >> userSet;
    
    InputCommand command;
    cin >> command;
    
    while(command != end_program) {
		/*
		 * 		NEW STUFF
		 */
        if(command == new_problem) {
            Problem* newProblem = new Problem; cin >> *newProblem;
            if(problemCollection.addProblem(newProblem)) cout << problemCollection.count() << endl;
            else error();
        }
        
        else if(command == new_session) {
			Session* newSession = new Session; cin >> *newSession;
			if(sessionRepository.addSession(newSession)) cout << sessionRepository.count() << endl;
			else error();
        }
        
        else if(command == new_course) {
			Course* newCourse = new Course; cin >> *newCourse;
			if(courseSet.addCourse(newCourse)) cout << courseSet.count() << endl; 
			else error();
        }
        
        else if(command == new_user) {
			User* newUser = new User; cin >> *newUser;
			if(userSet.addUser(newUser)) cout << userSet.count() << endl;
			else error();
        }
        /*
		 * 		REMOVE USER
		 */
        else if(command == remove_user) {
			usr::ID userID; cin >> userID;
			if(userSet.removeUser(userID)) cout << userSet.count() << endl;
			else error();
        }
        /*
		 * 		ENROLL USER
		 */
        else if(command == enroll_user) {
			usr::ID userID; 
			crs::ID courseID;
			cin >> userID >> courseID;
			User* user = userSet.getUser(userID);
			
			if(not user or user->getEnrolledCourse()) error();
			else {
				Course* course = courseSet.getCourse(courseID);
				if(not course) error();
				else {
					user->enrollCourse(course);
					course->enrollUser();
					cout << course->countUsersEnrolled() << endl;
				}
			}
        }
        /*
		 * 		USER COURSE
		 */
        else if(command == user_course) {
            usr::ID userID; cin >> userID;
			User* user = userSet.getUser(userID);
			if(user) {
				const Course* enrolledCourse = user->getEnrolledCourse();
				enrolledCourse? cout << enrolledCourse->getID(): cout << 0;
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
			
			const Course* course = courseSet.getCourse(courseID);
			
			if(not course) error();
			else {
				if(not problemCollection.getProblem(problemID)) error();
				else {
					const Session* session = course->getSessionByProblem(problemID);
					if(not session) error();
					else cout << session->getID() << endl;
				}
			}
        }
        /*
		 * 		SOLVED / SOLVABLE PROBLEMS
		 */
        else if(command == solved_problems) {
            usr::ID userID; cin >> userID;
			const User* user = userSet.getUser(userID);
			
			if(user) {
				auto& solvedStats = user->getSolvedStats();
				for(auto stats : solvedStats) cout << stats << endl;
			}
			else error();
        }
       
        else if(command == solvable_problems) {
			usr::ID userID; cin >> userID;
			const User* user = userSet.getUser(userID);
			
			if(user) {
				auto& solvableStats = user->getSolvableStats();
				for(auto stats : solvableStats) cout << stats << endl;
			}
			else error();
        }
        /*
		 * 		SUBMIT PROBLEMS
		 */
        else if(command == submit_problem) {
            usr::ID userID;
			prb::ID problemID;
			prb::result result;
			cin >> userID >> problemID >> result;
			
			User* user = userSet.getUser(userID);
			Problem* problem = problemCollection.getProblem(problemID);
			user->parseSubmission(problem, result);
			problem->parseSubmission(result);

			// check wheter the user has finished the course and unenroll him if so
			Course* enrolledCourse = user->getEnrolledCourse();
			if(usr::completedCourse(user, enrolledCourse)) {
				user->unenrollCourse();
				enrolledCourse->unenrollUser();
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
			cout << *(problemCollection.getProblem(problemID)) << endl;
		}
        else if(command == list_sessions) {
            cout << sessionRepository << endl;
        }
        else if(command == write_session) {
			ses::ID sessionID; cin >> sessionID;
			cout << *(sessionRepository.getSession(sessionID)) << endl;
		}
        else if(command == list_courses) {
            cout << courseSet << endl;
        }
        else if(command == write_course) {
			crs::ID courseID; cin >> courseID;
			cout << *(courseSet.getCourse(courseID)) << endl;
		}
        else if(command == list_users) {
			cout << userSet << endl;            
        }
        else if(command == write_user) {
			usr::ID userID; cin >> userID;
			cout << *(userSet.getUser(userID)) << endl;
		}
        else assert(false);
        
        cin >> command;
    }
}
