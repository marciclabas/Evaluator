# Evaluator Platform Documentation
Català
======
Projecte de l'assignatura PRO2 del Grau en Enginyeria Informàtica a la Facultat d'Informàtica de Barcelona (UPC)

### Abstracte

Aquest programa emula una plataforma de laboratoris de programació. Els usuaris registrats a la plataforma es poden
insciure en diferents cursos i enviar-hi problemes. Cada curs conté un conjunt de sessions, les quals contenen un
conjunt de problemes.

### Arquitectura de dades

El programa està organitzat en 4 classes úniques principals. Una col.lecció de problemes (<tt>ProblemCollection</tt>), un
repositori de sessions (SessionRepository), un conjunt de cursos (<tt>CourseSet</tt>) i un conjunt d'usuaris (<tt>UserSet</tt>),
cadascun d'ells contenint tots els elements del tipus corresponent disponibles dins la plataforma, i.e., problemes
(<tt>Problem</tt>s), sessions (<tt>Session</tt>s), cursos (<tt>Course</tt>s) i usuaris (<tt>User</tt>s), respectivament.

### Arquitectura de funcionalitats

Les funcionalitats del programa s'operen a través de l'entrada/sortida estàndart. Totes les possibles comandes (<tt>SystemCommand</tt>s)
estan definides dins del <em>namespace</em> <tt>io</tt>, i tota la lògica de control d'aquestes té lloc en el programa principal (<em>main</em>).

English
======
Project within the PRO2 subject of the Informatics Engineering Degree at the Faculty of Informatics in Barcelona (UPC)

### Abstract

This program mimics a programming lab like platform. Users signed in the platform can enroll
in courses and submit problems to the platform. Each course contains several sessions which,
in turn, contain several problems.

### Data architecture

The program data is structured in 4 main singleton classes. A <tt>ProblemCollection</tt>, a <tt>SessionRepository</tt>, a <tt>CourseSet</tt> and a <tt>UserSet</tt>, each of them containing all elements
of their kind available in the platform, i.e., <tt>Problem</tt>s, <tt>Session</tt>s,
<tt>Course</tt>s and <tt>User</tt>s, respectively.

### Functionality architecture

The program functionality is controlled through the standard input/output. All available
commands (<tt>SystemCommand</tt>s) are defined within the <tt>io <em>namespace</em>, and all the handling logic
of such commands is implemented in the <em>main</em> function.

