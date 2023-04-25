#pragma once

// Lo arme de la siguiente manera para que nos sea mas facil llamarlo de donde organicemos los pasos de inicio y demas de cada nivel, 
// no se si esta bien, chequeenlo, porfas.

class Story
{
public:
	char playerName[20];
	const char intro[400] = "El mundo esta siendo amenazado por una raza alienigena\nllamada los Xenoides, estos seres estan decididos a destruir\nla humanidad. Se estan liderando batallas de las cuales la\nmayoria de los habitantes de la Tierra no estan al tanto.\nLos comandantes estan buscando nuevos reclutas\nque tengan las cualidades necesarias para poder hacer\nfrente a esta batalla en aumento.";
	//oficial:
	const char dialog1[300] = "Soy el comandante Johnson. Hemos revisado tus habilidades\ny he venido hasta aqui para invitarte a formar parte de la\nAcademia de Batalla, para que recibas entrenamiento y nos ayudes en nuestra lucha con los Xenoides.";
	//Parte de intercambio de preguntas
		//Oficial inicio
	const char dialog2[100] = "Se que debes estar confundido y debes tener preguntas, estoy aqui para responderlas.";
	// Opcion de Pregunta 1
	const char preg1[50] = "¿Que es la Academia de Batalla?";
	// Respuesta1
	const char resp1[300] = "La Academia de Batalla es una institucion militar espacial donde los jovenes prodigios son entrenados en estrategias de combate y habilidades de liderazgo. Tendras que enfrentarte a desafios cada vez mas dificiles para convertirte en comandante y poder comandar tu propia flota.";
	// Opcion de Pregunta 2
	const char preg2[50] = "¿Que son los Xenoides?";
	// Respuesta 2
	const char resp2[250] = "Los Xenoides son una raza alienigena muy inteligente y agresiva. Hemos estado siguiendo sus pasos por años, han destruido planetas enteros. Cualquier especie diferente a ellos la consideran enemiga.";
	// opcion 3 --> opcion de salida
	const char preg3[100] = "No tengo mas preguntas, estoy listo para empezar mi entrenamiento.";
	const char resp3[150] = "El comandante te escolta hasta una nave que te lleva a una estacion espacial donde estas por comenzar con tu entrenamiento…";
	// Level 1 
	const char lvl1Intro[200] = "En tu primera simulacion te enfrentaras a las naves exploradoras, estas naves estan preparadas para realizar ataques, su defensa es muy escasa.";
	const char lvl1Outro[150] = "Bien hecho soldado, haz pasado la primera simulacion con exito.";
	// Level 2 
	const char lvl2Intro[160] = "En la siguiente fase de tu entrenamiento tendras que ademas de matar las naves, esquivar los asteroides.El contacto con estos dañan tu nave.";
	const char lvl2Outro[50] = "Soldado, su avance es maravilloso.";
	// Level 3 
	const char lvl3Intro[250] = "Decidimos que esta sea su ultima simulacion antes de la simulacion final. En esta simulacion sus rivales seran las naves de defensa, estas tienen una estructura dificil de flanquear, pero su ataque es debil.";
	const char lvl3Outro[62] = "Excelente desempeño soldado, estas lista para la prueba fianl";
	// Final Level
	const char finalLevelIntro[350] = "Para poder comandar tu propia nave y unirte a la batalla debes realizar la prueba final. En esta te enfrentaras a una nave nodriza que es escoltada por naves de defensa o exploradoras que no tendran piedad al atacar. Te otorgamos una nueva nave que sera la que pilotearas en el futuro con una mayor defensa";
	const char finalLevekIntro2[200] = "Tu desempeño a lo largo de los entrenamientos ha sido maravilloso, esperemos puedas unirte a nuestro frente de batalla. Han venido grandes lideres a ver tu ultima prueba.";
	// Dialogo Final
	const char introFinal[150] = "Luego de tu victoria la sala quedo en silencio, los lideres se retiraron de la sala, no hicieron ningun ademan por tu victoria.";
	//Oficial
	const char finalDialog1[75] = "Finalmente hemos ganado la batalla contra los Xenoides.";
	//Player
	const char finalDialog2[50] = "¿Como que hemos ganado la batalla?";
	//Oficial 
	const char finalDialog3[300] = "Si, como escuchas hemos vencido a los Xenoides, nuestra especie esta a salvo gracias a ti. Las simulaciones eran solo una fachada. Mantuvimos la verdad oculta para evitar la propagacion del panico y la ansiedad entre los reclutas. Pero es momento de que sepas la verdad.";
};