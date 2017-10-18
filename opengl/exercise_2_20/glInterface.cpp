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


void glInterfaceAlphaFunc(GLenum func, GLclampf ref)
{
	glAlphaFunc(func, ref);
}

GLboolean glInterfaceAreTexturesResident (GLsizei n, const GLuint *textures, GLboolean *residences)
{
	return glAreTexturesResident(n, textures, residences);
}

void glInterfaceArrayElement(GLint i)
{
	glArrayElement(i);
}

void glInterfaceBegin(GLenum mode)
{
	glBegin(mode);
}

void glInterfaceBindTexture (GLenum target, GLuint texture)
{
	glBindTexture(target, texture);
}

void glInterfaceBitmap (GLsizei width, GLsizei height, GLfloat xorig, GLfloat yorig, GLfloat xmove, GLfloat ymove, const GLubyte *bitmap)
{
	glBitmap(width, height, xorig, yorig, xmove, ymove, bitmap);
}

void glInterfaceBlendColor (GLclampf red, GLclampf green, GLclampf blue, GLclampf alpha)
{
	glBlendColor(red, green, blue, alpha);
}

void glInterfaceBlendEquation(GLenum mode)
{
	glBlendEquation(mode);
}

void glInterfaceBlendEquationSeparate(GLenum modeRGB, GLenum modeAlpha)
{
	glBlendEquationSeparate(modeRGB, modeAlpha);
}

void glInterfaceBlendFunc(GLenum sfactor, GLenum dfactor)
{
	glBlendFunc(sfactor, dfactor);
}

void glInterfaceCallList(GLuint list)
{
	glCallList(list);
}

void glInterfaceCallLists (GLsizei n, GLenum type, const GLvoid *lists)
{
	glCallLists(n, type, lists);
}

void glInterfaceClear (GLbitfield mask)
{
	glClear(mask);
}

void glInterfaceClearAccum (GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha)
{
	glClearAccum(red, green, blue, alpha);
}

void glInterfaceClearColor (GLclampf red, GLclampf green, GLclampf blue, GLclampf alpha)
{
	glClearColor(red, green, blue, alpha);
}

void glInterfaceClearDepth (GLclampd depth)
{
	glClearDepth(depth);
}

void glInterfaceClearIndex (GLfloat c)
{
	glClearIndex(c);
}

void glInterfaceClearStencil (GLint s)
{
	glClearStencil(s);
}

void glInterfaceClipPlane (GLenum plane, const GLdouble *equation)
{
	glClipPlane(plane, equation);
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

void glInterfaceCopyColorSubTable (GLenum target, GLsizei start, GLint x, GLint y, GLsizei width)
{
	glCopyColorSubTable(target, start, x, y, width);
}

void glInterfaceCopyColorTable (GLenum target, GLenum internalformat, GLint x, GLint y, GLsizei width)
{
	glCopyColorTable(target, internalformat, x, y, width);
}

void glInterfaceCopyConvolutionFilter (GLenum target, GLenum internalformat, GLint x, GLint y, GLsizei width)
{
	glCopyConvolutionFilter1D(target, internalformat, x, y, width);
}

void glInterfaceCopyConvolutionFilter (GLenum target, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height)
{
	glCopyConvolutionFilter2D(target, internalformat, x, y, width, height);
}

void glInterfaceCopyPixels (GLint x, GLint y, GLsizei width, GLsizei height, GLenum type)
{
	glCopyPixels(x, y, width, height, type);
}

void glInterfaceCopyTexImage (GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLint border)
{
	glCopyTexImage1D(target, level, internalformat, x, y, width, border);
}

void glInterfaceCopyTexImage (GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border)
{
	glCopyTexImage2D(target, level, internalformat, x, y, width, height, border);
}

void glInterfaceCopyTexSubImage (GLenum target, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width)
{
	glCopyTexSubImage1D(target, level, xoffset, x, y, width);
}

void glInterfaceCopyTexSubImage (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height)
{
	glCopyTexSubImage2D(target, level, xoffset, yoffset, x, y, width, height);
}

void glInterfaceCopyTexSubImage (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height)
{
	glCopyTexSubImage3D(target, level, xoffset, yoffset, zoffset, x, y, width, height);
}

void glInterfaceCullFace (GLenum mode)
{
	glCullFace(mode);
}

void glInterfaceDeleteLists (GLuint list, GLsizei range)
{
	glDeleteLists(list, range);
}

void glInterfaceDeleteTextures (GLsizei n, const GLuint *textures)
{
	glDeleteTextures(n, textures);
}

void glInterfaceDepthFunc (GLenum func)
{
	glDepthFunc(func);
}

void glInterfaceDepthMask (GLboolean flag)
{
	glDepthMask(flag);
}

void glInterfaceDepthRange (GLclampd zNear, GLclampd zFar)
{
	glDepthRange(zNear, zFar);	
}

void glInterfaceDisable (GLenum cap)
{
	glDisable(cap);	
}

void glInterfaceDisableClientState (GLenum array)
{
	glDisableClientState(array);
}

void glInterfaceDrawArrays (GLenum mode, GLint first, GLsizei count)
{
	glDrawArrays(mode, first, count);
}

void glInterfaceDrawBuffer (GLenum mode)
{
	glDrawBuffer(mode);
}

void glInterfaceDrawElements (GLenum mode, GLsizei count, GLenum type, const GLvoid *indices)
{
	glDrawElements(mode, count, type, indices);
}

void glInterfaceDrawPixels (GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid *pixels)
{
	glDrawPixels(width, height, format, type, pixels);
}

void glInterfaceDrawRangeElements (GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const GLvoid *indices)
{
	glDrawRangeElements(mode, start, end, count, type, indices);
}

void glInterfaceEdgeFlag (GLboolean flag)
{
	glEdgeFlag(flag);
}

void glInterfaceEdgeFlag (GLsizei stride, const GLvoid *pointer)
{
	glEdgeFlagPointer(stride, pointer);
}

void glInterfaceEdgeFlag(const GLboolean *flag)
{
	glEdgeFlagv(flag);
}

void glInterfaceEnable (GLenum cap)
{
	glEnable(cap);
}

void glInterfaceEnableClientState (GLenum array)
{
	glEnableClientState(array);
}

void glInterfaceEnd (void)
{
	glEnd();
}

void glInterfaceEndList (void)
{
	glEndList();
}

void glInterfaceEvalCoord (GLdouble u)
{
	glEvalCoord1d(u);
}

void glInterfaceEvalCoord (const GLdouble *u)
{
	glEvalCoord1dv(u);
}

void glInterfaceEvalCoord (GLfloat u)
{
	glEvalCoord1f(u);
}

void glInterfaceEvalCoord (const GLfloat *u)
{
	glEvalCoord1fv(u);
}

void glInterfaceEvalCoord (GLdouble u, GLdouble v)
{
	glEvalCoord2d(u,v);
}


void glInterfaceEvalCoord (GLfloat u, GLfloat v)
{
	glEvalCoord2f(u,v);	
}


void glInterfaceEvalCoord2 (const GLdouble *u)
{
	glEvalCoord2dv(u);
}

void glInterfaceEvalCoord2 (const GLfloat *u)
{
	glEvalCoord2fv(u);
}

void glInterfaceEvalMesh (GLenum mode, GLint i1, GLint i2)
{
	glEvalMesh1(mode, i1, i2);
}

void glInterfaceEvalMesh (GLenum mode, GLint i1, GLint i2, GLint j1, GLint j2)
{
	glEvalMesh2(mode, i1, i2, j1, j2);
}

void glInterfaceEvalPoint (GLint i)
{
	glEvalPoint1(i);
}

void glInterfaceEvalPoint (GLint i, GLint j)
{
	glEvalPoint2(i,j);
}

void glInterfaceFeedbackBuffer (GLsizei size, GLenum type, GLfloat *buffer)
{
	glFeedbackBuffer(size, type, buffer);
}

void glInterfaceFinish (void)
{
	glFinish();
}

void glInterfaceFlush (void)
{
	glFlush();
}

void glInterfaceFog (GLenum pname, GLfloat param)
{
	glFogf(pname, param);
}

void glInterfaceFog (GLenum pname, const GLfloat *params)
{
	glFogfv(pname, params);
}

void glInterfaceFog (GLenum pname, GLint param)
{
	glFogi(pname, param);
}

void glInterfaceFog (GLenum pname, const GLint *params)
{
	glFogiv(pname, params);
}

void glInterfaceFrontFace (GLenum mode)
{
	glFrontFace(mode);
}

void glInterfaceFrustum (GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble zNear, GLdouble zFar)
{
	glFrustum(left, right, bottom, top, zNear, zFar);
}

GLuint glInterfaceGenLists (GLsizei range)
{
	return glGenLists(range);
}

void glInterfaceGenTextures (GLsizei n, GLuint *textures)
{
	glGenTextures(n, textures);
}

void glInterfaceGetBooleanv (GLenum pname, GLboolean *params)
{
	glGetBooleanv(pname, params);
}

void glInterfaceGetClipPlane (GLenum plane, GLdouble *equation)
{
	glGetClipPlane(plane, equation);
}

void glInterfaceGetColorTable (GLenum target, GLenum format, GLenum type, GLvoid *table)
{
	glGetColorTable(target, format, type, table);
}

void glInterfaceGetColorTableParameter (GLenum target, GLenum pname, GLfloat *params)
{
	glGetColorTableParameterfv(target, pname, params);
}

void glInterfaceGetColorTableParameter (GLenum target, GLenum pname, GLint *params)
{
	glGetColorTableParameteriv(target, pname, params);
}

void glInterfaceGetConvolutionFilter (GLenum target, GLenum format, GLenum type, GLvoid *image)
{
	glGetConvolutionFilter(target, format, type, image);
}

void glInterfaceGetConvolutionParameter (GLenum target, GLenum pname, GLfloat *params)
{
	glGetConvolutionParameterfv(target, pname, params);
}

void glInterfaceGetConvolutionParameter (GLenum target, GLenum pname, GLint *params)
{
	glGetConvolutionParameteriv(target, pname, params);
}

void glInterfaceGetDoublev (GLenum pname, GLdouble *params)
{
	glGetDoublev(pname, params);
}

GLenum glInterfaceGetError (void)
{
	return glGetError();
}

void glInterfaceGetFloatv (GLenum pname, GLfloat *params)
{
	glGetFloatv(pname, params);
}

void glInterfaceGetHistogram (GLenum target, GLboolean reset, GLenum format, GLenum type, GLvoid *values)
{
	glGetHistogram(target, reset, format, type, values);
}

void glInterfaceGetHistogramParameter (GLenum target, GLenum pname, GLfloat *params)
{
	glGetHistogramParameterfv(target, pname, params);
}

void glInterfaceGetHistogramParameter (GLenum target, GLenum pname, GLint *params)
{
	glGetHistogramParameteriv(target, pname, params);
}

void glInterfaceGetIntegerv (GLenum pname, GLint *params)
{
	glGetIntegerv(pname, params);
}

void glInterfaceGetLight (GLenum light, GLenum pname, GLfloat *params)
{
	glGetLightfv(light, pname, params);
}

void glInterfaceGetLight (GLenum light, GLenum pname, GLint *params)
{
	glGetLightiv(light, pname, params);
}

void glInterfaceGetMap (GLenum target, GLenum query, GLdouble *v)
{
	glGetMapdv(target, query, v);
}

void glInterfaceGetMap (GLenum target, GLenum query, GLfloat *v)
{
	glGetMapfv(target, query, v);
}

void glInterfaceGetMap (GLenum target, GLenum query, GLint *v)
{
	glGetMapiv(target, query, v);
}

void glInterfaceGetMaterial (GLenum face, GLenum pname, GLfloat *params)
{
	glGetMaterialfv(face, pname, params);
}

void glInterfaceGetMaterialiv (GLenum face, GLenum pname, GLint *params)
{
	glGetMaterialiv(face, pname, params);
}

void glInterfaceGetMinmax (GLenum target, GLboolean reset, GLenum format, GLenum type, GLvoid *values)
{
	glGetMinmax(target, reset, format, type, values);
}

void glInterfaceGetMinmaxParameter (GLenum target, GLenum pname, GLfloat *params)
{
	glGetMinmaxParameterfv(target, pname, params);
}

void glInterfaceGetMinmaxParameter (GLenum target, GLenum pname, GLint *params)
{
	glGetMinmaxParameteriv(target, pname, params);
}

void glInterfaceGetPixelMap (GLenum map, GLfloat *values)
{
	glGetPixelMapfv(map, values);
}

void glInterfaceGetPixelMap (GLenum map, GLuint *values)
{
	glGetPixelMapuiv(map, values);
}

void glInterfaceGetPixelMap (GLenum map, GLushort *values)
{
	glGetPixelMapusv(map, values);
}

void glInterfaceGetPointerv (GLenum pname, GLvoid **params)
{
	glGetPointerv(pname, params);
}

void glInterfaceGetPolygonStipple (GLubyte *mask)
{
	glGetPolygonStipple(mask);
}

void glInterfaceGetSeparableFilter (GLenum target, GLenum format, GLenum type, GLvoid *row, GLvoid *column, GLvoid *span)
{
	glGetSeparableFilter(target, format, type, row, column, span);
}

const GLubyte *glInterfaceGetString (GLenum name)
{
	return glGetString(name);
}

void glInterfaceGetTexEnv (GLenum target, GLenum pname, GLfloat *params)
{
	glGetTexEnvfv(target, pname, params);
}

void glInterfaceGetTexEnv (GLenum target, GLenum pname, GLint *params)
{
	glGetTexEnviv(target, pname, params);
}

void glInterfaceGetTexGen (GLenum coord, GLenum pname, GLdouble *params)
{
	glGetTexGendv(coord, pname, params);
}

void glInterfaceGetTexGen (GLenum coord, GLenum pname, GLfloat *params)
{
	glGetTexGenfv(coord, pname, params);
}

void glInterfaceGetTexGen (GLenum coord, GLenum pname, GLint *params)
{
	glGetTexGeniv(coord, pname, params);
}

void glInterfaceGetTexImage (GLenum target, GLint level, GLenum format, GLenum type, GLvoid *pixels)
{
	glGetTexImage(target, level, format, type, pixels);
}

void glInterfaceGetTexLevelParameter (GLenum target, GLint level, GLenum pname, GLfloat *params)
{
	glGetTexLevelParameterfv(target, level, pname, params);
}

void glInterfaceGetTexLevelParameter (GLenum target, GLint level, GLenum pname, GLint *params)
{
	glGetTexLevelParameteriv(target, level, pname, params);
}

void glInterfaceGetTexParameter (GLenum target, GLenum pname, GLfloat *params)
{
	glGetTexParameterfv(target, pname, params);
}

void glInterfaceGetTexParameter (GLenum target, GLenum pname, GLint *params)
{
	glGetTexParameteriv(target, pname, params);
}

void glInterfaceHint (GLenum target, GLenum mode)
{
	glHint(target, mode);
}

void glInterfaceHistogram (GLenum target, GLsizei width, GLenum internalformat, GLboolean sink)
{
	glHistogram(target, width, internalformat, sink);
}

void glInterfaceIndexMask (GLuint mask)
{
	glIndexMask(mask);
}

void glInterfaceIndexPointer (GLenum type, GLsizei stride, const GLvoid *pointer)
{
	glIndexPointer(type, stride, pointer);
}

void glInterfaceIndex (GLdouble c)
{
	glIndexd(c);
}

void glInterfaceIndex (const GLdouble *c)
{
	glIndexdv(c);
}

void glInterfaceIndex (GLfloat c)
{
	glIndexf(c);
}

void glInterfaceIndex (const GLfloat *c)
{
	glIndexfv(c);
}

void glInterfaceIndex (GLint c)
{
	glIndexi(c);
}

void glInterfaceIndex (const GLint *c)
{
	glIndexiv(c);
}

void glInterfaceIndex(GLshort c)
{
	glIndexs(c);
}

void glInterfaceIndex (const GLshort *c)
{
	glIndexsv(c);
}

void glInterfaceIndex (GLubyte c)
{
	glIndexub(c);
}

void glInterfaceIndex (const GLubyte *c)
{
	glIndexubv(c);
}

void glInterfaceInitNames (void)
{
	glInitNames();
}

void glInterfaceInterleavedArrays (GLenum format, GLsizei stride, const GLvoid *pointer)
{
	glInterleavedArrays(format, stride, pointer);
}

GLboolean glInterfaceIsEnabled (GLenum cap)
{
	return glIsEnabled(cap);
}

GLboolean glInterfaceIsList (GLuint list)
{
	return glIsList(list);
}

GLboolean glInterfaceIsTexture (GLuint texture)
{
	return glIsTexture(texture);
}

void glInterfaceLightModel (GLenum pname, GLfloat param)
{
	glLightModelf(pname, param);
}

void glInterfaceLightModel (GLenum pname, const GLfloat *params)
{
	glLightModelfv(pname, params);
}

void glInterfaceLightModel (GLenum pname, GLint param)
{
	glLightModeli(pname, param);
}

void glInterfaceLightModel (GLenum pname, const GLint *params)
{
	glLightModeliv(pname, params);
}

void glInterfaceLight (GLenum light, GLenum pname, GLfloat param)
{
	glLightf(light, pname, param);
}

void glInterfaceLight (GLenum light, GLenum pname, const GLfloat *params)
{
	glLightfv(light, pname, params);
}

void glInterfaceLight (GLenum light, GLenum pname, GLint param)
{
	glLighti(light, pname, param);
}

void glInterfaceLight (GLenum light, GLenum pname, const GLint *params)
{
	glLightiv(light, pname, params);
}

void glInterfaceLineStipple (GLint factor, GLushort pattern)
{
	glLineStipple(factor, pattern);
}

void glInterfaceLineWidth (GLfloat width)
{
	glLineWidth(width);
}

void glInterfaceListBase (GLuint base)
{
	glListBase(base);
}

void glInterfaceLoadIdentity (void)
{
	glLoadIdentity();
}

void glInterfaceLoadMatrix (const GLdouble *m)
{
	glLoadMatrixd(m);
}

void glInterfaceLoadMatrix (const GLfloat *m)
{
	glLoadMatrixf(m);
}

void glInterfaceLoadName (GLuint name)
{
	glLoadName(name);
}

void glInterfaceLogicOp (GLenum opcode)
{
	glLogicOp(opcode);
}

void glInterfaceMap (GLenum target, GLdouble u1, GLdouble u2, GLint stride, GLint order, const GLdouble *points)
{
	glMap1d(target, u1, u2, stride, order, points);
}

void glInterfaceMap (GLenum target, GLfloat u1, GLfloat u2, GLint stride, GLint order, const GLfloat *points)
{
	glMap1f(target, u1, u2, stride, order, points);
}

void glInterfaceMap (GLenum target, GLdouble u1, GLdouble u2, GLint ustride, GLint uorder, GLdouble v1, GLdouble v2, GLint vstride, GLint vorder, const GLdouble *points)
{
	glMap2d(target, u1, u2, ustride, uorder, v1, v2, vstride, vorder, points);
}

void glInterfaceMap (GLenum target, GLfloat u1, GLfloat u2, GLint ustride, GLint uorder, GLfloat v1, GLfloat v2, GLint vstride, GLint vorder, const GLfloat *points)
{
	glMap2f(target, u1, u2, ustride, uorder, v1, v2, vstride, vorder, points);
}

void glInterfaceMapGrid (GLint un, GLdouble u1, GLdouble u2)
{
	glMapGrid1d(un, u1, u2);
}

void glInterfaceMapGrid (GLint un, GLfloat u1, GLfloat u2)
{
	glMapGrid1f(un, u1, u2);
}

void glInterfaceMapGrid (GLint un, GLdouble u1, GLdouble u2, GLint vn, GLdouble v1, GLdouble v2)
{
	glMapGrid2d(un, u1, u2, vn, v1, v2);
}

void glInterfaceMapGrid (GLint un, GLfloat u1, GLfloat u2, GLint vn, GLfloat v1, GLfloat v2)
{
	glMapGrid2f(un, u1, u2, vn, v1, v2);
}

void glInterfaceMaterial (GLenum face, GLenum pname, GLfloat param)
{
	glMaterialf(face, pname, param);
}

void glInterfaceMaterial (GLenum face, GLenum pname, const GLfloat *params)
{
	glMaterialfv(face, pname, params);
}

void glInterfaceMaterial (GLenum face, GLenum pname, GLint param)
{
	glMateriali(face, pname, param);
}

void glInterfaceMaterial (GLenum face, GLenum pname, const GLint *params)
{
	glMaterialiv(face, pname, params);
}

void glInterfaceMatrixMode (GLenum mode)
{
	glMatrixMode(mode);
}

void glInterfaceMinmax (GLenum target, GLenum internalformat, GLboolean sink)
{
	glMinmax(target, internalformat, sink);
}

void glInterfaceMultMatrix (const GLdouble *m)
{
	glMultMatrixd(m);
}

void glInterfaceMultMatrix (const GLfloat *m)
{
	glMultMatrixf(m);
}

void glInterfaceNewList (GLuint list, GLenum mode)
{
	glNewList(list, mode);
}

void glInterfaceNormal (GLbyte nx, GLbyte ny, GLbyte nz)
{
	glNormal3b(nx, ny, nz);
}

void glInterfaceNormal (const GLbyte *v)
{
	glNormal3bv(v);
}

void glItnerfaceNormal (GLdouble nx, GLdouble ny, GLdouble nz)
{
	glNormal3d(nx, ny, nz);
}

void glInterfaceNormal (const GLdouble *v)
{
	glNormal3dv(v);
}

void glInterfaceNormal (GLfloat nx, GLfloat ny, GLfloat nz)
{
	glNormal3f(nx, ny, nz);
}

void glInterfaceNormal (const GLfloat *v)
{
	glNormal3fv(v);
}

void glInterfaceNormal (GLint nx, GLint ny, GLint nz)
{
	glNormal3i(nx, ny, nz);
}

void glInterfaceNormal (const GLint *v)
{
	glNormal3iv(v);
}

void glInterfaceNormal (GLshort nx, GLshort ny, GLshort nz)
{
	glNormal3s(nx, ny, nz);
}

void glInterfaceNormal (const GLshort *v)
{
	glNormal3sv(v);
}

void glInterfaceNormalPointer (GLenum type, GLsizei stride, const GLvoid *pointer)
{
	glNormalPointer(type, stride, pointer);
}

void glInterfaceOrtho (GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble zNear, GLdouble zFar)
{
	glOrtho(left, right, bottom, top, zNear, zFar);
}

void glInterfacePassThrough (GLfloat token)
{
	glPassThrough(token);
}

void glInterfacePixelMap (GLenum map, GLint mapsize, const GLfloat *values)
{
	glPixelMapfv(map, mapsize, values);
}

void glInterfacePixelMap (GLenum map, GLint mapsize, const GLuint *values)
{
	glPixelMapuiv(map, mapsize, values);
}

void glInterfacePixelMap (GLenum map, GLint mapsize, const GLushort *values)
{
	glPixelMapusv(map, mapsize, values);
}

void glInterfacePixelStore (GLenum pname, GLfloat param)
{
	glPixelStoref(pname, param);
}

void glInterfacePixelStore (GLenum pname, GLint param)
{
	glPixelStorei(pname, param);
}

void glInterfacePixelTransfer (GLenum pname, GLfloat param)
{
	glPixelTransferf(pname, param);
}

void glInterfacePixelTransfer (GLenum pname, GLint param)
{
	glPixelTransferi(pname, param);
}

void glInterfacePixelZoom (GLfloat xfactor, GLfloat yfactor)
{
	glPixelZoom(xfactor, yfactor);
}

void glInterfacePointSize (GLfloat size)
{
	glPointSize(size);
}

void glInterfacePolygonMode (GLenum face, GLenum mode)
{
	glPolygonMode(face, mode);
}

void glInterfacePolygonOffset (GLfloat factor, GLfloat units)
{
	glPolygonOffset(factor, units);
}

void glInterfacePolygonStipple (const GLubyte *mask)
{
	glPolygonStipple(mask);
}

void glInterfacePopAttrib (void)
{
	glPopAttrib();
}

void glInterfacePopClientAttrib (void)
{
	glPopClientAttrib();
}

void glInterfacePopMatrix (void)
{
	glPopMatrix();
}

void glInterfacePopName (void)
{
	glPopName();
}

void glInterfacePrioritizeTextures (GLsizei n, const GLuint *textures, const GLclampf *priorities)
{
	glPrioritizeTextures(n, textures, priorities);
}

void glInterfacePushAttrib (GLbitfield mask)
{
	glPushAttrib(mask);
}

void glInterfacePushClientAttrib (GLbitfield mask)
{
	glPushClientAttrib(mask);
}

void glInterfacePushMatrix (void)
{
	glPushMatrix();
}

void glInterfacePushName (GLuint name)
{
	glPushName(name);
}

void glInterfaceRasterPos (GLdouble x, GLdouble y)
{
	glRasterPos2d(x, y);
}

void glInterfaceRasterPos (const GLdouble *v)
{
	glRasterPos2dv(v);
}

void glInterfaceRasterPos (GLfloat x, GLfloat y)
{
	glRasterPos2f(x, y);
}

void glInterfaceRasterPos (const GLfloat *v)
{
	glRasterPos2fv(v);
}

void glInterfaceRasterPos (GLint x, GLint y)
{
	glRasterPos2i(x, y);
}

void glInterfaceRasterPos (const GLint *v)
{
	glRasterPos2iv(v);
}

void glInterfaceRasterPos (GLshort x, GLshort y)
{
	glRasterPos2s(x, y);
}

void glInterfaceRasterPos (const GLshort *v)
{
	glRasterPos2sv(v);
}

void glInterfaceRasterPos3 (GLdouble x, GLdouble y, GLdouble z)
{
	glRasterPos3d(x, y, z);
}

void glInterfaceRasterPos3 (const GLdouble *v)
{
	glRasterPos3dv(v);
}

void glInterfaceRasterPos3 (GLfloat x, GLfloat y, GLfloat z)
{
	glRasterPos3f(x, y, z);
}

void glInterfaceRasterPos3 (const GLfloat *v)
{
	glRasterPos3fv(v);
}

void glInterfaceRasterPos3 (GLint x, GLint y, GLint z)
{
	glRasterPos3i(x, y, z);
}

void glInterfaceRasterPos3 (const GLint *v)
{
	glRasterPos3iv(v);
}

void glInterfaceRasterPos3 (GLshort x, GLshort y, GLshort z)
{
	glRasterPos3s(x, y, z);
}

void glInterfaceRasterPos3 (const GLshort *v)
{
	glRasterPos3sv(v);
}

void glInterfaceRasterPos4 (GLdouble x, GLdouble y, GLdouble z, GLdouble w)
{
	glRasterPos4d(x, y, z, w);
}

void glInterfaceRasterPos4 (const GLdouble *v)
{
	glRasterPos4dv(v);
}

void glInterfaceRasterPos4 (GLfloat x, GLfloat y, GLdouble z, GLdouble w)
{
	glRasterPos4f(x, y, z, w);
}

void glInterfaceRasterPos4 (const GLfloat *v)
{
	glRasterPos4fv(v);
}

void glInterfaceRasterPos4 (GLint x, GLint y, GLint z, GLint w)
{
	glRasterPos4i(x, y, z, w);
}

void glInterfaceRasterPos4 (const GLint *v)
{
	glRasterPos4iv(v);
}

void glInterfaceRasterPos4 (GLshort x, GLshort y, GLshort z, GLshort w)
{
	glRasterPos4s(x, y, z, w);
}

void glInterfaceRasterPos4 (const GLshort *v)
{
	glRasterPos4sv(v);
}

void glInterfaceReadBuffer (GLenum mode)
{
	glReadBuffer(mode);
}

void glInterfaceReadPixels (GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, GLvoid *pixels)
{
	glReadPixels(x, y, width, height, format, type, pixels);
}

void glInterfaceRect (GLdouble x1, GLdouble y1, GLdouble x2, GLdouble y2)
{
	glRectd(x1, y1, x2, y2);
}

void glInterfaceRect (const GLdouble *v1, const GLdouble *v2)
{
	glRectdv(v1, v2);
}

void glInterfaceRect (GLfloat x1, GLfloat y1, GLfloat x2, GLfloat y2)
{
	glRectf(x1, y1, x2, y2);
}

void glInterfaceRect (const GLfloat *v1, const GLfloat *v2)
{
	glRectfv(v1, v2);
}

void glInterfaceRect (GLint x1, GLint y1, GLint x2, GLint y2)
{
	glRecti(x1, y1, x2, y2);
}

void glInterfaceRect (const GLint *v1, const GLint *v2)
{
	glRectiv(v1, v2);
}

void glInterfaceRect (GLshort x1, GLshort y1, GLshort x2, GLshort y2)
{
	glRects(x1, y1, x2, y2);
}

void glInterfaceRect (const GLshort *v1, const GLshort *v2)
{
	glRectsv(v1, v2);
}

GLint glInterfaceRenderMode (GLenum mode)
{
	return glRenderMode(mode);
}

void glInterfaceResetHistogram (GLenum target)
{
	glResetHistogram(target);
}

void glInterfaceResetMinmax (GLenum target)
{
	glResetMinmax(target);
}

void glInterfaceRotate (GLdouble angle, GLdouble x, GLdouble y, GLdouble z)
{
	glRotated(angle, x, y, z);
}

void glInterfaceRotate (GLfloat angle, GLfloat x, GLfloat y, GLfloat z)
{
	glRotatef(angle, x, y, z);
}

void glInterfaceScale (GLdouble x, GLdouble y, GLdouble z)
{
	glScaled(x, y, z);
}

void glInterfaceScale (GLfloat x, GLfloat y, GLfloat z)
{
	glScalef(x, y, z);
}

void glInterfaceScissor (GLint x, GLint y, GLsizei width, GLsizei height)
{
	glScissor(x, y, width, height);
}

void glInterfaceSelectBuffer (GLsizei size, GLuint *buffer)
{
	glSelectBuffer(size, buffer);
}

void glInterfaceSeparableFilter2D (GLenum target, GLenum internalformat, GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid *row, const GLvoid *column)
{
	glSeparableFilter2D(target, internalformat, width, height, format, type, row, column);
}

void glInterfaceShadeModel (GLenum mode)
{
	glShadeModel(mode);
}

void glInterfaceStencilFunc (GLenum func, GLint ref, GLuint mask)
{
	glStencilFunc(func, ref, mask);
}

void glInterfaceStencilMask (GLuint mask)
{
	glStencilMask(mask);
}

void glInterfaceStencilOp (GLenum fail, GLenum zfail, GLenum zpass)
{
	glStencilOp(fail, zfail, zpass);
}

void glInterfaceTexCoord (GLdouble s)
{
	glTexCoord1d(s);
}

void glInterfaceTexCoord (GLdouble s, GLdouble t)
{
	glTexCoord2d(s, t);
}

void glInterfaceTexCoord (GLdouble s, GLdouble t, GLdouble r)
{
	glTexCoord3d(s, t, r);
}

void glInterfaceTexCoord (GLdouble s, GLdouble t, GLdouble r, GLdouble q)
{
	glTexCoord4d(s, t, r, q);
}

void glInterfaceTexCoord (const GLdouble *v)
{
	glTexCoord1dv(v);
}

void glInterfaceTexCoord2 (const GLdouble *v)
{
	glTexCoord2dv(v);
}

void glInterfaceTexCoord3 (const GLdouble *v)
{
	glTexCoord3dv(v);
}

void glInterfaceTexCoord4 (const GLdouble *v)
{
	glTexCoord4dv(v);
}

void glInterfaceTexCoord (GLfloat s)
{
	glTexCoord1f(s);
}

void glInterfaceTexCoord (GLfloat s, GLfloat t)
{
	glTexCoord2f(s, t);
}

void glInterfaceTexCoord (GLfloat s, GLfloat t, GLfloat r)
{
	glTexCoord3f(s, t, r);
}

void glInterfaceTexCoord (GLfloat s, GLfloat t, GLfloat r, GLfloat q)
{
	glTexCoord4f(s, t, r, q);
}

void glInterfaceTexCoord (const GLfloat *v)
{
	glTexCoord1fv(v);
}

void glInterfaceTexCoord2 (const GLfloat *v)
{
	glTexCoord2fv(v);
}

void glInterfaceTexCoord3 (const GLfloat *v)
{
	glTexCoord3fv(v);
}

void glInterfaceTexCoord4 (const GLfloat *v)
{
	glTexCoord4fv(v);
}

void glInterfaceTexCoord (GLint s)
{
	glTexCoord1i(s);
}

void glInterfaceTexCoord (GLint s, GLint t)
{
	glTexCoord2i(s, t);
}

void glInterfaceTexCoord (GLint s, GLint t, GLint r)
{
	glTexCoord3i(s, t, r);
}

void glInterfaceTexCoord (GLint s, GLint t, GLint r, GLint q)
{
	glTexCoord4i(s, t, r, q);
}

void glInterfaceTexCoord (const GLint *v)
{
	glTexCoord1iv(v);
}

void glInterfaceTexCoord2 (const GLint *v)
{
	glTexCoord2iv(v);
}

void glInterfaceTexCoord3 (const GLint *v)
{
	glTexCoord3iv(v);
}

void glInterfaceTexCoord4 (const GLint *v)
{
	glTexCoord4iv(v);
}

void glInterfaceTexCoord (GLshort s)
{
	glTexCoord1s(s);
}

void glInterfaceTexCoord (GLshort s, GLshort t)
{
	glTexCoord2s(s, t);
}

void glInterfaceTexCoord (GLshort s, GLshort t, GLshort r)
{
	glTexCoord3s(s, t, r);
}

void glInterfaceTexCoord (GLshort s, GLshort t, GLshort r, GLshort q)
{
	glTexCoord4s(s, t, r, q);
}

void glInterfaceTexCoord (const GLshort *v)
{
	glTexCoord1sv(v);
}

void glInterfaceTexCoord2 (const GLshort *v)
{
	glTexCoord2sv(v);
}

void glInterfaceTexCoord3 (const GLshort *v)
{
	glTexCoord3sv(v);
}

void glInterfaceTexCoord4 (const GLshort *v)
{
	glTexCoord4sv(v);
}

void glInterfaceTexCoordPointer (GLint size, GLenum type, GLsizei stride, const GLvoid *pointer)
{
	glTexCoordPointer(size, type, stride, pointer);
}

void glInterfaceTexEnv (GLenum target, GLenum pname, GLfloat param)
{
	glTexEnvf(target, pname, param);
}

void glInterfaceTexEnv (GLenum target, GLenum pname, const GLfloat *params)
{
	glTexEnvfv(target, pname, params);
}

void glInterfaceTexEnv (GLenum target, GLenum pname, GLint param)
{
	glTexEnvi(target, pname, param);
}

void glInterfaceTexEnv (GLenum target, GLenum pname, const GLint *params)
{
	glTexEnviv(target, pname, params);
}

void glInterfaceTexGen (GLenum coord, GLenum pname, GLdouble param)
{
	glTexGend(coord, pname, param);
}

void glInterfaceTexGen (GLenum coord, GLenum pname, const GLdouble *params)
{
	glTexGendv(coord, pname, params);
}

void glInterfaceTexGen (GLenum coord, GLenum pname, GLfloat param)
{
	glTexGenf(coord, pname, param);
}

void glInterfaceTexGen (GLenum coord, GLenum pname, const GLfloat *params)
{
	glTexGenfv(coord, pname, params);
}

void glInterfaceTexGen (GLenum coord, GLenum pname, GLint param)
{
	glTexGeni(coord, pname, param);
}

void glInterfaceTexGen (GLenum coord, GLenum pname, const GLint *params)
{
	glTexGeniv(coord, pname, params);
}

void glInterfaceTexImage (GLenum target, GLint level, GLint internalformat, GLsizei width, GLint border, GLenum format, GLenum type, const GLvoid *pixels)
{
	glTexImage1D(target, level, internalformat, width, border, format, type, pixels);
}

void glInterfaceTexImage (GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const GLvoid *pixels)
{
	glTexImage2D(target, level, internalformat, width, height, border, format, type, pixels);
}

void glInterfaceTexImage (GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const GLvoid *pixels)
{
	glTexImage3D(target, level, internalformat, width, height, depth, border, format, type, pixels);
}

void glInterfaceTexParameter (GLenum target, GLenum pname, GLfloat param)
{
	glTexParameterf(target, pname, param);
}

void glInterfaceTexParameter (GLenum target, GLenum pname, const GLfloat *params)
{
	glTexParameterfv(target, pname, params);
}

void glInterfaceTexParameter (GLenum target, GLenum pname, GLint param)
{
	glTexParameteri(target, pname, param);
}

void glInterfaceTexParameter (GLenum target, GLenum pname, const GLint *params)
{
	glTexParameteriv(target, pname, params);
}

void glInterfaceTexSubImage (GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const GLvoid *pixels)
{
	glTexSubImage1D(target, level, xoffset, width, format, type, pixels);
}

void glInterfaceTexSubImage (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid *pixels)
{
	glTexSubImage2D(target, level, xoffset, yoffset, width, height, format, type, pixels);
}

void glInterfaceTexSubImage (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const GLvoid *pixels)
{
	glTexSubImage3D(target, level, xoffset, yoffset, zoffset, width, height, depth, format, type, pixels);
}

void glInterfaceTranslate (GLdouble x, GLdouble y, GLdouble z)
{
	glTranslated(x, y, z);
}

void glInterfaceTranslate (GLfloat x, GLfloat y, GLfloat z)
{
	glTranslatef(x, y, z);
}

void glInterfaceVertex (GLdouble x, GLdouble y)
{
	glVertex2d(x, y);
}

void glInterfaceVertex (const GLdouble *v)
{
	glVertex2dv(v);
}

void glInterfaceVertex (GLfloat x, GLfloat y)
{
	glVertex2f(x, y);
}

void glInterfaceVertex (const GLfloat *v)
{
	glVertex2fv(v);
}

void glInterfaceVertex (GLint x, GLint y)
{
	glVertex2i(x, y);
}

void glInterfaceVertex (const GLint *v)
{
	glVertex2iv(v);
}

void glInterfaceVertex (GLshort x, GLshort y)
{
	glVertex2s(x, y);
}

void glInterfaceVertex (const GLshort *v)
{
	glVertex2sv(v);
}

void glInterfaceVertex (GLdouble x, GLdouble y, GLdouble z)
{
	glVertex3d(x, y, z);
}

void glInterfaceVertex3 (const GLdouble *v)
{
	glVertex3dv(v);
}

void glInterfaceVertex (GLfloat x, GLfloat y, GLfloat z)
{
	glVertex3f(x, y, z);
}

void glInterfaceVertex3 (const GLfloat *v)
{
	glVertex3fv(v);
}

void glInterfaceVertex (GLint x, GLint y, GLint z)
{
	glVertex3i(x, y, z);
}

void glInterfaceVertex3 (const GLint *v)
{
	glVertex3iv(v);
}

void glInterfaceVertex (GLshort x, GLshort y, GLshort z)
{
	glVertex3s(x, y, z);
}

void glInterfaceVertex3 (const GLshort *v)
{
	glVertex3sv(v);
}

void glInterfaceVertex (GLdouble x, GLdouble y, GLdouble z, GLdouble w)
{
	glVertex4d(x, y, z, w);
}

void glInterfaceVertex4 (const GLdouble *v)
{
	glVertex4dv(v);
}

void glInterfaceVertex (GLfloat x, GLfloat y, GLfloat z, GLfloat w)
{
	glVertex4f(x, y, z, w);
}

void glInterfaceVertex4 (const GLfloat *v)
{
	glVertex4fv(v);
}

void glInterfaceVertex (GLint x, GLint y, GLint z, GLint w)
{
	glVertex4i(x, y, z, w);
}

void glInterfaceVertex4 (const GLint *v)
{
	glVertex4iv(v);
}

void glInterfaceVertex (GLshort x, GLshort y, GLshort z, GLshort w)
{
	glVertex4s(x, y, z, w);
}

void glInterfaceVertex4 (const GLshort *v)
{
	glVertex4sv(v);
}

void glInterfaceVertexPointer (GLint size, GLenum type, GLsizei stride, const GLvoid *pointer)
{
	glVertexPointer(size, type, stride, pointer);
}

void glInterfaceViewport (GLint x, GLint y, GLsizei width, GLsizei height)
{
	glViewport(x, y, width, height);
}

void glInterfaceSampleCoverage (GLclampf value, GLboolean invert)
{
	glSampleCoverage(value, invert);
}

void glInterfaceLoadTransposeMatrix (const GLfloat *m)
{
	glLoadTransposeMatrixf(m);
}

void glInterfaceLoadTransposeMatrix (const GLdouble *m)
{
	glLoadTransposeMatrixd(m);
}

void glInterfaceMultTransposeMatrix (const GLfloat *m)
{
	glMultTransposeMatrixf(m);
}

void glInterfaceMultTransposeMatrix (const GLdouble *m)
{
	glMultTransposeMatrixd(m);
}

void glInterfaceCompressedTexImage (GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, const GLvoid *data)
{
	glCompressedTexImage3D(target, level, internalformat, width, height, depth, border, imageSize, data);
}

void glInterfaceCompressedTexImage (GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const GLvoid *data)
{
	glCompressedTexImage2D(target, level, internalformat, width, height, border, imageSize, data);
}

void glInterfaceCompressedTexImage (GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLsizei imageSize, const GLvoid *data)
{
	glCompressedTexImage1D(target, level, internalformat, width, border, imageSize, data);
}

void glInterfaceCompressedTexSubImage (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const GLvoid *data)
{
	glCompressedTexSubImage3D(target, level, xoffset, yoffset, zoffset, width, height, depth, format, imageSize, data);
}

void glInterfaceCompressedTexSubImage (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const GLvoid *data)
{
	glCompressedTexSubImage2D(target, level, xoffset, yoffset, width, height, format, imageSize, data);
}

void glInterfaceCompressedTexSubImage (GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const GLvoid *data)
{
	glCompressedTexSubImage1D(target, level, xoffset, width, format, imageSize, data);
}

void glInterfaceGetCompressedTexImage (GLenum target, GLint lod, GLvoid *img)
{
	glGetCompressedTexImage(target, lod, img);
}

void glInterfaceActiveTexture (GLenum texture)
{
	glActiveTexture(texture);
}

void glInterfaceClientActiveTexture (GLenum texture)
{
	glClientActiveTexture(texture);
}

void glInterfaceMultiTexCoord (GLenum target, GLdouble s)
{
	glMultiTexCoord1d(target, s);
}

void glInterfaceMultiTexCoord (GLenum target, const GLdouble *v)
{
	glMultiTexCoord1dv(target, v);
}

void glInterfaceMultiTexCoord (GLenum target, GLfloat s)
{
	glMultiTexCoord1f(target, s);
}

void glInterfaceMultiTexCoord (GLenum target, const GLfloat *v)
{
	glMultiTexCoord1fv(target, v);
}

void glInterfaceMultiTexCoord (GLenum target, GLint s)
{
	glMultiTexCoord1i(target, s);
}

void glInterfaceMultiTexCoord (GLenum target, const GLint *v)
{
	glMultiTexCoord1iv(target, v);
}

void glInterfaceMultiTexCoord (GLenum target, GLshort s)
{
	glMultiTexCoord1s(target, s);
}

void glInterfaceMultiTexCoord (GLenum target, const GLshort *v)
{
	glMultiTexCoord1sv(target, v);
}

void glInterfaceMultiTexCoord (GLenum target, GLdouble s, GLdouble t)
{
	glMultiTexCoord2d(target, s, t);
}

void glInterfaceMultiTexCoord2 (GLenum target, const GLdouble *v)
{
	glMultiTexCoord2dv(target, v);
}

void glInterfaceMultiTexCoord (GLenum target, GLfloat s, GLfloat t)
{
	glMultiTexCoord2f(target, s, t);
}

void glInterfaceMultiTexCoord2 (GLenum target, const GLfloat *v)
{
	glMultiTexCoord2fv(target, v);
}

void glInterfaceMultiTexCoord (GLenum target, GLint s, GLint t)
{
	glMultiTexCoord2i(target, s, t);
}

void glInterfaceMultiTexCoord2 (GLenum target, const GLint *v)
{
	glMultiTexCoord2iv(target, v);
}

void glInterfaceMultiTexCoord (GLenum target, GLshort s, GLshort t)
{
	glMultiTexCoord2s(target, s, t);
}

void glInterfaceMultiTexCoord (GLenum target, GLdouble s, GLdouble t, GLdouble r)
{
	glMultiTexCoord3d(target, s, t, r);
}

void glInterfaceMultiTexCoord3 (GLenum target, const GLdouble *v)
{
	glMultiTexCoord3dv(target, v);
}

void glInterfaceMultiTexCoord (GLenum target, GLfloat s, GLfloat t, GLfloat r)
{
	glMultiTexCoord3f(target, s, t, r);
}

void glInterfaceMultiTexCoord3 (GLenum target, const GLfloat *v)
{
	glMultiTexCoord3fv(target, v);
}

void glInterfaceMultiTexCoord (GLenum target, GLint s, GLint t, GLint r)
{
	glMultiTexCoord3i(target, s, t, r);
}

void glInterfaceMultiTexCoord3 (GLenum target, const GLint *v)
{
	glMultiTexCoord3iv(target, v);
}

void glInterfaceMultiTexCoord (GLenum target, GLshort s, GLshort t, GLshort r)
{
	glMultiTexCoord3s(target, s, t, r);
}

void glInterfaceMultiTexCoord3 (GLenum target, const GLshort *v)
{
	glMultiTexCoord3sv(target, v);
}

void glInterfaceMultiTexCoord (GLenum target, GLdouble s, GLdouble t, GLdouble r, GLdouble q)
{
	glMultiTexCoord4d(target, s, t, r, q);
}

void glInterfaceMultiTexCoord4 (GLenum target, const GLdouble *v)
{
	glMultiTexCoord4dv(target, v);
}

void glInterfaceMultiTexCoord (GLenum target, GLfloat s, GLfloat t, GLfloat r, GLfloat q)
{
	glMultiTexCoord4f(target, s, t, r, q);
}

void glInterfaceMultiTexCoord4 (GLenum target, const GLfloat *v)
{
	glMultiTexCoord4fv(target, v);
}

void glInterfaceMultiTexCoord (GLenum target, GLint s, GLint t, GLint r, GLint q)
{
	glMultiTexCoord4i(target, s, t, r, q);
}

void glInterfaceMultiTexCoord4 (GLenum target, const GLint *v)
{
	glMultiTexCoord4iv(target, v);
}

void glInterfaceMultiTexCoord (GLenum target, GLshort s, GLshort t, GLshort r, GLshort q)
{
	glMultiTexCoord4s(target, s, t, r, q);
}

void glInterfaceMultiTexCoord4 (GLenum target, const GLshort *v)
{
	glMultiTexCoord4sv(target, v);
}

void glInterfaceFogCoord (GLfloat coord)
{
	glFogCoordf(coord);
}

void glInterfaceFogCoord (const GLfloat *coord)
{
	glFogCoordfv(coord);
}

void glInterfaceFogCoord (GLdouble coord)
{
	glFogCoordd(coord);
}

void glInterfaceFogCoord (const GLdouble *coord)
{
	glFogCoorddv(coord);
}

void glInterfaceFogCoordPointer (GLenum type, GLsizei stride, const GLvoid *pointer)
{
	glFogCoordPointer(type, stride, pointer);
}

void glInterfaceSecondaryColor (GLbyte red, GLbyte green, GLbyte blue)
{
	glSecondaryColor3b(red, green, blue);
}

void glInterfaceSecondaryColor (const GLbyte *v)
{
	glSecondaryColor3bv(v);
}

void glInterfaceSecondaryColor (GLdouble red, GLdouble green, GLdouble blue)
{
	glSecondaryColor3d(red, green, blue);
}

void glInterfaceSecondaryColor (const GLdouble *v)
{
	glSecondaryColor3dv(v);
}

void glInterfaceSecondaryColor (GLfloat red, GLfloat green, GLfloat blue)
{
	glSecondaryColor3f(red, green, blue);
}

void glInterfaceSecondaryColor (const GLfloat *v)
{
	glSecondaryColor3fv(v);
}

void glInterfaceSecondaryColor (GLint red, GLint green, GLint blue)
{
	glSecondaryColor3i(red, green, blue);
}

void glInterfaceSecondaryColor (const GLint *v)
{
	glSecondaryColor3iv(v);
}

void glInterfaceSecondaryColor (GLshort red, GLshort green, GLshort blue)
{
	glSecondaryColor3s(red, green, blue);
}

void glInterfaceSecondaryColor (const GLshort *v)
{
	glSecondaryColor3sv(v);
}

void glInterfaceSecondaryColor (GLubyte red, GLubyte green, GLubyte blue)
{
	glSecondaryColor3ub(red, green, blue);
}

void glInterfaceSecondaryColor (const GLubyte *v)
{
	glSecondaryColor3ubv(v);
}

void glInterfaceSecondaryColor (GLuint red, GLuint green, GLuint blue)
{
	glSecondaryColor3ui(red, green, blue);
}

void glInterfaceSecondaryColor (const GLuint *v)
{
	glSecondaryColor3uiv(v);
}

void glInterfaceSecondaryColor (GLushort red, GLushort green, GLushort blue)
{
	glSecondaryColor3us(red, green, blue);
}

void glInterfaceSecondaryColor (const GLushort *v)
{
	glSecondaryColor3usv(v);
}

void glInterfaceSecondaryColorPointer (GLint size, GLenum type, GLsizei stride, const GLvoid *pointer)
{
	glSecondaryColorPointer(size, type, stride, pointer);
}

void glInterfacePointParameter (GLenum pname, GLfloat param)
{
	glPointParameterf(pname, param);
}

void glInterfacePointParameter (GLenum pname, const GLfloat *params)
{
	glPointParameterfv(pname, params);
}

void glInterfacePointParameter (GLenum pname, GLint param)
{
	glPointParameteri(pname, param);
}

void glInterfacePointParameter (GLenum pname, const GLint *params)
{
	glPointParameteriv(pname, params);
}

void glInterfaceBlendFuncSeparate (GLenum srcRGB, GLenum dstRGB, GLenum srcAlpha, GLenum dstAlpha)
{
	glBlendFuncSeparate(srcRGB, dstRGB, srcAlpha, dstAlpha);
}

void glInterfaceMultiDrawArrays (GLenum mode, const GLint *first, const GLsizei *count, GLsizei primcount)
{
	glMultiDrawArrays(mode, first, count, primcount);
}

void glInterfaceMultiDrawElements (GLenum mode, const GLsizei *count, GLenum type, const GLvoid* const *indices, GLsizei primcount)
{
	glMultiDrawElements(mode, count, type, indices, primcount);
}

void glInterfaceWindowPos (GLdouble x, GLdouble y)
{
	glWindowPos2d(x, y);
}

void glInterfaceWindowPos (const GLdouble *v)
{
	glWindowPos2dv(v);
}

void glInterfaceWindowPos (GLfloat x, GLfloat y)
{
	glWindowPos2f(x, y);
}

void glInterfaceWindowPos (const GLfloat *v)
{
	glWindowPos2fv(v);
}

void glInterfaceWindowPos (GLint x, GLint y)
{
	glWindowPos2i(x, y);
}

void glInterfaceWindowPos (const GLint *v)
{
	glWindowPos2iv(v);
}

void glInterfaceWindowPos (GLshort x, GLshort y)
{
	glWindowPos2s(x, y);
}

void glInterfaceWindowPos (const GLshort *v)
{
	glWindowPos2sv(v);
}

void glInterfaceWindowPos (GLdouble x, GLdouble y, GLdouble z)
{
	glWindowPos3d(x, y, z);
}

void glInterfaceWindowPos3 (const GLdouble *v)
{
	glWindowPos3dv(v);
}

void glInterfaceWindowPos (GLfloat x, GLfloat y, GLfloat z)
{
	glWindowPos3f(x, y, z);
}

void glInterfaceWindowPos3 (const GLfloat *v)
{
	glWindowPos3fv(v);
}

void glInterfaceWindowPos (GLint x, GLint y, GLint z)
{
	glWindowPos3i(x, y, z);
}

void glInterfaceWindowPos3 (const GLint *v)
{
	glWindowPos3iv(v);
}

void glInterfaceWindowPos (GLshort x, GLshort y, GLshort z)
{
	glWindowPos3s(x, y, z);
}

void glInterfaceWindowPos3 (const GLshort *v)
{
	glWindowPos3sv(v);
}

void glInterfaceGenQueries (GLsizei n, GLuint *ids)
{
	glGenQueries(n, ids);
}

void glInterfaceDeleteQueries (GLsizei n, const GLuint *ids)
{
	glDeleteQueries(n, ids);
}

GLboolean glInterfaceIsQuery (GLuint id)
{
	return glIsQuery(id);	
}

void glInterfaceBeginQuery (GLenum target, GLuint id)
{
	glBeginQuery(target, id);
}

void glInterfaceEndQuery (GLenum target)
{
	glEndQuery(target);
}

void glInterfaceGetQuery (GLenum target, GLenum pname, GLint *params)
{
	glGetQueryiv(target, pname, params);
}

void glInterfaceGetQueryObject (GLuint id, GLenum pname, GLint *params)
{
	glGetQueryObjectiv(id, pname, params);
}

void glInterfaceGetQueryObject (GLuint id, GLenum pname, GLuint *params)
{
	glGetQueryObjectuiv(id, pname, params);
}

void glInterfaceBindBuffer (GLenum target, GLuint buffer)
{
	glBindBuffer(target, buffer);
}

void glInterfaceDeleteBuffers (GLsizei n, const GLuint *buffers)
{
	glDeleteBuffers(n, buffers);
}

void glInterfaceGenBuffers (GLsizei n, GLuint *buffers)
{
	glGenBuffers(n, buffers);
}

GLboolean glInterfaceIsBuffer (GLuint buffer)
{
	return glIsBuffer(buffer);
}

void glInterfaceBufferData (GLenum target, GLsizeiptr size, const GLvoid *data, GLenum usage)
{
	glBufferData(target, size, data, usage);
}

void glInterfaceBufferSubData (GLenum target, GLintptr offset, GLsizeiptr size, const GLvoid *data)
{
	glBufferSubData(target, offset, size, data);
}

void glInterfaceGetBufferSubData (GLenum target, GLintptr offset, GLsizeiptr size, GLvoid *data)
{
	glGetBufferSubData(target, offset, size, data);
}

GLvoid *glInterfaceMapBuffer (GLenum target, GLenum access)
{
	return glMapBuffer(target, access);
}

GLboolean glInterfaceUnmapBuffer (GLenum target)
{
	return glUnmapBuffer(target);
}

void glInterfaceGetBufferParameteriv (GLenum target, GLenum pname, GLint *params)
{
	glGetBufferParameteriv(target, pname, params);
}

void glInterfaceGetBufferPointerv (GLenum target, GLenum pname, GLvoid **params)
{
	glGetBufferPointerv(target, pname, params);
}

void glInterfaceDrawBuffers (GLsizei n, const GLenum *bufs)
{
	glDrawBuffers(n, bufs);
}

void glInterfaceVertexAttrib (GLuint index, GLdouble x)
{
	glVertexAttrib1d(index, x);
}

void glInterfaceVertexAttrib (GLuint index, const GLdouble *v)
{
	glVertexAttrib1dv(index, v);
}

void glInterfaceVertexAttrib (GLuint index, GLfloat x)
{
	glVertexAttrib1f(index, x);
}

void glInterfaceVertexAttrib (GLuint index, const GLfloat *v)
{
	glVertexAttrib1fv(index, v);
}

void glInterfaceVertexAttrib (GLuint index, GLshort x)
{
	glVertexAttrib1s(index, x);
}

void glInterfaceVertexAttrib (GLuint index, const GLshort *v)
{
	glVertexAttrib1sv(index, v);
}

void glInterfaceVertexAttrib (GLuint index, GLdouble x, GLdouble y)
{
	glVertexAttrib2d(index, x, y);
}

void glInterfaceVertexAttrib2 (GLuint index, const GLdouble *v)
{
    glVertexAttrib2dv(index, v);
}

void glInterfaceVertexAttrib (GLuint index, GLfloat x, GLfloat y)
{
	glVertexAttrib2f(index, x, y);
}

void glInterfaceVertexAttrib2 (GLuint index, const GLfloat *v)
{
	glVertexAttrib2fv(index, v);
}

void glInterfaceVertexAttrib (GLuint index, GLshort x, GLshort y)
{
	glVertexAttrib2s(index, x, y);
}

void glInterfaceVertexAttrib2 (GLuint index, const GLshort *v)
{
	glVertexAttrib2sv(index, v);
}

void glInterfaceVertexAttrib (GLuint index, GLdouble x, GLdouble y, GLdouble z)
{
	glVertexAttrib3d(index, x, y, z);
}

void glInterfaceVertexAttrib3 (GLuint index, const GLdouble *v)
{
	glVertexAttrib3dv(index, v);
}

void glInterfaceVertexAttrib (GLuint index, GLfloat x, GLfloat y, GLfloat z)
{
	glVertexAttrib3f(index, x, y, z);
}

void glInterfaceVertexAttrib3 (GLuint index, const GLfloat *v)
{
	glVertexAttrib3fv(index, v);
}

void glInterfaceVertexAttrib (GLuint index, GLshort x, GLshort y, GLshort z)
{
	glVertexAttrib3s(index, x, y, z);
}

void glInterfaceVertexAttrib3 (GLuint index, const GLshort *v)
{
	glVertexAttrib3sv(index, v);
}

void glInterfaceVertexAttrib4N (GLuint index, const GLbyte *v)
{
	glVertexAttrib4Nbv(index, v);
}

void glInterfaceVertexAttrib4N (GLuint index, const GLint *v)
{
	glVertexAttrib4Niv(index, v);
}

void glInterfaceVertexAttrib4N (GLuint index, const GLshort *v)
{
	glVertexAttrib4Nsv(index, v);
}

void glInterfaceVertexAttrib4N (GLuint index, GLubyte x, GLubyte y, GLubyte z, GLubyte w)
{
	glVertexAttrib4Nub(index, x, y, z, w);
}

void glInterfaceVertexAttrib4N (GLuint index, const GLubyte *v)
{
	glVertexAttrib4Nubv(index, v);
}

void glInterfaceVertexAttrib4N (GLuint index, const GLuint *v)
{
	glVertexAttrib4Nuiv(index, v);
}

void glInterfaceVertexAttrib4N (GLuint index, const GLushort *v)
{
	glVertexAttrib4Nusv(index, v);
}

void glInterfaceVertexAttrib4 (GLuint index, const GLbyte *v)
{
	glVertexAttrib4bv(index, v);
}

void glInterfaceVertexAttrib (GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w)
{
	glVertexAttrib4d(index, x, y, z, w);
}

void glInterfaceVertexAttrib4 (GLuint index, const GLdouble *v)
{
	glVertexAttrib4dv(index, v);
}

void glInterfaceVertexAttrib (GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w)
{
	glVertexAttrib4f(index, x, y, z, w);
}

void glInterfaceVertexAttrib4 (GLuint index, const GLfloat *v)
{
	glVertexAttrib4fv(index, v);
}

void glInterfaceVertexAttrib4 (GLuint index, const GLint *v)
{
	glVertexAttrib4iv(index, v);
}

void glInterfaceVertexAttrib (GLuint index, GLshort x, GLshort y, GLshort z, GLshort w)
{
	glVertexAttrib4s(index, x, y, z, w);
}

void glInterfaceVertexAttrib4 (GLuint index, const GLshort *v)
{
	glVertexAttrib4sv(index, v);
}

void glInterfaceVertexAttrib4 (GLuint index, const GLubyte *v)
{
	glVertexAttrib4ubv(index, v);
}

void glInterfaceVertexAttrib4 (GLuint index, const GLuint *v)
{
	glVertexAttrib4uiv(index, v);
}

void glInterfaceVertexAttrib4 (GLuint index, const GLushort *v)
{
	glVertexAttrib4usv(index, v);
}

void glInterfaceVertexAttribPointer (GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const GLvoid *pointer)
{
	glVertexAttribPointer(index, size, type, normalized, stride, pointer);
}

void glInterfaceEnableVertexAttribArray (GLuint index)
{
	glEnableVertexAttribArray(index);
}

void glInterfaceDisableVertexAttribArray (GLuint index)
{
	glDisableVertexAttribArray(index);
}

void glInterfaceGetVertexAttrib (GLuint index, GLenum pname, GLdouble *params)
{
	glGetVertexAttribdv(index, pname, params);
}

void glInterfaceGetVertexAttrib (GLuint index, GLenum pname, GLfloat *params)
{
	glGetVertexAttribfv(index, pname, params);
}

void glInterfaceGetVertexAttrib (GLuint index, GLenum pname, GLint *params)
{
	glGetVertexAttribiv(index, pname, params);
}

void glInterfaceGetVertexAttribPointerv (GLuint index, GLenum pname, GLvoid **pointer)
{
	glGetVertexAttribPointerv(index, pname, pointer);
}

void glInterfaceDeleteShader (GLuint shader)
{
	glDeleteShader(shader);
}

void glInterfaceDetachShader (GLuint program, GLuint shader)
{
	glDetachShader(program, shader);
}

GLuint glInterfaceCreateShader (GLenum type)
{
	return glCreateShader(type);
}

void glInterfaceShaderSource (GLuint shader, GLsizei count, const GLchar* const *string, const GLint *length)
{
	glShaderSource(shader, count, string, length);
}

void glInterfaceCompileShader (GLuint shader)
{
	glCompileShader(shader);
}

GLuint glInterfaceCreateProgram (void)
{
	return glCreateProgram();
}

void glInterfaceAttachShader (GLuint program, GLuint shader)
{
	glAttachShader(program, shader);
}

void glInterfaceLinkProgram (GLuint program)
{
	glLinkProgram(program);
}

void glInterfaceUseProgram (GLuint program)
{
	glUseProgram(program);
}

void glInterfaceDeleteProgram (GLuint program)
{
	glDeleteProgram(program);
}

void glInterfaceValidateProgram (GLuint program)
{
	glValidateProgram(program);
}

void glInterfaceUniform (GLint location, GLfloat v0)
{
	glUniform1f(location, v0);
}

void glInterfaceUniform (GLint location, GLfloat v0, GLfloat v1)
{
	glUniform2f(location, v0, v1);
}

void glInterfaceUniform (GLint location, GLfloat v0, GLfloat v1, GLfloat v2)
{
	glUniform3f(location, v0, v1, v2);
}

void glInterfaceUniform (GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3)
{
	glUniform4f(location, v0, v1, v2, v3);
}

void glInterfaceUniform (GLint location, GLint v0)
{
	glUniform1i(location, v0);
}

void glInterfaceUniform (GLint location, GLint v0, GLint v1)
{
	glUniform2i(location, v0, v1);
}

void glInterfaceUniform (GLint location, GLint v0, GLint v1, GLint v2)
{
	glUniform3i(location, v0, v1, v2);
}

void glInterfaceUniform (GLint location, GLint v0, GLint v1, GLint v2, GLint v3)
{
	glUniform4i(location, v0, v1, v2, v3);
}

void glInterfaceUniform (GLint location, GLsizei count, const GLfloat *value)
{
	glUniform1fv(location, count, value);
}

void glInterfaceUniform2 (GLint location, GLsizei count, const GLfloat *value)
{
	glUniform2fv(location, count, value);
}

void glInterfaceUniform3 (GLint location, GLsizei count, const GLfloat *value)
{
	glUniform3fv(location, count, value);
}

void glInterfaceUniform4 (GLint location, GLsizei count, const GLfloat *value)
{
	glUniform4fv(location, count, value);
}

void glInterfaceUniform (GLint location, GLsizei count, const GLint *value)
{
	glUniform1iv(location, count, value);
}

void glInterfaceUniform2 (GLint location, GLsizei count, const GLint *value)
{
	glUniform2iv(location, count, value);
}

void glInterfaceUniform3 (GLint location, GLsizei count, const GLint *value)
{
	glUniform3iv(location, count, value);
}

void glInterfaceUniform4 (GLint location, GLsizei count, const GLint *value)
{
	glUniform4iv(location, count, value);
}

void glInterfaceUniformMatrix2 (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value)
{
	glUniformMatrix2fv(location, count, transpose, value);
}

void glInterfaceUniformMatrix3 (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value)
{
	glUniformMatrix3fv(location, count, transpose, value);
}

void glInterfaceUniformMatrix4 (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value)
{
	glUniformMatrix4fv(location, count, transpose, value);
}

GLboolean glInterfaceIsShader (GLuint shader)
{
	return glIsShader(shader);
}

GLboolean glInterfaceIsProgram (GLuint program)
{
	return glIsProgram(program);
}

void glInterfaceGetShaderiv (GLuint shader, GLenum pname, GLint *params)
{
	glGetShaderiv(shader, pname, params);
}

void glInterfaceGetProgramiv (GLuint program, GLenum pname, GLint *params)
{
	glGetProgramiv(program, pname, params);
}

void glInterfaceGetAttachedShaders (GLuint program, GLsizei maxCount, GLsizei *count, GLuint *shaders)
{
	glGetAttachedShaders(program, maxCount, count, shaders);
}

void glInterfaceGetShaderInfoLog (GLuint shader, GLsizei bufSize, GLsizei *length, GLchar *infoLog)
{
	glGetShaderInfoLog(shader, bufSize, length, infoLog);
}

GLint glInterfaceGetUniformLocation (GLuint program, const GLchar *name)
{
	return glGetUniformLocation(program, name);
}

void glInterfaceGetActiveUniform (GLuint program, GLuint index, GLsizei bufSize, GLsizei *length, GLint *size, GLenum *type, GLchar *name)
{
	glGetActiveUniform(program, index, bufSize, length, size, type, name);
}

void glInterfaceGetUniform (GLuint program, GLint location, GLfloat *params)
{
	glGetUniformfv(program, location, params);
}

void glInterfaceGetUniform (GLuint program, GLint location, GLint *params)
{
	glGetUniformiv(program, location, params);
}

void glInterfaceGetShaderSource (GLuint shader, GLsizei bufSize, GLsizei *length, GLchar *source)
{
	glGetShaderSource(shader, bufSize, length, source);
}

void glInterfaceBindAttribLocation (GLuint program, GLuint index, const GLchar *name)
{
	glBindAttribLocation(program, index, name);
}

void glInterfaceGetActiveAttrib (GLuint program, GLuint index, GLsizei bufSize, GLsizei *length, GLint *size, GLenum *type, GLchar *name)
{
	glGetActiveAttrib(program, index, bufSize, length, size, type, name);
}

GLint glInterfaceGetAttribLocation (GLuint program, const GLchar *name)
{
	return glGetAttribLocation(program, name);
}

void glInterfaceStencilFuncSeparate (GLenum face, GLenum func, GLint ref, GLuint mask)
{
	glStencilFuncSeparate(face, func, ref, mask);
}

void glInterfaceStencilOpSeparate (GLenum face, GLenum fail, GLenum zfail, GLenum zpass)
{
	glStencilOpSeparate(face, fail, zfail, zpass);
}

void glInterfaceStencilMaskSeparate (GLenum face, GLuint mask)
{
	glStencilMaskSeparate(face, mask);
}

void glInterfaceUniformMatrix2x3fv (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value)
{
	glUniformMatrix2x3fv(location, count, transpose, value);
}

void glInterfaceUniformMatrix3x2fv (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value)
{
	glUniformMatrix3x2fv(location, count, transpose, value);
}

void glInterfaceUniformMatrix2x4fv (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value)
{
	glUniformMatrix2x4fv(location, count, transpose, value);
}

void glInterfaceUniformMatrix4x2fv (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value)
{
	glUniformMatrix4x2fv(location, count, transpose, value);
}

void glInterfaceUniformMatrix3x4fv (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value)
{
	glUniformMatrix3x4fv(location, count, transpose, value);
}

void glInterfaceUniformMatrix4x3fv (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value)
{
	glUniformMatrix4x3fv(location, count, transpose, value);
}