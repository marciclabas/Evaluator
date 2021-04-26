#include "IO.hh"

const static io::InputCommand systemToInput[][2] = {
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
        { "escribir_usuario", "eu" }
    };

bool operator==(io::InputCommand a, io::SystemCommand b) {
	return a == systemToInput[int(b)][0] or a == systemToInput[int(b)][1];
}

bool operator!=(io::InputCommand a, io::SystemCommand b) {
	return a != systemToInput[int(b)][0] and a != systemToInput[int(b)][1];
}

inline void error(std::string s = "default error") {
	std::cout << "error: " << s << std::endl;
}
