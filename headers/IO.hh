/**
@file IO.hh
@brief File containing the specification of some IO operations and types within the io namespace
*/

#ifndef IO_HH
#define IO_HH

#ifndef NO_DIAGRAM
#include <string>
#include <iostream>
#endif

/**
@namespace io
@brief namespace containing type definitions and some input/output functions
*/
namespace io {
    
    /**
	@brief All system commands supported
    */
    enum SystemCommand {
		new_problem, new_session, new_course, new_user, remove_user,
    	enroll_user, user_course, problem_session, solved_problems, solvable_problems,
    	submit_problem, list_problems, write_problem, list_sessions, write_session,
    	list_courses, write_course, list_users, write_user, end_program
	};
    
    using InputCommand = std::string;
    
    /**
	@brief Checks whether an InputCommand corresponds to a SystemCommand
	@pre true
	@post returns @c true if @c inputCommand corresponds to @c systemCommand, returns @c false otherwise
    */
	bool operator==(InputCommand inputCommand, SystemCommand systemCommand);
	/**
	@brief Checks whether an InputCommand does not correspond to a SystemCommand
	@pre true
	@post returns @c true if @c inputCommand does not correspond to @c systemCommand, returns @c false otherwise
	*/
	bool operator!=(InputCommand inputCommand, SystemCommand systemCommand);

	enum Error {
		default_error,
		already_existing_problem,
		nonexistent_problem,
		already_existing_session,
		nonexistent_session,
		nonexistent_course,
		nonexistent_user,
		already_existing_user,
		already_enrolled_user,
		nonenrolled_user,
		problem_not_in_course
	};

	/**
	@brief
	*/
	void error(Error er = default_error);

	void echo(InputCommand command);
}

#endif
