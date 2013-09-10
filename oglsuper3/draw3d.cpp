#include <gl/glut.h>
#include <gl/gl.h>
#include <math.h>

static GLfloat GL_PI = 3.14159f;

//���Ƴ���
static void RenderSences()
{
  GLfloat z = -50.0f;  
  //��ջ���
  glClear(GL_COLOR_BUFFER_BIT);
  //���û�ͼʹ�õ���ɫ
  glColor3f(1.0f, 0.0f, 0.0f);
  //�������
  glPushMatrix();
  //��ת, �������ת����Щ��ͬ��εĵ㶼�ص���һ�𣬿�����3DЧ���ˡ�
  glRotatef(200.0f, 1.0f, 0.0f, 0.0f);
  glRotatef(120.5f, 0.0f, 1.0f, 0.0f);
  //��ȡ��Ĵ�С�ķ�Χ���Լ������Ĳ���
  GLfloat size[2];
  GLfloat sizeStep;
  glGetFloatv(GL_POINT_SIZE_RANGE, size);
  glGetFloatv(GL_POINT_SIZE_GRANULARITY, &sizeStep);
  GLfloat curStep = size[0];
  for (GLfloat a = 0.0; a < GL_PI * 3.0f; a += 0.1f)
  {
    GLfloat x = 50.0f * cos(a);
    GLfloat y = 50.0f * sin(a);
    //���õ�Ĵ�С
    glPointSize(curStep);
    curStep += sizeStep;
    //���ö���
    glBegin(GL_POINTS);
      glVertex3f(x, y, z);
    glEnd();
    //����zֵ
    z += 0.5f;
  }
  glPopMatrix();	
	glFlush();
}

void ChangeSize(GLsizei w, GLsizei h)
{
  GLfloat nRange = 100.0f;
	if (h == 0)
	{
		h = 1;
	}
  //�����ӿ�
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

  //���ÿ�������
	GLfloat aspect = (GLfloat)w / (GLfloat)h;
	if (w <= h)
	{
    glOrtho(-nRange, nRange, -nRange/aspect, nRange/aspect, -nRange, nRange);
	}
  else
  {
    glOrtho(-nRange*aspect, nRange*aspect, -nRange, nRange, -nRange, nRange);
  }

  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
}
//��ʼ������
static void SetupRC()
{
  glClearColor(0.0f, 1.0f, 0.0f, 1.0f);
}
//��������
static void CreateWindow() {
  glutInitWindowSize(200, 200);
  glutCreateWindow("3d Points");
}

int main(int args, char **argv)
{
	glutInit(&args, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(200, 200);
	glutCreateWindow("draw points");
  SetupRC();
	glutDisplayFunc(RenderSences);	
	glutReshapeFunc(ChangeSize);
	glutMainLoop();
	return 0;
}