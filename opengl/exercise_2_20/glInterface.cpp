#include "glInterface.h"

int main() {
	const GLbyte arr[] = {127.0,127.0,127.0};
	glInterfaceColor(127.0,127.0,127.0);
	glInterfaceColor(arr);
	return 0;
}

void glInterfaceAccum(GLenum op, GLfloat value)
{
	glAccum(op, value);
}

void glInterfaceColor(GLbyte red, GLbyte green, GLbyte blue)
{
	glColor3b(red, green, blue);
}

void glInterfaceColor(const GLbyte* v)
{
	glColor3bv(v);
}

void glInterfaceColor(GLdouble red, GLdouble green, GLdouble blue)
{
	glColor3d(red, green, blue);
}

void glInterfaceColor (const GLdouble *v)
{
	glColor3dv(v);
}

void glInterfaceColor (GLfloat red, GLfloat green, GLfloat blue)
{
	glColor3f(red, green, blue);
}

void glInterfaceColor (const GLfloat *v)
{
	glColor3fv(v);
}

void glInterfaceColor (GLint red, GLint green, GLint blue)
{
	glColor3i(red, green, blue);
}

void glInterfaceColor (const GLint *v)
{
	glColor3iv(v);
}

void glInterfaceColor (GLshort red, GLshort green, GLshort blue)
{
	glColor3s(red, green, blue);
}

void glInterfaceColor(const GLshort *v)
{
	glColor3sv(v);
}

void glInterfaceColor (GLubyte red, GLubyte green, GLubyte blue)
{
	glColor3ub(red, green, blue);
}

void glInterfaceColor (const GLubyte *v)
{
	glColor3ubv(v);
}

void glInterfaceColor (GLuint red, GLuint green, GLuint blue)
{
	glColor3ui(red, green, blue);
}

void glInterfaceColor (const GLuint *v)
{
	glColor3uiv(v);
}

void glInterfaceColor (GLushort red, GLushort green, GLushort blue)
{
	glColor3us(red, green, blue);
}

void glInterfaceColor (const GLushort *v)
{
	glColor3usv(v);
}

void glInterfaceColor (GLbyte red, GLbyte green, GLbyte blue, GLbyte alpha)
{
	glColor4b(red, green, blue, alpha);
}

void glInterfaceColor4 (const GLbyte *v)
{
	glColor4bv(v);
}

void glInterfaceColor (GLdouble red, GLdouble green, GLdouble blue, GLdouble alpha)
{
	glColor4d(red, green, blue, alpha);
}

void glInterfaceColor4 (const GLdouble *v)
{
	glColor4dv(v);
}

void glInterfaceColor (GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha)
{
	glColor4f(red, green, blue, alpha);
}

void glInterfaceColor4 (const GLfloat *v)
{
	glColor4fv(v);
}

void glInterfaceColor (GLint red, GLint green, GLint blue, GLint alpha)
{
	glColor4i(red, green, blue, alpha);
}

void glInterfaceColor4 (const GLint *v)
{
	glColor4iv(v);
}

void glInterfaceColor (GLshort red, GLshort green, GLshort blue, GLshort alpha)
{
	glColor4s(red, green, blue, alpha);
}

void glInterfaceColor4 (const GLshort *v)
{
	glColor4sv(v);
}

void glInterfaceColor (GLubyte red, GLubyte green, GLubyte blue, GLubyte alpha)
{
	glColor4ub(red, green, blue, alpha);
}

void glInterfaceColor4 (const GLubyte *v)
{
	glColor4ubv(v);
}

void glInterfaceColor (GLuint red, GLuint green, GLuint blue, GLuint alpha)
{
	glColor4ui(red, green, blue, alpha);
}

void glInterfaceColor4 (const GLuint *v)
{
	glColor4uiv(v);
}

void glInterfaceColor (GLushort red, GLushort green, GLushort blue, GLushort alpha)
{
	glColor4us(red, green, blue, alpha);
}

void glInterfaceColor4 (const GLushort *v)
{
	glColor4usv(v);
}

void glInterfaceColorMask (GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha)
{
	glColorMask(red, green, blue, alpha);
}

void glInterfaceColorMaterial (GLenum face, GLenum mode)
{
	glColorMaterial(face, mode);
}

void glInterfaceColorPointer (GLint size, GLenum type, GLsizei stride, const GLvoid *pointer)
{
	glColorPointer(size, type, stride, pointer);
}

void glInterfaceColorSubTable (GLenum target, GLsizei start, GLsizei count, GLenum format, GLenum type, const GLvoid *data)
{
	glColorSubTable(target, start, count, format, type, data);
}

void glInterfaceColorTable (GLenum target, GLenum internalformat, GLsizei width, GLenum format, GLenum type, const GLvoid *table)
{
	glColorTable(target, internalformat, width, format, type, table);
}

void glInterfaceColorTableParameter (GLenum target, GLenum pname, const GLfloat *params)
{
	glColorTableParameterfv(target, pname, params);
}

void glInterfaceColorTableParameter (GLenum target, GLenum pname, const GLint *params)
{
	glColorTableParameteriv(target, pname, params);
}

void glInterfaceConvolutionFilter (GLenum target, GLenum internalformat, GLsizei width, GLenum format, GLenum type, const GLvoid *image)
{
	glConvolutionFilter1D(target, internalformat, width, format, type, image);
}

void glInterfaceConvolutionFilter (GLenum target, GLenum internalformat, GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid *image)
{
	glConvolutionFilter2D(target, internalformat, width, height, format, type, image);
}

void glInterfaceConvolutionParameter (GLenum target, GLenum pname, GLfloat params)
{
	glConvolutionParameterf(target, pname, params);
}

void glInterfaceConvolutionParameter (GLenum target, GLenum pname, const GLfloat *params)
{
	glConvolutionParameterfv(target, pname, params);
}

void glInterfaceConvolutionParameter (GLenum target, GLenum pname, GLint params)
{
	glConvolutionParameteri(target, pname, params);
}

void glInterfaceConvolutionParameter (GLenum target, GLenum pname, const GLint *params)
{
	glConvolutionParameteriv(target, pname, params);
}