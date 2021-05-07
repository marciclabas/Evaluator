#include "IO.hh"

#include <unordered_map>
#include <list>

namespace io {

   const static std::unordered_map<io::SystemCommand, std::list<io::InputCommand>> commands = {
        { new_problem, { "nuevo_problema", "np" }},
        { new_session, { "nueva_sesion", "ns" }},
        { new_course, { "nuevo_curso", "nc" }},
        { new_user, { "alta_usuario", "a" }},
        { remove_user, { "baja_usuario", "b" }},
        { enroll_user, { "inscribir_curso", "i" }},
        { user_course, { "curso_usuario", "cu" }},
        { problem_session, { "sesion_problema", "sp" }},
        { solved_problems, { "problemas_resueltos", "pr" }},
        { solvable_problems, { "problemas_enviables", "pe" }},
        { submit_problem, { "envio", "e" }},
        { list_problems, { "listar_problemas", "lp" }},
        { write_problem, { "escribir_problema", "ep" }},
        { list_sessions, { "listar_sesiones", "ls" }},
        { write_session, { "escribir_sesion", "es" }},
        { list_courses, { "listar_cursos", "lc" }},
        { write_course, { "escribir_curso", "ec" }},
        { list_users, { "listar_usuarios", "lu" }},
        { write_user, { "escribir_usuario", "eu" }},
        { end_program, { "fin" }}
    };
    
	bool operator==(io::InputCommand input, io::SystemCommand system) {
		for(const io::InputCommand & command : commands.at(system))
	        if(command == input) return true;
	    return false;
	}
	
	bool operator!=(io::InputCommand input, io::SystemCommand system) {
		for(const io::InputCommand & command : commands.at(system))
	        if(command == input) return false;
	    return true;
	}
	
    const static std::unordered_map<io::Error, std::string> errors = {
        { default_error, "error por defecto" },
		{ already_existing_problem, "el problema ya existe" },
		{ nonexistent_problem, "el problema no existe" },
		{ already_existing_session, "la sesion ya existe" },
		{ nonexistent_session, "la sesion no existe" },
		{ nonexistent_course, "el curso no existe" },
		{ nonexistent_user, "el usuario no existe" },
		{ already_existing_user, "el usuario ya existe" },
		{ already_enrolled_user, "usuario inscrito en otro curso" },
		{ nonenrolled_user, "usuario no inscrito en ningun curso" },
        { problem_not_in_course, "el problema no pertenece al curso" },
        { malformed_course, "curso mal formado" }
    };

	void error(io::Error er) {
        std::cout << "error: " << errors.at(er) << std::endl;
	}
	
	void echo(io::InputCommand command) {
	    std::cout << '#' << command;
	}
}
