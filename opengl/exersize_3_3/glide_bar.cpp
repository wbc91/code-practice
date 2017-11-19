#include <GLUT/glut.h>
#include <stdio.h>  
int width = 600;
int height = 600;
int slidheight = 20;
GLfloat colors[4] = {1, 1, 1, 1};
class SlidBar
{
private:
	GLdouble pos0[2];//滑动条在屏幕上的位置 
	GLdouble pos_point[2];//滑动点的位置
	GLint length;//滑动条长度,单位:像素
	GLfloat ratio; //0-1, 滑动条当前百分比
	unsigned char* pixels;//滑动条的像素信息 
	GLdouble highvalue;//滑动条达到100%时的数值  
    GLdouble lowvalue;//0%时的数值  

   void SetRatio(int x)//设置百分比,滑动点
   {
   		ratio = (GLfloat)GLfloat(x - pos0[0]) / GLfloat(length);
   		pos_point[0] = pos0[0] + length*ratio;
   		printf("ratio %f\n", ratio);
   }

   void SetPixels()//改变像素信息,也就是滑动条的ui图像
   {
   		unsigned int index;
   		for (int i = 0; i < slidheight; i++)//初始化,全部设置成透明状态 
   		{
   			for (int j = 0; j < length; j++)
   			{
   				index = i*length+j;//像素矩阵第i行第j列,每个"单位"有rgba四个值需要设置
   				pixels[index*4+0] = 0; //r
   				pixels[index*4+1] = 0; //g
   				pixels[index*4+2] = 0; //b
   				pixels[index*4+3] = 0; //a
   			}
   		}
   		for (int i = 0; i < length; i++)//横向
   		{
   			index = 0.5*slidheight*length+i;

   			pixels[index * 4 + 0] = 255; //r
   			pixels[index * 4 + 1] = 0; //g
   			pixels[index * 4 + 2] = 0; //b
   			pixels[index * 4 + 3] = 255; //a
   		}

   		for (int j = 0; j < slidheight; j++)//纵向
   		{
   			index = j*length;//最左边的边界,表现为一条红色的竖"1"
   			pixels[index * 4 + 0] = 255;
   			pixels[index * 4 + 1] = 0;
   			pixels[index * 4 + 2] = 0;
   			pixels[index * 4 + 3] = 255;

   			index = j * length + length - 1;//最右边的边界，同上
   			pixels[index * 4 + 0] = 255;
   			pixels[index * 4 + 1] = 0;
   			pixels[index * 4 + 2] = 0;
   			pixels[index * 4 + 3] = 255;

   			index = j*length + (length - 1)*ratio;//当前滑动点的位置， 表现为一条黄色的竖“1”
   			pixels[index * 4 + 0] = 255;
   			pixels[index * 4 + 1] = 255;
   			pixels[index * 4 + 2] = 0;
   			pixels[index * 4 + 3] = 255;
   		}
   }
public:
	SlidBar()
	{

	}
	~SlidBar()
	{
		delete pixels;
	}
	void Init(GLdouble* pos0, GLfloat ratio, GLint length)//策略1:只返回ratio
	{
		this->pos0[0] = pos0[0];//滑动条位置
		this->pos0[1] = pos0[1];
		this->ratio = ratio;//初始百分比
		this->length = length;//长度
		pos_point[0] = pos0[0] + length*ratio;//滑动点的位置
		pos_point[1] = pos0[1];
		this->pixels = new unsigned char[length*slidheight*4];//初始化像素缓存
		SetPixels();//根据当前状态在像素缓存中进行绘制
	}

	void Init_value(GLdouble* pos0, GLfloat ratio, GLint length, GLdouble lowvalue, GLdouble highvalue)//策略2:直接获得最低值和最高值,返回现在的值 
	{
		this->pos0[0] = pos0[0];
		this->pos0[1] = pos0[1];
		this->ratio = ratio;
		this->length = length;
		pos_point[0] = pos0[0] + length*ratio;
		pos_point[1] = pos0[1];
		this->pixels = new unsigned char[length*slidheight*4];
		SetPixels();

		this->lowvalue = lowvalue;
		this->highvalue = highvalue;
	}

	GLfloat GetRatio() //获取当前百分比
	{
		return ratio;
	}

	GLdouble GetValue() //如果使用策略2,用这个函数获得当前值
	{
		return (lowvalue + (highvalue - lowvalue)*ratio);
	}
	bool TouchTest(int x, int y) //由传进来的鼠标坐标(左下角为原点,所以可能需要变换)测试是否点中
	{
		bool target = false;
		int x0 = pos0[0];//滑动条左下角x
		int y0 = pos0[1] - slidheight / 2;//左下角y
		int x1 = pos0[0] + length; //右上角x
		int y1 = pos0[1] + slidheight / 2;//右上角y

		if ((x > x0) && (x<x1) && (y>y0) && (y<y1))//是否在上面这个矩形中 
		{
			target = true;
			SetRatio(x);//设置百分比
			SetPixels();//改变像素信息,重新画图
		}

		return target;
	}

	void DrawSolid()//根据像素显示信息
	{
		glWindowPos2d(pos0[0], pos0[1]-slidheight/2);//在屏幕相应的位置放置滑动条,pos0[1]-slidheight/2:pos0[1]其实是滑动条半高处的y,所以还需要减半个高才是左下角的y
		glDrawPixels(length, slidheight, GL_RGBA, GL_UNSIGNED_BYTE, this->pixels);
	}

};

SlidBar test1;
void myDisplay(void)
{
	glClearColor(0.0,0.0,0.0,1.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor4fv(colors);
	glBegin(GL_TRIANGLES);
	glVertex2f(-0.6, -0.5);
	glVertex2f(0.6, -0.5);
	glVertex2f(0, 0.4);
	glEnd();
	test1.DrawSolid();

	glFlush();
}

void uiinit()
{
	GLdouble pos[2] = {20,40};
	GLfloat rat = colors[0]/1;
	test1.Init_value(pos, rat, 200, 0, 1);
}
void init()
{
	uiinit();
}

void mouse(int button, int state, int x, int y)
{
	if (state == GLUT_DOWN&&button==GLUT_LEFT_BUTTON)
	{
		printf("x:%d,y:%d\n", x, y);
		if(test1.TouchTest(x, height-y))
		{
			colors[0] = test1.GetValue();
		}
	}
	glutPostRedisplay();
}

int main(int argc, char**argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowPosition(100,100);
	glutInitWindowSize(width, height);
	glutCreateWindow("Slide Bar");
	glEnable(GL_BLEND);//启用这个特性,放置ui背景覆盖实际画面
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	init();
	glutDisplayFunc(myDisplay);
	glutMouseFunc(mouse);
	glutMainLoop();
	return 0;
}