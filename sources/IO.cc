#include "IO.hh"

#include <vector>
#include <list>

const static std::vector<std::list<io::InputCommand>> commands {
        { "nuevo_problema", "np" },
        { "nueva_sesion", "ns" },
        { "nuevo_curso", "nc" },
        { "alta_usuario", "a" },
        { "baja_usuario", "b" },
        { "inscribir_curso", "i" },
        { "curso_usuario", "cu" },
        { "sesion_problema", "sp" },
        { "problemas_resueltos", "pr" },
        { "problemas_enviables", "pe" },
        { "envio", "e" },
        { "listar_problemas", "lp" },
        { "escribir_problema", "ep" },
        { "listar_sesiones", "ls" },
        { "escribir_sesion", "es" },
        { "listar_cursos", "lc" },
        { "escribir_curso", "ec" },
        { "listar_usuarios", "lu" },
        { "escribir_usuario", "eu" },
        { "fin" }
};

namespace io {
	bool operator==(io::InputCommand input, io::SystemCommand system) {
		for(const io::InputCommand & command : commands[system])
	        if(command == input) return true;
	    return false;
	}
	
	bool operator!=(io::InputCommand input, io::SystemCommand system) {
		for(const io::InputCommand & command : commands[system])
	        if(command == input) return false;
	    return true;
	}
	
	void error(std::string s) {
		std::cout << "error: " << s << std::endl;
	}
	
	void echo(io::InputCommand command) {
	    std::cout << '#' << command;
	}
}
