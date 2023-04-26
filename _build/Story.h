#pragma once

// Lo arme de la siguiente manera para que nos sea mas facil llamarlo de donde organicemos los pasos de inicio y demas de cada nivel, 
// no se si esta bien, chequeenlo, porfas.

class Story
{
public:
	char playerName[20];
	const char intro[400] = "El mundo esta siendo amenazado por una raza \nalienigena llamada los Xenoides, estos seres \nestan decididos a destruir la humanidad. \nSe estan liderando batallas de las cuales la \nmayoria de los habitantes de la Tierra no estan \nal tanto. Los comandantes estan buscando nuevos \nreclutas que tengan las cualidades necesarias para \npoder hacer frente a esta batalla en aumento.";//oficial:
	const char dialog1[1000] = "Soy el comandante Johnson. Hemos revisado tus habilidades \ny he venido hasta aqui para invitarte a formar parte de \nla Academia de Batalla, para que recibas entrenamiento \ny nos ayudes en nuestra lucha con los Xenoides. \n\nSe que debes estar confundido y debes tener preguntas, \nestoy aqui para responderlas. \n \n  1. Que es la Academia de Batalla? \n  2. Que son los Xenoides? \n  3. No tengo mas preguntas, estoy listo para \n    empezar mi entrenamiento.\n\n  *Presiona el numero de pregunta que quieras elegir.";//Parte de intercambio de preguntas
		//Oficial inicio
	const char dialog2[100] = "Se que debes estar confundido y debes tener preguntas, estoy aqui para responderlas.";
	// Opcion de Pregunta 1
	const char preg1[50] = "1. Que es la Academia de Batalla?";
	// Respuesta1
	const char resp1[300] = "La Academia de Batalla es una institucion \nmilitar espacial donde los jovenes prodigios son \nentrenados en estrategias de combate y \nhabilidades de liderazgo. Tendras que \nenfrentarte a desafios cada vez mas dificiles\npara convertirte en comandante y poder \ncomandar tu propia flota.";// Opcion de Pregunta 2
	const char preg2[50] = "2. Que son los Xenoides?";
	// Respuesta 2
	const char resp2[250] = "Los Xenoides son una raza alienigena muy \ninteligente y agresiva. Hemos estado siguiendo \nsus pasos por años, han destruido planetas\n enteros. Cualquier especie diferente a ellos la \nconsideran enemiga.";// opcion 3 --> opcion de salida
	const char preg3[100] = "3. No tengo mas preguntas, estoy listo para \nempezar mi entrenamiento.";
	const char resp3[200] = "El comandante te escolta hasta una nave que \nte lleva a una estacion espacial donde estas \npor comenzar con tu entrenamiento. \n \n \nSi estas listo para comenzar, presiona ENTER";
	
	
	// Level 1 
	const char lvl1Intro[200] = "En tu primera simulacion te enfrentaras \na las naves exploradoras, estas naves \nestan preparadas para realizar ataques, \nsu defensa es muy escasa.";
	const char lvl1Outro[150] = "Bien hecho soldado, \nhaz pasado la primera simulacion con exito.";
	
	
	
	// Level 2 
	const char lvl2Intro[160] = "En la siguiente fase de tu entrenamiento \ntendras que ademas de matar las naves, \nesquivar los asteroides.El contacto con estos \ndañan tu nave.";
	const char lvl2Outro[50] = "Soldado, su avance es maravilloso.";
	
	
	
	// Level 3 
	const char lvl3Intro[250] = "Decidimos que esta sea su ultima simulacion \nantes de la simulacion final. \nEn esta simulacion sus rivales \nseran las naves de defensa, \nestas tienen una estructura dificil \nde flanquear, pero su ataque es debil.";
	const char lvl3Outro[65] = "Excelente desempeño soldado, \nestas lista para la prueba fianl";
	
	
	// Final Level
	const char finalLevelIntro[350] = "Para poder comandar tu propia nave \ny unirte a la batalla debes realizar \nla prueba final. \nEn esta te enfrentaras a una nave \nnodriza que es escoltada por naves de defensa \ny exploradoras que no tendran piedad al atacar. \nTe otorgamos una nueva nave que \nsera la que pilotearas en el futuro \ncon una mayor defensa";
	const char finalLevelIntro2[200] = "Tu desempeño a lo largo de los entrenamientos \nha sido maravilloso, esperemos puedas unirte a nuestro \nfrente de batalla. Han venido grandes \nlideres a ver tu ultima prueba.";
	
	
	// Dialogo Final
	const char introFinal[150] = "Luego de tu victoria \nla sala quedo en silencio, \nlos lideres se retiraron de la sala, \nno hicieron ningun ademan por tu victoria.";
	//Oficial
	const char finalDialog1[75] = "Finalmente hemos ganado la batalla contra los Xenoides.";
	//Player
	const char finalDialog2[50] = "¿Como que hemos ganado la batalla?";
	//Oficial 
	const char finalDialog3[300] = "Si, como escuchas, \nhemos vencido a los Xenoides, \nnuestra especie esta a salvo gracias a ti. \nLas simulaciones eran solo una fachada. \nMantuvimos la verdad oculta \npara evitar la propagacion del panico \ny la ansiedad entre los reclutas. \nPero es momento de que sepas la verdad.";
};