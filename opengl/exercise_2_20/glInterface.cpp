#include "glInterface.h"

int main() {
	glInterfaceAccum(1,1.0);
	return 0;
}

void glInterfaceAccum(GLenum op, GLfloat value)
{
	glAccum(op, value);
}

