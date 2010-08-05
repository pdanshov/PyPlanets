#include <stdio.h>
#include <math.h>
#include "Python.h"

#define CONST_GRAVITACIONAL 6.67428 * pow(10.0, -11.0)


void initcontas(void);

main(int argc, char **argv){
	// Inicializa o Interpretador python embutido
	Py_Initialize();
	// Adiciona o nosso modulo
	initcontas();
	// Sai do interpretador embutido.
	Py_Exit(0);
}

static PyObject *contas_forc(PyObject *self, PyObject* args){
	double x_diff, y_diff, distance, force;
	double ax, ay, ar, am, bx, by, br, bm;

	if (!PyArg_ParseTuple(args, "dddddddd", &ax , &ay , &ar , &am , &bx , &by , &br, &bm)) {
		return NULL;
	}
	x_diff = ax - bx;
	y_diff = ay - by;
	distance = sqrt(pow(x_diff, 2) + pow(y_diff, 2));

	if(distance < (ar + br)) {
		distance = ar + br;
	}
	force = (CONST_GRAVITACIONAL * am * pow(10, 10) * bm * pow(10, 10)) / pow(dist * pow(10, 6), 2); //F = (Constant*massA*massB)/dist**2

	return PyFloat_FromDouble(force);
}


static PyMethodDef contas_methods[] = {
	{"forc",contas_forc,METH_VARARGS, "Documentação do argumento_numeros"},
	{NULL, NULL} //sentinela
};

void initcontas(void) {
	PyImport_AddModule("contas");
	Py_InitModule("contas", contas_methods);
}
