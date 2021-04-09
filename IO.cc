#include "IO.hh"

const static InputCommand systemToInput[][2] = {
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

bool operator==(InputCommand a, SystemCommand b) {
	return a == comms[int(b)][0] or a == comms[int(b)][1];
}

bool operator!=(InputCommand a, SystemCommand b) {
	return not operator==(a, b);
}

inline void error(std::string s = "default error") {
	
}
